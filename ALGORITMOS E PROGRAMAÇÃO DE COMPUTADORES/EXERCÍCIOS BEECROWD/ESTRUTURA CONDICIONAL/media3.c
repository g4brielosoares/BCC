int main() {
    float N1, N2, N3, N4, nota_exame, media, mfinal;
    
    scanf("%f %f %f %f", &N1, &N2, &N3, &N4);
    
    media = ((N1 * 2) + (N2 * 3) + (N3 * 4) + (N4 * 1)) / (2 + 3 + 4 + 1);
    
    if (media >= 7) {
        printf("Media: %.1f\nAluno aprovado.\n", media);
    } else if (media < 5) {
        printf("Media: %.1f\nAluno reprovado.\n", media);
    } else if (media >= 5 && media < 7) { 
        printf("Media: %.1f\nAluno em exame.\n", media);
        scanf("%f", &nota_exame);
        mfinal = (media + nota_exame) / 2;
        if (mfinal >= 5) {
            printf("Nota do exame: %.1f\nAluno aprovado.\nMedia final: %.1f\n", nota_exame, mfinal);
        } else if (mfinal < 5) {
            printf("Nota do exame: %.1f\nAluno reprovado.\nMedia final: %.1f\n", nota_exame, mfinal);
        }
    }
    return 0;
}