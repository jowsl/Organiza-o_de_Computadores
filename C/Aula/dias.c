#include <stdio.h>

int main(){
	int matricula;
	float nota;
	printf("Digite a matricula: ");
		scanf("%d", &matricula);
	printf("Digite a nota: ");
	if (nota >= 9) {
		printf("Conceito A");
	} else if (nota >= 8 && nota < 9){
		printf("Conceito B");
	} else if (nota >= 6 && nota < 8){
		printf("Conceito C");
	} else if (nota >= 3 && nota < 6){
		printf("Conceito D");
	} else { 
		printf("Conceito E");
	}	
	

	

	
	
	return 0;
}