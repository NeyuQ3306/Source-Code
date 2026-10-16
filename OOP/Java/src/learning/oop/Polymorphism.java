package learning.oop;

public class Polymorphism {
    /*
    Tính chất đa hình - Polymorphism trong OOP
    - Tương tự như định nghĩa về tính đa hình, 1 hàm hay 1 phương thức được dùng chung cho các lớp con nhưng được phép
    thay đổi list args, chức năng tương ứng cho từng đối tượng
    - Ngoài ra, còn cung cấp thêm chức năng khai báo lớp con thông qua đối tượng lớp cha
    VD:
        Animal a = new Dog();
        Animal b = new Cat();
    -> Animal: kiểu tham chiếu, quyết định những phương thức nào có thể gọi tại thời điểm biên dịch.
    -> Dog/Cat: kiểu đối tượng thực tế, quyết định phiên bản phương thức instance được ghi đè sẽ chạy.
    -> Hiểu đơn giản là cho phép ta khai báo kdl lớp cha để xác định các phương thức chung và khi biên dịch
    sẽ sử dụng kdl lớp con để thực thi hàm tương ứng (cùng 1 tên hàm)
    -> Phù hợp cho khai báo mảng lưu trữ nhiều kiểu đối tượng lớp con, kết hợp instanceof để lọc theo điều kiện

    - Phân biệt Upcasting và Downcasting:
        Upcasting: khai báo lớp con thông qua lớp cha
            Dog trong Animal, ArrayList trong List, HashMap trong Map, ...
        Downcasting: ép kiểu đối tượng
            Animal a = new Dog(); // Upcasting
            Dog d = (Dog) a;      // Downcasting hợp lệ

        -> Ép kiểu có thể gây lỗi ClassCastException nếu kiểu đối tượng thực sử của a ko cùng kiểu đối tượng của b
            Animal a = new Dog();
            Cat c = (Cat) a; -> gây lỗi
     */
}
