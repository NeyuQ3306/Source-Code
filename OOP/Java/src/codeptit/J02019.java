package codeptit;

import java.util.Scanner;

public class J02019 {

    static int[] sum = new int[(int)1e6 + 5];
    public static void sang(){
        for (int i = 0; i < (int)1e6 + 5; i++) {
            sum[i] = 1;
        }

        for (int i = 2; i < ((int)1e6 + 5)/2; i++) {
            for (int j = i*2; j < (int)1e6 + 5; j+=i) {
                sum[j] += i;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt(), b = sc.nextInt();

        sang();
        int ans = 0;
        for (int i = a; i <= b; i++) {
            if(sum[i] > i) ++ans;
        }

        System.out.println(ans);
    }
}
