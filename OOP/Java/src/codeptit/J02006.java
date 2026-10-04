package codeptit;

import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class J02006 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[m];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        for (int i = 0; i < m; i++) {
            b[i] = sc.nextInt();
        }

        Map<Integer, Integer> mp = new TreeMap<>();
        for (int i = 0; i < a.length; i++) {
            mp.put(a[i], 1);
        }

        for (int i = 0; i < b.length; i++) {
            mp.put(b[i], 1);
        }

        for (Integer i : mp.keySet()) {
            System.out.print(i + " ");
        }

    }
}
