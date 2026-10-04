'''
Cách viết comparator trong Python
1. Thư viện
- from functools import cmp_to_key

2. Cú pháp: sort(key = cmp_to_key(cmp),reverse)

3. Sử dụng
- Tương tự như cmp trong Java,C++ dùng khi có nhiều tiêu chí sắp xếp
- Sử dụng trong các bài class, còn nếu tiêu chí đơn giản thì sử dụng lambda
'''
from functools import cmp_to_key

def tongcs(n):
    res = 0
    while n != 0:
        res += n % 10
        n //= 10

    return res

def cmp(a,b):
    if tongcs(a) != tongcs(b):
        return tongcs(a) - tongcs(b)
    else:
        return b - a

a = [30,123,3000,321,4,56,8,1]
a.sort(key = cmp_to_key(cmp))
print(a)
