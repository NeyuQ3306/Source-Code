package codeptit;

import java.nio.channels.Pipe;
import java.util.ArrayList;
import java.util.Scanner;

/*
Công thức Shoelace: Tính diện tích đa giác lồi N đỉnh trong toạ độ Oxy
- Điều kiện: Cần biết toạ độ N đỉnh và liệt kê theo thứ tự dọc theo chu vi
đa giác: chiều kim đồng hồ/ngược chiều kim đồng hồ

- Công thức: Quy ước đỉnh thứ N+1 chính là đỉnh 1
    S =  1/2|Tổng sigma(XiYi+1 - Xi+1Yi) 1->N|

 */

public class J05008 {
    public static class Point{
        private int x,y;
        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }

        public int getX(){return x;}
        public int getY(){return y;}

        public String toString(){
            return x + " " + y;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-->0){
            int n = sc.nextInt();
            ArrayList<Point> a = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                Point tmp = new Point(sc.nextInt(), sc.nextInt());
                a.add(tmp);
            }

            a.add(a.get(0));

            double s = 0;
            for (int i = 0; i < n; i++) {
                Point A = a.get(i);
                Point B = a.get(i+1);

                s += A.getX()*B.getY() - B.getX()*A.getY();
            }

            System.out.printf("%.3f\n", s * 1/2f);
        }
    }
}
