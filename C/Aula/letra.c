#include <stdio.h>

int main(){
	char letra;
	printf("\nDigite uma letra: ");
		scanf("%c", &letra);
	switch (letra){
		case 'a': case 'e':	case 'i': case 'o':	case 'u':
		printf("\nÉ vogal!\n");
		break;
		default:
		printf("\nÉ uma consoante!\n");
	}
	return 0;
}
