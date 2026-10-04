package codeptit;

import java.util.Scanner;

public class J01018 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            long n = sc.nextLong();
            boolean ok1 = true, ok2 = true;

            long k = n;
            int sum = 0;
            while(k != 0){
                sum += k%10;
                k /= 10;
            }

            if(sum % 10 != 0) ok2 = false;


            long last = n%10;
            n /= 10;

            while(n != 0){
                long tmp = n%10;
                if(Math.abs(last - tmp) != 2){
                    ok1 = false;
                    break;
                }

                else{
                    last = tmp;
                    n /= 10;
                }
            }

            System.out.println(ok1 && ok2 ? "YES\n" : "NO\n");
        }
    }
}
