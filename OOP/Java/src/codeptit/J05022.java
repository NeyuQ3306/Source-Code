package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

public class J05022 {
    public static class SinhVien{
        private String msv,ten,lop,mail;
        public SinhVien(String msv, String ten, String lop, String mail){
            this.msv = msv;
            this.ten = ten;
            this.lop = lop;
            this.mail = mail;
        }

        public String getLop(){return lop;}
        public String getMsv(){return msv;}

        public String toString(){
            return msv + " " + ten + " " + lop + " " + mail;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<SinhVien> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(new SinhVien(sc.nextLine().trim(), sc.nextLine().trim(),sc.nextLine().trim(),sc.nextLine().trim()));
        }

        int q = sc.nextInt();
        sc.nextLine();
        while(q-- > 0){
            String lop = sc.nextLine();
            System.out.println("DANH SACH SINH VIEN LOP " + lop + ":");
            for (SinhVien sinhVien : list) {
                if(sinhVien.getLop().equals(lop)){
                    System.out.println(sinhVien);
                }
            }
        }
    }
}
