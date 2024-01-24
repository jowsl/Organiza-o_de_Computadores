#include <stdio.h>
#include <unistd.h>

int main() {
    char texto[] = "Hello, World!";
    
    for (int i = 0; texto[i] != '\0'; i++) {
        // Imprime uma letra
        printf("%c", texto[i]);
        // Aguarda um curto período de tempo (em segundos)
        fflush(stdout); // Certifica-se de que o buffer é liberado antes de dormir
        usleep(75000); // Delay de 1 segundo
    }

    return 0;
}
