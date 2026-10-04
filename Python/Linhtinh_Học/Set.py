'''
Set trong Python
1. Tính chất
- Tập các phần tử duy nhất ko có thứ tự
- Ko thể truy cập qua chỉ số
- Có thể thay đổi mutable nhưng ko thể lưu các phần tử có kdl mutable như list

2. Khởi tạo
- Đặt các phần tử trong dấu {}
- Bằng hàm khởi tạo: set(iterable)

3. Các hàm thông dụng
- add(): thêm 1 phần tử
- update(): thêm nhiều phần tử
- remove(): xóa 1 phần tử nếu ko tồn tại trong set sẽ báo lỗi
- discard(): xóa 1 phần tử nếu ko tồn tại ko bị báo lỗi
- pop(): xóa 1 phần tử ngẫu nhiên
- clear(): xóa toàn bộ set
- isdisjoint(): xác định xem 2 tập có phần tử chung ko
- issubset(): ktra tập này có phải tập con của tập khác ko
- issuperset(): ktra tập này có phải tập cha của tập khác ko

4. Các phép toán trên tập hợp
- Phép Union: hàm s.union(t) hoặc v = s | t (hợp)
- Phép Intersection: hàm s.intersection(t) hoặc v = s & t (giao)
- Phép Difference: hàm s.difference(t) hoặc v = s - t (trừ)
- Phép Symmetric Difference: hàm s.symmetric_difference(t) hoặc v = s ^ t (hợp - giao)

'''