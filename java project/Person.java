/** Abstract base class holding information common to every person in the system. */
public abstract class Person {
    private final String id;
    private String name;

    public Person(String id, String name) {
        this.id = id.trim();
        this.name = name.trim();
    }

    public String getId() { return id; }
    public String getName() { return name; }
    public void setName(String name) { this.name = name.trim(); }

    /** Abstract method: each subclass defines its own role (runtime polymorphism). */
    public abstract String getRole();

    @Override
    public String toString() {
        return getRole() + " [ID: " + id + ", Name: " + name + "]";
    }
}
