package codeptit;

import java.util.Scanner;
import java.util.Stack;

public class J02017 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < n; i++) {
            if(st.empty()) st.push(sc.nextInt());
            else{
                int t = st.peek();
                int tmp = sc.nextInt();

                if((t + tmp) % 2 == 0){
                    st.pop();
                }
                else st.push(tmp);
            }
        }

        System.out.println(st.size());
    }
}
