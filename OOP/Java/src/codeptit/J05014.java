package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05014 {
    public static class GV{
        private String mgv,ten,mon,trangThai;
        private double m1,m2,tb;
        private static int cnt = 0;

        public GV(String ten, String mon, double m1, double m2){
            this.ten = ten;
            if(mon.charAt(0) == 'A') this.mon = "TOAN";
            else if(mon.charAt(0) == 'B') this.mon = "LY";
            else this.mon = "HOA";

            this.m1 = m1;
            this.m2 = m2;
            this.tb = m1 * 2 + m2;

            if(mon.charAt(1) == '1') this.tb += 2f;
            else if(mon.charAt(1) == '2') this.tb += 1.5f;
            else if(mon.charAt(1) == '3') this.tb += 1f;
            else this.tb += 0f;

            this.trangThai = tb >= 18f ? "TRUNG TUYEN" : "LOAI";

            ++cnt;
            this.mgv = String.format("GV%02d",cnt);
        }

        public double getTb(){return tb;}

        public String toString(){
            return mgv + " " + ten + " " + mon + " " + String.format("%.1f", tb) + " " + trangThai;
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<GV> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            GV a = new GV(sc.nextLine(),sc.nextLine(),Double.parseDouble(sc.nextLine()),Double.parseDouble(sc.nextLine()));
            list.add(a);
        }

        Collections.sort(list, new Comparator<GV>() {
            @Override
            public int compare(GV o1, GV o2) {
                return Double.compare(o2.getTb(),o1.getTb());
            }
        });

        for (GV gv : list) {
            System.out.println(gv);
        }
    }
}
