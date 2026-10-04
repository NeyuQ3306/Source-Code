package codeptit;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class J05062 {
    public static class SinhVien{
        private String ten,xepLoai;
        private double tbc,drl;
        private int stt;
        private static int cnt = 0;

        public SinhVien(String s, String t){
            ++cnt;
            stt = cnt;
            ten = s;

            String[] num = t.split("\\s+");
            tbc = Double.parseDouble(num[0]);
            drl = Double.parseDouble(num[1]);
            xepLoai = "";
        }

        public int getStt(){return stt;}
        public double getTbc(){return tbc;}
        public double getDrl(){return drl;}
        public void setXepLoai(String s){
            xepLoai = s;
        }

        public void xepLoai(double x, double y){
            if(x >= 3.6 && y >= 90){
                xepLoai = "XUATSAC";
            } else if(x >= 3.2 && y >= 80){
                xepLoai = "GIOI";
            } else if(x >= 2.5 && y >= 70){
                xepLoai = "KHA";
            } else{
                xepLoai = "KHONG";
            }
        }

        public String toString(){
            return ten + ": " + xepLoai;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();

        ArrayList<SinhVien> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new SinhVien(sc.nextLine(),sc.nextLine()));
        }

        a.sort(Comparator.comparing(SinhVien::getTbc).thenComparing(SinhVien::getDrl).reversed());
        for (int i = 0; i < n; i++) {
            if(i == 0){
                double tbc = a.get(i).getTbc();
                double drl = a.get(i).getDrl();

                a.get(i).xepLoai(tbc,drl);
            }

            if(m > 0){
                double tbc = a.get(i).getTbc();
                double drl = a.get(i).getDrl();
                a.get(i).xepLoai(tbc,drl);
                --m;
            } else{
                double tbc = a.get(i).getTbc();
                double drl = a.get(i).getDrl();
                double tbcPre = a.get(i-1).getTbc();
                double drlPre = a.get(i-1).getDrl();

                if(tbc == tbcPre && drl == drlPre){
                    a.get(i).xepLoai(tbc,drl);
                } else{
                    a.get(i).setXepLoai("KHONG");
                }
            }
        }

        a.sort((o1,o2) -> o1.getStt() - o2.getStt());
        a.forEach(System.out::println);
    }
}
