abstract class Emp {
    String name;
    int Salary;

    Emp() {
        System.out.println("This is Employee Class");
    }

    Emp(String n, int s) {
        this.name = n;
        this.Salary = s;
    }

    abstract void calculatebonus();

    void displaydetails() {
        System.out.println("Name is: " + name);
        System.out.println("Salary is: " + Salary);
    }
}

class Manager extends Emp {
    Manager(String n, int s) {
        super(n, s);
    }

    void calculatebonus() {
        System.out.println("Bonus is " + (Salary + 10000));
    }
}

class Developer extends Emp {
    Developer(String n, int s) {
        super(n, s);
    }

    void calculatebonus() {
        System.out.println("Bonus is " + (Salary + 20000));
    }
}

public class Main {
    public static void main(String[] args) {
        Manager m1 = new Manager("Alice", 50000);
        m1.displaydetails();
        m1.calculatebonus();
    }
}
