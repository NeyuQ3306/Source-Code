'''
Dictonary tương tự như map trong Java,C++
1. Tính chất
- Lưu các cặp phần tử (key,value)
- key trong dict là unique, nếu khai báo trùng key sẽ ghi đè value
- key phải là immutable object
- Có thứ tự là thứ tự thêm vào dict:
    + Tuy nhiên vẫn có thể sort theo key hoặc value:
VD:
my_dict = {'apple': 3, 'banana': 1, 'cherry': 2, 'date': 5}
# 1. Sắp xếp tăng dần theo value
sorted_asc = dict(sorted(my_dict.items(), key=lambda item: item[1]))
print(sorted_asc)
# Kết quả: {'banana': 1, 'cherry': 2, 'apple': 3, 'date': 5}

# 2. Sắp xếp giảm dần theo value (dùng thêm reverse=True)
sorted_desc = dict(sorted(my_dict.items(), key=lambda item: item[1], reverse=True))
print(sorted_desc)
# Kết quả: {'date': 5, 'apple': 3, 'cherry': 2, 'banana': 1}

    + Sau khi sort có thể truy xuất ra items theo value bằng max,min tốn O(n):
VD:
my_dict = {'apple': 3, 'banana': 1, 'cherry': 5, 'date': 2}

# Lấy ra key có value lớn nhất
max_key = max(my_dict, key=my_dict.get)
print(max_key) # Kết quả: cherry

# Lấy ra cả cặp (key, value) có value lớn nhất
max_item = max(my_dict.items(), key=lambda item: item[1])
print(max_item) # Kết quả: ('cherry', 5)

- Sử dụng cặp hàm next(iter(object)) để lấy phần tử đầu/cuối của dict:
    + Tương tự như iterator trong C++
    + Kết hợp với hàm next để dịch chuyển iterator
VD:
my_dict = {'apple': 3, 'banana': 1, 'cherry': 5}

# 1. Chuyển dict.items() thành iterator bằng iter()
my_iterator = iter(my_dict.items())

# 2. Lấy phần tử đầu tiên bằng next()
first_item = next(my_iterator)
print(first_item)  # Kết quả: ('apple', 3)

- Sử dụng islice để phân tách dict hoặc lấy phần tử theo thứ tự vì dict ko có idx:
VD:
from itertools import islice

my_dict = {'apple': 3, 'banana': 1, 'cherry': 5, 'date': 2}

# Lấy phần tử thứ 2 (vị trí index = 1)
# islice(iterable, start, stop)
second_item = next(islice(my_dict.items(), 1, 2))

print(second_item)  # Kết quả: ('banana', 1)

    + Hoặc chuyển đổi sang list để dùng idx tuy nhiên tốn bộ nhớ hơn:
VD:
my_dict = {'apple': 3, 'banana': 1, 'cherry': 5, 'date': 2}
# Chuyển các items thành list các tuple
items_list = list(my_dict.items())

# Lấy phần tử thứ 2 (index 1)
second_item = items_list[1]

print(second_item)  # Kết quả: ('banana', 1)
# Nếu bạn chỉ muốn lấy riêng Key hoặc Value của phần tử thứ 2:
second_key = items_list[1][0]    # 'banana'
second_value = items_list[1][1]  # 1

2.Khai báo
- Liệt kê các cặp key:value trong {}
infor = {'ten':'Quyen', 'tuoi':20}

- Tạo bằng constructor:dict(iterable) nhưng iterable phải có dạng phần tử là cặp
giá trị thỏa mãn điều kiện key của dict
a = [['ten','Quyen'], ['tuoi',20]]
b = dict(a)

- Constructor từ 2 iterable key, value
a = ['ten','tuoi']
b = ['Quyen',20]
c = dict(zip(a,b))

-Tạo từ iterable key với value = default
a = ['a','b','c']
default = 0
b = dict.fromkeys(a,default)

3. Truy xuất
- Tương tự như map của C++ cho phép truy xuất value qua dict[key] hoặc hàm get(key)
- Nếu truy cập dict[key] ko tồn tại sẽ báo lỗi, get(key) thì trả về None

4. Duyệt dict
- Có thể lấy ra tập các key,value hoặc items để duyệt
- Sử dụng đối tượng Counter để đếm tần suất nhanh thay cho dict

5. Các hàm cơ bản
- Thêm 1 phần tử mới / thay đổi value nếu đã tồn tại: dict[key] = value
- Xóa phần tử thông qua key: dict.pop(key) hoặc del dict[key]
- Xóa ngẫu nhiên 1 phần tử: popitem()
- Kiểm tra tồn tại của 1 key bằng toán tử in dict: Mất O(1)
- Kiểm tra tồn tại của 1 key bằng toán tử in dict.values(): Mất O(n)
- Trộn 2 dict / Nối 2 dict: dict1.update(dict2)

6. Dict comprehension
- Giúp tạo 1 dict nhanh chóng tương tự list comprehension
- Cú pháp: a = {key:value for var in iterable}
'''

a = {'ten':'Quyen', 'tuoi':20, 'nghe':'sinh vien'}
for x in a.keys():
    print(x)

# duyệt dict mặc định là tập keys
for x in a:
    print(x)

for x in a.values():
    print(x)

#  items sẽ có kdl tuple
for x in a.items():
    print(x)

