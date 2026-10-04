package learning.basic;

public class DataType {
    public static void main(String[] args) {
        /*
            Các kiểu dữ liệu trong Java cũng tương tự như C++ và cũng có kích cỡ tương đương
            1. Kiểu dữ liệu số nguyên
            - byte: 1byte
            - short: 2byte
            - int: 4byte
            - long: 8byte

            2. Kiểu dữ liệu số thực
            - float: 4byte
            - double: 8byte

            3. Kiểu dữ liệu kí tự và đúng sai
            - char: 2byte
                ! char trong Java có kích cỡ 2byte vì dùng bảng mã Unicode còn trong C,C++ là 1byte vì dùng mã ASCII
                ! Các hàm xử lí kí tự được dùng bằng cú pháp: Character.function_name
            - boolean - true - false: 1byte

            Cách khai báo biến cũng tương tự như C++: Cú pháp [Kiểu dữ liệu] [Tên biến]
            - Cần chú ý là với kiểu số nguyên thì mặc định là int nên muốn khai báo kích cỡ long thì thêm L ở cuối,
            số thực cũng tương tự mặc định là double nên muốn khai báo kích cỡ float thì thêm F ở cuối
            VD: float f = 3.456F
                long l = 187902184012840L

            - Quy tắc đặt tên biến cũng tương tự ko đặt chữ số ở đầu, ko chứa kí tự đặc biệt, khoảng trắng và trùng
            với từ khóa có sẵn trong Java
            - Name convention: quy tắc đặt tên biến khi lập trình Java nếu tên biến có từ 2 từ trở lên thì từ đầu viết
            thường và chữ cái đầu của các từ sau viết hoa
            VD: banKinh r = 5, chuVi = 10, diemTrungBinh = 3.6
            - Quy tắc đặt tên package là viết thường, đặt tên file phải trùng với tên class
            - Các đoạn code được đặt trong hàm void main đặt trong class trùng với tên file

            - Chú thích và kết thúc 1 dòng bằng ; thì tương tự như C++
            - Biến toàn cục thì thêm từ khoá static ở trước
        */
    }
}
