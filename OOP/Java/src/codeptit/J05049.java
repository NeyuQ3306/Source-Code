package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05049 {
    public static class MatHang{
        private String mmh;
        private long slNhap,slXuat,donGia,thue,tien;

        public MatHang(String s, long t){
            mmh = s;
            slNhap = t;

            slXuat = Math.round(slNhap * (mmh.charAt(0) == 'A' ? 0.6 : 0.7));
            donGia = mmh.charAt(s.length()-1) == 'Y' ? 110000 : 135000;
            tien = slXuat * donGia;

            if(mmh.charAt(0) == 'A'){
                if(mmh.charAt(s.length()-1) == 'Y'){
                    thue = tien * 8 / 100;
                } else{
                    thue = tien * 11 / 100;
                }
            } else{
                if(mmh.charAt(s.length()-1) == 'Y'){
                    thue = tien * 17 / 100;
                } else{
                    thue = tien * 22 / 100;
                }
            }
        }

        public long getThue() {
            return thue;
        }
        public String getMmh(){
            return mmh;
        }

        public String toString(){
            return mmh + " " + slNhap + " " + slXuat + " " + donGia + " " + tien + " " + thue;
         }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<MatHang> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new MatHang(sc.nextLine(),Long.parseLong(sc.nextLine())));
        }

        Collections.sort(a, new Comparator<MatHang>() {
            @Override
            public int compare(MatHang o1, MatHang o2) {
                return o2.getThue() > o1.getThue() ? 1 : -1;
            }
        });

        String s = sc.nextLine();
        for (MatHang matHang : a) {
            if(matHang.getMmh().substring(0,1).equals(s)){
                System.out.println(matHang);
            }
        }
    }
}
