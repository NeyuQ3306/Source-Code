package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05021 {
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

        ArrayList<SinhVien> list = new ArrayList<>();
        ArrayList<String> tmp = new ArrayList<>();

        // Chú ý xủ lý sinh viên cuối sau vòng while
        while(sc.hasNextLine()){
            if(tmp.size() == 4){
                list.add(new SinhVien(tmp.get(0),tmp.get(1),tmp.get(2),tmp.get(3)));
                tmp.clear();
                tmp.add(sc.nextLine().trim());
            } else{
                tmp.add(sc.nextLine().trim());
            }
        }

        list.add(new SinhVien(tmp.get(0), tmp.get(1), tmp.get(2), tmp.get(3)));

        Collections.sort(list, new Comparator<SinhVien>() {
            @Override
            public int compare(SinhVien o1, SinhVien o2) {
                return o1.getMsv().compareTo(o2.getMsv());
            }
        });

        for (SinhVien sinhVien : list) {
            System.out.println(sinhVien);
        }
    }
}
