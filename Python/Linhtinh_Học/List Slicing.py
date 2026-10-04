'''
Kĩ thuật phân tách list trong Python
- Cú pháp: list[start:stop:step]
    + bắt đầu từ chỉ số start
    + kết thúc ở chỉ số stop - 1
    + tham số nào ko khai báo thì mặc định là [0:len(list):1]
    + Có thể dùng negative idx

- Ứng dụng:
    + Lật ngược list: list[::-1]
    + Thay đổi giá trị của 1 khoảng trong list: list[start:stop:step] = list1
        -> muốn xóa thì thay list1 = []
    + Chèn vào đầu list: list[:0] = list1
    + Chèn vào cuối list: list[len(list):] = list1
    + Copy nhanh 1 list: list1 = list[:]

'''

a = [1,2,3,4]
b = a.copy()
print(a == b)
print(a is b)

c = a[:]
print(a == c)
print(a is c)

a[:3] = [100,200,300]
print(a)

a.reverse()
print(a)

