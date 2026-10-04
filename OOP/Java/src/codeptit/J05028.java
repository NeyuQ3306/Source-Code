package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05028 {
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

        Collections.sort(a, new Comparator<DoanhNghiep>() {
            @Override
            public int compare(DoanhNghiep o1, DoanhNghiep o2) {
                if(o1.getSl() != o2.getSl()){
                    return o2.getSl() - o1.getSl();
                } else{
                    return o1.getTenVietTat().compareTo(o2.getTenVietTat());
                }
            }
        });

        for (DoanhNghiep doanhNghiep : a) {
            System.out.println(doanhNghiep);
        }
    }
}
