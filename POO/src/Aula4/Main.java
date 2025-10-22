package Aula4;

public class Main {
    public static void main(String[] args) {
        /*
        Empresa e1 = new Empresa("LabMaker", "1111");
        Empresa e2 = new Empresa("Andrezito", "2222");
        Departamento d1 = new Departamento("Monitoria", e1, "1");
        e1.departamentos.add(d1);
        Departamento d2 = new Departamento("Projeto de Extensão", e1, "2");
        e1.departamentos.add(d2);
        Departamento d3 = new Departamento("Projeto de Ensino", e2, "3");
        e2.departamentos.add(d3);
        Funcionario f1 = new Funcionario("Gabriel", d2, "123");
        d2.funcionarios.add(f1);
        Funcionario f2 = new Funcionario("João", d1, "234");
        d1.funcionarios.add(f2);
        Funcionario f3 = new Funcionario("Pedro", d2, "345");
        d2.funcionarios.add(f3);
        Funcionario f4 = new Funcionario("Filipe", d3, "456");
        d3.funcionarios.add(f3);
        Funcionario f5 = new Funcionario("Guilherme", d3, "567");
        d3.funcionarios.add(f3);

        System.out.println(e1);
        */
        /*
        Motor motor = new Motor();
        motor.potencia = 320;
        motor.tipo = "V8";

        Carro carro = new Carro();
        carro.cor = "Branco";
        carro.modelo = "Mustang";
        carro.velocidadeAtual = 0.0;
        carro.velocidadeMaxima = 230;
        carro.motor = motor;
        */
        Pessoa pessoa = new Pessoa("Gabriel");
        System.out.println(pessoa.idade);
        pessoa.fazAniversario();
        System.out.println(pessoa.idade);
        pessoa.fazAniversario();
        System.out.println(pessoa.idade);
    }
}
