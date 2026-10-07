'''
Để tách từ trong xâu theo delim ta có 2 cách:
- Tách theo 1 delim thì dùng split("delim"), ko khai báo mặc định delim = khoảng trắng
- Tách theo nhiều delim thì dùng re.split(r'[delim]',str) trả về 1 list str
- Nếu delimiter là chuỗi chứ không chỉ một ký tự, dùng |:
    re.split(r'abc|xyz|hello', s)
- Nếu delim là nhiều khoảng trắng hay nhiều delim liên tiếp nhau thì dùng:
    re.split(r'[\s,.?!:;/()-]+', s)
        \s: 1 hoặc nhiều khoảng trắng
        +: là có thể nhiều delim liên tiếp

- Nếu chỉ yêu cầu tách theo kí tự ko phải chữ cái và chữ số thì:
    re.split(r'[^a-z0-9A-Z]+', s)
        ^ ở đây là phép phủ định
        a-z / A-Z: tập chữ cái
        0-9: tập chữ số
VD:
import re
s = "hello,world;python-java"
a = re.split(r'[,;-]', s)
print(a)

-> ['hello', 'world', 'python', 'java']
'''