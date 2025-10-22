package Aula3;

import java.util.Objects;

public class Main {
    public static void main(String[] args) {
        Estoque estoque01 = new Estoque("Impressora Jato de Tinta", 13, 6);
        Estoque estoque02 = new Estoque("Monitor LCD 17 polegadas", 11, 13);
        Estoque estoque03 = new Estoque("Mouse Otico", 6, 2);
        Estoque estoque04 = new Estoque("Impressora Jato de Tinta", 13, 6);

        estoque01.mostra();
        estoque02.mostra();
        estoque03.mostra();

        estoque01.darBaixa(5);
        estoque02.repor(7);
        estoque03.darBaixa(4);

        System.out.println("Precisa repor:\n" +
                "\t" + estoque01.getNome() + " : " + estoque01.precisaRepor() + "\n" +
                "\t" + estoque02.getNome() + " : " + estoque02.precisaRepor() + "\n" +
                "\t" + estoque03.getNome() + " : " + estoque03.precisaRepor()
        );

        estoque01.mostra();
        estoque02.mostra();
        estoque03.mostra();

        // Equals
        System.out.println(Objects.equals(estoque01, estoque02));
        // Equals embutido e sobrescrito na classe
        System.out.println(estoque01.equals(estoque04));
        }
}
