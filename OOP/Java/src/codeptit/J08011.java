package codeptit;

import java.util.*;

public class J08011 {
    public static boolean check(String s){
        for (int i = 0; i < s.length()-1; i++) {
            if(s.charAt(i) > s.charAt(i+1)) return false;
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Map<String,Integer> mp = new HashMap<>();
        ArrayList<String> list = new ArrayList<>();

        while(sc.hasNext()){
            String s = sc.next();
            if(check(s)){
                if(mp.containsKey(s)){
                    mp.put(s,mp.get(s)+1);
                } else{
                    mp.put(s,1);
                    list.add(s);
                }
            }
        }

        Collections.sort(list, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                 return mp.get(o2) - mp.get(o1);
            }
        });

        for (String s : list) {
            System.out.println(s + " " + mp.get(s));
        }
    }
}
