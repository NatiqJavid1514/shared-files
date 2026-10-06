import java.util.Scanner;


public class main{
    public static void main(String[] args) {
    
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter your String: ");
    String S=sc.nextLine();
    String K="";
    // tO check whether palindrome or not
    for(int i=(S.length()-1);i>=0;i--){
        K+=S.charAt(i);


    }
    // System.out.println(K);
    if(K.equals(S)){
        System.out.println("String is palindrome");
    }
    else{
        System.err.println("String is not Palindrome");
    }
    String str=sc.nextLine();
    for(int i =0;i<str.length();i++){
            int count = 0;

            for(int j=0;j<str.length();j++){
                if(str.charAt(i)==str.charAt(j)){
                    count++;
                }

            }
            System.out.println("The character " + str.charAt(i) + " appeared this number of times: " + count);


        }


    //
    //p3 first character of the string that occurs only once
    String L=sc.nextLine();
    for(int i=0;i<L.length();i++){
        for(int j=1;j<L.length();j++){
            if(L.charAt(i)==L.charAt(j)){
                break;
            }

        }
    }


}
}