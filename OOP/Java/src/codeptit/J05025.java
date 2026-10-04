package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05025 {
    public static class GiangVien{
        private String ten, boMon, maGV, lastName;
        private static int cnt = 0;

        public GiangVien(String s, String t){
            ten = s;
            String[] tokk = s.split("\\s+");
            lastName = tokk[tokk.length - 1];

            String[] tok = t.split("\\s+");
            boMon = "";
            for (String string : tok) {
                boMon += Character.toUpperCase(string.charAt(0));
            }

            ++cnt;
            maGV = String.format("GV%02d", cnt);
        }

        public String getlastTen(){return lastName;}
        public String getMaGV(){return maGV;}

        public String toString(){
            return maGV + " " + ten + " " + boMon;
         }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<GiangVien> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new GiangVien(sc.nextLine().trim(), sc.nextLine().trim()));
        }

        Collections.sort(a, new Comparator<GiangVien>() {
            @Override
            public int compare(GiangVien o1, GiangVien o2) {
                if (o1.getlastTen().equals(o2.getlastTen())){
                    return o1.getMaGV().compareTo(o2.getMaGV());
                } else{
                    return o1.getlastTen().compareTo(o2.getlastTen());
                }
            }
        });

        for (GiangVien giangVien : a) {
            System.out.println(giangVien);
        }
    }
}
