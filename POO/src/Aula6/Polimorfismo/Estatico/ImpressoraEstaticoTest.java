package Aula6.Polimorfismo.Estatico;

import Aula6.Polimorfismo.Dinamico.ImpressoraDinamico;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.io.ByteArrayOutputStream;
import java.io.PrintStream;

class ImpressoraEstaticoTest {
    @Test
    void testImprimirTexto() {
        ImpressoraDinamico impressora = new ImpressoraDinamico();
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        System.setOut(new PrintStream(out));
        impressora.imprimir("Teste");
        assertTrue(out.toString().contains("Imprimindo: Teste"));
    }

    @Test
    void testImprimirTextoCopias() {
        ImpressoraDinamico impressora = new ImpressoraDinamico();
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        System.setOut(new PrintStream(out));
        impressora.imprimir("Relatório", 2);
        String output = out.toString();
        assertTrue(output.contains("Cópia 1: Relatório"));
        assertTrue(output.contains("Cópia 2: Relatório"));
    }

    @Test
    void testImprimirTextoCopiasCor() {
        ImpressoraDinamico impressora = new ImpressoraDinamico();
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        System.setOut(new PrintStream(out));
        impressora.imprimir("Foto", 1, true);
        assertTrue(out.toString().contains("Cópia 1 (Colorida): Foto"));
    }
}
