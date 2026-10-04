package codeptit;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class J03031 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while(t-- > 0){
            String s = sc.nextLine();
            int k = sc.nextInt();
            sc.nextLine();

            Set<Character> se = new HashSet<>();
            for(char c : s.toCharArray()){
                se.add(c);
            }

            if(26 - se.size() <= k) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
