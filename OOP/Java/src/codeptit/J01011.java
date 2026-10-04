package codeptit;

import java.util.Scanner;

public class J01011 {
    public static long gcd(int a, int b){
        while(b != 0){
            int tmp = a%b;
            a = b;
            b = tmp;
        }

        return a;
    }

    public static long lcm(int a, int b){
        return a * (b / gcd(a,b));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int a = sc.nextInt(), b = sc.nextInt();
            long ucln = gcd(a, b), bcnn = lcm(a,b);
            System.out.println(bcnn + " " + ucln);
        }
    }
}
