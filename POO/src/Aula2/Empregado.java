package Aula2;

public class Empregado {
    String nomeEmpregado;
    int idade;
    Departamento departamento;

    public Empregado(String nomeEmpregado, int idade, Departamento departamento) {
        this.setNomeEmpregado(nomeEmpregado);
        this.setIdade(idade);
        this.setDepartamento(departamento);
    }

    @Override
    public String toString() {
        return "[nome: '" + this.getNomeEmpregado() + "', idade: " + this.getIdade() + ", departamento: " + this.getDepartamento() + "]";
    }

    public String getNomeEmpregado() {
        return nomeEmpregado;
    }

    public void setNomeEmpregado(String nomeEmpregado) {
        this.nomeEmpregado = nomeEmpregado;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public Departamento getDepartamento() {
        return departamento;
    }

    public void setDepartamento(Departamento departamento) {
        this.departamento = departamento;
    }
}
