package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

/*
Bài này lấy khóa phải lấy từ lớp chứ lấy từ msv bị wa =)))
 */
public class J05023 {
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
        public String getKhoa(){return "20" + lop.substring(1,3);}

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
        while (q-- > 0) {
            String khoa = sc.nextLine().trim();
            System.out.println("DANH SACH SINH VIEN KHOA " + khoa + ":");
            for (SinhVien sv : list) {
                if (sv.getKhoa().equals(khoa)) {
                    System.out.println(sv);
                }
            }
        }
    }
}
