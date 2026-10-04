'''
Lambda trong Python đơn giản là hàm ẩn danh (anonymous function) - tức là một hàm ngắn gọn, không có tên, thường được viết ngay trên 1 dòng
- Cú pháp: lambda <tham số>: <biểu thức trả về>
VD:
# Cách dùng thông thường với 'def':
def double(x):
    return x * 2

# Đổi sang dùng 'lambda':
double_lambda = lambda x: x * 2

print(double(5))        # Output: 10
print(double_lambda(5)) # Output: 10

- Trong C++ cũng có hàm lambda hay sử dụng khi viết cmp cho hàm sort nhưng thân hàm được
phép chứa nhiều dòng lệnh và có return giá trị trả về ở cuối
  ->  Trong Python thì chỉ được chứa 1 dòng lệnh là biểu thức trả về

- Ứng dụng: Kết hợp với map() và filter()
    + map(hàm, danh_sách): Áp dụng hàm lên từng phần tử
    + filter(hàm, danh_sách): Lọc các phần tử thỏa mãn điều kiện của hàm.
VD:
numbers = [1, 2, 3, 4, 5]

# Nhân đôi từng số bằng map + lambda
doubled = list(map(lambda x: x * 2, numbers)) 
# -> [2, 4, 6, 8, 10]

# Lọc số chẵn bằng filter + lambda
evens = list(filter(lambda x: x % 2 == 0, numbers)) 
# -> [2, 4]

- So sánh với list comprehension: List Comprehension ra đời chính là để thay thế bộ đôi map/filter + lambda 
giúp code ngắn gọn, dễ đọc hơn (nói rõ hơn trong file list comprehension)

=> lambda chỉ nên sử dụng hữu ích khi làm khóa sắp xếp (pivot sort) cho các hàm
built-in -> tương tự như sử dụng lambda trong cmp của C++ với các bài toán danh sách object 
sắp xếp theo nhiều tiêu chí
VD:
students = [
    ("Alice", 20, 85),
    ("Bob", 22, 90),
    ("Charlie", 19, 85)
]

# C++/Java: Phải viết custom Comparator (std::sort với lambda hoặc Compare class)
# Python: Chỉ cần 1 dòng lambda làm key!
students.sort(key=lambda x: (-x[2], x[1]))

print(students)
# Output: [('Bob', 22, 90), ('Charlie', 19, 85), ('Alice', 20, 85)]

'''