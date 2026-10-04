package codeptit;

import java.util.Scanner;

public class J04007 {
    public static class NhanVien{
        private String mnv,ten,gtinh,ns,dchi,mst,nkhd;

        public NhanVien(String ten, String gtinh, String ns, String dchi, String mst, String nkhd){
            this.ten = ten;
            this.gtinh = gtinh;
            this.ns = ns;
            this.dchi = dchi;
            this.mst = mst;
            this.nkhd = nkhd;
            this.mnv = "00001";
        }

        @Override
        public String toString(){
            return mnv + " " + ten + " " + gtinh + " " + ns + " " + dchi + " " + mst + " " + nkhd;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        NhanVien a = new NhanVien(sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine(), sc.nextLine());
        System.out.println(a);
    }
}
