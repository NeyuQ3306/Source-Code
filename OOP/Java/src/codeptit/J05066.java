package codeptit;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

/*
Bài này Wa là do lỗi khi xác định chức vụ
- Ko được xét theo thứ tự nhập mà phải xét theo số hiệu trước
- Nghĩa là 1 GD thì số hiệu GD001 hợp lệ còn 002 trở đi là NV
- Hoặc 3 TP/PP thì số hiệu TP001->003 hợp lệ còn 004 trở đi là NV
 */

public class J05066 {
    public static class NhanVien{
        private String mnv,ten,chucVu,soHieu,hso;

        public NhanVien(String s){
            String[] tok = s.trim().split("\\s+");
            mnv = tok[0];

            ten = "";
            for (int i = 1; i < tok.length; i++) {
                ten += tok[i] + " ";
            }
            ten = ten.trim();

            chucVu = mnv.substring(0,2);
            hso = mnv.substring(2,4);
            soHieu = mnv.substring(4);
            int stt = Integer.parseInt(soHieu);

            if(chucVu.equals("GD") && stt > 1){
                chucVu = "NV";
            } else if(chucVu.equals("TP") && stt > 3){
                chucVu = "NV";
            } else if(chucVu.equals("PP") && stt > 3){
                chucVu = "NV";
            }
        }

        public void setChucVu(String x){
            chucVu = x;
        }
        public String getChucVu(){return chucVu;}
        public String getHso(){return hso;}
        public String getSoHieu(){return soHieu;}
        public String getTen(){return ten.toLowerCase();}

        public String toString(){
            return ten + " " + chucVu + " " + soHieu + " " + hso;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());

        ArrayList<NhanVien> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(new NhanVien(sc.nextLine()));
        }

        list.sort(Comparator.comparing(NhanVien::getHso,Comparator.reverseOrder()).thenComparing(NhanVien::getSoHieu));
        int q = Integer.parseInt(sc.nextLine());
        while(q-->0){
            String s = sc.nextLine().trim().toLowerCase();
            for (NhanVien nhanVien : list) {
                if(nhanVien.getTen().contains(s)){
                    System.out.println(nhanVien);
                }
            }
            System.out.println();
        }
    }
}