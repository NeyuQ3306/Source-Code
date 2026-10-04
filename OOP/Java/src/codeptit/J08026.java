package codeptit;

import java.util.*;

public class J08026 {
    public static class Pair{
        int x, y;
        Pair(int a, int b){
            this.x = a;
            this.y = b;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt(), k = sc.nextInt();
            Set<Integer> st = new HashSet<>();
            Queue<Pair> q = new ArrayDeque<>();

            q.offer(new Pair(n,0));
            while(true){
                Pair top = q.poll();
                int tmp = top.x, step = top.y;

                if(tmp == k){
                    System.out.println(step);
                    break;
                }

                if(tmp > 1 && !st.contains(tmp-1)){
                    q.offer(new Pair(tmp-1, step + 1));
                    st.add(tmp-1);
                }

                if(tmp < k && !st.contains(tmp*2)){
                    q.offer(new Pair(tmp*2, step + 1));
                    st.add(tmp*2);
                }
            }
        }
    }
}
