package learning.control;

public class LambdaFunction {
    /*
    Cú pháp cơ bản: (tham_số) -> {thân_hàm}
        Tham số: Các biến đầu vào (có thể bỏ qua kiểu dữ liệu vì Java tự suy luận).
        Mũi tên ->: Tách biệt giữa tham số và thân hàm.
        Thân hàm: Đoạn code thực thi.


    Ví dụ thực tế: So sánh trước và sau khi dùng Lambda
    Giả sử bạn muốn sắp xếp danh sách SinhVien giảm dần theo GPA:
    1. Cách cũ (Dùng Anonymous Class - như trong code cũ của bạn):
    JavaCollections.sort(list, new Comparator<SinhVien>() {
        @Override
        public int compare(SinhVien o1, SinhVien o2) {
            return Double.compare(o2.getGpa(), o1.getGpa());
        }
    });

    2. Cách mới (Dùng Lambda Expression):
    // Ngắn gọn hơn rất nhiều, bỏ toàn bộ boilerplate code
    Collections.sort(list, (o1, o2) -> Double.compare(o2.getGpa(), o1.getGpa()));

    3. Kết hợp với Method Reference (Java 8+):
    // Cách viết hiện đại và đọc như tiếng Anh
    list.sort(Comparator.comparingDouble(SinhVien::getGpa).reversed());

    Khi nào thì dùng được Lambda?
    Lambda chỉ dùng được khi làm việc với Functional Interface (Interface chỉ có duy nhất 1 phương thức trừu tượng).
    Một số Functional Interface phổ biến trong Java:
        Comparator: Dùng để so sánh (compare())
        Runnable: Dùng trong đa luồng (run())
        Predicate<T>: Dùng để lọc/kiểm tra điều kiện (test())
        Consumer<T>: Dùng để duyệt/xử lý phần tử, như list.forEach(...)

    Ví dụ duyệt danh sách ngắn gọn:Java
    // Thay vì dùng vòng lặp for-each truyền thống:
    list.forEach(sv -> System.out.println(sv));

    // Hoặc viết tắt hơn nữa với Method Reference:
    list.forEach(System.out::println);

    4. Sort theo nhiều tiêu chí
    - Cú pháp: Mở rộng tương tự nếu nhiều tiêu chí hơn
    list.sort(Comparator.comparing(KieuDuLieu::TieuChi1)
                    .thenComparing(KieuDuLieu::TieuChi2));

    VD: Mặc định là tăng dần theo tiêu chí
    List<NhanVien> ds = getDanhSachNhanVien();
    ds.sort(Comparator.comparing(NhanVien::getTen)
                      .thenComparing(NhanVien::getTuoi));

    - Muốn giảm dần theo cả 2 tiêu chí thì thêm reversed() ở cuối:
    ds.sort(Comparator.comparing(NhanVien::getTen)
                  .thenComparing(Comparator.comparing(NhanVien::getTuoi).reversed()));

    - Muốn 1 tiêu chí tăng, 1 tiêu chí giảm thì thêm reversedOrder() vào tiêu chí giảm dần
    ds.sort(Comparator.comparing(NhanVien::getLuong, Comparator.reverseOrder())
                  .thenComparing(NhanVien::getTen));

     */
}
