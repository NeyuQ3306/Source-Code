package learning.collection;

public class Set {
    public static void main(String[] args){
        /*
        Set trong Java tương tự như trong C++, mỗi phần tử chỉ xuất hiện duy nhất 1 lần và được cài đặt bằng bảng
        băm Hashtable nên tốc độ truy xuất nhanh. Set là interface - hiểu tạm thời là lớp cha và bên trong sẽ có
        các lớp con khác có tính chất riêng biệt

        -> Mọi lớp con đều có thể khai báo qua lớp cha
        1. HashSet
        - Tính chất:
            Chỉ lưu được các phần tử khác nhau
            Ko có thứ tự xác định, ko có chỉ số -> duyệt bằng foreach
            Chỉ lưu được kiểu dữ liệu đối tượng -> lớp wrapper, object
            Tốc độ tìm kiếm phần tử O(1)

        - Cú pháp:
            HashSet<dataType> st1 = new HashSet<>();
        hoặc Set<dataType> st2 = new HashSet<>(); được dùng nhiều hơn

        - Một số hàm tương tự ArrayList: add, remove, size, contains, clear, isEmpty, ...

        2. LinkedHashSet
        - Tính chất:
            Chỉ lưu các phần tử khác nhau
            Có thứ tự là thứ tự thêm phần tử vào set
            Chỉ lưu được kdl đối tượng
            Tốc độ tìm kiếm phần tử O(1)
        - Cú pháp: Khai báo tương tự hashset, điểm khác nhau giữa 2 loại chỉ là linked có thứ tự xác định

        3. TreeSet
        - Tính chất:
            Chỉ lưu các phần tử khác nhau
            Có thứ tự tăng dần
            Tốc độ tìm kiếm, thêm, xóa O(logN) do cài đặt bằng cây đỏ đen - Red black tree
            Chỉ lưu được kdl đối tượng

       - Cú pháp: TreeSet<dataType> st = new TreeSet<>();
       - Muốn thứ tự trong TreeSet là giảm dần thì khai báo:
            TreeSet<dataType> st = new TreeSet<>(Collections.reverseOrder());

       4. Một số hàm thông dụng trong TreeSet
       - floor(x): trả về phần tử lớn nhất <= x, trả về null nếu ko tồn tại
       - ceiling(x): trả về phần tử nhỏ nhất >= x, trả về null nếu ko tồn tại
       - first(): trả về phần tử đầu tiên trong set
       - last(): trả về phần tử cuối cùng trong set
       - lower(x): trả về phần tử lớn nhất < x, trả về null nếu ko tồn tại
       - higher(x): trả về phần tử nhỏ nhất > x, trả về null nếu ko tồn tại
        */
    }
}
