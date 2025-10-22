package Aula4;

public class Funcionario {
    private String nome;
    private Departamento departamento;
    private final String CPF;

    public Funcionario(String nome, Departamento departamento, String CPF) {
        this.nome = nome;
        this.departamento = departamento;
        this.CPF = CPF;
    }

    @Override
    public String toString() {
        return "Funcionario{" +
                "nome='" + nome + '\'' +
                ", departamento=" + departamento +
                ", CPF='" + CPF + '\'' +
                '}';
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public Departamento getDepartamento() {
        return departamento;
    }

    public void setDepartamento(Departamento departamento) {
        this.departamento = departamento;
    }

    public String getCPF() {
        return CPF;
    }
}
