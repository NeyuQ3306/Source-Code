package codeptit;

import java.util.*;

public class J04022 {
    public static class WordSet{
        private String[] tok;

        public WordSet(String line){
            String[] a = line.toLowerCase().split("\\s+");
            tok = a;
        }

        public String[] getTok(){
            return tok;
        }

        public WordSet union(WordSet a){
            Set<String> st = new TreeSet<>();
            for(String str : tok) st.add(str);
            for(String str : a.getTok()) st.add(str);

            String tmp = "";
            for (String s : st) {
                tmp += s + " ";
            }

            return new WordSet(tmp.trim());
        }

        public WordSet intersection(WordSet a){
            Map<String,Integer> mp = new TreeMap<>();
            for(String s : tok){
                mp.put(s,1);
            }

            for(String s : a.getTok()){
                if(mp.containsKey(s)){
                    mp.put(s,2);
                }
                else mp.put(s,1);
            }

            String tmp = "";
            for (Map.Entry<String, Integer> entry : mp.entrySet()) {
                if(entry.getValue() == 2) tmp += entry.getKey() + " ";
            }

            return new WordSet(tmp.trim());
        }

        @Override
        public String toString(){
            String res = "";
            for (String s : tok) {
                res += s + " ";
            }

            return res.trim();
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        WordSet s1 = new WordSet(in.nextLine());
        WordSet s2 = new WordSet(in.nextLine());
        System.out.println(s1.union(s2));
        System.out.println(s1.intersection(s2));
    }
}
