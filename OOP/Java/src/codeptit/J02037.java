package codeptit;

import java.util.Scanner;

public class J02037 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while(t-- > 0){
            int cnt = 0, cnt_c = 0;
            String s = sc.nextLine();
            String[] tok = s.split(" ");

            cnt = tok.length;
            for (int i = 0; i < tok.length; i++) {
                int x = Integer.parseInt(tok[i]);
                if(x % 2 == 0) ++cnt_c;
            }

            if((cnt%2 == 0 && cnt_c > cnt - cnt_c)
                || (cnt%2 == 1 && cnt - cnt_c > cnt_c)) System.out.println("YES");

            else System.out.println("NO");
        }
    }
}
