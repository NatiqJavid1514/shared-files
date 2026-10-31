/** Associates one student with one course. */
public class Registration implements Persistable {
    private final Student student;
    private final Course course;

    public Registration(Student student, Course course) {
        this.student = student;
        this.course = course;
    }

    public Student getStudent() { return student; }
    public Course getCourse() { return course; }

    @Override
    public String toString() {
        return student.getName() + " (" + student.getId() + ") -> "
                + course.getCode() + " " + course.getName();
    }

    /** CSV: studentId,courseCode */
    @Override
    public String toCsv() {
        return student.getId() + "," + course.getCode();
    }
}
