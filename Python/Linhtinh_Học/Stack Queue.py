'''
Python ko có class Stack Queue như trong Java, C++ mà dùng qua
list và modulo collections.deque

1. Stack: sử dụng bằng list
- Các hàm thông dụng của Stack:
Khởi tạo: stack = []
Đẩy phần tử vào đỉnh (Push): stack.append(x)
Lấy và xóa phần tử ở đỉnh (Pop): stack.pop() (Trả về phần tử vừa xóa)
Xem phần tử ở đỉnh mà không xóa (Peek): stack[-1]
Kiểm tra stack có rỗng không: if not stack: hoặc if len(stack) == 0:
Lấy số lượng phần tử: len(stack)

2. Queue: Dùng collections.deque (Double-ended Queue).
from collections import deque
- Các hàm thông dụng của Queue:
Khởi tạo: q = deque() hoặc truyền sẵn list: q = deque([1, 2, 3])
Thêm phần tử vào cuối hàng đợi (Enqueue): q.append(x)
Lấy và xóa phần tử ở đầu hàng đợi (Dequeue): q.popleft()
Xem phần tử ở đầu hàng đợi mà không xóa: q[0]
Xem phần tử ở cuối hàng đợi: q[-1]
Kiểm tra hàng đợi có rỗng không: if not q:
Lấy số lượng phần tử: len(q)
'''