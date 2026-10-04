package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

public class J05044 {
    public static class NhanVien{
        private String ten,chucVu,mnv;
        private long luongCB, snc, tamUng, phuCap, luongThang, conLai;
        private static int cnt = 0;

        public NhanVien(String s, String t, long x, long y){
            ten = s;
            chucVu = t;
            luongCB = x;
            snc = y;

            ++cnt;
            mnv = String.format("NV%02d",cnt);

            if(chucVu.equals("GD")){
                phuCap = 500;
            } else if(chucVu.equals("PGD")){
                phuCap = 400;
            } else if(chucVu.equals("TP")){
                phuCap = 300;
            } else if(chucVu.equals("KT")){
                phuCap = 250;
            } else{
                phuCap = 100;
            }

            luongThang = luongCB * snc;
            double tmp = (phuCap + luongThang) * 2f / 3;
            tamUng = Math.round(tmp/1000) * 1000;

            if(tamUng >= 25000) tamUng = 25000;

            conLai = luongThang + phuCap - tamUng;
        }

        public String getChucVu(){return chucVu;}

        public String toString(){
            return mnv + " " + ten + " " + phuCap + " " + luongThang + " " + tamUng + " " + conLai;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<NhanVien> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new NhanVien(sc.nextLine(),sc.nextLine(),Long.parseLong(sc.nextLine()),Long.parseLong(sc.nextLine())));
        }

        String s = sc.nextLine();
        for (NhanVien nhanVien : a) {
            if(nhanVien.getChucVu().equals(s)){
                System.out.println(nhanVien);
            }
        }
    }
}
