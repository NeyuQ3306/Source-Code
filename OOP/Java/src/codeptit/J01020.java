package codeptit;

import java.util.*;

/*
Bài này đọc đề dễ bị lầm, Không phải tìm K có đủ 10 chữ số trong chính K, mà là tìm K sao cho
trong toàn bộ các giá trị đã gặp từ N đến K, tất cả 0..9 đã xuất hiện.
 */

public class J01020 {
    public static boolean check(long n) {
        int[] digit = new int[10];

        while (n > 0) {
            ++digit[(int)(n % 10)] ;
            n /= 10;
        }

        for (int x : digit) {
            if (x > 1) return false;
        }

        return true;
    }

    public static void solve(int n) {
        if (n == 0) {
            System.out.println("Impossible");
            return;
        }

        Queue<Long> q = new ArrayDeque<>();
        Set<Long> visited = new HashSet<>();

        q.offer((long) n*2);
        q.offer((long) n*3);
        visited.add((long) n);

        while (!q.isEmpty()) {
            long top = q.poll();

            if (check(top)) {
                System.out.println(top);
                return;
            }

            if (top <= 1e18 / 2) {
                long x = top * 2;
                if (visited.add(x)) {
                    q.offer(x);
                }
            }

            if (top <= 1e18 / 3) {
                long x = top * 3;
                if (visited.add(x)) {
                    q.offer(x);
                }
            }
        }

        System.out.println("Impossible");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            solve(n);
        }
    }
}
