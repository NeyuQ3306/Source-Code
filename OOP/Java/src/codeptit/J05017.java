package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/*
- Bài này chú ý điều kiện so sánh cmp phải là giữa 2 giá trị double rồi khi in mới ép sang số nguyên nếu ko sẽ bị wa
- Chú ý, các thuộc tính dẫn xuất của class thì tính toán luôn trong hàm khởi tạo
- Công thức tính số tiền điện phải tính từng từng bậc và phụ phí thì theo tổng số điện
 */

public class J05017 {
    public static class KhachHang{
        private String mkh,ten;
        private long csc,csm;
        private double tongTien;
        private static int cnt = 0;

        public KhachHang(String ten, long csc, long csm){
            this.ten = ten;
            this.csc = csc;
            this.csm = csm;

            ++cnt;
            this.mkh = String.format("KH%02d",cnt);

            long cs = csm - csc;
            if(cs < 51){
                this.tongTien = cs * 100;
                this.tongTien += this.tongTien * 2 / 100;
            }
            else if(cs < 101){
                this.tongTien = 50 * 100 + (cs - 50) * 150;
                this.tongTien += this.tongTien * 3 / 100;
            }
            else{
                this.tongTien = 50 * 100 + 50 * 150 + (cs - 100) * 200;
                this.tongTien += tongTien * 5 / 100;
            }
        }

        public double getTongTien(){return tongTien;}

        public String toString(){
            return mkh + " " + ten + " " + (long)(Math.round(tongTien));
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<KhachHang> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(new KhachHang(sc.nextLine().trim(), Long.parseLong(sc.nextLine().trim()), Long.parseLong(sc.nextLine().trim())));
        }

        Collections.sort(list, new Comparator<KhachHang>() {
            @Override
            public int compare(KhachHang o1, KhachHang o2) {
                return Double.compare(o2.getTongTien(), o1.getTongTien());
            }
        });

        for (KhachHang khachHang : list) {
            System.out.println(khachHang);
        }
    }
}
