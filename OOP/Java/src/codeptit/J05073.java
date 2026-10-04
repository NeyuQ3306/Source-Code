package codeptit;

import java.util.Scanner;

/*
Bài này cần chú ý 2 đoạn:
- Giảm 5% thuế khi đơn hàng có chừng từ đẩy đủ: last = 'C'
    Ko phải là từ 29% - > 24% mà là chỉ tính 95% của 29%
- Làm tròn tới chữ số thứ 2 phần thập phân:
    Công thức là: Math.round((double)(value*100)) / 100f;
    -> Phải là 100f vì math.round() trả về long mà long/long thì có thể làm sai đáp án dạng số thực
 */

public class J05073 {
    public static class DonHang{
        private String ma;
        private double donGia,soLuong,thue,phiVc,total,gia;

        public DonHang(String s){
            String[] tok = s.trim().split("\\s+");
            ma = tok[0];
            donGia = Double.parseDouble(tok[1]);
            soLuong = Double.parseDouble(tok[2]);

            double cost = donGia * soLuong;
            char first = ma.charAt(0);
            char last = ma.charAt(3);

            if(last == 'K'){
                if(first == 'T'){
                    thue = cost * 29 / 100;
                    phiVc = cost * 4 / 100;
                } else if(first == 'C'){
                    thue = cost * 10 / 100;
                    phiVc = cost * 3 / 100;
                } else if(first == 'D'){
                    thue = cost * 8 / 100;
                    phiVc = cost * 25 / 1000;
                } else {
                    thue = cost * 2 / 100;
                    phiVc = cost * 5 / 1000;
                }
            } else{
                if(first == 'T'){
                    thue = cost * 29 / 100 * 95 / 100;
                    phiVc = cost * 4 / 100;
                } else if(first == 'C'){
                    thue = cost * 10 / 100 * 95 / 100;
                    phiVc = cost * 3 / 100;
                } else if(first == 'D'){
                    thue = cost * 8 / 100 * 95 / 100;
                    phiVc = cost * 25 / 1000;
                } else {
                    thue = cost * 2 / 100 * 95 / 100;
                    phiVc = cost * 5 / 1000;
                }
            }

            total = cost + thue + phiVc;
            total += total * 20 / 100;
            gia = total / soLuong;
            gia = Math.round((double)(gia) * 100) / 100.0;
        }

        public String toString(){
            return ma + " " + String.format("%.2f",gia);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < n; i++) {
            DonHang a = new DonHang(sc.nextLine());
            System.out.println(a);
        }
    }
}
