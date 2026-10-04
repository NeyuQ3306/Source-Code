"""
1. Hàm in ra màn hình: print(object, sep, end)
- Object: Đối tượng - biến (số, string, mảng) cần in ra màn hình, nhiều đối tượng thì ngăn cách bằng dấu ,
- sep: Kí tự phân cách giữa các đối tượng, ko khai báo thì mặc định là khoảng trắng
- end: Kí tự được in cuối cùng của 1 dòng, ko khai báo thì mặc định là xuống dòng - \n

VD: print(100, 200, 300, sep = "-", end = " ! ")

2. Chú thích và syntax 
- Câu lệnh trong Python ko cần kết thúc bằng ;
- Ko sử dụng {} để xác định chương trình con mà sẽ dùng thụt lùi đầu dòng
VD:
if(a>b):
    a = a + 1;

- Ko cần khai báo kiểu dữ liệu
- String, kí tự được nằm trong dấu " " hoặc ' ' là tương đương nhau
- Chú thích trên 1 dòng dùng #, trên nhiều dòng dùng ''' cmt ''' - hoặc là thay ' bằng "

3. Hàm nhập input và hàm map
- Hàm input:
    ! Cú pháp: input(prompt) - prompt là kiểu câu dẫn xuất hiện trước khi nhập dữ liệu
        a = input('Nhap so a tu ban phim: ')
        
    ! Chú ý giá trị trả về của hàm input luôn là kiểu str nên cần ép kiểu sang dữ liệu cần 
        a = input()
        print(type(a))
        b = int(input())
        print(type(b))

    ! Cơ chế hoạt động của hàm này là đọc hết cả 1 dòng và gán cho biến được khai báo nên khi muốn nhập nhiều giá trị
    trên cùng 1 dòng cần sử dụng hàm map:
        a, b, c = map(int, input().split())
        print(a,b,c)

        - map(kiểu dữ liệu, list) dùng để ép từng phần tử của list sang kiểu dữ liệu mong muốn
        - split() dùng để tách xâu kí tự và lưu vào 1 list string
"""


