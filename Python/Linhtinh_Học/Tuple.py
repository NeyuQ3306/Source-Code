'''
Tuple là 1 collection trong Java
1. Tính chất
- Có thứ tự
- Truy xuất qua chỉ số
- Có thể chứa nhiều kiểu dữ liệu khác nhau
- Immutable nhưng nếu chứa phần tử mutable thì vẫn có thể thay đổi
-> Tương tự như list chỉ khác tính bất biến

2.Khởi tạo tuple
- Đưa các phần tử vào trong ngoặc tròn
VD: a = (1,"avc",2)
    b = (1,) // 1 phần tử thì phải có dấu , ở cuối
    c = (1,2,(3,4),'str','bcr') // nested tuple

- Thông qua constructor: Ép 1 iterable sang tuple
VD: a = tuple("Python")
    b = tuple([1,2,3])

3. Unpacking tuple tương tự list
4. Duyệt tuple bằng for idx hoặc for each
- Kiểm tra phần tử có xuất hiện ko bằng toán tử in

5.Concatenation và repetition
- Nối tuple bằng toán tử +
- Nhân bản tuple bằng toán tử *

6. Sắp xếp tuple
- Sử dụng sorted(a): trả về 1 list
- Ép từ tuple -> list: sử dụng .sort()

7. Hàm thông dụng
- count(): đếm số lần xuất hện của 1 phần tử
- index(): trả về chỉ số đầu tiên của 1 phần tử trong tuple
'''