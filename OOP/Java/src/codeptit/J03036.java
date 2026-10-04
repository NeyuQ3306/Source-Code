package codeptit;

import java.util.Scanner;

public class J03036 {
    // Đếm số bước dịch vòng trái để xâu s trở thành target
    public static int countRotate(String s, String target) {
        if (s.equals(target)) return 0;

        StringBuilder sb = new StringBuilder(s);
        int len = s.length();

        for (int i = 1; i <= len; i++) {
            char first = sb.charAt(0);
            sb.deleteCharAt(0);
            sb.append(first);

            // Phải dùng sb.toString().equals(...) để so sánh nội dung
            if (sb.toString().equals(target)) {
                return i;
            }
        }
        return -1; // Không thể xoay s thành target
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;

        int n = sc.nextInt();
        String[] a = new String[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.next();
        }

        int minTotalSteps = Integer.MAX_VALUE;
        int len = a[0].length();

        // Thử tất cả L trạng thái xoay của xâu a[0] làm xâu target
        StringBuilder targetBuilder = new StringBuilder(a[0]);

        for (int k = 0; k < len; k++) {
            String target = targetBuilder.toString();
            int currentTotalSteps = 0;
            boolean possible = true;

            // Tính tổng chi phí xoay N xâu về xâu target
            for (int i = 0; i < n; i++) {
                int steps = countRotate(a[i], target);
                if (steps == -1) {
                    possible = false;
                    break;
                }
                currentTotalSteps += steps;
            }

            if (possible) {
                minTotalSteps = Math.min(minTotalSteps, currentTotalSteps);
            }

            // Xoay xâu targetBuilder 1 bước để thử trạng thái tiếp theo
            char first = targetBuilder.charAt(0);
            targetBuilder.deleteCharAt(0);
            targetBuilder.append(first);
        }

        System.out.println(minTotalSteps == Integer.MAX_VALUE ? -1 : minTotalSteps);
        sc.close();
    }
}