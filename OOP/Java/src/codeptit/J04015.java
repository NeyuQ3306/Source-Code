package codeptit;

import java.util.Scanner;

public class J04015 {
    public static class GiangVien{
        private String mgv, ten;
        private long luongCoBan;

        public GiangVien(String ma, String ten, long luong){
            this.mgv = ma;
            this.ten = ten;
            this.luongCoBan = luong;
        }

        public String toString(){
            int bacLuong = Integer.parseInt(mgv.substring(2));
            String chucVu = mgv.substring(0,2);

            long phuCap = 0;
            if(chucVu.equals("HT")) phuCap = 2000000;
            else if(chucVu.equals("HP")) phuCap = 900000;
            else phuCap = 500000;

            return mgv + " " + ten + " " + bacLuong + " " + phuCap + " " + (luongCoBan*bacLuong + phuCap);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        GiangVien a = new GiangVien(sc.nextLine(), sc.nextLine(), Long.parseLong(sc.nextLine()));
        System.out.println(a);
    }
}
