package codeptit;

import java.math.BigInteger;
import java.util.Scanner;

public class J03039 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            BigInteger s1 = sc.nextBigInteger(), s2 = sc.nextBigInteger();
            System.out.println((s1.mod(s2).toString().equals("0") ||
                                s2.mod(s1).toString().equals("0")) ? "YES" : "NO");
        }
    }
}
