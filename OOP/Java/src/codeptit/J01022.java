package codeptit;

import java.util.Scanner;

public class J01022 {
    static long[] X = new long[93];
    public static void init(){
        X[1] = 1;
        X[2] = 1;

        for (int i = 3; i < 93; i++) {
            X[i] = X[i-2] + X[i-1];
        }
    }

    public static void find(int n, long k){
        if(n==1){
            System.out.println(0);
            return;
        }
        if(n==2){
            System.out.println(1);
            return;
        }

        else{
            if(k > X[n-2]) find(n-1, k - X[n-2]);
            else find(n-2, k);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        init();
        while(t-- > 0){
            int n = sc.nextInt();
            long k = sc.nextLong();
            find(n, k);
        }
    }
}
