package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05051 {
    public static class KhachHang{
        private String loaiSD,mkh;
        private int csm,csc,hso;
        private long thanhTien,phuTroi,total;
        private static int cnt = 0;

        public KhachHang(String t, int x, int y){
            ++cnt;
            mkh = String.format("KH%02d",cnt);
            loaiSD = t;
            csc = x;
            csm = y;

            if(loaiSD.equals("KD")){
                hso = 3;
            } else if(loaiSD.equals("NN")){
                hso = 5;
            } else if(loaiSD.equals("TT")){
                hso = 4;
            } else{
                hso = 2;
            }

            int cs = csm - csc;
            thanhTien = cs * 550 * hso;

            // chú ý đoạn làm tròn phải ép double cho thanhTien nếu ko bị Wa 
            if(cs > 100){
                phuTroi = thanhTien;
            }else if(cs >= 50){
                phuTroi = Math.round((double) thanhTien * 35f / 100f);
            } else{
                phuTroi = 0;
            }

            total = phuTroi + thanhTien;
        }

        public long getTotal(){return total;}
        public String toString(){
            return mkh + " " + hso + " " + thanhTien + " " + phuTroi + " " + total;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<KhachHang> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new KhachHang(sc.nextLine(),Integer.parseInt(sc.nextLine()),Integer.parseInt(sc.nextLine())));
        }

        Collections.sort(a, new Comparator<KhachHang>() {
            @Override
            public int compare(KhachHang o1, KhachHang o2) {
                return o2.getTotal() > o1.getTotal() ? 1 : -1;
            }
        });

        for (KhachHang khachHang : a) {
            System.out.println(khachHang);
        }
    }
}
