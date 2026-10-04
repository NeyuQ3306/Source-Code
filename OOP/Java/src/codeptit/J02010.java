package codeptit;

import java.util.Scanner;

public class J02010 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cnt = 1;
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            boolean ok = false;
            for(int j=i+1; j<n; j++){
                if(a[j] < a[i]){
                    ok = true;
                    int tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }

            if(ok){
                System.out.print("Buoc " + cnt + ": ");
                for (int i1 : a) {
                    System.out.print(i1 + " ");
                }
                ++cnt;
                System.out.println();
            }

            else break;
        }

    }
}
