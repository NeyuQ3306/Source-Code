package codeptit;

import java.util.*;

public class J05047 {
    static Map<String,Integer> mp = new HashMap<>();

    public static class MatHang{
        private String mmh,ten;
        private long sl,gia,ckhau,thanhTien;
        private static int cnt = 0;

        public MatHang(String t, long x, long y){
            ten = t;
            sl = x;
            gia = y;

            ++cnt;
            String[] tok = t.trim().toUpperCase().split("\\s+");
            String init = tok[0].charAt(0) + "" + tok[1].charAt(0) + "";

            int count = mp.getOrDefault(init, 0) + 1;
            mp.put(init, count);
            mmh = init + String.format("%02d", count);

//          Nếu init chưa có trong mp thì khởi tạo = 1, nếu đã có thì +1 và trả về fre mới
//          int count = mp.merge(init, 1, Integer::sum);
//          mmh = init + String.format("%02d", count);

            long tmp = gia * sl;
            if(sl > 10){
                ckhau = tmp * 5 / 100;
            } else if(sl >= 8){
                ckhau = tmp * 2 / 100;
            } else if(sl >= 5){
                ckhau = tmp * 1 / 100;
            } else{
                ckhau = 0;
            }

            thanhTien = tmp - ckhau;
        }

        public long getCkhau(){return ckhau;}

        public String toString(){
            return mmh + " " + ten + " " + ckhau + " " + thanhTien;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<MatHang> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new MatHang(sc.nextLine(),Long.parseLong(sc.nextLine()),Long.parseLong(sc.nextLine())));
        }

        Collections.sort(a, new Comparator<MatHang>() {
            @Override
            public int compare(MatHang o1, MatHang o2) {
                return o2.getCkhau() > o1.getCkhau() ? 1 : -1;
            }
        });

        for (MatHang matHang : a) {
            System.out.println(matHang);
        }
    }
}
