package codeptit;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class J05070 {
    public static class CLB{
        private String maClb,tenClb,maTran;
        private long giaVe,soCDV,doanhThu;
        private int stt;

        public CLB(String s, String t, String x){
            maClb = s;
            tenClb = t;
            giaVe = Long.parseLong(x);

            stt = 0;
            soCDV = 0;
            doanhThu = 0;
            maTran = "";
        }

        public String getTenClb(){return tenClb;}
        public String getMaClb(){return maClb;}
        public long getGiaVe(){return giaVe;}
        public long getDoanhThu(){return doanhThu;}

        public void setMaTran(String x){maTran = x;}
        public void setDoanhThu(long x, long y){doanhThu = x*y;}

        public String toString(){
            return maTran + " " + tenClb + " " + doanhThu;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<CLB> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(new CLB(sc.nextLine(),sc.nextLine(),sc.nextLine()));
        }

        int q = Integer.parseInt(sc.nextLine());
        while(q-->0){
            String[] tok = sc.nextLine().split("\\s+");
            String maTran = tok[0];
            String tenCLB = maTran.substring(1,3);
            long sl = Long.parseLong(tok[1]);

            for (CLB clb : list) {
                if(clb.getMaClb().equals(tenCLB)){
                    clb.setMaTran(maTran);
                    clb.setDoanhThu(clb.getGiaVe(),sl);
                }
            }
        }

        list.sort(Comparator.comparing(CLB::getDoanhThu,Comparator.reverseOrder()).thenComparing(CLB::getTenClb));
        list.forEach(System.out::println);
    }
}
