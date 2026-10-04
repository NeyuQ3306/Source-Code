package codeptit;

import java.util.Scanner;

public class J01021 {
    static long mod = (long) (1e9 + 7);

    public static long binpow(long a, long b){
        if(b==0) return 1;
        else{
            long X = binpow(a,b/2);
            if(b%2 == 0) return (X%mod * X%mod) % mod;
            else return (X%mod * X%mod * a%mod) % mod;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(true){
            long a = sc.nextLong(), b = sc.nextLong();
            if(a == 0 && b == 0){
                return;
            }

            long ans = binpow(a,b);
            System.out.println(ans);
        }
    }
}
