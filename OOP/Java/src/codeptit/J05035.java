package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05035 {
    public static class SinhVien{
        private String msv,ten,lop,mail,doanhNghiep;
        private int stt;
        private static int cnt = 0;

        public SinhVien(String s, String t, String x, String y, String z){
            msv = s;
            ten = t;
            lop = x;
            mail = y;
            doanhNghiep = z;

            ++cnt;
            stt = cnt;
        }

        public String getMsv(){return msv;}
        public String getDoanhNghiep(){return doanhNghiep;}
        public String toString(){
            return stt + " " + msv + " " + ten + " " + lop + " " + mail + " " + doanhNghiep;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<SinhVien> a = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            a.add(new SinhVien(sc.nextLine().trim(),sc.nextLine().trim(),sc.nextLine().trim(),sc.nextLine().trim(),sc.nextLine().trim()));
        }

        Collections.sort(a, new Comparator<SinhVien>() {
            @Override
            public int compare(SinhVien o1, SinhVien o2) {
                return o1.getMsv().compareTo(o2.getMsv());
            }
        });

        int q = Integer.parseInt(sc.nextLine().trim());
        while(q-->0){
            String s = sc.nextLine();
            for (SinhVien sinhVien : a) {
                if(sinhVien.getDoanhNghiep().equals(s)){
                    System.out.println(sinhVien);
                }
            }
        }
    }
}
