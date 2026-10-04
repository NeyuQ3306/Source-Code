'''
String trong Python
1. Tính chất
- Trong Java ko có kdl char nên 1 kí tự cũng coi là 1 str
- Có tính bất biến immutable nên ko thể bị thay đổi, xóa, thêm
-> Đa số các hàm thao tác là trả về str mới ko làm thay đổi str ban đầu
-> Làm key cho dict, làm phần tử cho set
- Có thể truy cập thông qua idx, negative idx tương tự list
- Cũng có tính chất str slicing tương tự list[start:stop:step]

2. Khởi tạo
- Đặt trong dấu nháy đơn '' hoặc nháy kép ""
- Bằng constructor: str(object)

3. Các hàm thông dụng
- Nối 2 xâu bằng toán tử +
- replace(s,t): thay thế xâu s thành xâu t (nếu có nhiều nhiều xâu s thay đổi toàn bộ)
- split("delim"): tách các từ trong xâu theo delim
-> nếu có nhiều delim liền nhau thì replace thành dấu cách trước r mới tách
- 'delim'.join(s): kết hợp các từ rời rạc thành 1 xâu phân tách bới delim
- Các hàm chuyển đổi hoa thường:
    upper()
    lower()
    capitalize(): viết hoa chữ cái đầu của xâu
    swapcase(): đảo ngược chữ cái hoa <-> thường
    title(): viết hoa chữ cái đầu của từng từ

- Kiểm tra xâu con: Toán tử in hoặc hàm find: Đpt O(n)
- Hàm ord(kí tự), chr(num) để chuyển đổi giữa kí tự và mã ASCII

4. String format
- Có 3 cách nhúng biến vào xâu kí tự
C1: s = '%s is %d years old' % ('CR7', 37)
C2: s = '{0} is {1} years old'.format('CR7', 37)
C3:
name = 'CR7'
age = 37
s = f'{name} is {age} years old'

s = f"{1000000:,}"  # Kết quả: '1,000,000'
s = f"{5:03d}"  # Kết quả: '005'
s = f"{3.14159:.2f}"  # Kết quả: '3.14'
'''