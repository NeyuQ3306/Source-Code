package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05041 {
    public static class NhanVien{
        private String mnv,ten,chucVu;
        private long snc,luongNgay,luongThang,thuong,phuCap,total;
        private static int cnt = 0;

        public NhanVien(String s, long t, long x, String y){
            ten = s;
            luongNgay = t;
            snc = x;
            luongThang = luongNgay * snc;
            chucVu = y;

            if(chucVu.equals("GD")){
                phuCap = 250000;
            } else if(chucVu.equals("PGD")){
                phuCap = 200000;
            } else if(chucVu.equals("TP")){
                phuCap = 180000;
            } else if(chucVu.equals("NV")){
                phuCap = 150000;
            } else{
                phuCap = 0;
            }

            if(snc >= 25){
                thuong = luongThang * 20 / 100;
            } else if(snc >= 22){
                thuong = luongThang * 10 / 100;
            } else{
                thuong = 0;
            }

            total = luongThang + thuong + phuCap;
            ++cnt;
            mnv = String.format("NV%02d",cnt);
        }

        public long getTotal(){return total;}

        public String toString(){
            return mnv + " " + ten + " " + luongThang + " " + thuong + " " + phuCap + " " + total;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<NhanVien> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new NhanVien(sc.nextLine().trim(),Long.parseLong(sc.nextLine()),Long.parseLong(sc.nextLine()),sc.nextLine().trim()));
        }

        Collections.sort(a, new Comparator<NhanVien>() {
            @Override
            public int compare(NhanVien o1, NhanVien o2) {
                return o2.getTotal() > o1.getTotal() ? 1 : -1;
            }
        });

        for (NhanVien nhanVien : a) {
            System.out.println(nhanVien);
        }
    }
}
