package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05005 {
    public static class SinhVien{
        private String msv,ten,lop,ns;
        private double diem;
        private static int cnt = 0;

        public SinhVien(String ten, String lop, String ns, double diem){
            this.ten = ten;
            this.lop = lop;
            this.ns = ns;
            this.diem = diem;

            ++cnt;
            this.msv = "B20DCCN" + String.format("%03d",cnt);
        }

        public double getDiem(){return diem;}

        public static String chuanHoaNs(String s){
            String[] tok = s.split("/");
            return String.format("%02d/%02d/%04d", Integer.parseInt(tok[0]), Integer.parseInt(tok[1]), Integer.parseInt(tok[2]));
        }

        public static String chuanHoaTen(String s){
            String[] tok = s.toLowerCase().split("\\s+");
            String res = "";

            for (int i = 0; i < tok.length; i++) {
                res += Character.toUpperCase(tok[i].charAt(0));
                res += tok[i].substring(1) + " ";
            }

            return res.trim();
        }

        @Override
        public String toString(){
            return msv + " " + ten + " " + lop + " " + ns + " " + String.format("%.2f", diem);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        ArrayList<SinhVien> a = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            SinhVien sv = new SinhVien(SinhVien.chuanHoaTen(sc.nextLine().trim()), sc.nextLine(), SinhVien.chuanHoaNs(sc.nextLine()), Double.parseDouble(sc.nextLine()));
            a.add(sv);
        }

        Collections.sort(a, new Comparator<SinhVien>() {
            @Override
            public int compare(SinhVien o1, SinhVien o2) {
                return Double.compare(o2.getDiem(),o1.getDiem());
            }
        });

        for (SinhVien sinhVien : a) {
            System.out.println(sinhVien);
        }
    }
}
