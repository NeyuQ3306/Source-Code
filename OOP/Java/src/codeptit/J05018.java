package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05018 {
    public static class HocSinh{
        private String mhs,ten,xepLoai;
        private double tongDiem;
        private static int cnt = 0;

        public HocSinh(String ten, String diem){
            this.ten = ten;
            String[] tok1 = diem.split("\\s+");

            for (int i = 0; i < tok1.length; i++) {
                if(i == 0 || i == 1){
                    this.tongDiem += Double.parseDouble(tok1[i]) * 2;
                } else{
                    this.tongDiem += Double.parseDouble(tok1[i]);
                }
            }

            this.tongDiem /= 12;
            // Bài này chú ý chỗ làm tròn đến chữ số đầu tiên sau dấu phẩy
            // Mẹo là nhân 10 r làm tròn r lại chia 10, chú ý là 10f 
            this.tongDiem = Math.round(this.tongDiem * 10f) / 10f;

            if(this.tongDiem >= 9) this.xepLoai = "XUAT SAC";
            else if(this.tongDiem >= 8) this.xepLoai ="GIOI";
            else if(this.tongDiem >= 7) this.xepLoai = "KHA";
            else if(this.tongDiem >= 5) this.xepLoai = "TB";
            else this.xepLoai = "YEU";

            ++cnt;
            this.mhs = String.format("HS%02d",cnt);
        }

        public double getTongDiem(){return tongDiem;}

        public String toString(){
            return mhs + " " + ten + " " + String.format("%.1f",tongDiem) + " " + xepLoai;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<HocSinh> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(new HocSinh(sc.nextLine().trim(), sc.nextLine().trim()));
        }

        Collections.sort(list, new Comparator<HocSinh>() {
            @Override
            public int compare(HocSinh o1, HocSinh o2) {
                return Double.compare(o2.getTongDiem(),o1.getTongDiem());
            }
        });

        for (HocSinh hocSinh : list) {
            System.out.println(hocSinh);
        }
    }
}
