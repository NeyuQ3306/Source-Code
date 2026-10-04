package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05045 {
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
        public long getConLai(){return conLai;}
        public long getLuongThang(){return luongThang + phuCap;}
        public int getStt(){return Integer.parseInt(mnv.substring(2));}

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

        Collections.sort(a, new Comparator<NhanVien>() {
            @Override
            public int compare(NhanVien o1, NhanVien o2) {
                if(o1.getLuongThang() != o2.getLuongThang()){
                    return o2.getLuongThang() > o1.getLuongThang() ? 1 : -1;
                } else{
                    return o1.getStt() - o2.getStt();
                }
            }
        });

        for (NhanVien nhanVien : a) {
            System.out.println(nhanVien);
        }
    }
}
