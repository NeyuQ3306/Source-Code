package codeptit;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/*
Bài này tối ưu hơn có thể dùng Map để có đpt O(N)
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (!sc.hasNextInt()) return;
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            long k = sc.nextLong();
            long[] a = new long[n];
            Map<Long, Long> map = new HashMap<>();

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
    // hàm getorDefault để tăng giá trị value nếu đã tồn tại lên 1 đvi hoặc tạo mới nếu chưa tồn tại
                map.put(a[i], map.getOrDefault(a[i], 0L) + 1);
            }

            long ans = 0;
            for (int i = 0; i < n; i++) {
                long target = k - a[i];
                if (map.containsKey(target)) {
                    ans += map.get(target);
                    // Nếu k - a[i] == a[i], trừ đi chính phần tử a[i]
                    if (target == a[i]) {
                        ans--;
                    }
                }
            }

            // Mỗi cặp (i, j) bị đếm lặp 2 lần nên chia 2
            System.out.println(ans / 2);
        }
    }
 */

public class J08015 {
    // tim vi tri phan tu dau tien >= x
    public static int lowerBound(long[] a, int l, int r, long x){
        int idx = r+1;
        while(l <=r){
            int m = (l+r)/2;
            if(a[m] >= x){
                idx = m;
                r = m-1;
            } else{
                l = m+1;
            }
        }

        return idx;
    }

    // tim vi tri phan tu dau tien > x
    public static int upperBound(long[] a, int l, int r, long x){
        int idx = r+1;
        while(l <= r){
            int m = (l+r)/2;
            if(a[m] > x){
                idx = m;
                r = m-1;
            } else{
                l = m+1;
            }
        }

        return idx;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt(), k = sc.nextInt();
            long[] a = new long[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
            }
            Arrays.sort(a);

            long ans = 0;
            for (int i = 0; i < n; i++) {
                int start = lowerBound(a,i+1,n-1,k-a[i]);
                int end = upperBound(a,i+1,n-1,k-a[i]);

                ans += end - start;
            }

            System.out.println(ans);
        }
    }
}
