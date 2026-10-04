package codeptit;

import java.util.Scanner;

public class J01006 {
    public static void main(String[] args) {
        long[] Fibo = new long[93];
        Fibo[0] = 0; Fibo[1] = 1; Fibo[2] = 1;

        for (int i = 3; i < 93; i++) {
            Fibo[i] = Fibo[i-1] + Fibo[i-2];
        }

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            System.out.println(Fibo[n]);
        }

    }
}
