package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

/*
- Bài này nếu phân tích chay thì sẽ tle, cách làm tối ưu hơn là sàng sẵn các số nto ra và chỉ duyệt trên các số nt
đó cho tới khi n=1 hoặc ans = n
*/

public class J01014 {
    static ArrayList<Integer> a = new ArrayList<>();
    static int[] prime = new int[100005];

    public static void sang(){
        for (int i = 0; i < 100005; i++) {
            prime[i] = 1;
        }

        prime[0] = prime[1] = 0;
        for (int i = 2; i*i <= 100005 ; i++) {
            if(prime[i] == 1){
                for(int j=i*i; j<100005; j+=i){
                    prime[j] = 0;
                }
            }
        }

        for(int i=2; i<100005; i++) {
            if (prime[i] == 1) a.add(i);
        }
    }

    public static void solution(long n){
        long ans = -1;
        for (Integer i : a) {
            while(n%i == 0 && i*i <= n){
                ans = Math.max(ans, i);
                n /= i;
            }
        }

        if(n != 1) ans = n;
        System.out.println(ans);
    }

    public static void main(String[] args) {
        sang();
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            long n = sc.nextLong();
            solution(n);
        }
    }
}
