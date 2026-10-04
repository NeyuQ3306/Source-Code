package codeptit;

import java.util.Scanner;

public class J04009 {
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

        public static String dienTich(double ab, double ac, double bc) {
            // Phải dùng 1 / 4f để khớp với đáp án mẫu CodePTIT vẫn sai 
            double s = 1 / 4f * Math.sqrt((ab + ac + bc) * (ab + ac - bc) * (ab + bc - ac) * (ac + bc - ab));
            return String.format("%.2f", s);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            Point a1 = new Point(sc.nextDouble(), sc.nextDouble());
            Point b1 = new Point(sc.nextDouble(), sc.nextDouble());
            Point c1 = new Point(sc.nextDouble(), sc.nextDouble());

            double a = a1.distance(b1), b = a1.distance(c1), c = b1.distance(c1);

            if (a + b > c && b + c > a && a + c > b) {
                // chỗ tính S này phải như này mới AC ? luôn codePtit
                double S = 1 / 4f * Math.sqrt((a + b + c) * (a + b - c) * (a - b + c) * (-a + b + c));
                System.out.printf("%.2f\n", S);
            } else {
                System.out.println("INVALID");
            }
        }
    }
}
