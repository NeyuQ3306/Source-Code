package learning.control;

public class Function {
        /*
        1. Hàm toán học có sẵn trong class Math
        - Cú pháp: Math.function_name(parameter)
        - Cũng có các hàm quen thuộc như min, max, sqrt, cbrt, ceil, floor, round, abs, pow, ....
        - Tuy nhiên, có 1 vấn đề cần chú ý khi sử dụng các hàm khai căn, làm tròn sẽ trả về kiểu số thực nên cần ép
        kiểu sang số nguyên nếu cần
        - Còn hàm pow nếu số trả về quá lớn thì sẽ in ra ở dạng khoa học nên muốn in ra ở kiểu số long thì phải ép
        kiểu trước
        VD:
        System.out.println(Math.pow(2,34));
        System.out.println((long)Math.pow(2,34));

        - Một số kiểu ít dùng khác như DecimalFormat thì phải import thêm thư viện java.text.DecimalFormat
        VD:
        import java.text.DecimalFormat
        double x = Math.pow(2,34);
        DecimalFormat df = new DecimalFormat("#");
        System.out.println(df.format(x));

        - Hoặc là vì hàm pow trả về kiểu số thực double nên có thể in ra theo format của printf
        VD:
        System.out.printf("%.0f\n", Math.pow(2, 34));
        -> Do kiểu double có thể sẽ ko lưu được nhiều chữ số cuối ko chính xác nếu tính toán số nguyên rất lớn ta
        phải dùng thư viện BigInterger

        VD:
        import java.math.BigInteger;

        BigInteger x = BigInteger.valueOf(2).pow(100);
        System.out.println(x);

        2. Viết hàm chức năng trong Java
        - Hàm thực hiện các chức năng phục vụ cho quá trình code, hàm static là hàm ko cần khai báo đối tượng của
        class chứa nó để thực thi như main, Math, Scanner, ...
        - Cú pháp: public static returnType functionName (parameter){ code }
        - Khác với C++ là hàm trong Java ko có tham chiếu chỉ có tham trị: gán giá trị đối số cho tham số hình thức
        của hàm và thực thi hàm trên tham số hình thức, thay vào đó nếu hàm có tham số là 1 biến tham chiếu thì có thể
        thay đổi giá trị mà biến tham chiếu chính thức quản lí
        - Nạp chồng hàm trong Java: có nhiều hàm cùng tên, cùng chức năng nhưng khác về tham số và kiểu dữ liệu thì
        khi gọi hàm sẽ phụ thuộc vào kiểu dữ liệu đối số truyền vào để thực thi hàm tương ứng

        VD:
        public static int sum(int a, int b){
            return a + b;
        }

        public static float sum(float a, float b){
            return a + b;
        }

        public static void main(String[] args){
            System.out.println(sum(20, 30));
            System.out.printf("%.2f", sum(3.14F, 2.37F));
        }

        */
    
}
