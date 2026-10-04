'''
List Comprehension: Tạo 1 list nhanh chóng từ iterable
- Cú pháp: [Expressiong for var in iterable]
    hoặc [var for var in iterable if function]

    Expression: biểu thức được thực hiện lên mỗi phần tử var của iterable
    function: hàm kiểm tra điều kiện thỏa mãn của mỗi phần tử var
    var: item-phần tử của iterable-collections có thể duyệt chứa object

- Tính chất: Thay thế cho 2 công việc
    + Áp dụng expression lên mọi phần tử của iterable: map + lambda
    + Lọc phần tử thỏa mãn function trong iterable: filter + lambda
    + Expression và function có thể là 1 câu lệnh đơn giản hoặc 1 hàm def bên ngoài

- Nested list comprehension: Biểu thức bên trong list comp có thể là 1 list comp khác
- So sánh list compre với map/filter + lambda
    map/filter + lambda chỉ thích hợp với các hàm có sẵn 
    list compr thích hợp với các function tự define
'''


a = [1,2,3,4,-4,2,-6,-9]
b = [abs(x) for x in a]
c = [x for x in a if x > 0]
print(b)
print(c)