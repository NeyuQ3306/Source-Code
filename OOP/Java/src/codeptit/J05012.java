package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05012 {
    public static class MatHang{
        private String mmh,ten,sl,gia,ck;
        private long thanhTien, donGia;

        public MatHang(String mmh, String ten, String sl, String gia, String ck){
            this.mmh = mmh;
            this.ten = ten;
            this.sl = sl;
            this.gia = gia;
            this.ck = ck;

            this.donGia = Integer.parseInt(sl) * Long.parseLong(gia);
            this.thanhTien = this.donGia - Integer.parseInt(ck);
        }

        public long getThanhTien(){return thanhTien;}

        public String toString(){
            return mmh + " " + ten + " " + sl + " " + gia + " " + ck + " " + thanhTien;
        }
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<MatHang> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            MatHang a = new MatHang(sc.nextLine(),sc.nextLine(),sc.nextLine(),sc.nextLine(),sc.nextLine());
            list.add(a);
        }

        Collections.sort(list, new Comparator<MatHang>(){
            @Override
            public int compare(MatHang a, MatHang b){
                return (b.getThanhTien() > a.getThanhTien() ? 1 : -1);
            }
        });

        for (MatHang matHang : list) {
            System.out.println(matHang);
        }
    }
}
