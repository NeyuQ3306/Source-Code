package codeptit;

import java.util.Scanner;

public class J04003 {
    public static long gcd(long a, long b){
        while(b != 0){
            long tmp = a%b;
            a = b;
            b = tmp;
        }
        return a;
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
            PhanSo b = new PhanSo(x/uc, y/uc);
            return b;
        }

    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PhanSo a = new PhanSo(sc.nextLong(), sc.nextLong());

        PhanSo tgian = a.toigian();
        System.out.println(tgian.getX() + "/" + tgian.getY());
    }
}
