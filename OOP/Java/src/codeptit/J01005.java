package codeptit;

import java.util.Scanner;

public class J01005 {
    public static void main(String[] args) {
        /*
        Bài này bản chất là bài ứng dụng tam giác đồng dạng, với mỗi lát cắt i ta có tam giác nhỏ với chiều cao hi
        tính từ đỉnh tới lát cắt thứ i và độ dài đáy di
        - Tam giác nhỏ đồng dạng với tam giác ban đầu nên ta có tỉ số: hi/h = di/d = di/1 = di
        - Tam giác được chia thành N phần nên diện tích tam giác nhỏ là i * S/N
        - Rút được công thức tính hi:
            Si = 1/2 * di * hi
               = 1/2 * hi/h * hi
               = 1/2 * hi^2/ h

            mà Si = i * S/N = i * h/2N
            => 1/2 * hi^2/h = i * h/2N
            <=> hi^2 = h^2 * i/N
            <=> hi = h * sqrt(i/N)
        */

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt(), h = sc.nextInt();
            for (int i = 1; i < n; i++) {
                // lỗi có thể gặp nếu ko ép phép chia sang căn sang double sẽ ra kq = 0
                double hi = h * Math.sqrt((double) i/n);
                System.out.printf("%.6f ", hi);
            }

            System.out.println();
        }
    }
}
