package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05007 {
    public static class NhanVien{
        private String mnv,ten,gtinh,ns,dchi,mst,nkhd;
        private static int cnt = 0;

        public NhanVien(String ten, String gtinh, String ns, String dchi, String mst, String nkhd){
            this.ten = ten;
            this.gtinh = gtinh;
            this.ns = ns;
            this.dchi = dchi;
            this.mst = mst;
            this.nkhd = nkhd;

            ++cnt;
            this.mnv = String.format("%05d",cnt);
        }

        public String getDob(){
            String[] tok = ns.split("/");
            return tok[2] + tok[1] + tok[0];
        }

        public String getMnv(){
            return mnv;
        }

        public String toString(){
            return mnv + " " + ten + " " + gtinh + " " + ns + " " + dchi + " " + mst + " " + nkhd;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        ArrayList<NhanVien> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            NhanVien b = new NhanVien(sc.nextLine(),sc.nextLine(),sc.nextLine(),sc.nextLine(),sc.nextLine(),sc.nextLine());
            a.add(b);
        }

        Collections.sort(a, new Comparator<NhanVien>() {
            @Override
            public int compare(NhanVien o1, NhanVien o2) {
               if(o2.getDob() != o1.getDob()){
                   return o1.getDob().compareTo(o2.getDob());
               } else{
                   return o1.getMnv().compareTo(o2.getMnv());
               }
            }
        });

        for (NhanVien nhanVien : a) {
            System.out.println(nhanVien);
        }

    }
}
