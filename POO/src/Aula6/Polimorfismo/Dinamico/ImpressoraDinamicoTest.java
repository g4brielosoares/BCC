package Aula6.Polimorfismo.Dinamico;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

class ImpressoraDinamicoTest {

    @Test
    void testImpressoraSimples() {
        ImpressoraDinamico impressora = new ImpressoraDinamicoSimples();
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        System.setOut(new PrintStream(out));
        impressora.imprimir("Teste");
        assertTrue(out.toString().contains("Imprimindo: Teste"));
    }

    @Test
    void testImpressoraComCopia() {
        ImpressoraDinamico impressora = new ImpressoraDinamicoComCopia(2);
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        System.setOut(new PrintStream(out));
        impressora.imprimir("Relatório");
        String output = out.toString();
        assertTrue(output.contains("Cópia 1: Relatório"));
        assertTrue(output.contains("Cópia 2: Relatório"));
    }

    @Test
    void testImpressoraColorida() {
        ImpressoraDinamico impressora = new ImpressoraDinamicoColorida(1, true);
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        System.setOut(new PrintStream(out));
        impressora.imprimir("Foto");
        assertTrue(out.toString().contains("Cópia 1 (Colorida): Foto"));
    }
}
