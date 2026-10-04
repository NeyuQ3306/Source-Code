package codeptit;

import java.util.Scanner;

/*
Nếu kích thước dữ liệu dài nên dùng class StringBuilder để cung cấp các thao tác tốt hơn là dùng + nối chuỗi
*/

public class J01010 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while(t-- > 0){
            String s = sc.nextLine();
            boolean ok = true;

            for (int i = 0; i < s.length(); i++) {
                if(s.charAt(i) != '0' && s.charAt(i) != '1' && s.charAt(i) != '8' && s.charAt(i) != '9'){
                    ok = false;
                    break;
                }
            }

            if(!ok) System.out.println("INVALID");
            else{
                String tmp = "";
                for (int i = 0; i < s.length(); i++) {
                    if(s.charAt(i) == '1') tmp += "1";
                    else tmp += "0";
                }

                long ans = Long.parseLong(tmp);
                if(ans != 0) System.out.println(ans);
                else System.out.println("INVALID");
            }

        }
    }
}
