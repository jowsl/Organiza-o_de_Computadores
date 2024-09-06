#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval tv;
    // Obter o tempo atual e preenche a struck
    gettimeofday(&tv, NULL);
    // Converter o tempo para milissegundos
    long int timestamp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    return 0;
}