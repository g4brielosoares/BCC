package Aula4;

import java.util.ArrayList;

public class Empresa {
    private String nome;
    public ArrayList<Departamento> departamentos;
    private final String CNPJ;

    public Empresa(String nome, String CNPJ) {
        this.departamentos = new ArrayList<Departamento>();
        this.nome = nome;
        this.CNPJ = CNPJ;
    }

    @Override
    public String toString() {
        return "Empresa{" +
                "nome='" + nome + '\'' +
                ", departamentos=" + departamentos +
                ", CNPJ='" + CNPJ + '\'' +
                '}';
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCNPJ() {
        return CNPJ;
    }
}
