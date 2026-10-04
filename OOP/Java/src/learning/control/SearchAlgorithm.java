package learning.control;

import java.util.Arrays;

public class SearchAlgorithm {
    /*
    1. Thuật toán tìm kiếm tuyến tính: O(n)
    2. Thuật toán tìm kiếm nhị phân: O(logN)
    - Tự cài đặt:
        public static boolean binarySearch(int[] a, int l, int r, int x){
        while(l < r){
            int m = (l+r) / 2;
            if(a[m] == x) return true;
            else if(a[m] < x) l = m+1;
            else r = m-1;
        }

        return false;
    }

    - Hàm có sẵn: Arrays.binarySearch(array, key);
        Hàm này sẽ trả về chỉ số của key nếu tồn tại trong mảng, ngược lại trả về giá trị: -(insertion point) - 1
        với insertion point là chỉ số thỏa mãn tính chất khi chèn key vào mảng sẽ ko làm mất thứ tự của mảng
        -> Đơn giản thì chỉ check chỉ số trả về > 0 hay ko là biết có tồn tại key trong mảng

    - Dùng trên arrayList thì tương tự hàm sort: Collections.binarySearch(list, key);

    - Các biến thể của binarySearch: Vị trí đầu tiên/cuối cùng >=/<=/>/<
        Java ko có hàm có sẵn upper_bound(): tìm vị trí đầu tiên > và lower_bound(): tìm vị trí đầu tiên >= như
        C++ mà ta phải viết hàm trực tiếp
    */

    public static boolean binarySearch(int[] a, int l, int r, int x){
        int m = (l+r) / 2;
        while(l < r){
            if(a[m] == x) return true;
            else if(a[m] < x) l = m+1;
            else r = m-1;
        }

        return false;
    }

    public static int upperBound(int[] a, int l, int r, int x){
        int ans = -1;
        while(l <= r){
            int m = (l+r) / 2;
            if(a[m] > x){
                ans = m;
                r = m-1;
            }

            else l = m+1;
        }

        return ans;
    }

    public static int lowerBound(int[] a, int l, int r, int x){
        int ans = -1;
        while(l <= r){
            int m = (l+r) / 2;
            if(a[m] >= x){
                ans = m;
                r = m-1;
            }

            else l = m+1;
        }

        return ans;
    }

    public static void main(String[] args) {
        int[] a = {2, 4, 5, 6, 7, 8, 9, 20, 1, 2, 5, 212, 53};
        System.out.println(binarySearch(a,0, 12, 63));
        System.out.println(Arrays.binarySearch(a, 2));
        System.out.println(upperBound(a,0,12, 9));
        System.out.println(lowerBound(a,0,12, 212));
    }
}
