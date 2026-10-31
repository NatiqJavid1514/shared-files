import java.io.IOException;
import java.util.List;
import java.util.Scanner;

/** Console menu for the Student Course Registration System. */
public class Main {
    private static final Scanner in = new Scanner(System.in);
    private static final RegistrationSystem system = new RegistrationSystem();
    private static final FileManager files = new FileManager("data");

    public static void main(String[] args) {
        try {
            files.load(system);
            System.out.println("Data loaded: " + system.getAllStudents().size() + " students, "
                    + system.getAllCourses().size() + " courses, "
                    + system.getAllRegistrations().size() + " registrations.");
        } catch (IOException e) {
            System.out.println("Could not load data: " + e.getMessage());
        }

        boolean running = true;
        while (running) {
            printMenu();
            String choice = prompt("Enter your choice");
            try {
                switch (choice) {
                    case "1": addStudent(); break;
                    case "2": viewSearchStudents(); break;
                    case "3": addCourse(); break;
                    case "4": viewSearchCourses(); break;
                    case "5": register(); break;
                    case "6": System.out.println(system.academicSummary(prompt("Student ID"))); break;
                    case "7": studentsInCourse(); break;
                    case "8": save(); break;
                    case "9": drop(); break;
                    case "10": markCompleted(); break;
                    case "11": save(); System.out.println("Goodbye!"); running = false; break;
                    default: System.out.println("Invalid choice. Please enter 1-11.");
                }
            } catch (RegistrationException e) {
                System.out.println("ERROR: " + e.getMessage());
            } catch (NumberFormatException e) {
                System.out.println("ERROR: Please enter a valid number.");
            }
        }
    }

    private static void printMenu() {
        System.out.println("\n=====================================");
        System.out.println(" STUDENT COURSE REGISTRATION SYSTEM");
        System.out.println("=====================================");
        System.out.println(" 1. Add Student");
        System.out.println(" 2. View/Search Students");
        System.out.println(" 3. Add Course");
        System.out.println(" 4. View/Search Courses");
        System.out.println(" 5. Register Student for Course");
        System.out.println(" 6. View Student Academic Summary");
        System.out.println(" 7. View Students Registered in a Course");
        System.out.println(" 8. Save Data");
        System.out.println(" 9. Drop a Course");
        System.out.println("10. Mark Course as Completed");
        System.out.println("11. Save & Exit");
    }

    private static String prompt(String label) {
        System.out.print(label + ": ");
        return in.hasNextLine() ? in.nextLine().trim() : "11";
    }

    /** Commas would break the CSV format, so strip them from free text. */
    private static String clean(String s) { return s.replace(",", " ").replace(";", " "); }

    private static void addStudent() throws RegistrationException {
        String id = clean(prompt("Student ID"));
        String name = clean(prompt("Name"));
        String dept = clean(prompt("Department"));
        int sem = Integer.parseInt(prompt("Semester (1-8)"));
        system.addStudent(new Student(id, name, dept, sem));
        autoSave();
        System.out.println("Student added successfully.");
    }

    private static void viewSearchStudents() {
        String choice = prompt("1) View all  2) Search by ID");
        if (choice.equals("2")) {
            Student s = system.findStudent(prompt("Student ID"));
            System.out.println(s == null ? "No student found with that ID." : s);
        } else {
            List<Student> all = system.getAllStudents();
            if (all.isEmpty()) System.out.println("No students yet.");
            for (Student s : all) System.out.println(s);
        }
    }

    private static void addCourse() throws RegistrationException {
        String code = clean(prompt("Course code"));
        String name = clean(prompt("Course name"));
        int credits = Integer.parseInt(prompt("Credits"));
        String prereq = clean(prompt("Prerequisite code (blank if none)"));
        int cap = Integer.parseInt(prompt("Max capacity"));
        if (!prereq.isEmpty() && system.findCourse(prereq) == null)
            throw new RegistrationException("Prerequisite course " + prereq + " is not in the catalogue. Add it first.");
        system.addCourse(new Course(code, name, credits, prereq, cap));
        autoSave();
        System.out.println("Course added successfully.");
    }

    private static void viewSearchCourses() {
        String choice = prompt("1) View all  2) Search by code");
        if (choice.equals("2")) {
            Course c = system.findCourse(prompt("Course code"));
            System.out.println(c == null ? "No course found with that code." : c);
        } else {
            List<Course> all = system.getAllCourses();
            if (all.isEmpty()) System.out.println("No courses yet.");
            for (Course c : all) System.out.println(c);
        }
    }

    private static void register() throws RegistrationException {
        String id = prompt("Student ID");
        String code = prompt("Course code");
        system.register(id, code);
        autoSave();
        System.out.println("Registration successful.");
    }

    private static void drop() throws RegistrationException {
        system.drop(prompt("Student ID"), prompt("Course code"));
        autoSave();
        System.out.println("Course dropped.");
    }

    private static void markCompleted() throws RegistrationException {
        system.markCompleted(prompt("Student ID"), prompt("Course code"));
        autoSave();
        System.out.println("Course marked as completed.");
    }

    private static void studentsInCourse() throws RegistrationException {
        String code = prompt("Course code");
        List<Student> list = system.studentsInCourse(code);
        if (list.isEmpty()) System.out.println("No students registered in this course.");
        for (Student s : list) System.out.println(s);
    }

    private static void save() {
        try {
            files.save(system);
            System.out.println("Data saved.");
        } catch (IOException e) {
            System.out.println("ERROR saving data: " + e.getMessage());
        }
    }

    private static void autoSave() {
        try { files.save(system); }
        catch (IOException e) { System.out.println("Warning: auto-save failed: " + e.getMessage()); }
    }
}
