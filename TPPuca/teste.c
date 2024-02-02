#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo = fopen("nono.txt", "r");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    char str[27];
    int contN = 0, maiorNlinha = 0, num;

    while (fscanf(arquivo, "%s", str) != EOF) {
        num = atoi(str);
        if (num >= 0 && num <= 26) {
            contN++;
        } else if (str[0] == '\n' || str[0] == EOF) {
            if (contN > maiorNlinha) {
                maiorNlinha = contN;
            }
            contN = 0;
        } else if (str[0] == '.') {
            break;
        }
    }

    printf("Maior quantidade de inteiros por linha: %d\n", maiorNlinha);

    fclose(arquivo);
    return 0;
}
