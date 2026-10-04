package codeptit;

import java.util.*;

public class JKT013 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            Stack<String> st = new Stack<>();
            Queue<String> q = new ArrayDeque<>();

            q.offer("6");
            q.offer("8");
            st.add("6");
            st.add("8");

            while(!q.isEmpty()){
                String top = q.poll();
                if(top.length() == n) continue;

                String t1 = top + "6";
                String t2 = top + "8";

                q.offer(t1);
                q.offer(t2);
                st.add(t1);
                st.add(t2);
            }

            System.out.println(st.size());
            while(!st.empty()){
                System.out.print(st.pop() + " ");
            }

            System.out.println();
        }

    }
}
