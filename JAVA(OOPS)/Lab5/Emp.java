class Employee {
    public String name;
    protected int Salary;
    String department;
    private int empID;

    Employee(String name, int salary, String dept, int empId) {
        this.name = name;
        this.Salary = salary;
        this.department = dept;
        this.empID = empId;
    }
    
    public int getEmpId() { 
        return empID; 
    }
}

class Manager extends Employee {
    String designation;

    Manager(String name, int empId, int salary, String dept, String designation) {
        super(name, salary, dept, empId);
        this.designation = designation;
    }
    
    public int getSalary(){
        return Salary;
    }

    // Method to display everything
    public void displayDetails() {
        System.out.println("--- Manager Details ---");
        System.out.println("Emp ID: " + getEmpId());       // Using getter because empID is private
        System.out.println("Name: " + name);               // Public
        System.out.println("Salary: " + Salary);           // Protected
        System.out.println("Department: " + department);   // Package-private
        System.out.println("Designation: " + designation); // Defined in Manager
    }
}

public class Emp {
    public static void main(String[] args) {
        Manager m1 = new Manager("natiq", 10000, 1000, "IT", "CEO");
        
    
        m1.displayDetails();
    }
}