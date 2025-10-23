package Aula6.Polimorfismo.Estatico;

public class Main {
	public static void main(String[] args) {

		System.out.println("Programa iniciado.");

		ImpressoraEstatico impressora = new ImpressoraEstatico();
		// Imprimir apenas texto
		impressora.imprimir("Olá, mundo!");

		// Imprimir texto com número de cópias
		impressora.imprimir("Relatório", 3);

		// Imprimir texto com número de cópias e cor
		impressora.imprimir("Foto", 2, true);
	}
}
