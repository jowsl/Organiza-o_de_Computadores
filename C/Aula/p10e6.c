// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

typedef struct
{
	char nome[16];
	float consumo; //kw/h
	float horas; 
}eletro;

int main()
{
	eletro eletros[4];
	int dias;
	float tot = 0;
	
	
	for (int i = 0; i < 4; i++)
	{
		printf("\nEletrodoméstico %i\n", i);
		
		printf("Nome: ");
		scanf("%s", eletros[i].nome);
		
		printf("Consumo (kW/h): ");
		scanf("%f", &eletros[i].consumo);
		
		printf("Tempo ativo em horas: ");
		scanf("%f", &eletros[i].horas);
		
		tot += (eletros[i].consumo * eletros[i].horas);
	}
	
	printf("Número de dias para cálculo: ");
	scanf("%d", &dias);
	
	tot *= dias;
	
	printf("Consumo total: %.1f\n", tot);
	
	printf("Porcentagens:\n\n");
	
	for (int i = 0; i < 4; i++)
	{
		printf("%s %.2f\n", eletros[i].nome, (eletros[i].consumo * dias * eletros[i].horas * 100) / tot);
	}

	return 0;
}
