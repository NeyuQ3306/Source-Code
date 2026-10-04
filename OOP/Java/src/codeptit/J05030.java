package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05030 {
    public static class SinhVien{
        private String msv,ten,lop;
        private double m1,m2,m3;

        public SinhVien(String s, String t, String x, double y, double z, double w){
            msv = s;
            ten = t;
            lop = x;
            m1 = y;
            m2 = z;
            m3 = w;

        }

        public String getMsv(){return msv;}

        public String toString(){
            return  msv + " " + ten + " " + lop + " " + m1 + " " + m2 + " " + m3;
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<SinhVien> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new SinhVien(sc.nextLine().trim(),sc.nextLine().trim(),sc.nextLine().trim(),Double.parseDouble(sc.nextLine().trim()),Double.parseDouble(sc.nextLine().trim()),Double.parseDouble(sc.nextLine().trim())));
        }

        Collections.sort(a, new Comparator<SinhVien>() {
            @Override
            public int compare(SinhVien o1, SinhVien o2) {
                return o1.getMsv().compareTo(o2.getMsv());
            }
        });

        int cnt = 1;
        for (SinhVien sinhVien : a) {
            System.out.print(cnt + " ");
            System.out.println(sinhVien);
            ++cnt;
        }
    }
}
