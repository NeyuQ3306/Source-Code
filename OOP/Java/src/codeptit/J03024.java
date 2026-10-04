package codeptit;

import java.util.Scanner;

public class J03024 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while(t-- > 0){
            String s = sc.nextLine();

            boolean ok = true;
            if(s.charAt(0) == '0') ok = false;
            for(char x : s.toCharArray()){
                if(Character.isAlphabetic(x)){
                    ok = false;
                    break;
                }
            }

            if(!ok) System.out.println("INVALID");
            else{
                int n = s.length(), cntc = 0;
                for(char c : s.toCharArray()){
                    if((c - '0') % 2 == 0) ++cntc;
                }

                if((n%2 == 0 && cntc > n - cntc) || (n%2 == 1 && cntc < n - cntc)){
                    System.out.println("YES");
                } else{
                    System.out.println("NO");

                }
            }
        }
    }
}
