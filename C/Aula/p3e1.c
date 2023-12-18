#include <stdio.h>
// Jouberth Matheus Simão Pereira - nº 23.2.4011
int main(){
	int matricula;
	float nota;
	printf("Digite a matricula: ");
		scanf("%d", &matricula);
	printf("Digite a nota: ");
		scanf("%f", &nota);
	printf("\nMatricula: %d", matricula);
	if (nota >= 9) {
		printf("\nConceito A");
	} else if (nota >= 8 && nota < 9){
		printf("\nConceito B");
	} else if (nota >= 6 && nota < 8){
		printf("\nConceito C");
	} else if (nota >= 3 && nota < 6){
		printf("\nConceito D");
	} else { 
		printf("\nConceito E");
	}	
	return 0;
}