package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05032 {
    public static class Nguoi{
        private String ten,ns;

        public Nguoi(String s, String t){
            ten = s;
            ns = t;
        }

        public String getNs(){
            String[] tok = ns.split("/");
            return tok[2] + tok[1] + tok[0];
        }

        public String toString(){
            return ten;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Nguoi> a = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            a.add(new Nguoi(sc.next(),sc.next()));
        }

        Collections.sort(a, new Comparator<Nguoi>() {
            @Override
            public int compare(Nguoi o1, Nguoi o2) {
                return o1.getNs().compareTo(o2.getNs());
            }
        });

        System.out.println(a.get(n-1));
        System.out.println(a.get(0));
    }
}
