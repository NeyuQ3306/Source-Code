package learning.control;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Sort_Comparator {
    public static void main(String[] args){
        /*
        1. Các thuật toán sắp xếp có sẵn trong Java
        - Dùng cho mảng: Array.sort(arrayName, start, end, functionSort)
            ! start, end, functionSort ko khai báo mặc định là toàn mảng và tăng dần
            ! Nếu muốn sắp xếp giảm dần thì kdl của mảng phải là kiểu object và funcionSort là
            Collections.reversesOrder

        - Dùng cho ArrayList: Collections.sort(list, functionSort)
            ! kdl của ArrayList luôn là kdl object nên sort giảm dần tương tự như mảng

        - Hàm sort trong Java là stable_sort nên khi viết cmp nếu điều kiện sắp xếp giống nhau giữa 2 phần tử
        thì sẽ giữ đúng thứ tự xuất hiện trong array/list

        2. Viết comparator cho hàm sort
        - Cú pháp: Dùng cho cả Array.sort
          Collections.sort(list, new Comparator<listDataType>(){
                Viết hàm compare định nghĩa logic so sánh giữa 2 phần tử
                public int compare(Integer a, Integer b){
                    code
                }
           };

        - Với 2 phần tử a, b:
            Nếu muốn a đứng trước b sau khi sắp xếp hàm trả về < 0 : -1
            Nếu muốn a đứng sau b sau khi sắp xếp hàm trả về > 0: 1
            Nếu a = b thì trả về 0: phần tử nào đứng trước cũng được hoặc theo thứ tự xuất hiện trong array/list

        - Chú ý: Hàm compare luôn trả về kdl int -1, 1, 0 tùy điều kiện so sánh 2 phần tử
            ! Array/list có kdl khác int thì phải return -1,1,0 cụ thể
            ! Array/list có kdl int thì có thể return x-y hoặc y-x cho tiện
            ! Hàm so sánh 2 số double: Double.compare(x,y) trả về hiệu x-y
        */

        ArrayList<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        list.add(0);
        list.add(14);
        list.add(10);

        Collections.sort(list, Collections.reverseOrder());
        for(int x : list) System.out.println(x + " ");

        Collections.sort(list,
                new Comparator<Integer>(){
                    public int compare(Integer x, Integer y){
                            return x - y;
                    }
                });

        for(int x : list) System.out.println(x + " ");
    }
}
