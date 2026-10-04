package codeptit;

import java.util.Scanner;

public class J04013 {
    public static class ThiSinh{
        private String mts, ten;
        private double toan, ly, hoa;

        public ThiSinh(String mts, String ten, double toan, double ly, double hoa){
            this.mts = mts;
            this.ten = ten;
            this.toan = toan;
            this.ly = ly;
            this.hoa = hoa;
        }

        public String formatDouble(Double d){
            int tmp = (int)(d * 10);
            return tmp%10 == 0 ? String.format("%.0f",d) : String.format("%.1f",d);
        }

        public String toString(){
            String kvuc = mts.substring(0,3);
            double tongDiem = toan*2 + ly + hoa;
            double diemCong;

            if(kvuc.equals("KV1")) diemCong = 0.5;
            else if(kvuc.equals("KV2")) diemCong = 1.0;
            else diemCong = 2.5;

            String finalDiemCong = formatDouble(diemCong);
            String finalTongDiem = formatDouble(tongDiem);

            String trangThai = (tongDiem + diemCong >= 24F ? "TRUNG TUYEN" : "TRUOT");
            return mts + " " + ten + " " + finalDiemCong + " " + finalTongDiem + " " + trangThai;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ThiSinh a = new ThiSinh(sc.nextLine(), sc.nextLine(), Double.parseDouble(sc.nextLine()), Double.parseDouble(sc.nextLine()), Double.parseDouble(sc.nextLine()));

        System.out.println(a);
    }
}
