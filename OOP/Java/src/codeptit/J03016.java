package codeptit;

import java.util.Scanner;

public class J03016 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while(t-- > 0){
            String s = sc.nextLine();
            long sch = 0, sl = 0;

            for (int i = 0; i < s.length(); i++) {
                if(i%2 == 0) sch += s.charAt(i) - '0';
                else sl += s.charAt(i) - '0';
            }

            System.out.println((int)(Math.abs(sch - sl)) % 11 == 0 ? 1 : 0);
        }
    }
}
