package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05013 {
    public static class ThiSinh{
        private String ten, mts,trangThai;
        private double m1,m2,tb;
        private static int cnt;

        public ThiSinh(String ten, double m1, double m2){
            this.ten = ten;
            this.m1 = m1;
            this.m2 = m2;

            this.tb = (m1 + m2) / 2f;
            if(this.tb > 10) this.tb /= 10f;

            if(tb > 9.5) trangThai = "XUAT SAC";
            else if(tb >= 8) trangThai = "DAT";
            else if(tb > 5) trangThai = "CAN NHAC";
            else trangThai = "TRUOT";

            ++cnt;
            this.mts = String.format("TS%02d",cnt);
        }

        public double getTb(){return tb;}

        public String toString(){
            return mts + " " + ten + " " + String.format("%.2f",tb) + " " + trangThai;
        }


    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<ThiSinh> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ThiSinh a = new ThiSinh(sc.nextLine(), Double.parseDouble(sc.nextLine()), Double.parseDouble(sc.nextLine()));
            list.add(a);
        }

        Collections.sort(list, new Comparator<ThiSinh>() {
            @Override
            public int compare(ThiSinh o1, ThiSinh o2) {
                return Double.compare(o2.getTb(),o1.getTb());
            }
        });

        for (ThiSinh thiSinh : list) {
            System.out.println(thiSinh);
        }
    }
}
