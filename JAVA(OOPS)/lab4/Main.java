class Employee {
    private String name;
    private String employeeId;
    private double baseSalary;
    private String department;

    public Employee(String name, String employeeId, double baseSalary, String department) {
        this.name = name;
        this.employeeId = employeeId;
        this.baseSalary = baseSalary;
        this.department = department;
    }

    public double calculateSalary() {
        return this.baseSalary;
    }

    public void displayDetails() {
        
        System.out.println("Name: " + name );
        System.out.println("Department: "+department);
        System.out.println("Employee ID: " + employeeId);
    }
}

class Manager extends Employee {
    private String managerId;

    public Manager(String name, String employeeId, double baseSalary, String department, String managerId) {
        super(name, employeeId, baseSalary, department); 
        this.managerId = managerId;
    }

    public double calculateSalary() {
        return super.calculateSalary();
    }

    public void displayDetails() {
        super.displayDetails();
        System.out.println("Manager ID: " + managerId);
    }
}

class Teaching extends Employee {
    private int noOfCourses;
    private String courseNames;

    public Teaching(String name, String employeeId, double baseSalary, String department, int noOfCourses, String courseNames) {
        super(name, employeeId, baseSalary, department);
        this.noOfCourses = noOfCourses;
        this.courseNames = courseNames;
    }

    public double calculateSalary() {
        double courseStipend = noOfCourses * 500.0;
        return super.calculateSalary() + courseStipend;
    }
    
    public void displayDetails() {
        super.displayDetails();
        System.out.println("Courses Assigned: " + courseNames);
    }
}

class NonTeaching extends Employee {
    private String section;

    public NonTeaching(String name, String employeeId, double baseSalary, String department, String section) {
        super(name, employeeId, baseSalary, department);
        this.section = section;
    }

    public double calculateSalary() {
        return super.calculateSalary();
    }
    
    public void displayDetails() {
        super.displayDetails();
        System.out.println("Section: " + section);
    }
}

class Outsourced extends Employee {
    private int tenureInMonths;

    public Outsourced(String name, String employeeId, double baseSalary, String department, int tenureInMonths) {
        super(name, employeeId, baseSalary, department);
        this.tenureInMonths = tenureInMonths;
    }

    public double calculateSalary() {
        return super.calculateSalary() * 0.90;
    }
    
    public void displayDetails() {
        super.displayDetails();
        System.out.println("Contract Tenure: " + tenureInMonths + " months");
    }
}

public class Main {
    public static void main(String[] args) {
        Manager mgr = new Manager("Natiq", "EMP100", 80000, "Operations", "MGR001");
        mgr.displayDetails();
        System.out.println("Final Salary: " + mgr.calculateSalary());

        Teaching teacher = new Teaching("Babar", "EMP201", 60000, "Computer Science", 2, "Data Structures, Algorithms");
        teacher.displayDetails();
        System.out.println("Final Salary: " + teacher.calculateSalary());

        NonTeaching admin = new NonTeaching("Ilha", "EMP305", 45000, "Admissions", "Student Records");
        admin.displayDetails();
        System.out.println("Final Salary: " + admin.calculateSalary());

        Outsourced contractor = new Outsourced("Lakshita", "OUT999", 50000, "IT Support", 12);
        contractor.displayDetails();
        System.out.println("Final Salary: " + contractor.calculateSalary());
    }
}