package codeptit;

import java.util.Scanner;

public class J03040 {
    public static boolean check(String s){
        boolean ok1 = true, ok2 = true, ok3 = true, ok4 = true;
        // tăng chặt từ trái qua phải
        for (int i = 1; i < s.length(); i++) {
            if(s.charAt(i) <= s.charAt(i-1)){
                ok1 = false;
                break;
            }
        }

        // chữ số đều bằng nhau
        for (int i = 1; i < s.length() ; i++) {
            if(s.charAt(i) != s.charAt(0)){
                ok2 = false;
                break;
            }
        }

        // Ba chữ số đầu bằng nhau và hai chữ số cuối bằng nhau
        if((s.charAt(0) != s.charAt(1) || s.charAt(1) != s.charAt(2) || s.charAt(0) != s.charAt(2))
            || (s.charAt(3) != s.charAt(4))) ok3 = false;

        // chữ số đều là 6 và/hoặc 8 (số lộc phát)
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i) != '6' && s.charAt(i) != '8'){
                ok4 = false;
                break;
            }
        }

        return ok1 || ok2 || ok3 || ok4;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while(t-- > 0){
            // 29T1-123.79
            String s = sc.nextLine();
            String num = s.substring(5,8) + s.substring(9);

            System.out.println(check(num) ? "YES" : "NO");
        }
    }
}
