package learning.oop;

public class Inheritance {
    /*
    Một trong 4 thuộc tính của lập trình hướng đối tượng
    1. Khái niệm
    - Inheritance hay kế thừa là kĩ thuật xử lý khi chương trình có nhiều class có chung thuộc tính
    khi đó ta có thể tổng quát hoá các class đó thành 1 class cha hay class cơ sở để tránh dư thừa code
    và tái sử dụng code
    - Các lớp con của lớp cơ sở sẽ chứa đầy đủ các thuộc tính và phương thức của lớp cha, có thể ghi đè lên
    các phương thức của lớp cha cho phù hợp với ngữ cảnh của thực thể


    2. Cú pháp: public class SubClass extends SuperClass{}
    - Lớp con kế thừa đầy đủ vào các thuộc tính, phương thức của lớp cha và có bổ sung thêm các thộc tính, phương
    thức riêng của thực thể
    - Vấn đề khi khai báo chế độ cho các thuộc tính của lớp cha:
        Nếu để private, thì các lớp con ko thể lấy ra các thuộc tính của lớp cha vì đảm bảo tính đóng gói
        Nếu để protected, thì các lớp con có thể lấy ra và sử dụng thuộc tính của lớp cha được
        -> Tùy vào nghiệp vụ và ngữ cảnh bài toán để linh hoạt
        Java chỉ hỗ trợ đơn kế thừa giữa các lớp: một lớp chỉ extends trực tiếp một lớp cha.
        Lớp con có thể sử dụng các phương thức được kế thừa nếu quyền truy cập cho phép.
        Constructor không được kế thừa.
        Mọi lớp đều kế thừa trực tiếp hoặc gián tiếp từ Object.
        Dùng kế thừa khi có quan hệ IS-A (Student là một Person), không dùng chỉ vì hai lớp có một vài thuộc tính giống nhau.

    3. Từ khoá cần biết
    - extends: kế thừa từ 1 class
    - super(): gọi constructor cha, hoặc super.methodName() để gọi hàm của lớp cha
    - super.x: truy cập thành viên của lớp cha -> modifier phải là public hoặc protected
    - final: ngăn kế thừa lớp hoặc ghi đè phươg thức -> bản vệ chức năng nguyên bản của method cha
    - abstract: khai báo lớp trừu tượng -> ko có đối tượng chung cho lớp con mà chỉ định nghĩa cấu trúc thuộc tính và method
    - instanceof: kiểm tra kiểu đối tượng lớp con -> dùng khi 1 list khai báo kdl lớp cha chứa nhiều lớp con cần sàng lọc

    -> Khi nào cần sử dụng private, protected: private bảo toàn tính đóng gói của class nhưng lớp con ko truy cập vào được thuộc
    tính lớp cha mà phải kết hợp với getter/setter còn protected lại cho phép truy cập và rút gọn lệnh code

    3. Lưu ý khi code Inheritance
    Khi tạo đối tượng lớp con, constructor lớp cha chạy trước.
    Nếu không viết super(...) hoặc this(...), Java sẽ ngầm chèn super().
    Nếu lớp cha không có constructor không tham số thì phải gọi constructor cha phù hợp.
    this(...) và super(...) không được cùng xuất hiện dưới dạng lời gọi constructor tường minh trong một constructor.
     */
}
