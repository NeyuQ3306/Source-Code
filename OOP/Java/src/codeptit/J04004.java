package codeptit;

import java.util.Scanner;

public class J04004 {
    public static long gcd(long a, long b){
        while(b != 0){
            long tmp = a%b;
            a = b;
            b = tmp;
        }
        return a;
    }

    public static long lcm(long a, long b){
        return a/gcd(a,b) * b;
    }

    public static class PhanSo{
        private long x,y;

        public PhanSo(long x, long y){
            this.x = x;
            this.y = y;
        }

        public long getX(){
            return x;
        }

        public long getY(){
            return y;
        }

        public PhanSo toigian(){
            long uc = gcd(x,y);
            return new PhanSo(x/uc, y/uc);
        }

        public PhanSo tong(PhanSo a){
            long bc = lcm(y, a.getY());
            return new PhanSo(bc/y * x + bc/a.y * a.x, bc).toigian();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PhanSo a = new PhanSo(sc.nextLong(), sc.nextLong());
        PhanSo b = new PhanSo(sc.nextLong(), sc.nextLong());

        a = a.toigian();
        b = b.toigian();
        
        PhanSo c = a.tong(b);
        System.out.println(c.getX() + "/" + c.getY());
    }
}
