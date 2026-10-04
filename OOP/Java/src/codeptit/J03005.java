package codeptit;

import java.util.Scanner;

public class J03005 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        sc.nextLine();
        while(t-- > 0){
            String s = sc.nextLine();
            String[] tok = s.trim().toLowerCase().split("\\s+");

            for (int i = 1; i < tok.length; i++) {
                String res = "";
                res += Character.toUpperCase(tok[i].charAt(0));

                for (int j = 1; j < tok[i].length(); j++) {
                    res += tok[i].charAt(j);
                }

                if(i != tok.length - 1) System.out.print(res + " ");
                else System.out.print(res + ", ");
            }

            String ho = tok[0];
            System.out.println(ho.toUpperCase());
        }
    }
}
