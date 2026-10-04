package codeptit;

import java.util.Scanner;

public class J03007 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while(t-- > 0){
            String s = sc.nextLine();
            boolean ok = true;

            int n = s.length();
            if(s.charAt(0) != '8' || s.charAt(n-1) != '8') ok = false;

            int sum = 0;
            for (int i = 0; i < n/2; i++) {
                if(s.charAt(i) != s.charAt(n-i-1)){
                    ok = false;
                    break;
                }

                sum += s.charAt(i) - '0' + s.charAt(n-i-1) - '0';
            }


            if(ok && sum % 10 == 0) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
