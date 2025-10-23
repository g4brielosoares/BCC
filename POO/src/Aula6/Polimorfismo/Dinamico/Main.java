package Aula6.Polimorfismo.Dinamico;

public class Main {

	public static void main(String[] args) {
		System.out.println("Programa iniciado.\n");

		ImpressoraDinamico impressora;

		impressora = new ImpressoraDinamicoSimples();
		impressora.imprimir("Olá, mundo!");

		impressora = new ImpressoraDinamicoComCopia(3);
		impressora.imprimir("Relatório");

		impressora = new ImpressoraDinamicoColorida(2, true);
		impressora.imprimir("Foto");
	}
}
