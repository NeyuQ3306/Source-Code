package codeptit;

import java.util.Scanner;

public class J04017 {
    public static class Matrix{
        private int n,m;
        private int[][] a;

        public int getM(){ return m;}
        public int getN(){ return n;}
        public int[][] getA(){ return a;}

        public Matrix(int n, int m){
            this.n = n;
            this.m = m;
            a = new int[n][m];
        }

        public void nextMatrix(Scanner sc){
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = sc.nextInt();
                }
            }
        }

        public Matrix trans(){
            Matrix trans = new Matrix(m, n);
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    trans.getA()[i][j] = a[j][i];
                }
            }

            return trans;
        }

        public Matrix mul(Matrix b){
            Matrix res = new Matrix(n,n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res.getA()[i][j] = 0;
                    for (int k = 0; k < m; k++) {
                        res.getA()[i][j] += a[i][k] * b.getA()[k][j];
                    }
                }
            }

            return res;
        }

        public String toString(){
            String res = "";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res += a[i][j] + " ";
                }
                res += "\n";
            }

            return res;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt(), m = sc.nextInt();
            Matrix a = new Matrix(n,m);
            a.nextMatrix(sc);
            Matrix b = a.trans();
            System.out.println(a.mul(b));
        }
    }
}
