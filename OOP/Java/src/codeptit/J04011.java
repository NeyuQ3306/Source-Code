package codeptit;

import java.util.Scanner;

public class J04011 {
    public static class Point3D{
        private int x,y,z;

        public Point3D(int x, int y, int z){
            this.x = x;
            this.y = y;
            this.z = z;
        }

        // tính chất của 4 điểm đồng phẳng là tích hỗn tạp = 0
        // Cho 4 điểm a,b,c,d đồng phẳng khi và chỉ khi [ab,ac].ad = 0
        // [ab,ac] là tích có hướng còn . ad là tích vô hướng
        public static boolean check(Point3D a, Point3D b, Point3D c, Point3D d){
            Point3D ab = new Point3D(b.x - a.x, b.y - a.y, b.z - a.z);
            Point3D ac = new Point3D(c.x - a.x, c.y - a.y, c.z - a.z);
            Point3D ad = new Point3D(d.x - a.x, d.y - a.y, d.z - a.z);

            /* Công thức tính tích có hướng: Biểu diễn toạ độ 2 cạnh ở dạng ma trận cỡ 2x3
            VD: ab = x y z
                ac = u v l
            [ab,ac] = (yl - vz, -xl + uz, xv - uy)
            -> Tính toạ độ nào thì che cột đấy và tính định thức phần còn lại
            -> Trừ tung độ phải đổi chiều
            */

            // CT tích vô hướng a.b = ax*bx + ay*by + az*bz
            Point3D tichCoHuong = new Point3D(ab.y*ac.z - ab.z*ac.y, ab.z*ac.x - ab.x*ac.z, ab.x*ac.y - ab.y*ac.x);
            int s = tichCoHuong.x*ad.x + tichCoHuong.y*ad.y + tichCoHuong.z*ad.z;

            return s == 0;
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            Point3D p1 = new Point3D(sc.nextInt(),sc.nextInt(),sc.nextInt());
            Point3D p2 = new Point3D(sc.nextInt(),sc.nextInt(),sc.nextInt());
            Point3D p3 = new Point3D(sc.nextInt(),sc.nextInt(),sc.nextInt());
            Point3D p4 = new Point3D(sc.nextInt(),sc.nextInt(),sc.nextInt());

            if(Point3D.check(p1,p2,p3,p4)){
                System.out.println("YES");
            } else{
                System.out.println("NO");
            }
        }
    }
}
