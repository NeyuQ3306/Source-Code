package codeptit;

import java.util.Map;
import java.util.Scanner;
import java.util.Stack;

public class J08021 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            String s = sc.next();
            // dp[i]: độ dài dãy ngoặc đúng dài nhất kthuc tại i
            int[] dp = new int[s.length()];
            Stack<Integer> st = new Stack<>();

            int ans = 0;
            for (int i = 0; i < s.length(); i++) {
                if(s.charAt(i) == '(') st.push(i);
                else{
                    if(!st.empty()){
                        dp[i] = i - st.peek() + 1;
                        if(st.peek() > 0) dp[i] += dp[st.peek()-1];
                        st.pop();

                        ans = Math.max(ans, dp[i]);
                    }

                }
            }

            System.out.println(ans);
        }
    }
}
