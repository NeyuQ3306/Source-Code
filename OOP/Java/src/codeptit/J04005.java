package codeptit;

import java.util.Scanner;

public class J04005 {
    public static class SinhVien{
        private String name, date;
        private double m1,m2,m3;

        public SinhVien(String ten, String ns, double m1, double m2, double m3){
            this.name = ten;
            this.date = ns;
            this.m1 = m1;
            this.m2 = m2;
            this.m3 = m3;
        }

        public String getName(){
            return name;
        }

        public String getDate(){
            return date;
        }

        public double getM1(){
            return m1;
        }

        public double getM2(){
            return m2;
        }

        public double getM3(){
            return m3;
        }

        public void displayInfo(){
            System.out.print(name + " " + date + " ");
            System.out.printf("%.1f\n", m1 + m2 + m3);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String ten = sc.nextLine(), ns = sc.nextLine();

        // input là 4.5 10.0 nên gọi nextDouble() định dạng số thực dùng dấu , nên bị lỗi
        // double m1 = sc.nextDouble(), m2 = sc.nextDouble(), m3 = sc.nextDouble();
        // fix đọc vào string rồi mới convert sang double

        double m1 = Double.parseDouble(sc.nextLine()), m2 = Double.parseDouble(sc.nextLine());
        double m3 = Double.parseDouble(sc.nextLine());

        // String.format("%0xd", a) để in 1 string theo định dạng biết trước: x kí tự nếu thiếu thì chèn 0
        // lên đầu String.format("%03d", a) a = 21 -> output: 021
        SinhVien a = new SinhVien(ten, ns, m1, m2, m3);
        a.displayInfo();
    }
}
