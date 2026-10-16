package learning.oop;

public class Overriding_Overloading {
    /*
    Phân biệt 2 khái niệm Overriding - ghi đè và Overloading - nạp chồng
                         Overriding	                            Overloading
    Mục đích	         Thay đổi hành vi kế thừa	            Cung cấp nhiều cách gọi
    Tên phương thức	     Giống nhau	                            Giống nhau
    Tham số	             Giống nhau	                            Khác danh sách tham số
    Kiểu trả về	         Giống hoặc kiểu con hợp lệ	            Có thể khác, nhưng không đủ để phân biệt
    Quan hệ kế thừa	     Cần phương thức được kế thừa phù hợp	Không bắt buộc
    Annotation	         @Override	                            Không có


    VD:
    class Animal {
        public void sound() {
            System.out.println("Animal");
        }
    }

    class Dog extends Animal {
        @Override
        public void sound() {
            System.out.println("Woof");
        }

        public void sound(int n) {
            for (int i = 0; i < n; i++) {
                sound();
            }
        }
    }

    -> Lỗi thường gặp: private, static và final không thể được ghi đè theo cơ chế overriding thông thường. Phương thức static
    cùng chữ ký ở lớp con là method hiding, không phải overriding.
    -> Khái niệm đa hình thể hiện ở việc nạp chồng hàm, cùng 1 method của lớp cha nhưng kế thừa ở các lớp con được Overloading
    thêm các chức năng khác vẫn giữ nguyên tên method nhưng thay đổi danh sách tham số và thêm chức năng cho đối tượng tương ứng
     */
}
