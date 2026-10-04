package codeptit;

import java.util.Scanner;

public class J04010 {
    public static class Point{
        private double x,y;

        public Point(double x, double y){
            this.x = x;
            this.y = y;
        }

        public double distance(Point a){
            return Math.sqrt(Math.pow(a.x - x, 2) + Math.pow(a.y - y, 2));
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            Point a = new Point(sc.nextDouble(), sc.nextDouble());
            Point b = new Point(sc.nextDouble(), sc.nextDouble());
            Point c = new Point(sc.nextDouble(), sc.nextDouble());

            double d1 = a.distance(b), d2 = a.distance(c), d3 = b.distance(c);
            if(d1 + d2 > d3 && d1 + d3 > d2 && d2 + d3 > d1){
                double s = 1 / 4f * Math.sqrt((d1 + d2 + d3) * (d1 + d2 - d3) * (d1 - d2 + d3) * (-d1 + d2 + d3));
//                System.out.println(s);
                double r = d1 / (4*s) * d2 * d3;
//                System.out.println(d1 + " " + d2 + " " + d3);
//                System.out.println(r);
                double S = Math.PI*r*r;
                System.out.printf("%.3f\n", S);
            } else{
                System.out.println("INVALID");
            }
        }
    }
}

