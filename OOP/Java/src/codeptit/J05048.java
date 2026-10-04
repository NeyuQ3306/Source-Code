package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

public class J05048 {
    public static class MatHang{
        private String mmh;
        private long slNhap,slXuat,donGia,tien,thue;

        public MatHang(String t, long x){
            mmh = t;
            slNhap = x;

            if(t.charAt(0) == 'A'){
                slXuat = Math.round(slNhap * 60f / 100);
            } else if(t.charAt(0) == 'B'){
                slXuat = Math.round(slNhap * 70f / 100);
            }

            if(t.charAt(t.length() - 1) == 'Y'){
                donGia = 110000;
            } else if(t.charAt(t.length() - 1) == 'N'){
                donGia = 135000;
            }
            tien = donGia * slXuat;

            if(t.charAt(0) == 'A' && t.charAt(t.length()-1) == 'Y'){
                thue = (tien * 8 / 100);
            } else if(t.charAt(0) == 'A' && t.charAt(t.length()-1) == 'N'){
                thue = (tien * 11 / 100);
            } else if(t.charAt(0) == 'B' && t.charAt(t.length()-1) == 'Y'){
                thue = (tien * 17 / 100);
            } else{
                thue = (tien * 22 / 100);
            }
        }

        public String toString(){
            return mmh + " " + slNhap + " " + slXuat + " " + donGia + " " + tien + " " + thue;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < n; i++) {
            MatHang a = new MatHang(sc.nextLine(),Long.parseLong(sc.nextLine()));
            System.out.println(a);
        }
    }
}
