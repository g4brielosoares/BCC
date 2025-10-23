package Aula6.Polimorfismo.Dinamico;

public class ImpressoraDinamicoComCopia extends ImpressoraDinamico {
    private int copias;

    public ImpressoraDinamicoComCopia(int copias) {
        this.copias = copias;
    }

    @Override
    public void imprimir(String texto) {
        for (int i = 1; i <= copias; i++) {
            System.out.println("Cópia " + i + ": " + texto);
        }
    }
}