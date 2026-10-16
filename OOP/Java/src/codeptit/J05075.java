package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

public class J05075 {
    public static class SinhVien{
        private String msv,ten,lop,trangThai;
        private int dcc;

        public SinhVien(String s, String t, String x){
            msv = s;
            ten = t;
            lop = x;

            dcc = 10;
            trangThai = "";
        }

        public void setDcc(String s){
            for(char c : s.toCharArray()){
                if(c == 'm'){
                    dcc -= 1;
                } else if(c == 'v'){
                    dcc -= 2;
                } else{
                    dcc -= 0;
                }
            }

            if(dcc < 0) dcc = 0;
            if(dcc == 0) trangThai = "KDDK";
        }

        public String getMsv(){return msv;}
        public String getLop(){return lop;}

        public String toString(){
            return msv + " " + ten + " " + lop + " " + dcc + " " + trangThai;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<SinhVien> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new SinhVien(sc.nextLine(),sc.nextLine(),sc.nextLine()));
        }

        for (int i = 0; i < n; i++) {
            String line = sc.nextLine();
            String[] tok = line.split("\\s+");

            String msv = tok[0];
            String banGhi = tok[1];

            for (SinhVien sinhVien : a) {
                if(sinhVien.getMsv().equals(msv)){
                    sinhVien.setDcc(banGhi);
                }
            }
        }

        String lop = sc.nextLine();
        for (SinhVien sinhVien : a) {
            if(sinhVien.getLop().equals(lop)){
                System.out.println(sinhVien);
            }
        }
    }
}
