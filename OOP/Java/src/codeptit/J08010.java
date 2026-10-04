package codeptit;

import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Scanner;

public class J08010 {
    public static boolean tn(String s){
        for (int i = 0; i < s.length()/2; i++) {
            if(s.charAt(i) != s.charAt(s.length()-i-1)) return false;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Map<String, Integer> mp = new LinkedHashMap<>();
        int maxle = 0;

        while(sc.hasNextLine()){
            String s = sc.nextLine();
            String[] tok = s.split("\\s+");

            for (String str : tok) {
                if(tn(str)){
                    if(mp.containsKey(str)){
                        mp.put(str,mp.get(str) + 1);
                    } else{
                        mp.put(str, 1);
                    }

                    maxle = Math.max(maxle, str.length());
                }
            }
        }

        for(Map.Entry<String,Integer> entry : mp.entrySet()){
            if(entry.getKey().length() == maxle)
                System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
}

