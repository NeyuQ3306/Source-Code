package codeptit;

import java.util.Scanner;

public class J05003 {
    public static class SinhVien{
        private String msv,ten,lop,ns;
        private double diem;
        private static int cnt = 0;

        public SinhVien(String ten, String lop, String ns, double diem){
            this.ten = ten;
            this.lop = lop;
            this.ns = ns;
            this.diem = diem;

            ++cnt;
            this.msv = "B20DCCN" + String.format("%03d",cnt);
        }

        public static String chuanHoaNs(String s){
            String[] tok = s.split("/");
            return String.format("%02d/%02d/%04d", Integer.parseInt(tok[0]), Integer.parseInt(tok[1]), Integer.parseInt(tok[2]));
        }

        @Override
        public String toString(){
            return msv + " " + ten + " " + lop + " " + ns + " " + String.format("%.2f", diem);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        while(n-- > 0){
            SinhVien a = new SinhVien(sc.nextLine(), sc.nextLine(), SinhVien.chuanHoaNs(sc.nextLine()), Double.parseDouble(sc.nextLine()));
            System.out.println(a);
        }
    }
}
