package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

public class J05026 {
    public static class GiangVien{
        private String ten, boMon, maBoMon, maGV, lastName;
        private static int cnt = 0;

        public GiangVien(String s, String t){
            ten = s;
            String[] tokk = s.split("\\s+");
            lastName = tokk[tokk.length - 1];

            boMon = t;
            String[] tok = t.split("\\s+");
            maBoMon = "";
            for (String string : tok) {
                maBoMon += Character.toUpperCase(string.charAt(0));
            }

            ++cnt;
            maGV = String.format("GV%02d", cnt);
        }

        public String getBoMon(){return boMon;}
        public String getlastTen(){return lastName;}
        public String getMaGV(){return maGV;}

        public String toString(){
            return maGV + " " + ten + " " + maBoMon;
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

        int q = Integer.parseInt(sc.nextLine());
        while(q-- > 0){
            String s = sc.nextLine();
            String[] tok = s.split("\\s+");
            String tmp = "";

            for (String string : tok) {
                tmp += Character.toUpperCase(string.charAt(0));
            }

            System.out.println("DANH SACH GIANG VIEN BO MON " + tmp + ":");
            for (GiangVien giangVien : a) {
                if(giangVien.getBoMon().equals(s)){
                    System.out.println(giangVien);
                }
            }
        }
    }
}
