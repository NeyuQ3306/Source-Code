package codeptit;

import java.util.*;

public class J05054 {
    public static class HocSinh{
        private String ten,mhs,xepLoai;
        private double dtb;
        private int xepHang,stt;
        private static int cnt = 0;

        public HocSinh(String s, double t){
            ten = s;
            dtb = t;

            ++cnt;
            mhs = String.format("HS%02d",cnt);
            stt = cnt;

            if(dtb >= 9){
                xepLoai = "Gioi";
            }else if(dtb >= 7){
                xepLoai = "Kha";
            }else if(dtb >= 5){
                xepLoai = "Trung Binh";
            }else{
                xepLoai = "Yeu";
            }

            xepHang = 0;
        }

        public double getDtb(){return dtb;}
        public int getStt(){return stt;}
        public int getXepHang(){return xepHang;}
        public void setXepHang(int x){
            xepHang = x;
        }

        public String toString(){
            return mhs + " " + ten + " " + String.format("%.1f",dtb) + " " + xepLoai + " " + xepHang;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        List<HocSinh> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new HocSinh(sc.nextLine(), Double.parseDouble(sc.nextLine())));
        }

        // sort theo dtb
        a.sort((o1,o2) -> Double.compare(o2.getDtb(),o1.getDtb()));
        a.get(0).setXepHang(1);

        for (int i = 1; i < n; i++) {
            int tmp = a.get(i-1).getXepHang();
            if(Double.compare(a.get(i).getDtb(),a.get(i-1).getDtb()) == 0){
                a.get(i).setXepHang(tmp);
            } else{
                a.get(i).setXepHang(i+1);
            }
        }

        // sort theo stt để in theo thứ tự nhập
        a.sort((o1,o2) -> o1.getStt() -  o2.getStt());
        a.forEach(System.out::println);
    }
}
