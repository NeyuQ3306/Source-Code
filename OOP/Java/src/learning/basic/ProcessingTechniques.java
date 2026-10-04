package learning.basic;

public class ProcessingTechniques {
    /*
    1. Làm tròn số tới hàng trăm, ngàn, ....
    public static long roundTo(double value, int place) {
        return Math.round(value / place) * place;
    }

    // Cách dùng cực kỳ gọn:
    long kqHangTram = roundTo(12678.5, 100);   // 12700
    long kqHangNghin = roundTo(12678.5, 1000); // 13000

    - Còn nếu làm tròn tới số thập phân x sau dấu phẩy:
        return Math.round(value * 10^x) / 10^xf;

    2. Làm tròn số theo yêu cầu bài toán:
    - Ví dụ: Làm tròn số tới hàng trăm nếu phần lẻ != 0
        if(value % 100 != 0) value = value - value%100 + 100;

    3. Làm tròn số tới số nguyên gần nhất bằng toán học số
    - Có thể có test bị sai số do cách lưu trữ dữ liệu số thực
        VD:
        phuTroi = Math.round((double) tien * 0.35); -> Wa
        phuTroi = Math.round((double) this.tien * 35.0 / 100.0); -> Ac
        phuTroi = (tien * 35 + 50) / 100; -> Ac
    - An toàn là dùng toán học số nguyên thuần túy thay vì round(), luôn + 50 vào số thực
    cần làm tròn rồi chia 100

    4. Bài toán tính thời gian giữa 2 thời điểm định dạng hh:mm:ss
    - Sử dùng thư viện localTime
    - Khoảng thời gian < 24h:
            import java.time.LocalTime;
            import java.time.format.DateTimeFormatter;
            import java.time.temporal.ChronoUnit;

            public class TimeExample {
                public static void main(String[] args) {
                    LocalTime start = LocalTime.parse("08:30:15");
                    LocalTime end   = LocalTime.parse("10:45:30");

                    // 1. Tính tổng số giây
                    long seconds = ChronoUnit.SECONDS.between(start, end);

                    // 2. Ép trực tiếp số giây về lại LocalTime
                    LocalTime diffTime = LocalTime.ofSecondOfDay(seconds);

                    // 3. In ra định dạng HH:mm:ss bằng DateTimeFormatter
                    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
                    String result = diffTime.format(formatter);

                    System.out.println("Kết quả: " + result); // Output: 02:15:15
                }
            }

    - Ko giới hạn thời gian
            import java.time.Duration;
            import java.time.LocalTime;
            import java.time.format.DateTimeFormatter;

            public class DurationExample {
                public static void main(String[] args) {
                    LocalTime start = LocalTime.parse("08:30:15");
                    LocalTime end   = LocalTime.parse("10:45:30");

                    // Tính khoảng thời gian Duration giữa 2 mốc
                    Duration duration = Duration.between(start, end);

                    // Chuyển Duration thành LocalTime bằng cách lấy tổng số giây
                    LocalTime resultTime = LocalTime.ofSecondOfDay(duration.getSeconds());

                    // Định dạng ra chuỗi HH:mm:ss
                    String formatted = resultTime.format(DateTimeFormatter.ofPattern("HH:mm:ss"));

                    System.out.println("Kết quả: " + formatted); // Output: 02:15:15
                }
            }

     - Code trâu:
             public class FastTimeDiff {
            // Hàm chuyển đổi HH:mm:ss thành tổng số giây (Cực nhanh)
            public static int toSeconds(String time) {
                // time = "hh:mm:ss"
                int h = (time.charAt(0) - '0') * 10 + (time.charAt(1) - '0');
                int m = (time.charAt(3) - '0') * 10 + (time.charAt(4) - '0');
                int s = (time.charAt(6) - '0') * 10 + (time.charAt(7) - '0');
                return h * 3600 + m * 60 + s;
            }

            public static void main(String[] args) {
                String t1 = "08:30:15";
                String t2 = "10:45:30";

                int sec1 = toSeconds(t1);
                int sec2 = toSeconds(t2);

                int diffInSeconds = sec2 - sec1;
                if (diffInSeconds < 0) {
                    diffInSeconds += 24 * 3600; // Xử lý trường hợp qua đêm
                }

                System.out.println("Chênh lệch số giây: " + diffInSeconds);
            }
        }
     */

}
