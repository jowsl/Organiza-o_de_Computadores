#include <stdio.h>
#include <math.h>
//incompleto, hard.
int main(){
int A, B, C, D, E, F, G, H, I, K, L, M, Mes, pascoa, ano, sextaSanta, tercaCarnaval, CorpusChristi;
printf("Digite o ano com 4 dígitos: \n");
    scanf("%d", &ano);

A = ano%19;
B = ano/100;
C = ano%100;
D = B/4;
E = B%4;
F = (B + 8)/25;
G = (B - F + 1)/3;
H = (19 * A + B - D - G + 15)%30;
I = C/4;
K = C%4;
L = (32 + 2 * E + 2 * I - H - K)%7;
M = (A + 11 * H + 22 * L)/451;
Mes = (H + L - 7 * M + 114)/31;
pascoa = (H + L - 7 * M + 114)%31 + 1;
sextaSanta = pascoa -2;
tercaCarnaval = pascoa - 47;
CorpusChristi = pascoa + 60;
printf("\nA páscoa é dia %d do mês %d a sexta-feira Santar é %d o Carnaval é dia %d e Corpus Christi é no dia %d\n ",
pascoa, Mes, sextaSanta, tercaCarnaval, CorpusChristi);
    return 0;
}