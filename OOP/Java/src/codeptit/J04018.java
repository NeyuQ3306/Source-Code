package codeptit;

import java.util.Scanner;

public class J04018 {
    public static class SoPhuc{
        private int real, image;

        public SoPhuc(int x, int y){
            real = x;
            image = y;
        }

        public int getReal(){ return real;}
        public int getImage(){ return image;}

        public SoPhuc add(SoPhuc a){
            return new SoPhuc(real + a.getReal(), image + a.getImage());
        }

        public SoPhuc mul(SoPhuc a){
           return new SoPhuc(real*a.getReal() - image*a.getImage(), real*a.getImage() + image*a.getReal());
        }

        @Override
        public String toString(){
            if(image < 0){
                return real + " - " + (-image) + "i";
            } else{
                return real + " + " + image + "i";
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-->0){
            SoPhuc a = new SoPhuc(sc.nextInt(), sc.nextInt());
            SoPhuc b = new SoPhuc(sc.nextInt(), sc.nextInt());

            System.out.println((a.add(b)).mul(a) + ", " + (a.add(b)).mul(a.add(b)));
        }
    }
}
