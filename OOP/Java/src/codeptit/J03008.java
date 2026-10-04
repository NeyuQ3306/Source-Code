package codeptit;

import java.util.Scanner;

public class J03008 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while(t-- > 0){
            String s = sc.nextLine();
            boolean ok = true;

            for (int i = 0; i < s.length()/2; i++) {
                if(s.charAt(i) != s.charAt(s.length()-i-1)){
                    ok = false;
                    break;
                }

                int dg = s.charAt(i) - '0';
                if(dg != 2 && dg != 3 && dg != 5 && dg != 7){
                    ok = false;
                    break;
                }
            }

            System.out.println(ok ? "YES" : "NO");
        }
    }
}
