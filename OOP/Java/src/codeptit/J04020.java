package codeptit;

import java.util.Scanner;

public class J04020 {
    // Generic Class - lớp tổng quát ko cần xác định kdl thuộc tính khi xây dựng class
    // Thay vào đó dùng kí tự <K,V> để làm biến kdl khi khai báo đối tượng
    // Lưu ý khi khai báo kdl luôn phải là kdl object

    public static boolean Prime(Integer n){
        for (int i = 2; i <= Math.sqrt(n) ; i++) {
            if(n % i == 0) return false;
        }
        return n>1;
    }

    public static class Pair<K,V>{
        private K fi;
        private V se;

        public Pair(K x, V y){
            fi = x;
            se = y;
        }

        public K getFi(){return fi;}
        public V getSe(){return se;}

        // Vì lớp Pair<K, V> của bạn là Generic Class (lớp tổng quát).
        // Compiler (trình biên dịch) hoàn toàn không biết K và V là kiểu dữ liệu gì
        // Để tránh xung đột dữ liệu khi nhập ta sử dụng hàm instanceof KDL Object để ktra
        // Cú pháp: tên_biến instanceof Kiểu_Dữ_Liệu trả về true/false

        public boolean isPrime(){
            // vì bài này input đã nói rõ là số thực nên ta có thể ko cần ktra

            if(fi instanceof Integer && se instanceof Integer){
                return Prime((Integer) fi) && Prime((Integer) se);
            }

            return false;
        }

        public String toString(){
            return fi + " " + se;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            boolean check = false;
            for(int i = 2; i <= 2*Math.sqrt(n); i++){
                Pair<Integer, Integer> p = new Pair<>(i, n-i);
                if(p.isPrime()){
                    System.out.println(p);
                    check = true;
                    break;
                }
            }
            if(!check) System.out.println(-1);
        }
    }
}
