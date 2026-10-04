package codeptit;

import java.util.*;

public class J03038 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        Set<Character> se = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            se.add(s.charAt(i));
        }

        System.out.println(se.size());
    }
}
