package codeptit;

import java.util.ArrayList;
import java.util.Scanner;

public class J02105 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // trước khi truy cập vào từng hàng bằng get(idx) thì phải tạo thủ công trước
        ArrayList<ArrayList<Integer>> a = new ArrayList<>();
        for (int i = 0; i < n+5; i++) {
            a.add(new ArrayList<>());
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <=n; j++) {
                int x = sc.nextInt();
                if(x == 1 && i < j){
                    a.get(i).add(j);
                    a.get(j).add(i);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            System.out.printf("List(%d) = ", i);
            for (int x : a.get(i)) {
                System.out.printf("%d ", x);
            }

            System.out.println();
        }
    }
}
