package codeptit;

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class J08024 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            Queue<Long> q = new ArrayDeque<>();
            q.offer(9L);

            while(!q.isEmpty()){
                long top = q.poll();

                if(top % n == 0){
                    System.out.println(top);
                    break;
                }
                if(top > 1l*1e18) continue;

                q.offer(top*10);
                q.offer(top*10+9);
            }
        }
    }
}
