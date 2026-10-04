'''
Với các bài toán có số lượng testcase lớn - cỡ triệu test việc sử dụng
input() có thể dẫn đến chương trình đúng thuật toán vẫn bị tle
-> Giải pháp sử dụng sys.stdin

1. sys.stdin.readline() — Đọc từng dòng (Nhanh hơn input())
- Thay vì dùng input(), bạn dùng sys.stdin.readline().
- Điểm khác biệt lớn nhất: sys.stdin.readline() giữ nguyên ký tự xuống dòng (\n) ở cuối câu lệnh. Do đó, bạn thường
phải kết hợp thêm hàm .strip() để xóa khoảng trắng và ký tự thừa.

2. sys.stdin.read() — Đọc TOÀN BỘ input một lần (Cực kỳ nhanh)
- Thay vì đọc từng dòng, hàm này hút sạch toàn bộ dữ liệu từ đầu đến cuối file input vào thành một chuỗi (str)
khổng lồ duy nhất.

3. sys.stdin.read().split() — "Bùa hộ mệnh" cho các bài nhiều test case
- Đây là cách viết được sử dụng nhiều nhất trong code tối ưu:
   + sys.stdin.read(): Đọc toàn bộ dữ liệu.
   + .split(): Tự động cắt toàn bộ chuỗi đó dựa theo khoảng trắng (dấu cách, xuống dòng, tab), trả về một danh sách (list)
 chứa tất cả các từ/số theo đúng thứ tự xuất hiện.

4. Dùng vòng lặp for line in sys.stdin (Đọc từng dòng theo dạng luồng)
- Cách này dùng khi bạn không biết trước số lượng test case (đọc đến hết file thì thôi - EOF):
'''