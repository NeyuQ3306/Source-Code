package codeptit;
import java.util.ArrayList;
import java.util.Scanner;

/*
Bài này dễ bị Wa ở đoạn làm tròn phụ trội tới số nguyên gần nhất
Dùng:
Lỗi sai số dấu phẩy động (Floating point precision): Do cách lưu trữ số thực của Java
0.35 sẽ ko chính xác là 0.35 mà là 0.34999999999999777 nên có khả năng sai số
phuTroi = Math.round((double) tien * 0.35); -> Wa
phuTroi = (tien * 35 + 50) / 100; -> Ac (làm tròn số theo lý thuyết)
phuTroi = Math.round((double) this.tien * 35.0 / 100.0); -> Ac
 */

public class J05050 {
    public static class KhachHang{
        private String mkh,loai;
        private int csc,csm;
        private long hso,tien,total,phuTroi;
        private static int cnt = 0;

        public KhachHang(String s, int x, int y){
            loai = s;
            csc = x;
            csm = y;

            ++cnt;
            mkh = String.format("KH%02d",cnt);

            if(s.equals("KD")){
                hso = 3;
            } else if(s.equals("NN")){
                hso = 5;
            } else if(s.equals("TT")){
                hso = 4;
            } else{
                hso = 2;
            }

            tien = (csm - csc) * hso * 550;
            int tmp = csm - csc;

            if(tmp > 100){
                phuTroi = tien;
            } else if(tmp >= 50){
                phuTroi = Math.round((double) this.tien * 35.0 / 100.0);
            } else{
                phuTroi = 0;
            }

            total = tien + phuTroi;
        }

        public String toString(){
            return  mkh + " " + hso + " " + tien + " " + phuTroi + " " + total;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());

        ArrayList<KhachHang> a =  new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            a.add(new KhachHang(sc.nextLine().trim(),Integer.parseInt(sc.nextLine().trim()),Integer.parseInt(sc.nextLine().trim())));
        }
        for (KhachHang khachHang : a) {
            System.out.println(khachHang);
        }
    }
}
