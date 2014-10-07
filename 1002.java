import java.math.BigInteger;
import java.util.Scanner;



public class Main{
    public static void main(String[] args){
        int T;
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        for(int i = 1; i < T; i++){
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            BigInteger c = a.add(b);
            System.out.println("Case "+i+":");
            System.out.println(a+" + "+b+" = "+c);
            System.out.println();
        }
                BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
        BigInteger c = a.add(b);
        System.out.println("Case "+T+":");
        System.out.println(a+" + "+b+" = "+c);
    }
}