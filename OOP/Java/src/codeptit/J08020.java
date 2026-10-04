package codeptit;

import java.util.Scanner;
import java.util.Stack;

public class J08020 {
    public static boolean open(char c){
        if(c == '(' || c == '{' || c == '[') return true;
        else return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            String s = sc.next();
            Stack<Integer> st = new Stack<>();

            boolean ok = true;
            for (int i = 0; i < s.length(); i++) {
                if(open(s.charAt(i))) st.push(i);
                else{
                    if(st.empty()){
                        ok = false;
                        break;
                    } else{
                        if(s.charAt(i) == ')' && s.charAt(st.peek()) != '('
                                || s.charAt(i) == '}' && s.charAt(st.peek()) != '{'
                                || s.charAt(i) == ']' && s.charAt(st.peek()) != '['){
                            ok = false;
                            break;
                        } else{
                            st.pop();
                        }
                    }
                }
            }

            if(!st.empty()) ok = false;

            System.out.println(ok ? "YES" : "NO");
        }
    }
}
