class FIRSTPROGRAM{
    public static void main(String[] args) {
        System.out.println("My Name is Natiq Javid\n");
        int x=10,y=20,z=40;
        System.out.println(x);
        if(x>y&&x>z){
            System.out.println("The greatest number among x y z is:x ");




        }
        else if(y>z){
            System.out.println("The greatest number is y");
        }
        else{
            System.out.println("Z is the greatest number");
        }
        System.out.println("\n");

        System.out.println("The integers x y and z are: "+x +" "+y+" " +z);

        int a,b,sum;
        a=1;
        b=2;
        sum=a+b;

        System.out.println("Sum is: " +sum);
        int n=55;
        int flag=0;
        int i;
        for(i=2;i<n/2;i++){
            if(n%i==0){
                flag=1;
            }
            else{
                return;
            }
        }
        if(flag==1){
            System.out.println("the number is not prime");
        }
        else
            System.out.println("the number is non prime");
        







        

        
    
} }