 class Employee{
    int id;
    Employee(int x){
        this.id=x;
    }



}
class Teaching extends Employee{
    int course_id;
    Teaching (int y){
        this.course_id=y;
    }

}
public class a{
    public static void main(String[] args) {
        Employee e1=new Employee(1);
        Teaching t1=new Teaching(1);
        
        
        
    }
}