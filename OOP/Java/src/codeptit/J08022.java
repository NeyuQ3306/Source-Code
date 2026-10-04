package codeptit;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class J08022 {
    public static void main(String[] args) throws IOException {
        // code bằng Scanner bị tle phải dùng BufferedReader mới AC =)))
    /*    Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            int[] a = new int[n], b = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            Stack<Integer> st = new Stack<>();
            for (int i = 0; i < n; i++) {
                if(st.empty()) st.push(i);
                else{
                    while(!st.empty() && a[i] > a[st.peek()]){
                        b[st.peek()] = a[i];
                        st.pop();
                    }

                    st.push(i);
                }
            }

            while(!st.empty()){
                b[st.peek()] = -1;
                st.pop();
            }

            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(b[i]).append(" ");
            }
            System.out.println(sb.toString().trim());
        }

     */
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String line = br.readLine();
        if (line == null || line.trim().isEmpty()) return;
        int t = Integer.parseInt(line.trim());

        while (t-- > 0) {
            line = br.readLine();
            while (line != null && line.trim().isEmpty()) {
                line = br.readLine();
            }
            int n = Integer.parseInt(line.trim());

            int[] a = new int[n];
            int[] b = new int[n];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(st.nextToken());
            }

            // Logic Stack giữ nguyên 100% từ code của bạn
            Stack<Integer> stack = new Stack<>();
            for (int i = 0; i < n; i++) {
                while (!stack.empty() && a[i] > a[stack.peek()]) {
                    b[stack.peek()] = a[i];
                    stack.pop();
                }
                stack.push(i);
            }

            while (!stack.empty()) {
                b[stack.peek()] = -1;
                stack.pop();
            }

            // Dùng StringBuilder để gom kết quả in ra 1 lần
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                sb.append(b[i]).append(" ");
            }
            System.out.println(sb.toString().trim());
        }
    }
}
