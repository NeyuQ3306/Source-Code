package codeptit;


import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05010 {
    public static class MatHang{
        private String ten,loai;
        private double mua,ban;
        private int stt;
        private static int cnt = 0;

        public MatHang(String ten, String loai, double mua, double ban){
            this.ten = ten;
            this.loai = loai;
            this.mua = mua;
            this.ban = ban;

            ++cnt;
            this.stt = cnt;
        }

        public double getLoiNhuan(){
            return ban - mua;
        }

        public int getStt(){return stt;}

        public String toString(){
            return stt + " " + ten + " " + loai + " " + String.format("%.2f", ban - mua);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<MatHang> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            MatHang a = new MatHang(sc.nextLine(), sc.nextLine(), Double.parseDouble(sc.nextLine()), Double.parseDouble(sc.nextLine()));
            list.add(a);
        }

        Collections.sort(list, new Comparator<MatHang>(){
            @Override
            public int compare(MatHang a, MatHang b){
                if(a.getLoiNhuan() != b.getLoiNhuan()){
                    return Double.compare(b.getLoiNhuan(),a.getLoiNhuan());
                } else{
                    return a.getStt() - b.getStt();
                }
            }
        });

        for (MatHang matHang : list) {
            System.out.println(matHang);
        }
    }
}
