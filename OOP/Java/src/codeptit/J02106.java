package codeptit;

import java.util.Scanner;

public class J02106 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int ans = 0, cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < n; i++) {
            cnt0 = cnt1 = 0;
            for (int j = 0; j < 3; j++) {
                int x = sc.nextInt();
                if(x == 1) ++cnt1;
                else ++cnt0;
            }

            if(cnt1 > cnt0) ++ans;
        }

        System.out.println(ans);
    }
}
