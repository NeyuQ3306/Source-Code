package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05020 {
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
            list.add(new SinhVien(sc.nextLine().trim(),sc.nextLine().trim(),sc.nextLine().trim(),sc.nextLine().trim()));
        }

        Collections.sort(list, new Comparator<SinhVien>() {
            @Override
            public int compare(SinhVien o1, SinhVien o2) {
                if(!o1.getLop().equals(o2.getLop())){
                    return o1.getLop().compareTo(o2.getLop());
                } else{
                    return o1.getMsv().compareTo(o2.getMsv());
                }
            }
        });

        for (SinhVien sinhVien : list) {
            System.out.println(sinhVien);
        }
    }
}
