package codeptit;

import java.util.Scanner;

public class J03022 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            String s = sc.nextLine();
            String[] sentence = s.trim().toLowerCase().split("[.?!]");

            for (int i = 0; i < sentence.length; i++) {
                if(sentence[i].trim().isEmpty()) continue;

                String[] tok = sentence[i].trim().split("\\s+");
                String first = "";

                first += Character.toUpperCase(tok[0].charAt(0)) + tok[0].substring(1);

                System.out.print(first + " ");
                for (int j = 1; j < tok.length; j++) {
                    System.out.print(tok[j] + " ");
                }

                System.out.println();
            }
        }
    }
}
