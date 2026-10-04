package codeptit;

import java.util.Scanner;

public class J04006 {
    public static class SinhVien{
        private String ten,lop,ns,msv;
        private double diem;

        public SinhVien(String name, String lop, String ns, double diem){
            this.ten = name;
            this.lop = lop;
            this.ns = ns;
            this.diem = diem;
            this.msv = "B20DCCN001";
        }

        public void chuanHoaNs(){
            String[] a = ns.split("/");
            this.ns = String.format("%02d/%02d/%04d", Integer.parseInt(a[0]), Integer.parseInt(a[1]), Integer.parseInt(a[2]));
        }

        @Override
        public String toString(){
            return msv + " " + ten + " " + lop + " " + ns + " " + String.format("%.2f",diem);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        SinhVien a = new SinhVien(sc.nextLine(), sc.nextLine(), sc.nextLine(), Double.parseDouble(sc.nextLine()));
        a.chuanHoaNs();

        System.out.println(a);
    }
}
