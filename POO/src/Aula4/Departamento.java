package Aula4;

import java.util.ArrayList;

public class Departamento {
    private String nome;
    public ArrayList<Funcionario> funcionarios;
    private Empresa empresa;
    private final String ID;

    public Departamento(String nome, Empresa empresa, String ID) {
        this.funcionarios = new ArrayList<Funcionario>();
        this.nome = nome;
        this.empresa = empresa;
        this.ID = ID;
    }

    @Override
    public String toString() {
        return "Departamento{" +
                "nome='" + nome + '\'' +
                ", funcionarios=" + funcionarios +
                ", empresa=" + empresa +
                ", ID='" + ID + '\'' +
                '}';
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Empresa getEmpresa() {
        return empresa;
    }

    public void setEmpresa(Empresa empresa) {
        this.empresa = empresa;
    }

    public String getID() {
        return ID;
    }
}
