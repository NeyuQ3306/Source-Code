package codeptit;

import java.util.Scanner;

public class J02014 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i];
            }

            int[] presum = new int[n];
            presum[0] = a[0];

            for (int i = 1; i < n; i++) {
                presum[i] = presum[i-1] + a[i];
            }

            int ans = -1;
            for (int i = 0; i < n; i++) {
                if(presum[i] - a[i] == sum - presum[i]){
                    ans = i+1;
                    break;
                }
            }

            System.out.println(ans);


        }
    }
}
