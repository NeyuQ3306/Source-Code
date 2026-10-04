package codeptit;
import java.util.*;

public class J01024 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            boolean ok = true;
            for (char c : s.toCharArray()) {
                if (c != '0' && c != '1' && c != '2') {
                    ok = false;
                    break;
                }
            }

            if (ok)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}