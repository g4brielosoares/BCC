package Aula2;

public class Main {
    public static void main(String[] args) {
        Departamento d1 = new Departamento("RH", 1234);
        Empregado e = new Empregado("João", 24, d1);

        System.out.println(e);
    }
}