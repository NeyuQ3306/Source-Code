'''
1. Hàm trong Python
- Cú pháp:
    def function_name(parameter):
        code
        return value # nếu hàm cần trả về 1 giá trị nào đó, ko có câu lệnh return thì mặc định giá trị None

    ! parameter là tham số hình thức có nhiệm vụ làm biến tính toán/thực thi chức năng của hàm
    ! Khi gọi hàm thì ta truyền vào các đối số hay tham số chính thức - argument để gán cho các parameter

- Để phân biệt giữa các hàm chức năng và chương trình chính của mã code thì ta def các hàm ở trên và đặt code của chương
trình chính ở trong if __name__ == '__main__':


2. Điểm mới so với hàm trong C++
- Vì Python ko cần khai báo kiểu dữ liệu của biến nên ta cũng ko cần xác định kiểu dữ liệu trả về của hàm, của tham số
- Có thể return về nhiều giá trị - điểm mạnh hơn so với C++
def calc(a, b):
    return a + b, a - b

- Hàm có thể coi là 1 giá trị và gán cho biến khác được
def hello():
    print("Hello")

f = hello

f()

- Hàm lồng nhau - thật ra là C++ vẫn có thể gọi hàm trong hàm được
- Viết hàm bằng lamda - C++ cũng có nhưng ít sử dụng chỉ nên dùng cho các hàm ngắn như cmp của sort
- Có thể chú thích kiểu: Tuy nhiên đây chỉ là chú thích nên kiểu dữ liệu tham số sẽ phụ thuộc vào đối số truyền vào
def add(a: int, b: int) -> int:
    return a + b

    
- Keyword argument: truyền tham số theo tên
    ! Vì thứ tự truyền đối số tương ứng với thứ tự của tham số hình thức nên thứ tự truyền vào hàm là quan trọng
    ! Thay vào đó có thể gán trực tiếp tham số hình thức = đối số khi gọi hàm
def xinchao(lastname, firstname):
    print(lastname, firstname)

xinchao('Minh', 'Quyen')
xinchao(firstname = 'Quyen', lastname = 'Minh')

- Default argument: tham số mặc định
    ! Nếu hàm có nhiều tham số hình thức mà khi gọi hàm ko truyền đối số tương ứng thì tham số hình thức được mặc định
    1 giá trị cho trước
    ! Giá trị mặc định được sử dụng khi ko có đối số tương ứng

def xinchao(name = 'somebody'):
    print('Hello', name)

xinchao('Quyen')
xinchao()

- Không cần truyền tham chiếu (&) như C++. Việc đối tượng có bị thay đổi hay không phụ thuộc vào tính 
mutable/immutable của kiểu dữ liệu.
    ! Kiểu bất biến (immutable) như int, float, str, tuple: bên trong hàm không thể thay đổi chính đối tượng đó.
    ! Kiểu có thể thay đổi (mutable) như list, dict, set: nếu sửa trực tiếp (ví dụ append, gán phần tử...), đối tượng
    bên ngoài cũng thay đổi.

- Variable length argument: được sử dụng khi ko biết trước số lượng tham số của hàm
    ! *args: khi tham số của hàm có * ở trước hàm sẽ tự động gom tất cả các đối số thành 1 tuple (nói rõ hơn ở phần tuple)
    và có thể sử dụng args như 1 tuple
    ! *kwargs: được sử dụng với keyword argument, các đối số được thu thập thành 1 dictionary, trong đó tên đối số
    là key và giá trị đối số là value

- Một chút sơ quá về tuple và dictionary:
    ! tuple của Python khác với tuple của C++ là có thể lưu 3 phần tử với kiểu dữ liệu có thể khác nhau, tuple của Python
    có hình thức tương tự như 1 const vector của C++ nên có tính chất thứ tự theo chỉ số nhưng ko thể chỉnh sửa được giá trị
    các phần tử hay thêm bớt phần tử -> tính bất biến immutable
    ! Tuy nhiên cách lưu trữ lại tương đồng với tuple của C++ là các phần tử có thể có kiểu dữ liệu khác nhau
    ! dictionary bản chất tương tự như map của C++ gồm 2 phần là key-value giúp ánh xạ truy xuất nhanh, nhưng thực chất 
    là unordered_map vì ko có tính sắp xếp như map C++
    ! Nên dictionary của Python sẽ có tốc độ truy xuất tb là O(1) vì cài đặt bằng bảng băm - hash table giống unordered map
'''
