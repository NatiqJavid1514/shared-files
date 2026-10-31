import java.io.*;
import java.util.ArrayList;
import java.util.List;

/** Saves and loads all application data using CSV text files. */
public class FileManager {
    private final String dir;

    public FileManager(String dir) {
        this.dir = dir;
    }

    private File file(String name) { return new File(dir, name); }

    public void save(RegistrationSystem sys) throws IOException {
        new File(dir).mkdirs();
        List<Persistable> students = new ArrayList<>(sys.getAllStudents());
        List<Persistable> courses = new ArrayList<>(sys.getAllCourses());
        List<Persistable> regs = new ArrayList<>(sys.getAllRegistrations());
        write("students.csv", students);
        write("courses.csv", courses);
        write("registrations.csv", regs);
    }

    private void write(String name, List<Persistable> items) throws IOException {
        try (PrintWriter pw = new PrintWriter(new FileWriter(file(name)))) {
            for (Persistable p : items) pw.println(p.toCsv());   // polymorphic call
        }
    }

    public void load(RegistrationSystem sys) throws IOException {
        // Courses first, then students, then registrations (which depend on both)
        for (String[] f : read("courses.csv", 5)) {
            try {
                sys.addCourse(new Course(f[0], f[1], Integer.parseInt(f[2].trim()), f[3], Integer.parseInt(f[4].trim())));
            } catch (RegistrationException | NumberFormatException e) {
                System.out.println("Skipped bad course record: " + e.getMessage());
            }
        }
        for (String[] f : read("students.csv", 4)) {
            try {
                Student s = new Student(f[0], f[1], f[2], Integer.parseInt(f[3].trim()));
                if (f.length > 4 && !f[4].trim().isEmpty())
                    for (String code : f[4].split(";")) s.addCompleted(code.trim().toUpperCase());
                sys.addStudent(s);
            } catch (RegistrationException | NumberFormatException e) {
                System.out.println("Skipped bad student record: " + e.getMessage());
            }
        }
        for (String[] f : read("registrations.csv", 2)) {
            try {
                sys.restoreRegistration(f[0].trim(), f[1].trim());
            } catch (RegistrationException e) {
                System.out.println("Skipped bad registration record: " + e.getMessage());
            }
        }
    }

    /** Reads a CSV file; returns rows with at least minFields fields. Missing file = empty. */
    private List<String[]> read(String name, int minFields) throws IOException {
        List<String[]> rows = new ArrayList<>();
        File f = file(name);
        if (!f.exists()) return rows;
        try (BufferedReader br = new BufferedReader(new FileReader(f))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (line.trim().isEmpty()) continue;
                String[] parts = line.split(",", -1);
                if (parts.length >= minFields) rows.add(parts);
            }
        }
        return rows;
    }
}
