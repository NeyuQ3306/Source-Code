package codeptit;

import java.util.Scanner;

/*
Code bằng cách phân tích thừa số ngto của từng số rồi cộng vào sẽ bị tle, cách tối ưu là sàng sãn mảng s[i] = tổng
các thừa số ngto của i => Vẫn tle mặc dù truy vấn trong main chỉ mất O(1) nhưng hàm sàng lại phải mất O(NloglogN)
- Cách code tối ưu nhất là chỉ tính toán ước nguyên tố đầu tiên của mỗi số n, và viết hàm chia n cho ước nto nhỏ nhất
cho tới khi về 1 => bản chất là sàng biến đổi nhưng trong main chỉ thực hiện phân tích số được hỏi mất O(logN)
=> Tưởng là mất tgian hơn nhma lại AC =))) chắc do vòng while trong sàng cách bị tle mất tgian hơn
*/


public class J01013 {
    // tle
//    public static int pttsnt(int n){
//        int sum = 0;
//        for(int i=2; i<=Math.sqrt(n); i++){
//            if(n%i==0){
//                while(n%i == 0){
//                    sum += i;
//                    n /= i;
//                }
//            }
//        }
//
//        if(n != 1) sum += n;
//        return sum;
//    }

    // tle
    // sum[i] = tổng thừa số ngto của i
//    static long[] sum = new long[2000005];
//    public static void sang(){
//        for(int i=2; i < 2000005; i++){
//            // i là số nt: ko là bội của số nào trước nó
//            if(sum[i] == 0){
//                // duyệt các bội của i: khi phân tích thừa số ngto sẽ chứa i
//                for(int j=i; j < 2000005; j += i){
//                    int x = j;
//
//                    while(x % i == 0){
//                        sum[j] += i;
//                        x /= i;
//                    }
//                }
//            }
//        }
//    }

    static int[] untnn = new int[2000005];
    public static void sang(){
        // tìm ước ngto nhỏ nhất của mỗi số i
        for(int i=2; i*i <= 2000005; i++){
            // i là số nt nếu nó ko là bội của số nào trước đó
            if(untnn[i] == 0){
                for(int j=i; j<2000005; j+=i){
                    // duyệt các bội của i nhưng phải ktra là j chưa có untnn nếu ko sẽ bị ghi đè
                    // VD: 6 = 2*3 thì đã được duyệt bởi 2 nhưng gặp 3 nếu ko có câu lệnh if bị ghi đè sai thành 3
                    if(untnn[j] == 0){
                        untnn[j] = i;
                    }
                }
            }
        }
    }

    // Hàm tính toán tổng ước nt của 1 số n
    public static int solution(int n){
        int sum = 0;
        while(n != 1){
            sum += untnn[n];
            n /= untnn[n];
        }

        return sum;
    }

    public static void main(String[] args) {
        sang();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        long ans = 0;
        while(n-- > 0){
            int x = sc.nextInt();
            ans += solution(x);
        }

        System.out.println(ans);
    }
}
