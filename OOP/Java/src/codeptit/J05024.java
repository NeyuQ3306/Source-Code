package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

public class J05024 {
    public static class SinhVien{
        private String msv,ten,lop,mail,nganh;
        public SinhVien(String msv, String ten, String lop, String mail){
            this.msv = msv;
            this.ten = ten;
            this.lop = lop;
            this.mail = mail;

            if(msv.contains("DCKT")) this.nganh = "Ke toan";
            else if(msv.contains("DCCN") && lop.charAt(0) != 'E') this.nganh = "Cong nghe thong tin";
            else if(msv.contains("DCAT") && lop.charAt(0) != 'E') this.nganh = "An toan thong tin";
            else if(msv.contains("DCVT")) this.nganh = "Vien thong";
            else if(msv.contains("DCDT")) this.nganh = "Dien tu";
            else this.nganh = "";
        }

        public String getLop(){return lop;}
        public String getMsv(){return msv;}
        public String getNganh(){return nganh;}

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

        int q = Integer.parseInt(sc.nextLine().trim());
        while(q-->0){
            String nganh = sc.nextLine().trim();
            System.out.println("DANH SACH SINH VIEN NGANH " + nganh.toUpperCase() + ":");
            for (SinhVien sinhVien : list) {
                if(sinhVien.getNganh().equals(nganh)){
                    System.out.println(sinhVien);
                }
            }
        }
    }
}
