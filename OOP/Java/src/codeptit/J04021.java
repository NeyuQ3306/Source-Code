package codeptit;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class J04021 {
    public static class IntSet{
        private int[] a;

        public IntSet(int[] a){
            this.a = a;
        }

        public int[] getA(){
            return a;
        }

        public IntSet union(IntSet b){
            Set<Integer> st = new TreeSet<>();
            for(int x : a) st.add(x);
            for(int x : b.getA()) st.add(x);

            int[] res = new int[st.size()];
            int idx = 0;

            for (Integer intSet : st) {
                res[idx++] = intSet;
            }

            return new IntSet(res);
        }

        @Override
        public String toString(){
            String res = "";
            for (int i = 0; i < a.length; i++) {
                res += a[i] + " ";
            }

            return res;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), m = sc.nextInt(), a[] = new int[n], b[] = new int[m];
        for(int i = 0; i<n; i++) a[i] = sc.nextInt();
        for(int i = 0; i<m; i++) b[i] = sc.nextInt();
        IntSet s1 = new IntSet(a);
        IntSet s2 = new IntSet(b);
        IntSet s3 = s1.union(s2);
        System.out.println(s3);
    }
}
