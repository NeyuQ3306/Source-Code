package codeptit;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class J03009 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();

        while(t-- > 0){
            String s1 = sc.nextLine(), s2 = sc.nextLine();
            Map<String, Integer> mp = new TreeMap<>();

            String[] a1 = s1.split("\\s+"), a2 = s2.split("\\s+");
            for (String s : a1) {
                if(mp.containsKey(s)){
                    mp.put(s, 1);
                }

                else mp.put(s, 1);
            }

            for (String s : a2) {
                if(mp.containsKey(s)){
                    mp.put(s, 2);
                }

                else mp.put(s, 0);
            }

            for(Map.Entry<String, Integer> entry : mp.entrySet()){
                if(entry.getValue() == 1) System.out.print(entry.getKey() + " ");
            }

            System.out.println();
        }


    }
}
