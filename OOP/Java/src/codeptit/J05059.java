package codeptit;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class J05059 {
    public static class ThiSinh{
        private String mts,ten,trangThai;
        private double toan,ly,hoa,tb,uuTien;

        public ThiSinh(String s, String t, double x, double y, double z){
            ten = chuanHoaTen(t);
            mts = s;

            int tmp = Integer.parseInt(mts.charAt(2)+"");
            if(tmp == 1){
                uuTien = 0.5;
            } else if(tmp == 2){
                uuTien = 1.0;
            } else{
                uuTien = 2.5;
            }

            toan = x;
            ly = y;
            hoa = z;

            tb = (x*2 + y + z) + uuTien;
            trangThai = "";
        }

        public String chuanHoaTen(String s){
            String res = "";
            String[] tok = s.trim().toLowerCase().split("\\s+");

            for (String string : tok) {
                res += Character.toUpperCase(string.charAt(0)) + string.substring(1) + " ";
            }

            return res.trim();
        }

        public String chuanHoaFloat(double tb){
            return tb*10%10 == 0 ? String.format("%.0f",tb) : String.format("%.1f",tb);
        }

        public double getTb(){
            return tb;
        }
        public String getMts(){
            return mts;
        }
        public void setTrangThai(String s){
            trangThai = s;
        }

        public String toString(){
            return mts + " " + ten + " " + chuanHoaFloat(uuTien) + " " + chuanHoaFloat(tb) + " " + trangThai;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<ThiSinh> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new ThiSinh(sc.nextLine(),sc.nextLine(),Double.parseDouble(sc.nextLine()),Double.parseDouble(sc.nextLine()),Double.parseDouble(sc.nextLine())));
        }

        int chiTieu = Integer.parseInt(sc.nextLine());
        double diemChuan = 0;

        a.sort(Comparator.comparing(ThiSinh::getTb, Comparator.reverseOrder()).thenComparing(ThiSinh::getMts));
        for (ThiSinh thiSinh : a) {
            --chiTieu;
            if(chiTieu == 0){
                diemChuan = thiSinh.getTb();
            }
        }

        System.out.println(diemChuan);
        for (ThiSinh thiSinh : a) {
            if(thiSinh.getTb() >= diemChuan){
                thiSinh.setTrangThai("TRUNG TUYEN");
            } else{
                thiSinh.setTrangThai("TRUOT");
            }

            System.out.println(thiSinh);
        }
    }
}
