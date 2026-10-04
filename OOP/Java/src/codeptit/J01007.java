package codeptit;

import java.util.HashSet;
import java.util.Scanner;

public class J01007 {
    public static void main(String[] args) {
        long[] Fibo = new long[93];
        Fibo[0] = 0; Fibo[1] = 1; Fibo[2] = 1;
        HashSet<Long> set = new HashSet<>();

        set.add(0L); set.add(1L); set.add(1L);

        for (int i = 3; i < 93; i++) {
            Fibo[i] = Fibo[i-1] + Fibo[i-2];
            set.add(Fibo[i]);
        }

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            long n = sc.nextLong();
            System.out.println(set.contains(n) ? "YES" : "NO");

        }
    }
}
