package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

public class J08012 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();

        int n = sc.nextInt();
        for (int i = 0; i <= n; i++) {
            list.add(new ArrayList<>());
        }

        for (int i = 0; i < n-1; i++) {
            int x = sc.nextInt(), y = sc.nextInt();
            list.get(x).add(y);
            list.get(y).add(x);
        }

        int cnt1 = 0, cnt2 = 0;
        for (ArrayList<Integer> x : list) {
            if(x.size() == n-1) ++cnt1;
            if(x.size() == 1) ++cnt2;
        }

        System.out.println((cnt1 == 1 && cnt2 == n-1) ? "Yes" : "No");
    }

    /* Ngắn gọn thì ko cần lưu trữ dsk mà chỉ cần đếm bậc thỏa mãn tính chất đồ thị hình sao là được
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] deg = new int[n + 1];

        for (int i = 0; i < n - 1; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            deg[x]++;
            deg[y]++;
        }

        int cntCenter = 0, cntLeaf = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == n - 1) cntCenter++;
            else if (deg[i] == 1) cntLeaf++;
        }

        System.out.println((cntCenter == 1 && cntLeaf == n - 1) ? "Yes" : "No");
    }
     */
}
