package codeptit;

import java.util.Scanner;

public class J03004 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        sc.nextLine();
        while(t-- > 0){
            String s = sc.nextLine();
            String[] tok = s.trim().toLowerCase().split("\\s+");

            for (String str : tok) {
                String res = "";
                res += Character.toUpperCase(str.charAt(0));
                for (int i = 1; i < str.length(); i++) {
                    res += str.charAt(i);
                }

                System.out.print(res + " ");
            }

            System.out.println();
        }
    }
}
