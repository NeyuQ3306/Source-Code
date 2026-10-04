'''
Cấu trúc dữ liệu list trong Python: Sử dụng như mảng 1 chiều/ 2 chiều trong C++ nhưng linh hoạt hơn
- Cú pháp: thislist = [1,2,3, 'csd', 2.4, "python"]
- Tính chất:
    + Các phần tử trong list có thứ tự
    + Có thể truy cập thông qua idx
    + Có thể chứa nhiều kiểu dữ liệu đồng thời
    + Là kdl mutable nên các phần tử của list có thể bị thay đổi

- List constructor: Hàm khởi tạo list
    + Cú pháp: thislist = list(iterable)
    + Tạo 1 list từ 1 iterable được truyền vào

- Truy xuất phần tử thông quả idx:
    + Idx dương: 0 -> len(list) - 1
    + Idx âm: -1 -> -len(list) (duyệt ngược list)
    + Có thể duyệt bằng for idx in iterable hoặc for each: for item in list

- list làm tham số cho hàm: 
    + Vì list là đối tượng mutable nên khi truyền vào làm tham số cho hàm,
    nếu có thay đổi giá trị phần tử của list thì list ban đầu cũng bị thay đổi

- Các hàm thông dụng của list:
    + len(thislist): trả về số lượng phần tử
    + append(item): để thêm 1 phần tử vào cuối list
    + insert(idx, item): chèn item vào chỉ số idx
    + pop(idx): xóa 1 phần tử khỏi list, ko nhập idx thì xóa phần tử cuối
    + del list[idx]: xóa 1 phần tử tại vị trí idx
    + remove(value): xóa 1 phần tử thông qua giá trị, nếu có nhiều phần tử = value thì xóa ptu đầu tiên
    + clear(): xóa mọi phần tử của list
    + Hàm count(item): trả về tần suất của 1 item trong list
    + Hàm index(item): trả về chỉ số đầu tiên của item trong list

- Các phương thức thông dụng của list:
    + Nhân bản list: Giúp nhân bản nội dung của list ban đầu
        a = [1,2,3]
        b = a * 2 // b = [1,2,3,1,2,3]
    + Tìm kiếm phần tử trong list: if item in list - đpt O(N)
    + Combine list: Nối 2 list lại với nhau hoặc dùng toán tử +
    + Sao chép list: Trả về 1 list mới có nội dung giống list ban đầu
        a = [1,2,3]
        b = a.copy() // b = [1,2,3] nhưng b != a

        // Nếu gán b = a từ đầu thì b is a vì củng trỏ tới 1 đối tượng list


    
'''