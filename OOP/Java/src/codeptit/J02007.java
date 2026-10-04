package codeptit;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

/*
- Trong Java ko thể truy cập map[x]++ được thay vào đó dùng map.put(x, map.getOrDefault(x, 0) + 1) thì nếu là key
mới tự tạo value = 1 còn nếu đã có key thì tự tăng lên 1
*/

public class J02007 {
    static int test = 1;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            int[] a = new int[n];

            Map<Integer, Integer> mp = new LinkedHashMap<>();
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                mp.put(a[i], mp.getOrDefault(a[i], 0) + 1);
            }

            System.out.println("Test " + test + ":");
            for (Integer i : mp.keySet()) {
                System.out.println(i + " xuat hien " + mp.get(i) + " lan");
            }

            ++test;
        }
    }
}
