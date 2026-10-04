package codeptit;

import java.util.Scanner;

public class J03032 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while(t-- > 0){
            String s = sc.nextLine();
            String[] tok = s.split("\\s+");

            for (String str : tok) {
                StringBuilder sb = new StringBuilder(str);
                System.out.print(sb.reverse() + " ");
            }

            System.out.println();
        }
    }
}
