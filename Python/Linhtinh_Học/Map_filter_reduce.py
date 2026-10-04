'''
Map và Filter là hàm chức năng có sẵn trong Python
1. Map
- Sử dụng để apply 1 expression lên mọi phần tử của 1 iterable
- Trả về 1 đối tượng thuộc lớp mảng nên cần ép kiểu nếu muốn sử dụng list, tuple, ..
- Cú pháp: map(expression, iterable)

VD: a = (1,-2,3,-4,5)
    b = tuple(map(abs,a))
-> b = (1,2,3,4,5)

- Có thể áp dụng map với nhiều iterabl đồng thời
VD:
def add(a,b):
    return a+b

a = [1,2,3,4,5]
b = [6,7,8,6,3]
c = list(map(add,a,b))

2. Filter
- Sử dụng để lọc các phần tử của 1 iterabl thỏa mãn 1 function/điều kiện cho truước
- Trả về 1 đối tượng thuộc lớp filter nên cũng cần ép kiểu khi sử dụng
- Cú pháp: filter(function, iterable)

VD:
def even(a):
    return a%2==0;

a = [1,2,3,4,5]
b = list(filter(even,a)) // b = [2,4]

3. Map/Filter + lambda function
- Nếu expression và function là các hàm đơn giản - 1 biểu thức thì có thể viết bằng
hàm lambda var : function(var)
VD:
a = [1,2,3,4,5]
b = list(map(lambda x : x**2, a)) // b = [1,4,9,16,25]
c = list(filter(lambda x : x % 2 == 0, a)) // c = [2,4]

4. Sử dụng list comprehension thay thế cho map/filter
- map = [expression(x) for x in iterable]
- filter = [x for x in iterable if funtion(x)]
'''

a = [1,2,3,4,5]
b = list(map(lambda x : x**2, a)) # b = [1,4,9,15,25]
c = list(filter(lambda x : x % 2 == 0, a))# c = [2,4]
print(b)
print(c)