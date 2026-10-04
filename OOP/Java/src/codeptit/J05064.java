package codeptit;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class J05064 {
    public static class GiaoVien{
        private String mgv,ten,chucVu;
        private long luongCoBan,bacLuong,phuCap,tienLuong;
        private int hso;

        public GiaoVien(String s, String t, long x){
            mgv = s;
            ten = t;
            luongCoBan = x;

            chucVu = s.substring(0,2);
            hso = Integer.parseInt(s.substring(2));

            if(chucVu.equals("HT")){
                phuCap = 2000000;
            } else if(chucVu.equals("HP")){
                phuCap = 900000;
            } else{
                phuCap = 500000;
            }

            tienLuong = luongCoBan * hso + phuCap;
        }

        public String getChucVu(){return chucVu;}
        public String toString(){
            return mgv + " " + ten + " " + hso + " " + phuCap + " " + tienLuong;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        int cntHT = 0, cntHP = 0;

        ArrayList<GiaoVien> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            GiaoVien b = new GiaoVien(sc.nextLine(),sc.nextLine(),Long.parseLong(sc.nextLine()));
            String chucVu = b.getChucVu();

            if(chucVu.equals("HT")){
                ++cntHT;
                if(cntHT <= 1)
                    a.add(b);
            } else if(chucVu.equals("HP")){
                ++cntHP;
                if(cntHP <= 2)
                    a.add(b);
            } else{
                a.add(b);
            }
        }

        a.forEach(System.out::println);
    }
}
