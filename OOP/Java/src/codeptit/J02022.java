package codeptit;

import java.util.Arrays;
import java.util.Scanner;

public class J02022 {
    static int n;
    static int[] X = new int[100];
    static boolean[] used = new boolean[10];

    public static void inkq(){
        boolean ok = true;
        for (int i = 1; i < n ; i++) {
            if(Math.abs(X[i] - X[i+1]) == 1){
                ok = false;
                break;
            }
        }

        if(ok){
            for (int i = 1; i <= n ; i++) {
                System.out.print(X[i]);
            }
            System.out.println();
        }
    }

    public static void ql(int i){
        for (int j = 1; j <= n ; j++) {
            if(!used[j]){
                X[i] = j;
                used[j] = true;

                if(i == n) inkq();
                else ql(i+1);
                used[j] = false;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            n = sc.nextInt();
            Arrays.fill(used, false);
            ql(1);
        }
    }
}
