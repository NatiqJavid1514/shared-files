import java.util.ArrayList;
import java.util.List;

/** A course in the catalogue. */
public class Course implements Persistable {
    private final String code;
    private String name;
    private int credits;
    private String prerequisite;   // empty string = none
    private int capacity;
    private final List<String> enrolledStudentIds = new ArrayList<>();

    public Course(String code, String name, int credits, String prerequisite, int capacity) {
        this.code = code.trim().toUpperCase();
        this.name = name.trim();
        this.credits = credits;
        this.prerequisite = (prerequisite == null) ? "" : prerequisite.trim().toUpperCase();
        this.capacity = capacity;
    }

    public String getCode() { return code; }
    public String getName() { return name; }
    public int getCredits() { return credits; }
    public String getPrerequisite() { return prerequisite; }
    public boolean hasPrerequisite() { return !prerequisite.isEmpty(); }
    public int getCapacity() { return capacity; }
    public List<String> getEnrolledStudentIds() { return enrolledStudentIds; }
    public int getSeatsAvailable() { return capacity - enrolledStudentIds.size(); }
    public boolean isFull() { return getSeatsAvailable() <= 0; }

    public void enroll(String studentId) { enrolledStudentIds.add(studentId); }
    public void unenroll(String studentId) { enrolledStudentIds.remove(studentId); }

    @Override
    public String toString() {
        return String.format("%-8s %-30s Credits: %d  Prereq: %-8s Seats: %d/%d",
                code, name, credits, hasPrerequisite() ? prerequisite : "None",
                enrolledStudentIds.size(), capacity);
    }

    /** CSV: code,name,credits,prerequisite,capacity */
    @Override
    public String toCsv() {
        return code + "," + name + "," + credits + "," + prerequisite + "," + capacity;
    }
}
