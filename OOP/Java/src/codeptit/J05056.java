package codeptit;

import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class J05056 {
    public static class ThiSinh{
        private String mts,ten,thanhTichThucTe,uuTien,thanhTichXepHang,ns;
        private int xepHang;
        private long time;
        private static int cnt = 0;

        public ThiSinh(String s, String t, String x, String y){
            ++cnt;
            mts = String.format("VDV%02d",cnt);
            ten = s;
            ns = t;

            DateTimeFormatter form = DateTimeFormatter.ofPattern("HH:mm:ss");
            int yearolds = 2021 - Integer.parseInt(ns.substring(6));
            long tmp1 = 0;
            if(yearolds >= 32){
                tmp1 = 3;
            } else if(yearolds >= 25){
                tmp1 = 2;
            } else if(yearolds >= 18){
                tmp1 = 1;
            }

            LocalTime tmp2 = LocalTime.ofSecondOfDay(tmp1);
            uuTien = tmp2.format(form);

            LocalTime start = LocalTime.parse(x);
            LocalTime end = LocalTime.parse(y);

            long tmp3 = ChronoUnit.SECONDS.between(start,end);
            if(tmp3 < 0){
                tmp3 += 24 * 3600;
            }

            LocalTime tmp4 = LocalTime.ofSecondOfDay(tmp3);
            thanhTichThucTe = tmp4.format(form);

            long tmp5 = tmp3 - tmp1;
            time = tmp5;
            LocalTime tmp6 = LocalTime.ofSecondOfDay(tmp5);
            thanhTichXepHang = tmp6.format(form);

            xepHang = 0;
        }

        public long getTime(){return time;}
        public int getXepHang(){return xepHang;}
        public void setXepHang(int x){
            xepHang = x;
        }

        public String toString(){
            return mts + " " + ten + " " + thanhTichThucTe + " " + uuTien + " " + thanhTichXepHang + " " + xepHang;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        List<ThiSinh> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new ThiSinh(sc.nextLine(),sc.nextLine(),sc.nextLine(),sc.nextLine()));
        }

        a.sort((o1,o2) -> o1.getTime() < o2.getTime() ? -1 : 1);
        a.get(0).setXepHang(1);

        for (int i = 1; i < n; i++) {
            int xepHang = a.get(i-1).getXepHang();
            long time = a.get(i-1).getTime();

            if(a.get(i).getTime() == time){
                a.get(i).setXepHang(xepHang);
            } else{
                a.get(i).setXepHang(i+1);
            }
        }

        a.forEach(System.out::println);
    }
}
