#include <stdio.h>
// Jouberth Matheus Simão Pereira - nº 23.2.4011
int main(){
	char sexo;
	int idade, anos_contribuinte;
	printf("Digite o sexo: "); 
        scanf("%c", &sexo);
    printf("Digite a idade: ");
        scanf("%d", &idade);
    printf("Digite o tempo de contribuição para o INSS: ");
        scanf("%d", &anos_contribuinte);
    if ( sexo =='M' && idade>=65 && anos_contribuinte>=35){
        printf("Voce pode se aposentar com salario integral");
    } else if ( sexo =='M' && idade + anos_contribuinte >= 100){
        printf("Voce pode se aposentar com salario integral");
    } else if ( sexo =='F' && idade>=60 && anos_contribuinte>=30){
        printf("Voce pode se aposentar com salario integral");    
    } else if ( sexo =='F' && idade + anos_contribuinte >= 90){
        printf("Voce pode se aposentar com salario integral");
    } else {
        printf("Voce nao pode se aposentar com salario integral");
    }
	return 0;
}