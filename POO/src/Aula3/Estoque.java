package Aula3;

import java.util.Objects;

public class Estoque {
    private String nome;
    private int qtdAtual;
    private int qtdMinima;

    Estoque(String nome, int qtdAtual, int qtdMinima) {
        this.nome = nome;
        this.qtdAtual = qtdAtual;
        this.qtdMinima = qtdMinima;
    }

    @Override
    public String toString() {
        return "{" + this.nome + ", " + this.qtdAtual + ", " + this.qtdMinima + "} ";
    }

    public void mostra() {
        System.out.println(this.toString());
    }

    public void darBaixa(int qtdVendida) {
        if (qtdVendida <= this.qtdAtual) {
            this.qtdAtual -= qtdVendida;
            System.out.println("-->" + qtdVendida + " " + this.nome + " " + "vendidos.");
            return;
        }
        System.out.println("-->" + "Sem estoque de " + this.getNome() + " suficiente.");
    }

    public void repor(int qtdAdicional) {
        this.qtdAtual += qtdAdicional;
        System.out.println("-->" + qtdAdicional + " " + this.nome + " adicionadas ao estoque.");
    }

    public boolean precisaRepor() {
        return this.qtdAtual < this.qtdMinima;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Estoque estoque = (Estoque) o;
        return qtdAtual == estoque.qtdAtual && qtdMinima == estoque.qtdMinima && Objects.equals(nome, estoque.nome);
    }

    @Override
    public int hashCode() {
        return Objects.hash(nome, qtdAtual, qtdMinima);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getQtdAtual() {
        return qtdAtual;
    }

    public void setQtdAtual(int qtdAtual) {
        this.qtdAtual = qtdAtual;
    }

    public int getQtdMinima() {
        return qtdMinima;
    }

    public void setQtdMinima(int qtdMinima) {
        this.qtdMinima = qtdMinima;
    }
}
