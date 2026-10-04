package codeptit;

import java.util.Scanner;

public class J02103 {
    static int test = 1;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt(), m = sc.nextInt();
            int[][] a = new int[n][m], b = new int[m][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = sc.nextInt();
                    b[j][i] = a[i][j];
                }
            }

            int[][] c = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    c[i][j] = 0;
                    for (int k = 0; k < m; k++) {
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }

            System.out.printf("Test %d:\n", test);
            ++test;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.printf("%d ", c[i][j]);
                }
                System.out.println();
            }
        }
    }
}
