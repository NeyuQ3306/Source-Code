package codeptit;

import java.util.Scanner;

public class J04019 {
    public static class Point{
        private double x, y;

        public Point(double x, double y){
            this.x = x;
            this.y = y;
        }

        public double getX(){return x;}
        public double getY(){return y;}

        public static Point nextPoint(Scanner sc){
            return new Point(sc.nextDouble(), sc.nextDouble());
        }

        public double distance(Point a){
            return Math.sqrt(Math.pow(a.getX() - x, 2) + Math.pow(a.getY() - y, 2));
        }
    }

    public static class Triangle{
        private Point a,b,c;

        public Triangle(Point a, Point b, Point c){
            this.a = a;
            this.b = b;
            this.c = c;
        }

        public boolean valid(){
            double d1 = a.distance(b), d2 = a.distance(c), d3 = b.distance(c);
            if(d1 + d2 > d3 && d1 + d3 > d2  && d2 + d3 > d1) return true;
            else return false;
        }

        public String getPerimeter(){
            double d1 = a.distance(b), d2 = a.distance(c), d3 = b.distance(c);
            return String.format("%.3f", d1 + d2 + d3);
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- >0){
            Triangle a = new Triangle(Point.nextPoint(sc), Point.nextPoint(sc), Point.nextPoint(sc));
            if(!a.valid()){
                System.out.println("INVALID");
            } else{
                System.out.println(a.getPerimeter());
            }
        }
    }
}
