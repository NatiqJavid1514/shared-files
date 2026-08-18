import java.util.Scanner;

public class employee {

    String name;
    int id;
    String course;
    String researchArea;

    employee(String name, int id, String course) {
        this.name = name;
        this.id = id;
        this.course = course;
    }

    employee(String name, int id, String course, String researchArea) {
        this.name = name;
        this.id = id;
        this.course = course;
        this.researchArea = researchArea;
    }

    void display() {
        System.out.println("\nEmployee Details are:-");
        System.out.println("Name: " + name);
        System.out.println("ID: " + id);
        System.out.println("Course: " + course);

        if (researchArea != null) {
            System.out.println("Research Area: " + researchArea);
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("1. Employee with Course");
        System.out.println("2. Employee with Course and Research Area");

        System.out.print("Enter your choice: ");
        int choice = sc.nextInt();

        employee e;

        if (choice == 1) {

            System.out.print("Enter name: ");
            String name = sc.next();

            System.out.print("Enter ID: ");
            int id = sc.nextInt();

            System.out.print("Enter course: ");
            String course = sc.next();

            e = new employee(name, id, course);

        } else if (choice == 2) {

            System.out.print("Enter name: ");
            String name = sc.next();

            System.out.print("Enter ID: ");
            int id = sc.nextInt();

            System.out.print("Enter course: ");
            String course = sc.next();

            System.out.print("Enter research area: ");
            String researchArea = sc.next();

            e = new employee(name, id, course, researchArea);

        } else {

            System.out.println("Invalid choice.");
            sc.close();
            return;
        }

        e.display();

        sc.close();
    }
}