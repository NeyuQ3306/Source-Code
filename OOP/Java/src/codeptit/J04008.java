package codeptit;

import java.util.Scanner;

public class J04008 {
    public static class Point{
        private double x,y;

        public Point(double x, double y){
            this.x = x;
            this.y = y;
        }

        public double distance(Point a){
            return Math.sqrt(Math.pow(a.x - x, 2) + Math.pow(a.y - y, 2));
        }

        public static String chuVi(Point a, Point b, Point c){
            return String.format("%.3f", a.distance(b) + a.distance(c) + b.distance(c)) ;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            Point a = new Point(sc.nextDouble(), sc.nextDouble());
            Point b = new Point(sc.nextDouble(), sc.nextDouble());
            Point c = new Point(sc.nextDouble(), sc.nextDouble());

            double ab = a.distance(b), ac = a.distance(c), bc = b.distance(c);

            if(Double.compare(ab+ac, bc) <= 0
            || Double.compare(ab+bc, ac) <= 0
            || Double.compare(bc+ac, ab) <= 0){
                System.out.println("INVALID");
            } else{
                System.out.println(Point.chuVi(a,b,c));
            }
        }
    }
}
