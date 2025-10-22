package Aula2;

public class Departamento {
    String nomeDepartamento;
    int id;

    public Departamento(String nomeDepartamento, int id) {
        this.setNomeDepartamento(nomeDepartamento);
        this.setId(id);
    }

    @Override
    public String toString() {
        return "[nome ='" + nomeDepartamento + "', id =" + id + "]";
    }

    public String getNomeDepartamento() {
        return nomeDepartamento;
    }

    public void setNomeDepartamento(String nomeDepartamento) {
        this.nomeDepartamento = nomeDepartamento;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }
}
