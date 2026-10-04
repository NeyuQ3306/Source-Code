package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05042 {
    public static class SinhVien{
        private String ten;
        private int submit,ac;

        public SinhVien(String s, String t){
            ten = s;
            String[] num = t.split("\\s+");

            ac = Integer.parseInt(num[0]);
            submit = Integer.parseInt(num[1]);
        }

        public String getTen(){return ten;}
        public int getSubmit(){return submit;}
        public int getAc(){return ac;}

        public String toString(){
            return ten + " " + ac + " " + submit;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<SinhVien> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new SinhVien(sc.nextLine().trim(),sc.nextLine().trim()));
        }

        Collections.sort(a, new Comparator<SinhVien>() {
            @Override
            public int compare(SinhVien o1, SinhVien o2) {
                if(o1.getAc() != o2.getAc()){
                    return o2.getAc() - o1.getAc();
                } else if(o1.getSubmit() != o2.getSubmit()){
                    return o1.submit - o2.submit;
                } else{
                    return o1.getTen().compareTo(o2.getTen());
                }
            }
        });

        for (SinhVien sinhVien : a) {
            System.out.println(sinhVien);
        }
    }
}
