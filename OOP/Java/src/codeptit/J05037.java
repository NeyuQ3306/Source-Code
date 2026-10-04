package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05037 {
    public static class MatHang{
        private String mmh,ten,dvi;
        private long phiVc,thanhTien,giaBan,sl,nhap;
        private static int cnt = 0;

        public MatHang(String t, String s, long x, long y){
            ten = t;
            dvi = s;
            nhap = x;
            sl = y;

            phiVc = Math.round((nhap * sl) * 0.05);
            thanhTien = Math.round((nhap * sl) + phiVc);
            giaBan = Math.round(thanhTien + thanhTien * 0.02) / sl;

            // luôn làm tròn lên nếu phần lẻ != 0
            if(giaBan%100 != 0) giaBan = giaBan - giaBan%100 + 100;

            ++cnt;
            mmh = String.format("MH%02d", cnt);
        }

        public long getGiaBan(){return giaBan;}

        public String toString(){
            return mmh + " " + ten + " " + dvi + " " + phiVc + " " + thanhTien + " " + giaBan;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<MatHang> a = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            a.add(new MatHang(sc.nextLine().trim(),sc.nextLine().trim(),Long.parseLong(sc.nextLine()),Long.parseLong(sc.nextLine())));
        }

        Collections.sort(a, new Comparator<MatHang>() {
            @Override
            public int compare(MatHang o1, MatHang o2) {
                return o1.getGiaBan() < o2.getGiaBan() ? 1 : -1;
            }
        });

        for (MatHang matHang : a) {
            System.out.println(matHang);
        }
    }
}
