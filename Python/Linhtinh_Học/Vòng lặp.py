'''
1. Vòng lặp for
- Cú pháp:
for var in iterable: # var là 1 biến để duyệt phụ thuộc vào kiểu dữ liệu lưu trữ trong iterable
    code
else:
    code    

! 1 số điều khác so với for của C++:
- iterable là 1 kiểu đối tượng/cấu trúc có thể duyệt như list, array, string, dictionary, ... và có thể tự định nghĩa
như struct
- hàm range(start, stop, step), mặc định start = 0, step = 1 nếu ko khai báo dùng để sinh 1 dãy số từ start -> stop-1 
dùng làm con đếm cho vòng lặp
- hàm zip(a,b,c) dùng để duyệt đồng thời nhiều iterable 1 lúc
VD:
    a = [1, 2, 3]
    b = [4, 5, 6]
    c = [7, 8, 9]

    for x, y, z in zip(a, b, c):
        print(x, y, z)
- hàm enumerate(iterable) dùng để duyệt đồng thời chỉ số và giá trị nếu ko thích dùng range(len(a))
VD:
    a = [1, 2, 3]

    for i, x in enumerate(a):
        print(i, x)

    for i in range(len(a)):
        print(i, a[i])

- hàm reversed(a) để duyệt ngược
- for lồng nhau thì cũng tương tự C++
- câu lệnh break, continue thì tương tự như C++ ngoài ra có điểm khác biệt là câu lệnh else trong for khi mà đã duyệt
qua hết tất cả các giá trị thì sẽ nhảy vào câu lệnh else


2. Vòng lặp while thì cũng tương tự như C++
- Cú pháp:
while condition:
    code
else:
    code if condition false
VD:
    i = 1
    while i <= 5:
        print(i)
        i += 1
    else:
        print('done')
'''
