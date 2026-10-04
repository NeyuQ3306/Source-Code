package codeptit;

import java.util.Scanner;

public class J05006 {
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

        public String toString(){
            return mnv + " " + ten + " " + gtinh + " " + ns + " " + dchi + " " + mst + " " + nkhd;
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();

        while(n-- > 0){
            NhanVien a = new NhanVien(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine());
            System.out.println(a);
        }
    }
}
