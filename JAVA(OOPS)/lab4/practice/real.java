class Employee{
    String name;
    String employeeID;
    double basesalary;
    String Department;

    public Employee(String name,String employeeID,double basesalary,String Department){
        this.name=name;
        this.employeeID=employeeID;
        this.basesalary=basesalary;
        this.Department=Department;

    }
    public double salarycalculation(){
        return this.basesalary;
    }
    public void displaydetails(){
        System.out.println("Name of Employee is: "+name);
        System.out.println("EMP ID of Employee is: "+employeeID);
        System.out.println("Department of Employee is: "+Department);
    }

    

}
class Manager extends Employee{
        private String managerId;

    public Manager(String name, String employeeId, double baseSalary, String department, String managerId) {
        super(name, employeeId, baseSalary, department); 
        this.managerId = managerId;

    }
    public double salarycalculation(){
        return super.salarycalculation();
    }
    public void displaydetails(){
        super.displaydetails();
        System.out.println("Manager ID: "+managerId);

    }
}

class Teaching extends Employee{
    private int noOfCourses;
    private String courseNames;

    public Teaching(String name, String employeeId, double baseSalary, String department, int noOfCourses, String courseNames) {
        super(name, employeeId, baseSalary, department);
        this.noOfCourses = noOfCourses;
        this.courseNames = courseNames;
    }
        public double calculateSalary() {
        double courseStipend = noOfCourses * 500.0;
        return super.salarycalculation()+ courseStipend;
    }
    
    public void displaydetails() {
        super.displaydetails();
        System.out.println("Courses Assigned: " + courseNames);
    }



}
class Nonteaching extends Employee{
    private String section;

    public NonTeaching (String name, String employeeId, double baseSalary, String department, String section){
        super(name, employeeId, baseSalary, department);
        this.section = section;
    }

    public double calculateSalary() {
        return super.salarycalculation();
    }
    
    public void displayDetails() {
        super.displaydetails();
        System.out.println("Section: " + section);
}
}
class outsourced extends Employee{
    private int tenureinmonths;
    public outsourced(String name,String employeeid,double baseSalary,String Deparment,int tenureinmonths){
        super(name,employeeid,baseSalary,Deparment);
        this.tenureinmonths=tenureinmonths;

    }
    public double salarycalculation(){
        return super.salarycalculation() *0.6;
    }
    public void displaydetails(){
        super.displaydetails();
        System.out.println("Tenure of employee is: " +tenureinmonths);
        }
}

public class real{
     public static void main(String[] args)

}

