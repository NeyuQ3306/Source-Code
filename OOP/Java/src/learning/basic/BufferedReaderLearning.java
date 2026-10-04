package learning.basic;

import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BufferedReaderLearning {
    public static void main(String[] args) {
        /*
        BufferedReader kết hợp với StringTokenizer là bộ đôi tối ưu nhất để đọc dữ liệu tốc độ cao trong các bài lập
        trình thi đấu (Competitive Programming).
        - Một số bài dùng Scanner để nhập input sẽ bị tle =))

        // 1. Khởi tạo BufferedReader
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Đọc 1 số nguyên trên 1 dòng
        int n = Integer.parseInt(br.readLine().trim());

        // 2. Đọc nhiều số trên 1 dòng (dùng StringTokenizer để tách theo khoảng trắng)
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
        }

        // Đọc đến hết file (EOF)
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue; // Bỏ qua dòng trống nếu có
            // Xử lý dòng dữ liệu tại đây...
        }

         */
    }
}
