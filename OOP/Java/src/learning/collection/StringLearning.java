package learning.collection;

import java.util.StringTokenizer;

public class StringLearning {
    /*
        String trong Java là 1 lớp đối tượng để xử lý xâu kí tự tương tự như C++ cũng cung cấp các hàm để thao tác
        xâu nhanh chóng
    1. Đọc vào xâu
    - Sử dụng: nextLine(): để đọc cả dòng cho tới khi đọc tới phím enter hoặc next(): để đọc từng từ gặp khoảng
    trắng thì dừng
    - Lỗi hay gặp: dùng nextLine() sau khi đọc vào các kdl số nextInt(), nextLong(), ... sẽ để lại phím enter trong
    bộ đệm đến khi dùng nextLine() thì string bị rỗng
        -> giải pháp: sử dụng sc.nextLine() để xóa dấu enter trong bộ đệm rồi mới đọc vào xâu cần đọc

    2. Các hàm thông dụng
    - length(): trả số độ dài xâu kí tự
    - charAt(index): trả về kí tự ở chỉ số index
    - toUpperCase(): trả về xâu in hoa của xâu s nhưng ko làm thay đổi xâu s ban đầu
    - toLowerCase(): tương tự trả về xâu in thường của s
    - s.concat(t): nối xâu t vào cuối xâu s hoặc có thể dùng toán tử +
    - s.compareTo(t): so sánh thứ tự từ điển xâu s với t, trả về 0 nếu 2 xâu trùng nhau, trả về < 0 nếu s đứng trước t
    và > 0 nếu s đứng sau t
    - s.compareToIgnoreCase(t): tương tự nhưng sẽ bỏ qua kí tự in hoa in thường -> chuyển cả 2 xâu về cùng 1 dạng toàn
    thường/toàn hoa để so sánh
    - s.substring(fromIndex, toIndex): trả về xâu con từ chỉ số fromIndex tới toIndex-1
    - s.contains(t): kiểm tra sự tồn tại của t trong s
    - s.starts/endWith(string): kiểm tra từ đứng đầu/cuối có phải string ko
    - s.replace(s1, s2): thay từ s1 thành s2
    - s.trim(): xóa khoảng trắng đầu/cuối
    - s.equals(t): so sánh 2 xâu có trùng nhau
    - s.equalsIgnoreCase(t): so sánh bỏ qua in hoa in thường
    - s.replaceAll("[regex]", "char"): thay các kí tự regex thành char mới
        VD: s = s .replaceAll("[a-zA-Z]", " "): thay toàn bộ chữ cái thành khoảng trắng
        
    3. Tách từ trong xâu
    - Sử dụng split và regex - tách khi gặp loại kí tự nào đó
    - VD: s.split("regex"); hoặc s.trim().split("\\s+") để xóa khoảng trắng đầu cuối nếu có
        String s = "Java OOP PYTHON  SQL";
        String[] tok = s.split("\\s+");

        for (int i = 0; i < tok.length; i++) {
            System.out.println(tok[i]);
        }
    -> \\s+ có ý nghĩa là 1 hoặc nhiều khoảng trắng

    - Sử dụng StringTokenizer: StringTokenizer st = new StringTokenizer(s, "delim");
        st.hasMoreTokens(): để kiểm tra xem còn có từ tiếp theo ko
        st.nextToken(): để truy xuất tới từ tiếp theo

     4. Chuyển qua lại giữa xâu và số
     - Muốn chuyền từ số -> xâu: Chỉ cần cộng với 1 xâu rỗng ""
     - Muốn chuyển từ xâu -> số: Sử dụng class Integer.parseInt/Long(s)

     5. Lớp BigInteger để cung cấp các phép toán với số nguyên lớn > long

     6. Lớp StringBuilder để cung cấp các thao tác chèn, xóa, thay đổi in hoa in thường các kí tự
     - Vì String trong Java là bất biến nên ko thể bị thay đổi khi đã khai báo

    */

    public static void main(String[] args) {
//        String s = "Java OOP PYTHON  SQL";
//        String[] tok = s.split("\\s+");
//
//        for (int i = 0; i < tok.length; i++) {
//            System.out.println(tok[i]);
//        }

        // nếu muốn tách theo nhiều regex thì dùng "[regex1 regex2 ...]" để tách khi gặp 1 trong các regex đã nêu
//        String str = "Java-OOP,SQL C";
//        String[] token = str.split("[-, ]");
//
//        for (int i = 0; i < token.length; i++) {
//            System.out.println(token[i]);
//        }

        String s = "Java-OOP,Python C++";
        StringTokenizer st = new StringTokenizer(s, "-, ");
        while(st.hasMoreTokens()){
            System.out.println(st.nextToken());
        }
    }
}
