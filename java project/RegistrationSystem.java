import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

/** Coordinates student management, course management, registration and dropping. */
public class RegistrationSystem {
    public static final int MAX_CREDITS = 20;

    private final Map<String, Student> students = new LinkedHashMap<>();
    private final Map<String, Course> courses = new LinkedHashMap<>();
    private final List<Registration> registrations = new ArrayList<>();

    // ---------- Students ----------
    public void addStudent(Student s) throws RegistrationException {
        if (s.getId().isEmpty() || s.getName().isEmpty())
            throw new RegistrationException("Student ID and name cannot be empty.");
        if (s.getSemester() < 1 || s.getSemester() > 8)
            throw new RegistrationException("Semester must be between 1 and 8.");
        if (students.containsKey(s.getId()))
            throw new RegistrationException("Duplicate student ID: " + s.getId());
        students.put(s.getId(), s);
    }

    public Student findStudent(String id) { return students.get(id.trim()); }

    public Student getStudent(String id) throws RegistrationException {
        Student s = findStudent(id);
        if (s == null) throw new RegistrationException("Student not found: " + id);
        return s;
    }

    public List<Student> getAllStudents() { return new ArrayList<>(students.values()); }

    // ---------- Courses ----------
    public void addCourse(Course c) throws RegistrationException {
        if (c.getCode().isEmpty() || c.getName().isEmpty())
            throw new RegistrationException("Course code and name cannot be empty.");
        if (c.getCredits() <= 0) throw new RegistrationException("Credits must be positive.");
        if (c.getCapacity() <= 0) throw new RegistrationException("Capacity must be positive.");
        if (courses.containsKey(c.getCode()))
            throw new RegistrationException("Duplicate course code: " + c.getCode());
        if (c.getPrerequisite().equals(c.getCode()))
            throw new RegistrationException("A course cannot be its own prerequisite.");
        courses.put(c.getCode(), c);
    }

    public Course findCourse(String code) { return courses.get(code.trim().toUpperCase()); }

    public Course getCourse(String code) throws RegistrationException {
        Course c = findCourse(code);
        if (c == null) throw new RegistrationException("Course not found: " + code);
        return c;
    }

    public List<Course> getAllCourses() { return new ArrayList<>(courses.values()); }

    // ---------- Registration ----------
    public int totalCredits(Student s) {
        int total = 0;
        for (String code : s.getRegisteredCourses()) {
            Course c = courses.get(code);
            if (c != null) total += c.getCredits();
        }
        return total;
    }

    public void register(String studentId, String courseCode) throws RegistrationException {
        Student s = getStudent(studentId);                       // 1. student validity
        Course c = getCourse(courseCode);                        // 2. course validity
        if (s.isRegisteredFor(c.getCode()))                      // 3. duplicate
            throw new RegistrationException(s.getName() + " is already registered for " + c.getCode() + ".");
        if (c.hasPrerequisite() && !s.hasCompleted(c.getPrerequisite()))   // 4. prerequisite
            throw new RegistrationException("Prerequisite " + c.getPrerequisite()
                    + " has not been completed by " + s.getName() + ".");
        int newTotal = totalCredits(s) + c.getCredits();         // 5. credit limit
        if (newTotal > MAX_CREDITS)
            throw new RegistrationException("Credit limit exceeded: " + totalCredits(s) + " + "
                    + c.getCredits() + " = " + newTotal + " > " + MAX_CREDITS + ".");
        if (c.isFull())                                          // 6. capacity
            throw new RegistrationException("Course " + c.getCode() + " is full (" + c.getCapacity() + " seats).");
        link(s, c);
    }

    public void drop(String studentId, String courseCode) throws RegistrationException {
        Student s = getStudent(studentId);
        Course c = getCourse(courseCode);
        if (!s.isRegisteredFor(c.getCode()))
            throw new RegistrationException(s.getName() + " is not registered for " + c.getCode() + ".");
        s.removeRegistered(c.getCode());
        c.unenroll(s.getId());
        registrations.removeIf(r -> r.getStudent() == s && r.getCourse() == c);
    }

    /** Used while loading from file: no checks except existence. */
    public void restoreRegistration(String studentId, String courseCode) throws RegistrationException {
        Student s = getStudent(studentId);
        Course c = getCourse(courseCode);
        if (!s.isRegisteredFor(c.getCode())) link(s, c);
    }

    private void link(Student s, Course c) {
        s.addRegistered(c.getCode());
        c.enroll(s.getId());
        registrations.add(new Registration(s, c));
    }

    public void markCompleted(String studentId, String courseCode) throws RegistrationException {
        Student s = getStudent(studentId);
        Course c = getCourse(courseCode);
        if (s.hasCompleted(c.getCode()))
            throw new RegistrationException(c.getCode() + " is already marked completed for " + s.getName() + ".");
        if (s.isRegisteredFor(c.getCode())) {   // finishing a course frees the seat & credits
            s.removeRegistered(c.getCode());
            c.unenroll(s.getId());
            registrations.removeIf(r -> r.getStudent() == s && r.getCourse() == c);
        }
        s.addCompleted(c.getCode());
    }

    public List<Registration> getAllRegistrations() { return new ArrayList<>(registrations); }

    // ---------- Reports ----------
    public String academicSummary(String studentId) throws RegistrationException {
        Student s = getStudent(studentId);
        StringBuilder sb = new StringBuilder();
        sb.append("\n===== ACADEMIC SUMMARY =====\n");
        sb.append("Student ID : ").append(s.getId()).append("\n");
        sb.append("Name       : ").append(s.getName()).append("\n");
        sb.append("Department : ").append(s.getDepartment()).append("  (Semester ").append(s.getSemester()).append(")\n");
        sb.append("\nRegistered Courses:\n");
        if (s.getRegisteredCourses().isEmpty()) sb.append("  (none)\n");
        for (String code : s.getRegisteredCourses()) {
            Course c = courses.get(code);
            sb.append(String.format("  %-8s %-30s %d credits%n", code, c.getName(), c.getCredits()));
        }
        int total = totalCredits(s);
        sb.append("\nTotal Registered Credits : ").append(total).append("\n");
        sb.append("Remaining Credit Allowance: ").append(MAX_CREDITS - total).append("\n");
        sb.append("Completed Prerequisite Courses: ")
          .append(s.getCompletedCourses().isEmpty() ? "(none)" : String.join(", ", s.getCompletedCourses()))
          .append("\n");
        return sb.toString();
    }

    public List<Student> studentsInCourse(String courseCode) throws RegistrationException {
        Course c = getCourse(courseCode);
        List<Student> list = new ArrayList<>();
        for (String id : c.getEnrolledStudentIds()) list.add(students.get(id));
        return list;
    }
}
