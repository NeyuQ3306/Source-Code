package codeptit;

import java.math.BigInteger;
import java.util.Scanner;

public class J03012 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            BigInteger s1 = sc.nextBigInteger(), s2 = sc.nextBigInteger();
            System.out.println(s1.add(s2));
        }
    }
}
