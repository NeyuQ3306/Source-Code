package codeptit;

import java.util.Arrays;
import java.util.Scanner;

public class J02102 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] a = new int[n][n];
        int[] list = new int[n*n];

        for (int i = 0; i < n*n; i++) {
            list[i] = sc.nextInt();
        }

        Arrays.sort(list);
        int c1 = 0, c2 = n-1, h1 = 0, h2 = n-1;
        int idx = 0;
        while(c1 <= c2 && h1 <= h2){
            for (int i = c1; i <= c2; i++) {
                a[h1][i] = list[idx++];
            }
            ++h1;

            for (int j = h1; j <= h2; j++) {
                a[j][c2] = list[idx++];
            }
            --c2;

            for (int k = c2; k >= c1 ; k--) {
                a[h2][k] = list[idx++];
            }
            --h2;

            for (int l = h2; l >= h1 ; l--) {
                a[l][c1] = list[idx++];
            }
            ++c1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.printf("%d ", a[i][j]);
            }
            System.out.println();
        }
    }
}
