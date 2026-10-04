package codeptit;

import java.util.LinkedHashSet;
import java.util.Scanner;

public class J02104 {
//    public static class Pair{
//        int fi, se;
//
//        Pair(int x, int y){
//            this.fi = x;
//            this.se = y;
//        }
//    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int x = sc.nextInt();
                if(i < j && x == 1){
                    System.out.printf("(%d,%d)\n", i, j);
                }
            }
        }

    }
}
