import java.util.ArrayList;
import java.util.List;

/** A student: extends Person, tracks completed and currently registered courses. */
public class Student extends Person implements Persistable {
    private String department;
    private int semester;
    private final List<String> completedCourses = new ArrayList<>();
    private final List<String> registeredCourses = new ArrayList<>();

    public Student(String id, String name, String department, int semester) {
        super(id, name);
        this.department = department.trim();
        this.semester = semester;
    }

    public String getDepartment() { return department; }
    public int getSemester() { return semester; }
    public List<String> getCompletedCourses() { return completedCourses; }
    public List<String> getRegisteredCourses() { return registeredCourses; }

    public boolean hasCompleted(String code) { return completedCourses.contains(code); }
    public boolean isRegisteredFor(String code) { return registeredCourses.contains(code); }

    public void addCompleted(String code) {
        if (!completedCourses.contains(code)) completedCourses.add(code);
    }
    public void addRegistered(String code) { registeredCourses.add(code); }
    public void removeRegistered(String code) { registeredCourses.remove(code); }

    @Override
    public String getRole() { return "Student"; }   // overriding

    @Override
    public String toString() {
        return super.toString() + " Dept: " + department + ", Semester: " + semester;
    }

    /** CSV: id,name,department,semester,completed1;completed2 */
    @Override
    public String toCsv() {
        return getId() + "," + getName() + "," + department + "," + semester + ","
                + String.join(";", completedCourses);
    }
}
