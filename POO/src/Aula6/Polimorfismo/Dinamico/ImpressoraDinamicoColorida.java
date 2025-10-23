package Aula6.Polimorfismo.Dinamico;

public class ImpressoraDinamicoColorida extends ImpressoraDinamico {
    private int copias;
    private boolean colorida;

    public ImpressoraDinamicoColorida(int copias, boolean colorida) {
        this.copias = copias;
        this.colorida = colorida;
    }

    @Override
    public void imprimir(String texto) {
        String tipo = colorida ? "Colorida" : "Preto e Branco";
        for (int i = 1; i <= copias; i++) {
            System.out.println("Cópia " + i + " (" + tipo + "): " + texto);
        }
    }
}