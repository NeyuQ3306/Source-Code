'''
Xử lý file trong Python
1. Hàm open()
- Cú pháp: f = open("Input.txt","mode")
    r: đọc file
    w: ghi file từ đầu (xóa dữ liệu cũ nếu file có dữ liệu sẵn)
    a: mở file ghi tiếp vào cuối
    x: tạo file (gây lỗi nếu file đấy đã tồn tại)
    -> Ngoài ra có thể chỉ rõ file là text hay nhị phân bằng thêm t/b vào cuối mode

- Chú ý:
    Nếu file cần thao tác nằm trong cùng thư mục với file code thì xử dùng đường dẫn tương đối
    Ngược lại sử dụng đường dẫn tuyệt đối
    Với mode w/a nếu chưa tồn tại file thì tạo mới, ngược lại thì sử dụng luôn

- Các hàm thông dụng:
    read(): đọc toàn bộ file
    read(len): đọc len kí tự đầu tiên
    readline(): đọc 1 dòng
    for line in f: đọc từng dòng
    close(): đóng file
    write(string): để ghi file
'''