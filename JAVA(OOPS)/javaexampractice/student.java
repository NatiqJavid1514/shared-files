import java.util.Scanner;


class student{
    int enroll;
    String name;
   static int  count=0;

   void setname(String s){
    this.name=s;
    count++;
   }
   void setroll(int x){
    this.enroll=x;

   }

   public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    int x=sc.nextInt();
    sc.nextLine();
    String s=sc.nextLine();
    System.out.println(s);
    student s1=new student ();
    student s2=new student ();
    s1.setname("Nats");
    s2.setname("Bats");
    s1.setroll(10);
    s2.setroll(20);
    System.out.println("Number of students present are: "+student.count);


       
   }







}