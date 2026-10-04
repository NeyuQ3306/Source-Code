package codeptit;

import java.math.BigInteger;
import java.util.Scanner;

public class J03015 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger s1 = sc.nextBigInteger(), s2 = sc.nextBigInteger();

        BigInteger s = s1.subtract(s2);
        String str = s.toString();

        int idx = 0;
        for (int i = 0; i < str.length(); i++) {
            if(str.charAt(i) == '0') idx++;
            else break;
        }


        if(idx == 0){
            for (int i = 0; i < str.length(); i++) {
                System.out.print(str.charAt(i));
            }
        }

        else{
            for (int i = idx-1; i < str.length(); i++) {
                System.out.print(str.charAt(i));
            }
        }

    }
}
