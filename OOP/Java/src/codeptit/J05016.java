package codeptit;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05016 {
    public static class KhachHang{
        private String mkh,ten,soPhong,ngayNhan,ngayTra,phatSinh;
        private int totalDay, totalMoney;
        private static int cnt = 0;

        public KhachHang(String ten, String phong, String nhan, String tra, String them){
            this.ten = ten;
            this.soPhong = phong;
            this.ngayNhan = nhan;
            this.ngayTra = tra;
            this.phatSinh = them;

            ++cnt;
            this.mkh = String.format("KH%02d",cnt);

            DateTimeFormatter fomat = DateTimeFormatter.ofPattern("dd/MM/yyyy");
            LocalDate den = LocalDate.parse(nhan,fomat), di = LocalDate.parse(tra,fomat);

            this.totalDay = Math.toIntExact(ChronoUnit.DAYS.between(den, di)) + 1;
            if(phong.charAt(0) == '1') this.totalMoney = totalDay * 25;
            else if(phong.charAt(0) == '2') this.totalMoney = totalDay * 34;
            else if(phong.charAt(0) == '3') this.totalMoney = totalDay * 50;
            else this.totalMoney = totalDay * 80;

            this.totalMoney += Integer.parseInt(them);
        }

        public int getTotalMoney(){return totalMoney;}

        public String toString(){
            return mkh + " " + ten + " " + soPhong + " " + totalDay + " " + totalMoney;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<KhachHang> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            // ko dùng .trim() sẽ bị rte -> cẩn thận thì bài nào cũng dùng luôn lúc đọc input
            list.add(new KhachHang(sc.nextLine().trim(),sc.nextLine().trim(),sc.nextLine().trim(),sc.nextLine().trim(),sc.nextLine().trim()));
        }

        Collections.sort(list, new Comparator<KhachHang>() {
            @Override
            public int compare(KhachHang o1, KhachHang o2) {
                return o2.getTotalMoney() - o1.getTotalMoney();
            }
        });

        for (KhachHang khachHang : list) {
            System.out.println(khachHang);
        }
    }
}
