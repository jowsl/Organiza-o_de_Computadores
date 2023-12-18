#include <stdio.h>

// ALGORITMO
int main()
{
	float salario1, salario2; // Float para caso sejam salários com moedas 
	char nome1[30], nome2[30]; 
	printf("Digite o seu nome: \n");
	scanf(" %s", nome1);
	printf("Agora digite o seu salário: \n");
	scanf("%f", &salario1);
	// calculo
	if (salario1>2000)
	{
		printf("%s seu aumento salarial será de 10%%: \n", nome1);
		salario1 =(salario1*1.10);
	}
    else 
	{
    	printf("%s seu aumento salarial será de 12%%: \n", nome1);
    	salario1=salario1*1.12;
    }
	printf("Seu novo salário será de: %.2f reais \n", salario1);
	printf("Digite agora o nome do seu superior: \n");
	scanf(" %s", nome2);
	printf("Digite agora o salário do seu superior: \n");
	scanf("%f", &salario2);
		if (salario2>2500) 
		{ 
    		printf("%s seu aumento salarial será 5%%: \n",  nome2);
    		salario2 = salario2*1.05;
		}
      	else
		{
        	printf("%s seu salário terá um aumento de 7%%: \n", nome2);
        	salario2 = salario2*1.07;	
		}     
	printf("Seu novo salário será de: %.2f reais \n", salario2);		
	printf("Tenha um bom dia!\n");
	    	return 0;
} 
//FIM_ALGORITMO