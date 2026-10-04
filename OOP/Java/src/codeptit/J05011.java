package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05011 {
    public static class KhachHang{
        private String tk,ten,gioDen,gioDi;
        private int tongGio, tongPhut;

        public KhachHang(String tk, String ten, String gioDen, String gioDi){
            this.gioDen = gioDen;
            this.gioDi = gioDi;
            this.ten = ten;
            this.tk = tk;

            String[] tach1 = gioDen.split(":");
            String[] tach2 = gioDi.split(":");

            int carry = 0;
            int phut = Integer.parseInt(tach2[1]) - Integer.parseInt(tach1[1]);
            int gio = Integer.parseInt(tach2[0]) - Integer.parseInt(tach1[0]);

            if(phut < 0){
                phut += 60;
                carry = 1;
            }

            gio = gio - carry;

            this.tongGio = gio;
            this.tongPhut = phut;
        }

        public int getTongGio(){return tongGio;}
        public int getTongPhut(){return tongPhut;}

        public String toString(){
            return tk + " " + ten + " " + tongGio + " gio " + tongPhut + " phut";
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<KhachHang> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            KhachHang a = new KhachHang(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine());
            list.add(a);
        }

        Collections.sort(list, new Comparator<KhachHang>(){
            @Override
            public int compare(KhachHang a, KhachHang b){
                if(a.getTongGio() != b.getTongGio()){
                    return b.getTongGio() - a.getTongGio();
                } else{
                    return b.getTongPhut() - a.getTongPhut();
                }
            }
        });

        for (KhachHang khachHang : list) {
            System.out.println(khachHang);
        }
    }
}
