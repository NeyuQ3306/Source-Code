package learning.oop;

public class AbstractClass_Interface {
    /*
    Phân biệt AbstractClass - lớp trừu tượng và Interface - giao diện
    1. Khái niệm
    Abstract Class: Mô tả một nhóm đối tượng có chung bản chất, thuộc tính và hành vi.
    Interface: Quy định những hành vi mà một lớp phải hỗ trợ, không nhất thiết các lớp đó có cùng bản chất.

    -> Cả 2 đều có chức năng hỗ trợ tính đa hình trong OOP
    Ví dụ: Dog và Cat đều là Animal, nhưng Bird và Airplane đều có thể Flyable (bay được).
    -> Dog,Cat chung bản chất nên ta có thể sử dụng AbstractClass
    -> Bird và Airplane 1 cái là động vật 1 cái là phương tiện nên dùng interface

    2. AbstractClass
    Abstract Class là một lớp được khai báo bằng từ khóa abstract.
    * Đặc điểm:
    - Không thể tạo đối tượng trực tiếp bằng new.
    - Có thể chứa thuộc tính, constructor, phương thức thông thường và phương thức abstract.
    - Có thể có hoặc không có phương thức abstract.
        -> Chứa abstract method thì là abstract class nhưng abstract class có thể ko chứa abstract method
    - Một lớp chỉ được extends trực tiếp một lớp cha.
    - Lớp con phải triển khai các phương thức trừu tượng được kế thừa, trừ khi lớp con cũng là abstract.

    -> Phù hợp với bài toán cùng 1 phương thức ở lớp cha, các lớp con lại có chức năng hoặc công thức tính
    khác nhau ta có thể sử dụng abstractclass để dùng abstract method
        -> Đảm bảo việc tất cả lớp con đều phải Override abstract method đó
        -> Nếu chỉ extends từ lớp cha thông thường, do ko bắt buộc tất cả lớp con phải override lại method abstract
        nên có thể bị quên và khi cần sử dụng sẽ nhầm thành method gốc trong lớp cha

    -> Dấu hiệu nhận biết nên sử dụng abstract class: Tất cả lớp con có chung 1 vài method của lớp cha nhưng có định nghĩa
    về list args, chức năng khác nhau thì sử dụng để luôn bắt buộc override lại method đó

    3. Interface
    Interface là một bản hợp đồng quy định các hành vi mà lớp triển khai phải cung cấp.
    * Đặc điểm:
    - Khai báo bằng từ khóa interface.
    - Lớp triển khai dùng implements.
    - Không có constructor.
    - Không thể khai báo thuộc tính instance. Các trường khai báo trong interface mặc định là public static final.
    - Phương thức abstract thông thường mặc định là public abstract.
    - Có thể có phương thức default, static và private (tùy phiên bản Java).
    - Một lớp có thể triển khai nhiều interface.

    -> Hay sử dụng cho các lớp cha ko định nghĩa được mà chỉ mang tính quy tính về hằng số, method chung cho các lớp
    con ko cùng bản chất
    VD:
    interface Flyable {
        void fly();
    }

    class Bird implements Flyable {
        @Override
        public void fly() {
            System.out.println("Bird is flying");
        }
    }

    class Airplane implements Flyable {
        @Override
        public void fly() {
            System.out.println("Airplane is flying");
        }
    }

    -> 2 đối tượng Bird và Airplane ta ko thể định nghĩa được 1 lớp cha cho cả 2 nhưng lại có chung phương thức
    flyable nên sử dụng lớp Interface và 2 lớp đối tượng Bird, Airplane có chức năng làm rõ/phát triển Interface Flyable
    -> Phù hợp cho trường hợp các kiểu đối tượng ko cùng bản chất mà có chức năng/ khả năng giống nhau thì ta cho kế thừa
    từ 1 Interface Skill_name chung thay vì kế thừa từ 1 lớp cha khác (cũng có flyable) chỉ để có phương thức fly

    * Điểm đặc biệt của Interface là các lớp con có thể implements từ nhiều Interface đồng thời extends từ 1 SuperClass khác
    VD:
    class Duck extends Animal
           implements Flyable, Swimmable {
        // Triển khai các phương thức cần thiết
    }

    * Từ khoá default và static:
    interface Printable {
        void print();

        default void showMessage() {
            System.out.println("Hello");
        }

        static void info() {
            System.out.println("Printable interface");
        }
    }

    class Student implements Printable {
        @Override
        public void print() {
            System.out.println("Student");
        }
    }

    Main:
        Student s = new Student();
        s.print();          // Student
        s.showMessage();    // Hello
        Printable.info();   // Printable interface

    -> default cho ta khai báo 1 method chung cho tất cả các lớp con, ko cần override lại
    -> static cho ta sử dụng method trực tiếp qua class ko cần khai báo kiểu đối tượng
        -> phù hợp với đặc điểm của interface - ko có định nghĩa rõ ràng về lớp cha

    3. So sánh
    Tiêu chí	            Abstract Class	               Interface
    Từ khóa	                abstract class	               interface
    Quan hệ	                extends	                       implements
    Constructor	            Có	                           Không
    Thuộc tính instance	    Có	                           Không
    Phương thức abstract	Có	                           Có
    Phương thức có nội dung	Có	                           Có (default, static, private)
    Đa kế thừa trực tiếp	Không	                       Một lớp implements nhiều interface
    Quyền truy cập	        Đa dạng	                       Phương thức abstract thông thường là public
    Mục đích	            Chia sẻ cấu trúc, trạng thái   Quy định hành vi
     */
}
