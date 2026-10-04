package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/*
Bài này chú ý điều kiện sort theo vận tốc ở dạng double, so sánh khi làm tròn bị wa
 */

public class J05015 {
    public static class ThiSinh{
        private String ten,dvi,mts;
        private double vt;

        public ThiSinh(String ten, String dvi, String time){
            this.ten = ten;
            this.dvi = dvi;

            this.mts = "";
            String[] tok1 = dvi.split("\\s+");
            String[] tok2 = ten.split("\\s+");

            for (String s : tok1) {
                this.mts += s.charAt(0) + "";
            }

            for (String s : tok2) {
                this.mts += s.charAt(0) + "";
            }

            this.mts = this.mts.toUpperCase();

            String[] tok3 = time.split(":");
            int gio = Integer.parseInt(tok3[0]), phut = Integer.parseInt(tok3[1]);

            int totalH = gio - 6, totalM = phut;
            double h = totalH + phut / 60f;

            this.vt = 120/h;
        }

        public double getVt(){return vt;}

        @Override
        public String toString(){
            return mts + " " + ten + " " + dvi + " " + (int)(Math.round(vt)) + " Km/h";
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<ThiSinh> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ThiSinh a = new ThiSinh(sc.nextLine(),sc.nextLine(),sc.nextLine());
            list.add(a);
        }

        Collections.sort(list, new Comparator<ThiSinh>() {
            @Override
            public int compare(ThiSinh o1, ThiSinh o2) {
                return Double.compare(o2.getVt(),o1.getVt());
            }
        });

        for (ThiSinh thiSinh : list) {
            System.out.println(thiSinh);
        }
    }
}
