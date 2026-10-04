package codeptit;

import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.*;

public class J05055 {
    public static class ThiSinh{
        private String mts,ten,ns,xuatPhat,denDich,tgianThucTe,uuTien,tgianXepHang;
        private long timeXepHangSecond;
        private int xepHang,stt;
        private static int cnt;

        public ThiSinh(String s, String t, String x, String y){
            ten = s;
            ns = t;
            xuatPhat = x;
            denDich = y;

            int year = Integer.parseInt(ns.substring(6));
            int yearolds = 2021 - year;
            long tmp = 0;   

            DateTimeFormatter form = DateTimeFormatter.ofPattern("HH:mm:ss");
            if(yearolds >= 32){
                tmp = 3;
            } else if(yearolds >= 25){
                tmp = 2;
            } else if(yearolds >= 18){
                tmp = 1;
            }

            LocalTime tmp1 = LocalTime.ofSecondOfDay(tmp);
            uuTien = tmp1.format(form);


            LocalTime start = LocalTime.parse(xuatPhat);
            LocalTime end = LocalTime.parse(denDich);

            long time = ChronoUnit.SECONDS.between(start,end);
            if(time < 0){
                time += 24 * 3600;
            }

            LocalTime diff = LocalTime.ofSecondOfDay(time);

            tgianThucTe = diff.format(form);
            timeXepHangSecond = time - tmp;
            tgianXepHang = LocalTime.ofSecondOfDay(timeXepHangSecond).format(form);

            xepHang = 0;
            ++cnt;
            mts = String.format("VDV%02d",cnt);
            stt = cnt;
        }

        public int getStt(){return stt;}
        public int getXepHang(){return xepHang;}
        public long getTimeXepHang(){return timeXepHangSecond;}
        public void setXepHang(int x){
            xepHang = x;
        }

        public String toString(){
            return mts + " " + ten + " " + tgianThucTe + " " + uuTien + " " + tgianXepHang + " " + xepHang;
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        List<ThiSinh> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new ThiSinh(sc.nextLine(),sc.nextLine(),sc.nextLine(),sc.nextLine()));
        }

        a.sort((o1,o2) -> o1.getTimeXepHang() > o2.getTimeXepHang() ? 1 : -1);
        a.get(0).setXepHang(1);

        for (int i = 1; i < n; i++) {
            int tmp1 = a.get(i-1).getXepHang();
            long tmp2 = a.get(i-1).getTimeXepHang();

            if(a.get(i).getTimeXepHang() == tmp2){
                a.get(i).setXepHang(tmp1);
            } else{
                a.get(i).setXepHang(i+1);
            }
        }

        a.sort((o1,o2) -> o1.getStt() - o2.getStt());
        a.forEach(System.out::println);
    }
}
