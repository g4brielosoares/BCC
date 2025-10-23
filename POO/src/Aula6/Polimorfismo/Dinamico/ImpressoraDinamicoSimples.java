package Aula6.Polimorfismo.Dinamico;

public class ImpressoraDinamicoSimples extends ImpressoraDinamico {
    @Override
    public void imprimir(String texto) {
        System.out.println("Imprimindo: " + texto);
    }
}