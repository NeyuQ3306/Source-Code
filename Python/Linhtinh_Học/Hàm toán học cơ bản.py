''' 
- Muốn sử dụng các hàm toán học có sẵn thì cần import math - thư viện / module toán học
    import math
    print(help(math)) - help(math) để xem module cung cấp những function nào

- Lưu ý nếu chỉ import math thì khi sử dụng các hàm có sẵn phải dùng cú pháp math.function() còn nếu muốn ngắn gọn thì
dùng: from math import * thì khi dùng hàm chỉ cần function() là được
    VD:
        dùng import math: print(math.sqrt(36))
        dùng from math import *: print(sqrt(36))

- Một số hàm toán học cơ bản: Tương tự như C++
    Hàm căn bậc 2: sqrt(num) - trả về số float
    Hàm căn bậc 2 trả về số nguyên: isqrt(num)
    Hàm lũy thừa: pow(cơ số, số mũ) - trả về float - dùng toán tử ** cho tiện đỡ phải ép kiểu
    Hàm làm tròn lên: ceil(num)
    Hàm làm tròn xuống: floor(num)
    Hàm ước chung lớn nhất: gcd(a, b)
    Hàm bội chung nhỏ nhất: lcm(a, b)
    Hàm trị tuyệt đối: abs(num)
    Hàm trị tuyệt đối số thực: fabs(num_float)
    Hàm max, min: max(list)/min(list)


- Một số hàm mới:
    Hàm giai thừa: factorial(num)
    Hàm tính tổ hợp chập k của n: comb(n,k)
    Hàm làm tròn đến chữ số thứ k của phần thập phân: round(num, k)
    Hàm tính tổng list: sum(list)
'''


from math import *
a = round(123.4556, 2)
print(a)

