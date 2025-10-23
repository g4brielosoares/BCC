package Aula6.Polimorfismo.Estatico;

public class ImpressoraEstatico {

    public void imprimir(String texto) {
        System.out.println("Imprimindo: " + texto);
    }

    public void imprimir(String texto, int copias) {
        for (int i = 1; i <= copias; i++) {
            System.out.println("Cópia " + i + ": " + texto);
        }
    }

    public void imprimir(String texto, int copias, boolean colorida) {
        String tipo = colorida ? "Colorida" : "Preto e Branco";
        for (int i = 1; i <= copias; i++) {
            System.out.println("Cópia " + i + " (" + tipo + "): " + texto);
        }
    }
}
