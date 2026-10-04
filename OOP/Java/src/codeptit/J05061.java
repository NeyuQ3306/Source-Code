package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

public class J05061 {
    public static class ThiSinh{
        private String ten,ns,mts,xepLoai;
        private float lyThuyet,thucHanh,thuong;
        private int diemThi,tuoi;
        private static int cnt = 0;

        public ThiSinh(String s, String t, float x, float y){
            ++cnt;
            mts = String.format("PH%02d",cnt);

            ten = s;
            ns = t;
            lyThuyet = x;
            thucHanh = y;

            if(x >= 8 && y >= 8){
                thuong = 1;
            } else if(x >= 7.5 && y >= 7.5){
                thuong = 0.5f;
            } else{
                thuong = 0.0f;
            }

            tuoi = 2021 - Integer.parseInt(ns.substring(6));
            float tmp = (lyThuyet + thucHanh) / 2f;
            diemThi = Math.round(tmp + thuong);

            if(diemThi > 10) diemThi = 10;
            if(diemThi == 9 || diemThi == 10){
                xepLoai = "Xuat sac";
            } else if(diemThi == 8){
                xepLoai = "Gioi";
            } else if(diemThi == 7){
                xepLoai = "Kha";
            } else if(diemThi >= 5){
                xepLoai = "Trung binh";
            } else{
                xepLoai = "Truot";
            }
        }

        public int getDiemThi(){return diemThi;}

        public String toString(){
            return mts + " " + ten + " " + tuoi + " " + diemThi + " " + xepLoai;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<ThiSinh> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new ThiSinh(sc.nextLine(),sc.nextLine(),Float.parseFloat(sc.nextLine()),Float.parseFloat(sc.nextLine())));
        }

        a.sort((o1,o2) -> o2.getDiemThi() - o1.getDiemThi());
        a.forEach(System.out::println);
    }
}
