package codeptit;

import java.util.Scanner;
import java.util.Stack;

public class J03027 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            if(st.empty()) st.push(s.charAt(i));
            else{
                char c = st.peek();
                if(c == s.charAt(i)){
                    st.pop();
                } else{
                    st.push(s.charAt(i));
                }
            }
        }

        if(st.empty()){
            System.out.println("Empty String");
        } else{
            String tmp = "";
            while(!st.empty()){
                char c = st.peek();
                st.pop();
                tmp += c;
            }

            StringBuilder sb = new StringBuilder(tmp);
            System.out.println(sb.reverse());
        }
    }
}
