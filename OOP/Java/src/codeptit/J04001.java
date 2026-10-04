package codeptit;

import java.util.Scanner;

public class J04001 {
    public static class Point{
        private double x,y;

        public Point(double x, double y){
            this.x = x;
            this.y = y;
        }

        public double getX(){
            return x;
        }

        public double getY(){
            return y;
        }

        public double dis(Point a){
            return Math.sqrt(Math.pow(this.x - a.getX(), 2) + Math.pow(this.y - a.getY(), 2));
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            Point a = new Point(sc.nextDouble(), sc.nextDouble());
            Point b = new Point(sc.nextDouble(), sc.nextDouble());

            System.out.printf("%.4f", a.dis(b));
            System.out.println();
        }
    }
}
