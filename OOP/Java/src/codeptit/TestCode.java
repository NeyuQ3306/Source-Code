package codeptit;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class TestCode {

    public static class NhanVien {
        private String mnv, ten, chucVu, soHieu, hso;

        public NhanVien(String s) {
            String[] tok = s.trim().split("\\s+");

            mnv = tok[0];

            ten = "";
            for (int i = 1; i < tok.length; i++) {
                ten += tok[i] + " ";
            }
            ten = ten.trim();

            chucVu = mnv.substring(0, 2);
            hso = mnv.substring(2, 4);
            soHieu = mnv.substring(4);

            // Các mã có số hiệu không hợp lệ
            int stt = Integer.parseInt(soHieu);

            if (chucVu.equals("GD") && stt > 1) {
                chucVu = "NV";
            } else if ((chucVu.equals("TP") || chucVu.equals("PP"))
                    && stt > 3) {
                chucVu = "NV";
            }
        }

        public void setChucVu(String x) {
            chucVu = x;
        }

        public String getChucVu() {
            return chucVu;
        }

        public String getHso() {
            return hso;
        }

        public String getSoHieu() {
            return soHieu;
        }

        public String getTen() {
            return ten.toLowerCase();
        }

        @Override
        public String toString() {
            return ten + " " + chucVu + " " + soHieu + " " + hso;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());

        ArrayList<NhanVien> list = new ArrayList<>();

        int cntGD = 0;
        int cntTP = 0;
        int cntPP = 0;

        for (int i = 0; i < n; i++) {
            NhanVien nv = new NhanVien(sc.nextLine());

            String chucVu = nv.getChucVu();

            // Công ty chỉ có 1 GD
            if (chucVu.equals("GD")) {
                cntGD++;

                if (cntGD > 1) {
                    nv.setChucVu("NV");
                }
            }

            // Công ty có không quá 3 TP
            else if (chucVu.equals("TP")) {
                cntTP++;

                if (cntTP > 3) {
                    nv.setChucVu("NV");
                }
            }

            // Công ty có không quá 3 PP
            else if (chucVu.equals("PP")) {
                cntPP++;

                if (cntPP > 3) {
                    nv.setChucVu("NV");
                }
            }

            list.add(nv);
        }

        // Hệ số lương giảm dần
        // Nếu bằng nhau -> số hiệu tăng dần
        list.sort(
                Comparator.comparing(
                        NhanVien::getHso,
                        Comparator.reverseOrder()
                ).thenComparing(NhanVien::getSoHieu)
        );

        int q = Integer.parseInt(sc.nextLine());

        while (q-- > 0) {
            String s = sc.nextLine().trim().toLowerCase();

            for (NhanVien nv : list) {
                if (nv.getTen().contains(s)) {
                    System.out.println(nv);
                }
            }

            System.out.println();
        }
    }
}