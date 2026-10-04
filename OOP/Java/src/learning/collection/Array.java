package learning.collection;

import java.util.ArrayList;

public class Array {
    public static void main(String[] args){
        /*
        1. Mảng 1 chiều
        - Cú pháp: Data_type[] tên_Biến = new Data_type[kích thước mảng];
        hoặc có thể dùng như C++ cú pháp: Datatype tên_biến[] = new datatype[kích thước mảng];

        VD:
        int[] a = new int[5]; Java ưu tiên dùng cú pháp này hơn
        int b[] = new int[5];

        - Chú ý: Khác so với mảng 1 chiều trong C++ là mảng khai báo tĩnh, tên biến là con trỏ trỏ tới phần tử đầu
        tiên của mảng và các phần tử nằm liên tiếp nhau trong bộ nhớ stack
            ! Còn trong Java cú pháp là cấp phát động nên các phần tử được lưu trong bộ nhớ heap và tên biến là phần
            tử tham chiếu (reference - khác với con trỏ trong C/C++ nhưng chức năng tương tự nhau) trỏ tới phần tử đầu
            tiên của mảng thì nằm trong bộ nhớ stack
            ! Các phần tử trong heap vẫn nằm ở các ô nhớ liên tiếp nhau
            ! Vì lưu ở bộ nhớ heap nên có thể tránh stackoverflow khi kích thước mảng quá lớn

        2. Arraylist: được coi là mảng động (1 hoặc 2 chiều) trong Java tuy nhiên chỉ lưu được các object chứ ko thể
        khai báo lưu trữ các kdl nguyên thủy như int, long, float, ... thay vào đó có thể sử dụng lớp Wrapper của kdl
        là Interger, Long, Float, Double, ... -> dataType phải là đối tượng hoặc biến reference

        - Cú pháp: List<dataType> arr = new ArrayList<>();
        hoặc ArrayList<dataType> arr = new ArrayList<>(); dùng được cả 2 cú pháp vì List là interface của arraylist

        - Sử dụng tương tự như vector của C++, có thể khai báo ArrayList<ArrayList> như vector<vector> sử dụng như 1
        mảng 2 chiều
            ! ArrayList<ArrayList> arr = new ArrayList<>();
            hoặc ArrayList<Interger>[] arr = new ArrayList[n]; tuy nhiên cách 2 thì khi nhập vào mỗi 1 arraylist phải
            cấp phát động trước khi add nếu ko sẽ bị lỗi NullPointerException - lỗi chưa cấp phát cho các container như
            list, set, map, ...

        - Duyệt ArrayList:
            ! Bằng chỉ số tương tự như mảng bằng hàm get(index)
            ! Duyệt foreach

        - Thêm phần tử vào cuối ArrayList:
            ! Bằng hàm add(giá trị phần tử)
            ! Nhập từ bàn phím: add(sc.nextInt())

        - Hàm xóa và kiểm tra rỗng:
            ! .clear() để xóa ArrayList
            ! .isEmpty() để ktra rỗng trả về true/false

        - Kiểm tra 1 phần tử có thuộc ArrayList bằng hàm contains(value) trả về true/false

        - Xóa 1 phần tử trong ArrayList:
            ! Biết chỉ số: remove(index)
            ! Biết giá trị: remove((Object)(3)) -> chỉ xóa phần tử = 3 đầu tiên nếu có nhiều phần tử = 3

        - Hàm indexOf(): trả về chỉ số đầu tiên của 1 phần tử nếu thuộc ArrayList, ngược lại trả về -1
        - Sửa phần tử thứ j hàng i thành x: a.get(i).set(j,x)
        
        3. Mảng 2 chiều
        - Cú pháp: dataType[][] a = new dataType[rowSize][columSize]
        - Nhập, xuất tương tự như mảng 1 chiều
        */
        ArrayList<Integer> a = new ArrayList<>();
        for(int i=1; i<=5; i++)
            a.add(i);

        for(int i=1; i<=5; i++)
            System.out.println(a.get(i));

        for(int x : a)
            System.out.println(x);




    }
}
