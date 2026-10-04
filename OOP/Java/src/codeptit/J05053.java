package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05053 {
    public static class DonHang{
        private String mdh,ten,stt;
        private int loai,sluong;
        private long giamGia,thanhTien,donGia;

        public DonHang(String t, String s, long x, int y){
            ten = t;
            mdh = s;
            donGia = x;
            sluong = y;

            stt = mdh.substring(1,4);
            loai = Integer.parseInt(mdh.substring(4));

            if(loai == 1){
                giamGia = donGia * sluong * 50 / 100;
            } else{
                giamGia = donGia * sluong * 30 / 100;
            }

            thanhTien = donGia * sluong - giamGia;
        }

        public String getStt(){return stt;}

        public String toString(){
            return ten + " " + mdh + " " + stt + " " + giamGia + " " + thanhTien;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<DonHang> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new DonHang(sc.nextLine(),sc.nextLine(),Long.parseLong(sc.nextLine()),Integer.parseInt(sc.nextLine())));
        }

        Collections.sort(a, new Comparator<DonHang>() {
            @Override
            public int compare(DonHang o1, DonHang o2) {
                return o1.getStt().compareTo(o2.getStt());
            }
        });

        for (DonHang donHang : a) {
            System.out.println(donHang);
        }
    }
}
