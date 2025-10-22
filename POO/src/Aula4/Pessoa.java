package Aula4;

public class Pessoa {
    String nome;
    int idade;

    Pessoa(String nome) {
        this.idade = 0;
        this.nome = nome;
    }

    void fazAniversario() {
        ++this.idade;
    }
}
