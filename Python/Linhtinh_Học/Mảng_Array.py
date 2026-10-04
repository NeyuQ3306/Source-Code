'''
Mảng trong Python
1. Mảng 1 chiều
- Sử dụng list để lữu trữ

2. Mảng 2 chiều
- Sử dụng nested list để lưu trữ
- Khai báo:
    Thủ công nhập từng hàng từng cột:
        a = []
        for i in range(n):
            b = list(map(int,input().split()))
            a.append(b)

    Sử dụng list comprehension: Tạo mảng toàn số 0
        a = for[[0 for _ in range(m)] for _ in range(n)]
        for i in range(n):
            a[i] = list(map(int,input().split()))

- Truy xuất qua chỉ số tương tự như trong Java,C++
- Duyệt:
    Duyệt từng hàng từng cột:
        for i in range(n):
            for j in range(m):
                print(a[i][j], end = '')
            print()

'''

n,m = map(int,input().split());
a = []

for i in range(n):
    b = list(map(int,input().split()))
    a.append(b)

print(a)

