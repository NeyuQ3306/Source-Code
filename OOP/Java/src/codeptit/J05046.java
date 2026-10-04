package codeptit;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class J05046{

    static Map<String,Integer> mp = new HashMap<>();

    public static class MatHang{
        private String mmh,ten;
        private long sl,gia,ckhau,thanhTien;
        private static int cnt = 0;

        public MatHang(String t, long x, long y){
            ten = t;
            sl = x;
            gia = y;

            ++cnt;
            String[] tok = t.trim().toUpperCase().split("\\s+");
            String init = tok[0].charAt(0) + "" + tok[1].charAt(0) + "";

            int count = mp.getOrDefault(init, 0) + 1;
            mp.put(init, count);
            mmh = init + String.format("%02d", count);

//            int count = mp.merge(init, 1, Integer::sum);
//            mmh = init + String.format("%02d", count);
            
            long tmp = gia * sl;
            if(sl > 10){
                ckhau = tmp * 5 / 100;
            } else if(sl >= 8){
                ckhau = tmp * 2 / 100;
            } else if(sl >= 5){
                ckhau = tmp * 1 / 100;
            } else{
                ckhau = 0;
            }

            thanhTien = tmp - ckhau;
        }

        public String toString(){
            return mmh + " " + ten + " " + ckhau + " " + thanhTien;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<MatHang> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new MatHang(sc.nextLine(),Long.parseLong(sc.nextLine()),Long.parseLong(sc.nextLine())));
        }

        for (MatHang matHang : a) {
            System.out.println(matHang);
        }
    }
}
