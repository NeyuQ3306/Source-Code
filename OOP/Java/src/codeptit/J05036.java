package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

public class J05036 {
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
            giaBan = Math.round(thanhTien + 0.02 * thanhTien);

            ++cnt;
            mmh = String.format("MH%02d", cnt);
        }

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

        for (MatHang matHang : a) {
            System.out.println(matHang);
        }
    }
}
