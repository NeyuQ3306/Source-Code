package codeptit;

import java.util.Scanner;

public class J04014 {
    public static class PhanSo{
        private long tu, mau;

        public PhanSo(long x, long y){
            tu = x;
            mau = y;
        }

        public long gcd(long a, long b){
            while(b != 0){
                long tmp = a%b;
                a = b;
                b = tmp;
            }
            return a;
        }

        public long lcm(long a, long b){
            return a / gcd(a,b) * b;
        }

        public void toiGian(){
            long uc = gcd(tu, mau);
            tu /= uc;
            mau /= uc;
        }

        public PhanSo tong(PhanSo a){
            long bc = lcm(mau, a.mau);
            PhanSo kq = new PhanSo(bc / mau * tu + bc / a.mau * a.tu, bc);
            return kq;
        }

        public PhanSo tich(PhanSo a){
            PhanSo kq = new PhanSo(tu * a.tu, mau * a.mau);
            kq.toiGian();

            return kq;
        }

        public String toString(){
            return tu + "/" + mau;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            PhanSo a = new PhanSo(sc.nextLong(), sc.nextLong());
            PhanSo b = new PhanSo(sc.nextLong(), sc.nextLong());

            PhanSo c = a.tong(b).tich(a.tong(b));
            c.toiGian();

            PhanSo d = a.tich(b).tich(c);
            d.toiGian();

            System.out.print(c + " ");
            System.out.println(d);
        }
    }
}
