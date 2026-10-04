package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05009 {
    public static class ThiSinh{
        private String ten,ns;
        private double m1,m2,m3;
        private int mts;
        private static int cnt = 0;

        public ThiSinh(String ten, String ns, double m1, double m2, double m3){
            this.ten = ten;
            this.ns = ns;
            this.m1 = m1;
            this.m2 = m2;
            this.m3 = m3;

            ++cnt;
            this.mts = cnt;
        }

        public int getMts(){return mts;}
        public double getTongDiem(){
            return m1 + m2 + m3;
        }

        public String toString(){
            return mts + " " + ten + " " + ns + " " + (m1+m2+m3);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<ThiSinh> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ThiSinh a = new ThiSinh(sc.nextLine(), sc.nextLine(), Double.parseDouble(sc.nextLine()), Double.parseDouble(sc.nextLine()), Double.parseDouble(sc.nextLine()));
            list.add(a);
        }

        Collections.sort(list, new Comparator<ThiSinh>() {
            @Override
            public int compare(ThiSinh o1, ThiSinh o2) {
                if(o1.getTongDiem() != o2.getTongDiem()){
                    return Double.compare(o2.getTongDiem(), o1.getTongDiem());
                } else{
                    return o1.getMts() - o2.getMts();
                }
            }
        });

        double maxP = list.get(0).getTongDiem();
        for (ThiSinh thiSinh : list) {
            if(thiSinh.getTongDiem() == maxP) System.out.println(thiSinh);
        }
    }
}
