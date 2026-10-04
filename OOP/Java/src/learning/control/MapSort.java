package learning.control;

public class MapSort {
    /*
    Sắp xếp map theo tiêu chí key/value: Dùng LinkedHashMap
    - Cú pháp:
        Map<K, V> sortedMap = originalMap.entrySet()
            .stream()
            .sorted( tiêu_chí_sắp_xếp )
            .collect(Collectors.toMap(
                    Map.Entry::getKey,
                    Map.Entry::getValue,
                    (oldValue, newValue) -> oldValue,
                    LinkedHashMap::new
            ));
    - Chức năng từng hàm:
        originalMap.entrySet().stream(): Chuyển Map thành một luồng (Stream) các cặp Map.Entry<K, V>.
        sorted(...): Nơi bạn truyền tiêu chí sắp xếp.
        Collectors.toMap(...): Gom luồng đã sắp xếp ngược trở lại thành Map:
        Map.Entry::getKey: Lấy lại Key.
        Map.Entry::getValue: Lấy lại Value.
        (oldValue, newValue) -> oldValue: Hàm xử lý xung đột Key (ch chẵn trường hợp trùng Key, lấy giá trị cũ).
        LinkedHashMap::new: Cực kỳ quan trọng. Giúp giữ nguyên thứ tự sắp xếp (vì HashMap thông thường sẽ làm mất thứ tự).

    1. Sắp xếp theo Key
        import java.util.*;
        import java.util.stream.Collectors;

        public class SortMapExample {
            public static void main(String[] args) {
                Map<String, Integer> map = Map.of("Banana", 3, "Apple", 5, "Cherry", 2);

                // Sắp xếp theo Key
                Map<String, Integer> sortedByKey = map.entrySet()
                        .stream()
                        .sorted(Map.Entry.comparingByKey()) // Lambda / Method Reference
                        .collect(Collectors.toMap(
                                Map.Entry::getKey,
                                Map.Entry::getValue,
                                (e1, e2) -> e1,
                                LinkedHashMap::new // Bắt buộc dùng LinkedHashMap để giữ thứ tự sau khi sort
                        ));

                System.out.println("Sort theo Key: " + sortedByKey);
            }
        }
       2. Sắp xếp theo Value
            // Sắp xếp theo Value tăng dần
            Map<String, Integer> sortedByValue = map.entrySet()
                    .stream()
                    .sorted(Map.Entry.comparingByValue())
                    .collect(Collectors.toMap(
                            Map.Entry::getKey,
                            Map.Entry::getValue,
                            (e1, e2) -> e1,
                            LinkedHashMap::new
                    ));

            System.out.println("Sort theo Value: " + sortedByValue);

        3. Sắp xếp tùy biến Lambda
        - Giảm dần theo Value:
        .sorted(Map.Entry.<String, Integer>comparingByValue().reversed())
        - Tùy biến Lambda:
        .sorted((e1, e2) -> Integer.compare(e1.getKey().length(), e2.getKey().length()))


        4. So sánh với CustomSort + Lambda trong Python
        - Sort theo Key:
        PY: dict(sorted(d.items(), key=lambda x: x[0]))
        JA: .sorted(Map.Entry.comparingByKey())
        - Sort theo Value:
        PY: dict(sorted(d.items(), key=lambda x: x[1]))
        JA: .sorted(Map.Entry.comparingByValue()
        - Giảm dần:
        PY: dict(sorted(d.items(), key=lambda x: x[1], reverse=True))
        JA: .sorted(Map.Entry.<K,V>comparingByValue().reversed())
     */
}
