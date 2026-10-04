'''
Hàm sort() của list trong Python:
1. Cú pháp: list.sort(key,reverse)
- key: tiêu chí sắp xếp tăng dần
- reverse: đảo ngược tiêu chí sắp xếp - giảm dần
- Ko khai báo key thì mặc định là sắp xếp tăng dần
- Thay đổi trực tiếp vào list ban đầu
- Có tính chất stable: Cài đặt bằng Tim Sort = MergerSort + InsertionSort
- Độ phức tạp: O(nlogn)

2. Custom key
- key có thể là hàm có sẵn build-in hoặc hàm tự define, lambda
a = [1,-3,-5,6,-8,9]
a.sort(key = lambda x : abs(x))
print(a)
a.sort(reverse = True)
print(a)

- Sắp xếp nested list bằng lambda
a = [[1,2], [2,3], [1,4], [2,1]]
// x là từng list con, truy cập x[0] là tiêu chí sắp xếp tăng dần theo x[0]
a.sort(key = lambda x : x[0])
print(a)

b = [[1,2], [2,3], [1,4], [2,1]]
// nếu 2 list con có x[0] bằng nhau thì sắp xếp theo x[1] giảm dần
b.sort(key = lambda x : (x[0],-x[1]))
print(b)

- Sử dụng itemgetter() hoặc attrgetter() để lấy thuộc tính của 1 class/dict để
làm tiêu chí sắp xếp

3. So sánh sort(key,reverse) và sorted(iterable,key,reverse)
- Nếu muốn ko thay đổi list ban đầu thì sử dụng sorted() sẽ trả về 1 list mới đã sắp
xếp
- Nếu muốn thay đổi trên list ban đầu thì sử dụng sort()

'''

a = [[1,2], [2,3], [1,4], [2,1]]
a.sort(key = lambda x : x[0])
print(a)

b = [[1,2], [2,3], [1,4], [2,1]]
b.sort(key = lambda x : (x[0],-x[1]))
print(b)

c = [1,4,2,15,3,14,6]
d = sorted(c,reverse = True);
print(d)
