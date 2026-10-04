package codeptit;

import java.math.BigInteger;
import java.util.Scanner;

public class J03013 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            BigInteger a = sc.nextBigInteger(), b = sc.nextBigInteger();
            long sz = Math.max(a.toString().length(),b.toString().length());

            BigInteger c = a.subtract(b);
            c = c.abs();

            if(c.toString().length() < sz){
                for (int i = 1; i <= sz - c.toString().length(); i++) {
                    System.out.print(0);
                }
                System.out.println(c);
            }

            else System.out.println(c);
        }
    }
}
