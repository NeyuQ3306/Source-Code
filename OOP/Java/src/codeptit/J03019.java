package codeptit;

import java.util.Scanner;

public class J03019 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
/*
        String ans = String.valueOf(s.charAt(s.length()-1));
        char maxc = s.charAt(s.length()-1);

     dùng toán tử + để nối chuỗi sẽ bị tle do String trong Java là immutable nên mỗi khi dùng + để nối chuỗi
     sẽ phải tạo 1 đối tượng bản sao từ chuỗi ban đầu mất O(n^2) còn StringBuilder chỉ mất O(N)

        for (int i = s.length()-2; i >=0 ; i--) {
            if(s.charAt(i) >= maxc){
                ans += String.valueOf(s.charAt(i));
                maxc = s.charAt(i);
            }
        }

 */
        StringBuilder ans = new StringBuilder();
        ans.append(String.valueOf(s.charAt(s.length()-1)));
        char maxc = s.charAt(s.length()-1);

        for (int i = s.length()-2; i >= 0 ; i--) {
                if(s.charAt(i) >= maxc){
                    ans.append(String.valueOf(s.charAt(i)));
                    maxc = s.charAt(i);
                }
        }

        System.out.println(ans.reverse());
    }
}
