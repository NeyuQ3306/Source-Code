package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05029 {
    public static class DoanhNghiep{
        private String tenDayDu, tenVietTat;
        private int sl;

        public DoanhNghiep(String s, String t, int a){
            tenVietTat = s;
            tenDayDu = t;
            sl = a;
        }

        public String getTenVietTat(){return tenVietTat;}
        public int getSl(){return sl;}

        public String toString(){
            return tenVietTat + " " + tenDayDu + " " + sl;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<DoanhNghiep> a = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            a.add(new DoanhNghiep(sc.nextLine().trim(),sc.nextLine().trim(),Integer.parseInt(sc.nextLine())));
        }

        Collections.sort(a,new Comparator<DoanhNghiep>(){
            @Override
            public int compare(DoanhNghiep a, DoanhNghiep b){
                if(a.getSl() != b.getSl()){
                    return b.getSl() - a.getSl();
                } else{
                    return a.getTenVietTat().compareTo(b.getTenVietTat());
                }
            }
        });

        int q = Integer.parseInt(sc.nextLine());
        while(q-->0){
            int x = sc.nextInt(), y = sc.nextInt();
            System.out.println(String.format("DANH SACH DOANH NGHIEP NHAN TU %d DEN %d SINH VIEN:", x,y));

            for (DoanhNghiep doanhNghiep : a) {
                if(doanhNghiep.getSl() >= x && doanhNghiep.getSl() <=y){
                    System.out.println(doanhNghiep);
                }
            }
        }
    }
}
