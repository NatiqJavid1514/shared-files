class student{
    String name;
    int id;
    static int count;
    void setname(String n){
        this.name=n;
        count++;
    }
    public static void main(string args[]){
        student s1=new student();
        student s2=new student();
        s2.setname("nats");
        s1.setname("lakshita");
        System.out.println("No of students is");
        

    }

    
}