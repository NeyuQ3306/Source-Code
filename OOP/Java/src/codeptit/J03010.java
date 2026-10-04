package codeptit;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class J03010 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<String,Integer> mp = new HashMap<>();

        int n = sc.nextInt();
        sc.nextLine();
        while(n-- > 0){
            String s = sc.nextLine();
            String[] tok = s.trim().toLowerCase().split("\\s+");

            String name = tok[tok.length - 1];
            for (int i = 0; i < tok.length-1; i++) {
                name += tok[i].charAt(0);
            }

            if(mp.containsKey(name)){
                mp.put(name, mp.get(name) + 1);
                System.out.println(name + mp.get(name) + "@ptit.edu.vn");
            }
            else{
                mp.put(name,1);
                System.out.println(name + "@ptit.edu.vn");
            }
        }
    }
}
