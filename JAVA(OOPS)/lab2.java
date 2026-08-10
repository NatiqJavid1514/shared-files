
    class lab2{
        static void analyze(int n){
        int flag=0;
        int i;
        for(i=2;i<n/2;i++){
            if(n%i==0){
                flag=1;
                break;

        }
        else {
            continue;
        }
        }
         if(flag==1){
            System.out.println("the number is not prime");

        }
        else{
            System.out.println("the number is prime");
        }
        }
        static void analyze(int a,int b){
            if(a>b){
                System.out.println(a+ " is greater");
            }
            else{
                System.out.println(b+ " is greater");
            }

        }
        static void analyze(int x,int y,int z){
            if(x<y && x<z){
                System.out.println(x+" is the smallest");
            }
            else if(y<z){
                System.out.println(y+" is the smallest");

            }
            else{
                System.out.println(z+" is the smallest");
            }

        };
static void armstrong(int n,int max) {
            int num, rem, size = 0, temp = 0;
            num = n;
            while (num != 0) {
                num /= 10;
                size++;
            }
            num = n;
            for(int =min;i<=max;i++){
            

            while (num != 0) {
                rem = num % 10;
                temp += Math.pow(rem, size);
                num /= 10;
            }
            
           
        }}
        
    public static void main(String args []){
        int a=10;
        int b=20;
        int c=30;
        analyze(a,b,c);
        for(int i=100;i<999;i++){

            

        }







    }
 }
