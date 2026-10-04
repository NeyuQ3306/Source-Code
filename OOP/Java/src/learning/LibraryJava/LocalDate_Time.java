package learning.LibraryJava;

public class LocalDate_Time {
    /*
    Dưới đây là các hàm thông dụng và thực tế nhất của bộ thư viện java.time, rất hữu ích khi bạn làm bài tập hoặc viết dự án:
    1. Khởi tạo và tạo mới ngày tháng (LocalDate, LocalDateTime)
    LocalDate.now(): Lấy ngày hiện tại của hệ thống.
    LocalDate.of(year, month, day): Tạo một mốc ngày cụ thể.
    LocalDateTime.now(): Lấy cả ngày lẫn giờ hiện tại.

    2. Chuyển đổi giữa Chuỗi (String) và Ngày (Parse & Format)
    Đây là thao tác dùng nhiều nhất khi đọc/ghi dữ liệu từ bàn phím (đặc biệt trong các bài toán PTIT).
    DateTimeFormatter.ofPattern(String): Định nghĩa định dạng (VD: "dd/MM/yyyy").
    LocalDate.parse(String, formatter): Chuyển chuỗi (String) thành đối tượng LocalDate.
    .format(formatter): Chuyển đối tượng LocalDate ngược lại thành chuỗi (String).

    3. So sánh ngày tháng (Cực kỳ quan trọng khi Sắp xếp - Sort)
    Các hàm này trả về boolean (true/false) hoặc số nguyên:
    .isBefore(date2): Kiểm tra ngày hiện tại có trước date2 không.
    .isAfter(date2): Kiểm tra ngày hiện tại có sau date2 không.
    .isEqual(date2): Kiểm tra 2 ngày có bằng nhau không.
    .compareTo(date2): Trả về số âm (nếu trước), số dương (nếu sau), và 0 (nếu bằng). Rất hay dùng bên trong Comparator để
    sắp xếp danh sách (Collections.sort).

    4. Trích xuất thông tin (Getters)
    Lấy từng thành phần lẻ ra khỏi một ngày:
    .getDayOfMonth(): Lấy ngày trong tháng (1 - 31).
    .getMonthValue(): Lấy tháng bằng số (1 - 12).
    .getYear(): Lấy năm.
    .getDayOfWeek(): Lấy thứ trong tuần (MONDAY, TUESDAY...).

    5. Cộng / Trừ thời gian
    Các hàm này sinh ra một mốc thời gian mới (không làm thay đổi biến ban đầu):
    .plusDays(n), .plusMonths(n), .plusYears(n): Cộng thêm số ngày/tháng/năm.
    .minusDays(n), .minusMonths(n), .minusYears(n): Trừ đi số ngày/tháng/năm.

    6. Tính khoảng cách (ChronoUnit)
    Như đã đề cập ở câu trước, dùng để đếm khoảng cách giữa 2 mốc thời gian:
    ChronoUnit.DAYS.between(d1, d2): Khoảng cách số ngày.
    ChronoUnit.MONTHS.between(d1, d2): Khoảng cách số tháng.
    ChronoUnit.YEARS.between(d1, d2): Khoảng cách số năm.
    ChronoUnit.SECONDS.between(): Khoảng cách theo giây
     */
}
