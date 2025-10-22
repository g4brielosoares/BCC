package Aula5;

import java.time.LocalDate;
import java.util.ArrayList;

public class Funcionario {
    private String nome;
    private double salario;
    private LocalDate datainicio;
    private Departamento departamento;
    private static ArrayList<Funcionario> funcionarios = new ArrayList<>();

    public Funcionario(String nome, double salario, LocalDate datainicio) {
        this.nome = nome;
        this.salario = salario;
        this.datainicio = datainicio;
        funcionarios.add(this);
    }

    public ArrayList<Funcionario> getFuncionarios(){
        return funcionarios;
    }
}
