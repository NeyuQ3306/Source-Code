package learning.basic;

import java.util.Scanner;

public class InOut {
    public static void main(String[] args) {
        /*
            Cú pháp để nhập xuất trong Java: (Khá giống nhập xuất của C)
            1. In ra màn hình
            - Sử dụng cú pháp: System.out.println/printf/print(danh sách biến)
                println để khi in xong tự động xuống dòng
                print in xong thì ko xuống dòng
                printf dùng để in theo format - giống vào hàm printf trong C gồm đặc tả và biến

            - Chú ý nếu muốn in nhiều biến trên cùng 1 dòng thì dùng cú pháp:
                System.out.print(a + " " + b + " " + c)
            -> biến a,b,c có thể là kiểu số thực, số nguyên hay xâu đều được trình biên dịch tự động chuyển thành
            xâu và phép + là phép nối xâu

            - Cú pháp để in ra số thực với số chữ số phần thập phân xác định:
            VD: System.out.printf("%. xf %.yf", a, b) để in ra x chữ số phần thập phân của biến a và y chữ số thập
            phân của biến b


            2. Nhập từ bàn phím
            - Sử dụng đối tượng Scanner: Scanner sc = new Scanner(System.in)
            - Để nhập vào các biến thì phải dùng các hàm tương ứng:
            VD:
                int a = sc.nextInt()
                long b = sc.nextLong()
                float c = sc.nextFloat()

             - Chú ý với nhập vào biến kiểu char thì do hàm sc.next() nó sẽ đọc 1 từ còn sc.nextLine() sẽ đọc cả dòng
             mà ko có hàm nextChar() nên ta phải dùng cú pháp đọc vào 1 từ và lấy kí tự đầu tiên:
             VD: char c = sc.next().charAt(index = 0)

             - Hàm next() tương tự như hàm cin của C++ nếu có nhiều từ trên 1 dòng cách nhau bởi khoảng trắng thì sẽ
             đọc vào từ đầu tiên và ngừng, hoặc là đọc vào 1 số sẽ dừng khi gặp kí tự enter và sẽ lưu vào bộ nhớ đệm
                ! Giống lỗi khi dùng cin và getline trong C++ thì lệnh getline sẽ đọc kí tự enter ở trong bộ nhớ đệm
                ! Khắc phục bằng cách sau hàm next() thì xóa kí tự enter bằng nextLine() trước khi muốn nhập vào 1 xâu
                bằng nextLine()

             VD:
            Scanner sc = new Scanner(System.in);
            int a = sc.nextInt();
            sc.nextLine();

            String s = sc.nextLine();
            System.out.print(a + " " + s);

            - Nhập ko biết trước số lượng phần tử:
                ! sử dụng vòng lặp while và hàm sc.hasNext(): có chức năng kiểm tra xem trong luồng input vào có còn
                token hay ko nếu có trả về true và ngược lại trả về false
                ! VD:
                Scanner sc = new Scanner(System.in);
                int n = 0;
                while(sc.hasNext()){
                    n = sc.nextInt();
                    System.out.println(n);
               }
        */


    }
}
