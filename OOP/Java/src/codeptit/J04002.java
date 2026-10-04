package codeptit;

import java.util.Scanner;

public class J04002 {
    public static class Rectange{
        private int w,h;
        private String color;

        public Rectange(int a, int b, String s){
            this.w = a;
            this.h = b;
            this.color = s;
        }

        public String getColor(){
            return color;
        }

        public long chuVi(){
            return (w+h) * 2;
        }

        public long dienTich(){
            return w * h;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt();
        String tmp = sc.next().toLowerCase();

        String color = Character.toUpperCase(tmp.charAt(0)) + tmp.substring(1);
        if(a > 0 && b > 0){
            Rectange X = new Rectange(a,b,color);
            System.out.println(X.chuVi() + " " + X.dienTich() + " " + X.getColor());
        } else{
            System.out.println("INVALID");
        }
    }
}
