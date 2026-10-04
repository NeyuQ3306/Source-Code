/*
package codeptit;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class J02009 {
    static record Pair(int x, int y){}

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Codeptit ko hỗ trợ record hz
        // record pair là class đặc biệt để lưu trữ ngắn gọn các phần tử cùng kdl, có tính bất biến nên
        // khi đã khai báo ko thể thay đổi các trường dữ liệu con
        Pair[] a = new Pair[n];
        for (int i = 0; i < n; i++) {
           a[i] = new Pair(sc.nextInt(), sc.nextInt());
        }

        Arrays.sort(a,
                new Comparator<Pair>() {
                    @Override
                    public int compare(Pair o1, Pair o2) {
                        return o1.x() - o2.x();
                    }
                });

        int ans = 0;
        for (Pair p : a) {
            if(ans < p.x())
                ans = p.x();

            ans += p.y();

//            System.out.println(p.x + " " + p.y);
        }

        System.out.println(ans);
    }

     */

package codeptit;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class J02009 {
        static class Pair {
            int x, y;

            // constructor
            Pair(int x, int y) {
                this.x = x;
                this.y = y;
            }
        }

        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);

            int n = sc.nextInt();

            Pair[] a = new Pair[n];

            for (int i = 0; i < n; i++) {
                a[i] = new Pair(sc.nextInt(), sc.nextInt());
            }

            Arrays.sort(a, new Comparator<Pair>() {
                @Override
                public int compare(Pair o1, Pair o2) {
                    return Integer.compare(o1.x, o2.x);
                }
            });

            int ans = 0;

            for (Pair p : a) {
                if (ans < p.x) {
                    ans = p.x;
                }

                ans += p.y;
            }

            System.out.println(ans);
        }
    }

