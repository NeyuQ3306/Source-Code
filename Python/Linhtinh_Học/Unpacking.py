'''
Kỹ thuật Unpacking (Mở gói / Phân rã dữ liệu) là một trong những tính năng "Pythonic" nhất giúp bạn gán các phần tử
trong một chuỗi/container (List, Tuple, String, Dict) vào các biến riêng biệt chỉ trong 1 dòng code.

1. Unpacking cơ bản
- Số lượng biến ở bên trái phải bằng chính xác số lượng phần tử của container ở bên phải, nếu không Python sẽ quăng
lỗi ValueError
# Unpacking với Tuple hoặc List
point = (10, 20)
x, y = point  # x = 10, y = 20

# Unpacking với String
a, b, c = "CAT"  # a = 'C', b = 'A', c = 'T'

# Tráo đổi giá trị 2 biến (Swap) siêu tốc - Không cần biến tạm!
a, b = 5, 10
a, b = b, a  # a = 10, b = 5

2. Unpacking nâng cao với toán tử *
- Khi chỉ muốn lấy 1 số phần tử đầu/cuối và phần còn lại gom thành 1 list
numbers = [1, 2, 3, 4, 5]

# Lấy phần tử đầu, gom phần còn lại
first, *rest = numbers
print(first) # 1
print(rest)  # [2, 3, 4, 5]

# Lấy đầu, lấy cuối, gom phần giữa
first, *middle, last = numbers
print(first)  # 1
print(middle) # [2, 3, 4]
print(last)   # 5

# Bỏ qua các giá trị không cần thiết bằng biến '_' (Quy ước trong Python)
a, *_, b = numbers # Chỉ lấy phần tử đầu và cuối

3. Gộp Container bằng * và **
Bạn có thể dùng * cho List/Tuple/Set và ** cho Dictionary để gộp hoặc mở rộng dữ 
liệu cực kỳ nhanh chóng.
'''