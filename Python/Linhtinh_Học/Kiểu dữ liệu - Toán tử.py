'''
1. Biến: phương thức lưu trữ dữ liệu
- Python ko cần phải khai báo kiểu dữ liệu như int, long long, string như C++ mà chỉ cần gán giá trị cho 1 biến thì
biến sẽ tự động có kiểu dữ liệu tương ứng
- Để biết kiểu dữ liệu của 1 biến a thì dùng type(a) thì output có dạng <class 'kiểu dữ liệu'>
VD:
a = 100
print(type(a))
- Quy tăc đặt tên tương tự như C++: Ko chứa dấu cách, kí tự đặc biệt, số ko được ở đầu và phân biệt in hoa in thường

2. Kiểu dữ liệu
- Số:
+ Số nguyên int: <class 'int'> a = 100
    ! Ưu điểm của số trong Python so với C++ là ko có giới hạn về giá trị có thể lưu nên có thể sử dụng xử lý số 
nguyên lớn
    ! Có thể in ra các số nguyên ở hệ đếm khác chỉ cần thêm tiền tố ở trước
        VD: có thể dùng in thường 0b hay in hoa 0B đều được
            a = 0b101 -> hệ binary 
            print(a)
            b = 0o571 -> hệ octal 
            print(b)
            c = 0xA14B -> hệ hexan
            print(c)
    -> để chuyển đổi nhanh giữa hệ 10 với các hệ đếm dùng hàm: format(num,'type')
        VD: s = format(10,'b') ->  1010
            s = format(10,'o') -> 12
            s = format(10,'x') -> a
            s = format(10,'X') -> A
    ! Từ các hệ khác về hệ 10 dùng hàm: int(chuỗi_số,hệ_cơ_số)
        VD: n = int('1010',2) -> 10    

+ Số thực float: <class 'float'> a = 10.5
    ! Số thực là số âm hoặc dương và có phần thập phân
    ! Khác với số nguyên thì số thực chỉ lưu được trong khoảng giá trị nhất định từ 10^-324 tới 10^308, các giá trị lớn
    hơn thì được mô tả là inf, nhỏ hơn thì được coi là 0.0
        VD:
            a = 1e-324
            print(a)
            b = 1e309
            print(b)
    ! Cú pháp được in số lượng chữ số phần thập phân:
        a = 36.3735
        print('%.2f' % a)
        print(round(a, 3)) -> dùng cẩn thận vì hàm round làm tròn có thể in ra sai kết quả
        print('{:.4f}'.format(a))

+ Số phức complex: <class 'complex'> a = 1 + 5j
    ! Gồm 2 phần: Phần thực và phần ảo đi kèm với j
    ! Truy xuất phần thực .real và phần ảo .imag -> output là số thực


    
- Bool: True / False - <class 'bool'>
    ! Các giá trị được xác định là True là xâu khác rỗng và số khác 0
    ! Nhưng phải ép kiểu trước khi xét:
        VD:
            a = 'deo me vcl'
            print(bool(a))
            b = 18
            print(bool(b))

- String: <class 'str'>
    ! Xâu kí tự được trong dấu nháy đơn '' hoặc nháy kép "" trên 1 dòng
    ! Nếu lưu trên nhiều dòng phải đặt trong dấu nháy 3 """  """ / ''' '''


- Ép kiểu giữa các kiểu dữ liệu tương tự như C++

3. Các loại toán tử
- Toán tử gán:
    ! giữa 2 giá trị: a = b
    ! gán nhanh cho nhiều biến: a, b, c = 10, 20, 30
    ! hoán vị giá trị giữa 2 biến: a, b = b, a

- Toán tử tính toán: cũng có +, -, *, % như C++
    ! có thêm 2 phép chia là / - chia thập phân và // - chia nguyên
    ! có phép lũy thừa **

- Toán tử so sánh: tương tự C++
- Toán tử logic: dùng chữ cái: and, or, not thay vì kí hiệu &&, ||, ! như C++
- Toán tử nhận dạng: dùng để so sánh 2 đối tượng chứ ko phải 2 giá trị
    ! is: trả về True nếu 2 đối tượng giống nhau
    ! is not: trả về True nếu 2 đối tượng khác nhau
    ! Toán tử thành viên: dùng kiểm tra sự tồn tại của 1 đối tượng trong str, list, ...
        in: trả về true nếu có xuất hiện
        not in: trả về true nếu ko xuất hiện
'''

