package codeptit;

import java.util.Scanner;

public class J01017 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            long n = sc.nextLong();
            boolean ok = true;

            long last = n%10;
            n /= 10;

            while(n != 0){
                long tmp = n%10;
                if(Math.abs(last - tmp) != 1){
                    ok = false;
                    break;
                }

                else{
                    last = tmp;
                    n /= 10;
                }
            }

            System.out.println(ok  ? "YES\n" : "NO\n");
        }
    }
}
