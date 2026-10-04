package learning.LibraryJava;

public class ChronoUnitLibrary {
    /*
    1. Vai trò chính của ChronoUnit
    ChronoUnit cung cấp 2 tính năng chính:
    Tính khoảng cách (chênh lệch) giữa 2 mốc thời gian: Dùng hàm .between(start, end).
    Cộng / Trừ thời gian theo đơn vị cụ thể: Dùng hàm .addTo() hoặc kết hợp trực tiếp với các lớp thời gian qua hàm .plus() / .minus().

    2. Cú pháp
    - import java.time.temporal.ChronoUnit;
    - Khoảng cách chênh lệch:
    long result = ChronoUnit.<ĐƠN_VỊ>.between(mốc_thời_gian_1, mốc_thời_gian_2);

    - Cộng/trừ thời gian:
    // Cách 1: Sử dụng phương thức plus/minus từ đối tượng thời gian (Phổ biến nhất)
    MốcThờiGian newTime = startTime.plus(giá_trị, ChronoUnit.<ĐƠN_VỊ>);
    MốcThờiGian newTime = startTime.minus(giá_trị, ChronoUnit.<ĐƠN_VỊ>);

    // Cách 2: Sử dụng hàm addTo / subtractFrom trực tiếp từ ChronoUnit
    MốcThờiGian newTime = (MốcThờiGian) ChronoUnit.<ĐƠN_VỊ>.addTo(startTime, giá_trị);

    - Cộng thêm amount đơn vị vào mốc thời gian:
    addTo(temporal, amount)

    - Trừ đi amount đơn vị vào mốc thời gian:
    subtractFrom(temporal, amount)

    - Kiểm tra đơn vị:
    isDateBased(): trả về true nếu đơn vị đo theo Ngày/Tháng/Năm
    isTimeBased(): trả về true nếu đơn vị đo theo Giờ/Phút/Giây
     */
}
