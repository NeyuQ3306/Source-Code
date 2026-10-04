package codeptit;
import java.util.Scanner;

public class J01026 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t-- > 0){
            int n = sc.nextInt();
            int tmp = (int)Math.sqrt(n);

            if(tmp * tmp == n) System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
