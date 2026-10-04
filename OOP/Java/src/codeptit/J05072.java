package codeptit;

import java.time.LocalTime;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.Scanner;

public class J05072 {
    public static class TinhThanh{
        private String ten;
        private int ma,gia;

        public TinhThanh(int x, String s, int y){
            ma = x;
            ten = s;
            gia = y;
        }

        public String getTen(){return ten;}
        public int getMa(){return ma;}
        public int getGia(){return gia;}

    }

    public static class CuocGoi{
        private String thueBaoDen,batDau,ketThuc,tinhThanh;
        private long time,giaCuoc;

        public CuocGoi(String s){
            String[] tok = s.trim().split("\\s+");
            thueBaoDen = tok[0];
            batDau = tok[1];
            ketThuc = tok[2];

            LocalTime start = LocalTime.parse(batDau);
            LocalTime end = LocalTime.parse(ketThuc);

            time = ChronoUnit.SECONDS.between(start,end);
            time /= 60;

            if(thueBaoDen.charAt(0) != '0'){
                tinhThanh = "Noi mang";
                time = (long)(Math.ceil((double)(time) / 3));
                giaCuoc = time * 800;
            } else{
                tinhThanh = "";
                giaCuoc = 0;
            }
        }

        public String getThueBaoDen(){return thueBaoDen;}
        public long getTime(){return time;}
        public String getTinhThanh(){return tinhThanh;}
        public long getGiaCuoc(){return giaCuoc;}

        public void setGiaCuoc(long x, long y){giaCuoc = x * y;}
        public void setTinhThanh(String s){tinhThanh = s;}

        public String toString(){
            return thueBaoDen + " " + tinhThanh + " " + time + " " + giaCuoc;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<TinhThanh> tinh = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            tinh.add(new TinhThanh(Integer.parseInt(sc.nextLine()),sc.nextLine(),Integer.parseInt(sc.nextLine())));
        }

        int m = Integer.parseInt(sc.nextLine());
        ArrayList<CuocGoi> goi = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            CuocGoi a = new CuocGoi(sc.nextLine());

            String tinhThanh = a.getTinhThanh();
            if(!tinhThanh.equals("Noi mang")){
                int tmp1 = Integer.parseInt(a.getThueBaoDen().substring(1,3));
                for (TinhThanh thanh : tinh) {
                    if(thanh.getMa() == tmp1){
                        a.setTinhThanh(thanh.getTen());
                        a.setGiaCuoc(a.getTime(),thanh.getGia());
                    }
                }
            }

            goi.add(a);
        }

        goi.sort((o1,o2)-> o2.giaCuoc > o1.giaCuoc ? 1 : -1);
        goi.forEach(System.out::println);
    }
}
