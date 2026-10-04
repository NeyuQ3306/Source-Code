'''
Bisect là thư viện cung cấp các hàm tìm kiếm nhị phân nhanh chóng
1. Các hàm thông dụng trong thư viện bisect
import bisect
- bisect.bisect_left(a, x):
    Tương đương với lower_bound trong C++.
    Trả về chỉ số (index) đầu tiên mà tại đó nếu chèn x vào, mảng vẫn giữ nguyên tính sắp xếp
    (tìm vị trí của phần tử >= x đầu tiên).

- bisect.bisect_right(a, x) (hoặc gọi ngắn gọn là bisect.bisect):
    Tương đương với upper_bound trong C++.
    Trả về chỉ số đầu tiên mà tại đó nếu chèn x vào, mảng vẫn giữ nguyên tính sắp xếp
    (tìm vị trí của phần tử > x đầu tiên).

- bisect.insort_left(a, x) và bisect.insort_right(a, x):
    Vừa tìm vị trí thích hợp vừa tự động chèn (insert) phần tử x trực tiếp vào danh sách a sao cho mảng vẫn được giữ
    nguyên thứ tự sắp xếp.
    Lưu ý: Thao tác chèn vào giữa list có độ phức tạp O(N), nên chỉ dùng khi dữ liệu vừa phải).
'''