package codeptit;

import java.util.Scanner;

public class J05040 {
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
        
        for (int i = 0; i < n; i++) {
            NhanVien a = new NhanVien(sc.nextLine().trim(),Long.parseLong(sc.nextLine().trim()),Long.parseLong(sc.nextLine().trim()),sc.nextLine().trim());
            System.out.println(a);
        }
    }
}
