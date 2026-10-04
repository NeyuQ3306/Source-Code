package codeptit;

import java.util.*;

public class J03020 {
    public static boolean tn(String s){
        for (int i = 0; i < s.length()/2; i++) {
            if(s.charAt(i) != s.charAt(s.length()-i-1)){
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<String, Integer> mp = new LinkedHashMap<>();

        while(sc.hasNext()){
            String s = sc.next();
            if(tn(s)){
                if(mp.containsKey(s)) mp.put(s, mp.get(s) + 1);
                else mp.put(s,1);
            }
        }

        ArrayList<String> a = new ArrayList<>();
        for(Map.Entry<String, Integer> entry : mp.entrySet()){
            a.add(entry.getKey());
        }

        Collections.sort(a, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o2.length() - o1.length();
            }
        });

        int maxl = a.get(0).length();
        for(Map.Entry<String, Integer> entry : mp.entrySet()){
            if(entry.getKey().length() == maxl)
                System.out.println(entry.getKey() + " " + entry.getValue());
        }
    }
}
