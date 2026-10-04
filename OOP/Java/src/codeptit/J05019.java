package codeptit;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/*
Bài này chú ý công thức tính là tổng lượng mưa / tổng tgian
 */

public class J05019 {
    public static class LuongMua{
        private String diaDiem,stt;
        private double luongMua, tongThoiGian;
        private static int cnt = 0;

        public LuongMua(String diaDiem, String bd, String kthuc, double tb){
            this.diaDiem = diaDiem;
            double gio = Integer.parseInt(kthuc.substring(0,2)) - Integer.parseInt(bd.substring(0,2));
            double phut = Integer.parseInt(kthuc.substring(3)) - Integer.parseInt(bd.substring(3));

            if(phut < 0){
                phut += 60f;
                gio -= 1f;
            }

            this.tongThoiGian = gio + phut/60f;
            this.luongMua = tb;

            ++cnt;
            this.stt = String.format("T%02d",cnt);
        }

        public void setLuongMua(double a){
            this.luongMua = a;
        }
        public void setTongThoiGian(double a){
            this.tongThoiGian = a;
        }
        public String getDiaDiem(){return diaDiem;}
        public double getLuongMua(){return luongMua;}
        public double getTongThoiGian(){return tongThoiGian;}

        public String toString(){
            return stt + " " + diaDiem + " " + String.format("%.2f",luongMua/tongThoiGian);
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        Set<String> st = new HashSet<>();
        ArrayList<LuongMua> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String diaDiem = sc.nextLine().trim();
            String bd = sc.nextLine().trim(), kt = sc.nextLine().trim();
            double tb = Double.parseDouble(sc.nextLine().trim());

            if(st.contains(diaDiem)){
                LuongMua tmp = new LuongMua(diaDiem,bd,kt,tb);
                double time = tmp.getTongThoiGian();

                for (LuongMua luongMua : list) {
                    if(luongMua.getDiaDiem().equals(diaDiem)){
                        luongMua.setLuongMua(luongMua.getLuongMua() + tb);
                        luongMua.setTongThoiGian(luongMua.getTongThoiGian() + time);
                        break;
                    }
                }
            } else{
                list.add(new LuongMua(diaDiem,bd,kt,tb));
                st.add(diaDiem);
            }
        }

        for (LuongMua luongMua : list) {
            System.out.println(luongMua);
        }
    }
}
