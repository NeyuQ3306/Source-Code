package learning.control;

public class Loop {
    public static void main(String[] args){
        /*
            Vòng lặp trong Java thì tương tự như trong C++, gồm các hàm lặp quen thuộc như for, while và do while
        1. for
        - Cú pháp:
        for(int i = giá trị khởi tạo; Biểu thức điều kiện dừng của i; Cập nhật i sau mỗi lần lặp){
            code
        }

        2. while
        - Cú pháp:
        while(condition){
            code
        }

        3. do while
        do{
            code
        }while(conditon);

        4. Câu lệnh break, continue để điều khiển chương trình cũng tương tự
        5. for each: Tương tự như C++ dùng để duyệt nhanh các container
        */

        for(int i=1; i<=10; i++)
            System.out.println(i);

        int j = 1;
        while(j <= 5){
            System.out.println("Hello");
            j += 1;
        }

        int i = 1;
        do{
            System.out.println("Java");
            i += 1;
        }while(i <= 5);
    }
}
