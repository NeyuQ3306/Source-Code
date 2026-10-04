package codeptit;

import java.util.Scanner;



public class J02023 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), s = sc.nextInt();

        if(s == 0 && n > 1) System.out.println(-1 + " " + -1);
        else if(s != 0 && n * 9 < s) System.out.println(-1 + " " + -1);
        else{
            int init = s, cnt = 0;
            String maxv = "";

            while(cnt != n){
                if(init >= 9){
                    maxv += "9";
                    init -= 9;
                }

                else if(init < 9){
                    maxv += init + "";
                    init = 0;
                }

                else if(init == 0) maxv += "0";
                ++cnt;
            }

            // System.out.println(maxv);

            StringBuilder min = new StringBuilder();
            int sum = s;

            sum--;

            for (int i = n - 1; i > 0; i--) {
                int x = Math.min(9, sum);
                min.append(x);
                sum -= x;
            }

            min.append(sum + 1);
            min.reverse();

            System.out.println(min + " " + maxv);
        }
    }
}
