package learning.oop;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class ClassObject {
    /*
1. Tính Đóng gói (Encapsulation)
Ý nghĩa đơn giản: Gom thuộc tính (dữ liệu) và phương thức (hành động) liên quan vào trong một Lớp (Class), đồng thời che
giấu dữ liệu bên trong để tránh bị truy cập hoặc sửa đổi tự do từ bên ngoài.

Ví dụ Ô tô: Động cơ, bình xăng được giấu kín dưới nắp capo. Bạn không thể chọc tay trực tiếp vào để chỉnh lượng xăng nạp
vào xi-lanh, mà phải thông qua bàn đạp ga (hàm getter/setter hoặc phương thức công khai).

Trong Java: Dùng thuộc tính private và cung cấp các hàm public getX(), setX().

2. Tính Kế thừa (Inheritance)
Ý nghĩa đơn giản: Lớp con có thể sử dụng lại các thuộc tính và phương thức của Lớp cha mà không cần viết lại từ đầu,
 đồng thời có thể mở rộng thêm các tính năng mới.

Ví dụ Ô tô: Bạn có lớp cha là XeCo (có bánh xe, động cơ, hàm chay()). Lớp con OTo kế thừa từ XeCo sẽ tự động có bánh xe
và động cơ, sau đó viết thêm tính năng riêng như batDieuHoa().

Trong Java: Dùng từ khóa extends.

3. Tính Đa hình (Polymorphism)
Ý nghĩa đơn giản: Cùng một hành động (phương thức) nhưng các đối tượng thuộc các Lớp khác nhau sẽ thực hiện theo các
 cách khác nhau.

Ví dụ Ô tô: Khi nhấn nút KhoiDong(), xe xăng sẽ gầm máy và đánh lửa, xe điện sẽ im lặng bật hệ thống pin, xe máy chạy
bằng xích... Cùng là hành động "Khởi động", nhưng cơ chế chạy thực tế tùy thuộc vào từng loại xe.

Trong Java: Thể hiện qua Ghi đè phương thức (Overriding) và Nạp chồng phương thức (Overloading).

4. Tính Trừu tượng (Abstraction)
Ý nghĩa đơn giản: Chỉ tập trung vào những thông tin quan trọng mà người dùng cần quan tâm, ẩn đi toàn bộ chi tiết cài
đặt phức tạp bên dưới.

Ví dụ Ô tô: Bác tài chỉ cần biết xoay Vô-lăng là xe rẽ, đạp Phanh là xe dừng. Bác tài không cần biết phanhABS hoạt động
 bằng thủy lực thế nào hay vô-lăng điều khiển thước lái ra sao.

Trong Java: Dùng Abstract Class hoặc Interface.

- Phân biệt nhanh: Trừu tượng là CHE CÁI GÌ (Show WHAT, Hide HOW), còn Đóng gói là CHE Ở ĐÂU (Hide WHERE, Protect DATA).
     */
    // cùng 1 file thì phải khai báo class toàn cục - public static class
    // còn nếu class nằm ở file khác thì chỉ cần khai báo public class
    public static class SinhVien{
        // thuộc tính - attribute phải để là private để đảm bảo tính chất đóng gói của OOP
        // mục đích là bảo toàn dữ liệu
        private String name;
        private String msv;
        private String ns;
        private double gpa;

        // class attribute: thuộc tính của lớp - mọi đối tượng của class đều dùng chung biến static
        private static int cnt;

        // construtor function: hàm khởi tạo thuộc tính khi khai báo 1 object mới
        // default attribute: khi chưa biết trước dữ liệu thuộc tính
        public SinhVien(){
            ++cnt;
            name = msv = ns = "";
            gpa = 0.0;
        }

        // nhập dữ liệu thuộc tính luôn khi khai báo object
        public SinhVien(String name, String msv, String ns, double gpa){
            // name = name; nếu gán như này trình biên dịch sẽ ko biết là gán giá trị tham số name cho thuộc tính name
            // vì vậy ta dùng con trỏ this.attribute để truy cập vào thuộc tính của class nếu bị trùng tên tham số
            // ko trùng thì gán thoải mái nhưng nên dùng this cho cẩn thận
            // mỗi khi khởi tạo thêm 1 đối tượng SV thì biến static tăng lên
            ++cnt;
            this.name = name;
            this.msv = msv;
            this.ns = ns;
            this.gpa = gpa;
        }

        // các method - phương thức thì được khai báo public và có thể truy cập qua các object
        public void displayInfor(){
            System.out.println(name + " " + msv + " " + gpa);
        }

        // muốn truy xuất và thay đổi private attribute sử dụng 2 hàm getter, setter
        public void setMaSinhVien(String maMoi){ msv = maMoi; }

        public void setGpa(double newGpa){ gpa = newGpa; }

        public String getName(){ return name; }

        public  String getMsv(){ return msv; }

        public Double getGpa() { return gpa; }

        // hàm static của class có thể truy cập thông qua lớp thay vì phải khai báo đối tượng
        public int getCnt(){ return cnt; }

        // Override method toString cho các subclass của superclass Object: để sout(object) sẽ thực hiện hàm toString
        @Override
        public String toString(){
            return name + " " + msv + " " + String.format("%.2f", gpa);
        }

        public void chuanHoaTen(){
            String[] tok = name.toLowerCase().split("\\s+");
            String res = "";

            for (String s : tok) {
                res += Character.toUpperCase(s.charAt(0));
                res += s.substring(1);
                res += " ";
            }

            this.name = res.trim();
        }

        public void chuanHoaNS(){
            String tok[] = ns.split("/");
            this.ns = String.format("%02d/%02d/%04d", Integer.parseInt(tok[0]), Integer.parseInt(tok[1]), Integer.parseInt(tok[2]));
        }

        // kiểm tra xem thộc tính ngày sinh có sinh trước ngày sinh cho trước ko
        public boolean checkDoB(String s){
            String[] a = s.split("/");
            String[] b = ns.split("/");

            String tmp1 = a[2] + a[1] + a[0];
            String tmp2 = b[2] + b[1] + b[0];

            return tmp2.compareTo(tmp1) < 0;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
//        SinhVien a = new SinhVien();
//        a.displayInfor();
//
//        SinhVien b = new SinhVien("Quyền", "B24DCCN484", 3.7);
//        b.displayInfor();
//        System.out.println(b);

        // ArrayListObject: Mảng đối tượng với các bài toán yêu cầu sort 1 danh sách đối tượng cho trước

        ArrayList<SinhVien> list = new ArrayList<>();
        int n = Integer.parseInt(sc.nextLine());

        for (int i = 0; i < n; i++) {
            SinhVien a = new SinhVien(sc.nextLine(), sc.nextLine(), sc.nextLine(), Double.parseDouble(sc.nextLine()));
            a.chuanHoaNS();
            a.chuanHoaTen();

            list.add(a);
        }

        Collections.sort(list, new Comparator<SinhVien>() {
            @Override
            public int compare(SinhVien o1, SinhVien o2) {
                if(o1.getGpa() != o2.getGpa()){
                    return Double.compare(o2.getGpa(), o1.getGpa());
                } else{
                    return o1.getMsv().compareTo(o2.getMsv());
                }
            }
        });

        for (SinhVien sinhVien : list) {
            System.out.println(sinhVien);
        }

    }
}
