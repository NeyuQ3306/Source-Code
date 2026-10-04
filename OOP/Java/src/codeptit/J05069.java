package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

/*
Bài này chú ý là in theo thứ tự nhập nên khi set xong các thuộc tính thì in ra luôn
Ko cần sử dụng thuộc tính stt
 */

public class J05069 {
    public static class CLB{
        private String maCLB,tenCLB,maTran;
        private long giaVe,soCDV,doanhThu;
        private int stt;

        public CLB(String s, String t, String u){
            maCLB = s;
            tenCLB = t;
            giaVe = Long.parseLong(u);

            stt = 0;
            soCDV = 0;
            doanhThu = 0;
            maTran = "";
        }

        public void setMaTran(String s){
            maTran = s;
        }

        public void setSoCDV(long x){
            soCDV = x;
        }

        public void setDoanhThu(long x, long y){
            doanhThu = x * y;
        }

        public void setStt(int x){stt = x;}
        public long getGiaVe(){return giaVe;}
        public String getMaCLB(){return maCLB;}
        public int getStt(){return stt;}

        public String toString(){
            return maTran + " " + tenCLB + " " + doanhThu;
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
            String s = sc.nextLine();
            String[] tok = s.split("\\s+");

            String maClb = tok[0].substring(1,3);
            long sl = Long.parseLong(tok[1]);
            int stt = Integer.parseInt(tok[0].charAt(3) + "");

            for (CLB clb : list) {
                if(clb.getMaCLB().equals(maClb)){
                    clb.setMaTran(tok[0]);
                    clb.setSoCDV(sl);
                    clb.setDoanhThu(clb.getGiaVe(),sl);
                    clb.setStt(stt);

                    System.out.println(clb);
                }
            }
        }
    }
}
