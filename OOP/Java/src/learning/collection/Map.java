package learning.collection;

public class Map {
    public static void main(String[] args){
        /*
            Map trong Java tương tự như trong C++ là container gồm 2 phần key-value, giúp ánh xạ nhanh từ key sang
        value tương ứng
        1. Tính chất
        - Key là giá trị riêng biệt ko được lặp lại, nếu add vào map 2 phần tử cùng 1 key thì sẽ bị ghi mới
        - Chỉ lưu các phần tử kiểu object

        2. Phân loại
        - Giống như set thì map cũng có 3 loại thường dùng là HashMap, LinkedHashMap và TreeMap
            HashMap ko có thứ tự xác định
            LinkedHashMap có thứ tự là thứ tự thêm phần tử vào
            TreeMap có thứ tự tăng dần

        - Cú pháp:
            Map<keyDataType, valueDataType> mp = new HashMap<>();
            HashMap<keyDataType, valueDataType> mp = new HashMap<>();
            LinkedHashMap<keyDataType, valueDataType> mp = new LinkedHashMap<>();
            TreeMap<keyDataType, valueDataType> mp = new TreeMap<>();

        3. Các hàm thường dùng của HashMap
        - put(key,value): thêm phần tử
        - size(), isEmpty(), clear()
        - containsKey(x): kiểm tra có key = x hay ko
        - containsValue(x): kiểm tra có value = x hay ko
        - get(x): trả về value tương ứng với key = x
        - remove(x): xóa phần tử có key = x
        - replace(x,y): thay thế phần tử (x,y)

        4. Các hàm thường dùng của TreeMap
        - first/lastKey(): trả về key đầu/cuối trong map
        - first/lastEntry(): trả về cặp phần tử đầu/cuối trong map
        - floorKey(x): trả về key lớn nhất <= x
        - floorEntry(x): trả về cặp phần tử có key lớn nhất <= x
        - ceilingKey(x): trả về key nhỏ nhất >= x
        - ceilingEntry(x): trả về cặp phần tử có key nhỏ nhất >= x

        5. Một số điểm khác biệt của map trong Java và C++
        - Trong Java, ko có kiểu dữ liệu pair, tuple để lưu các các phần tử khác kiểu dữ liệu thành 1 nhóm nhưng
        ta có thể dùng record - 1 dạng class đặc biệt tập trung vào lưu trữ dữ liệu 1 cách ngắn gọn
        VD:
        C++: pair<int,int> p = {5,6}
        Java:
            record pair(int x, int y) {}
            pair p = new pair(5,6);
        -> sẽ nói rõ hơn khi học về phần oop

        - Cách duyệt map trong Java: Trong Java ko có kiểu dữ liệu pair hay auto như C++ để duyệt foreach nhanh nhưng
        có Entry() tương tự như pair<> và var tương tự như auto
            ! Chỉ nên dùng var khi duyệt các collection, ko nên lạm dụng có khả năng bị lỗi
        VD:
        Map<Interger, String> map = new HashMap<>();

        for (Map.Entry<Integer, String> entry : map.entrySet()) {
                ...
        }

        var map = new HashMap<Integer, String>();
        map.put(1, "An");
        map.put(2, "Binh");
        // var thay cho việc khai báo kiểu dữ liệu Entry() -> giống auto
        // map.entrySet() tạo 1 tập set gồm các phần tử của map để duyệt
        for (var entry : map.entrySet()) {
            // truy xuất vào key-value của mỗi entry bằng cú pháp getKey/Value
            System.out.println(entry.getKey() + " " + entry.getValue());
        }

        */
    }
}
