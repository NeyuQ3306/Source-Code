package codeptit;

import java.util.Scanner;

public class J02021 {
    static int cnt = 0;
    static int n, k;
    static int[] X = new int[100];
    public static void ql(int i){
        for (int j = X[i-1]+1; j <= n-k+i ; j++) {
            X[i] = j;
            if(i == k){
                ++cnt;
                for (int l = 1; l <= k; l++) {
                    System.out.print(X[l]);
                }
                System.out.print(" ");
            }

            else ql(i+1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        ql(1);
        System.out.println();
        System.out.printf("Tong cong co %d to hop", cnt);
    }
}
