package codeptit;

import java.util.Scanner;

public class J04012 {
    public static class NhanVien{
        private String mnv,ten,luong,snc,cv;
        private static int cnt;

        public NhanVien(String ten, String luong, String snc, String cv){
            this.ten = ten;
            this.luong = luong;
            this.snc = snc;
            this.cv = cv;

            ++cnt;
            this.mnv = "NV" + String.format("%02d",cnt);
        }

        public String toString(){
            long luongCoBan = Long.parseLong(luong) * Long.parseLong(snc);
            long thuong = 0;

            if(Long.parseLong(snc) >= 25) thuong = luongCoBan * 20 / 100;
            else if(Long.parseLong(snc) >= 22) thuong = luongCoBan * 10 / 100;
            else thuong = 0;

            long phuCap = 0;
            if(cv.equals("GD")) phuCap = 250000;
            else if(cv.equals("PGD")) phuCap = 200000;
            else if(cv.equals("TP")) phuCap = 180000;
            else phuCap = 150000;

            long thuNhap = luongCoBan + phuCap + thuong;
            return mnv + " " + ten + " " + luongCoBan + " " + thuong + " " + phuCap + " " + thuNhap;
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        NhanVien a = new NhanVien(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine());

        System.out.println(a);
    }
}
