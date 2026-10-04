package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

public class J05068 {
    public static class DonHang{
        private String mdh,tenHang;
        private long donGia,thue,thanhTien,soLuong;

        public DonHang(String s){
            String tok[] = s.trim().split("\\s+");
            mdh = tok[0];
            soLuong = Long.parseLong(tok[1]);

            char ma = mdh.charAt(0);
            if(ma == 'X'){
                donGia = 128000;
                thue = donGia * soLuong * 3 / 100;
            } else if(ma == 'D'){
                donGia = 11200;
                thue = donGia * soLuong * 35 / 1000;
            } else{
                donGia = 9700;
                thue = donGia * soLuong * 2 / 100;
            }

            String maSX = mdh.substring(3);
            if(maSX.equals("BP")){
                tenHang = "British Petro";
            } else if(maSX.equals("ES")){
                tenHang = "Esso";
            } else if(maSX.equals("SH")){
                tenHang = "Shell";
            } else if(maSX.equals("CA")){
                tenHang = "Castrol";
            } else if(maSX.equals("MO")){
                tenHang = "Mobil";
            } else{
                tenHang = "Trong Nuoc";
                thue = 0;
            }

            thanhTien = donGia * soLuong + thue;
        }

        public long getThanhTien() {
            return thanhTien;
        }

        public String toString(){
            return mdh + " " + tenHang + " " + donGia + " " + thue + " " + thanhTien;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<DonHang> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(new DonHang(sc.nextLine()));
        }

        list.sort((o1,o2) -> o2.getThanhTien() > o1.getThanhTien() ? 1 : -1);
        list.forEach(System.out::println);

    }
}
