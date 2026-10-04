package codeptit;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class J05033 {
    public static class Time{
        private int gio,phut,giay;

        public Time(int a, int b, int c){
            gio = a;
            phut = b;
            giay = c;
        }

        public int getGio(){return gio;}
        public int getPhut(){return phut;}
        public int getGiay(){return giay;}

        public String toString(){
            return gio + " " + phut + " " + giay;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Time> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(new Time(sc.nextInt(),sc.nextInt(),sc.nextInt()));
        }

        Collections.sort(a, new Comparator<Time>() {
            @Override
            public int compare(Time o1, Time o2) {
                if(o1.gio == o2.gio){
                    if(o1.getPhut() == o2.getPhut()){
                        return o1.getGiay() - o2.getGiay();
                    } else{
                        return o1.getPhut() - o2.getPhut();
                    }
                } else{
                    return o1.getGio() - o2.getGio();
                }
            }
        });

        for (Time time : a) {
            System.out.println(time);
        }
    }
}
