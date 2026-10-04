package codeptit;

import java.util.Scanner;

public class J01008 {
    static int k = 1;

    public static void pttsnt(int n){
        System.out.print("Test " + k + ": ");
        ++k;

        for(int i=2; i<=Math.sqrt(n); i++){
            if(n % i == 0){
                int cnt = 0;
                while(n % i == 0){
                    n /= i;
                    ++cnt;
                }

                System.out.print(i + "(" + cnt + ")" + " ");
            }
        }

        if(n != 1) System.out.println(n + "(" + 1 + ")");
        else System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            pttsnt(n);
        }
    }
}
