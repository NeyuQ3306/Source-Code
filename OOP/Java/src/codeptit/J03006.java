package codeptit;

import java.util.Scanner;

public class J03006 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while(t-- > 0){
            String s = sc.nextLine();
            boolean ok = true;

            int n = s.length();
            for (int i = 0; i < s.length()/2; i++) {
                if(s.charAt(i) != s.charAt(n-i-1)){
                    ok = false;
                    break;
                }

                if((s.charAt(i) - '0') % 2 != 0 || (s.charAt(n-i-1) - '0') % 2 != 0){
                    ok = false;
                    break;
                }
            }

            System.out.println(ok ? "YES" : "NO");
        }
    }
}
