// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h> // __fpurge(stdin)

typedef struct{	
	char nome[16];
	float consumo;
	float horas; 
}eletro;

int main(){
	eletro eletros[4];
	int dias;
	float tot = 0;
	
	for (int i = 0; i < 4; i++){
		printf("\nEletrodoméstico %i\n", i);
		printf("Nome: ");
		__fpurge(stdin);
		fgets(eletros[i].nome, 16, stdin);
		int x = strlen(eletros[i].nome);
		if (eletros[i].nome[x - 1] == '\n') {
            eletros[i].nome[x - 1] = '\0';
        }
		printf("Consumo (kW/h): ");
		scanf("%f", &eletros[i].consumo);
		printf("\nTempo ativo em horas: ");
		scanf("%f", &eletros[i].horas);
		tot += (eletros[i].consumo * eletros[i].horas);
	}
	printf("\nNúmero de dias para cálculo: ");
	scanf("%d", &dias);
	tot *= dias;
	printf("\nConsumo total: %.1f\n\n", tot);
	printf("Porcentagens:\n\n");
	for (int i = 0; i < 4; i++){
		printf("%s %.2f%%\n", eletros[i].nome, (eletros[i].consumo * dias * eletros[i].horas * 100) / tot);
	}
	return 0;
}
