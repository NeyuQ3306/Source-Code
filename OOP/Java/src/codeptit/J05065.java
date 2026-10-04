package codeptit;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class J05065 {
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
        }

        public void setChucVu(String x){
            chucVu = x;
        }
        public String getChucVu(){return chucVu;}
        public String getHso(){return hso;}
        public String getSoHieu(){return soHieu;}

        public String toString(){
            return ten + " " + chucVu + " " + soHieu + " " + hso;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<NhanVien> list = new ArrayList<>();

        int cntGD = 0, cntTP = 0, cntPP = 0;
        for (int i = 0; i < n; i++) {
            NhanVien a = new NhanVien(sc.nextLine());
            String chucVu = a.getChucVu();

            if(chucVu.equals("GD")){
                ++cntGD;
                if(cntGD > 1){
                    a.setChucVu("NV");
                }
            } else if(chucVu.equals("TP")){
                ++cntTP;
                if(cntTP > 3){
                    a.setChucVu("NV");
                }
            } else if(chucVu.equals("PP")){
                ++cntPP;
                if(cntPP > 3){
                    a.setChucVu("NV");
                }
            }

            list.add(a);
        }

        list.sort(Comparator.comparing(NhanVien::getHso,Comparator.reverseOrder()).thenComparing(NhanVien::getSoHieu));
        int q = Integer.parseInt(sc.nextLine());
        while(q-->0){
            String s = sc.nextLine();
            for (NhanVien nhanVien : list) {
                if(nhanVien.getChucVu().equals(s)){
                    System.out.println(nhanVien);
                }
            }

            System.out.println();
        }
    }
}
