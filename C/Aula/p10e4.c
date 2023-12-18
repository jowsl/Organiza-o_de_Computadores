// Jouberth Matheus Simão Pereira nº23.2.4011
#include <stdio.h>

typedef struct {
    double real;
    double imaginario;
} Complexo;

Complexo somcmp(Complexo x, Complexo y)
{
	Complexo aux;
	
	aux.real = x.real + y.real;
	aux.imaginario = x.imaginario + y.imaginario;
	
	return aux;
}

Complexo subComplexo(Complexo x, Complexo y)
{
	Complexo aux;
	
	aux.real = x.real - y.real;
	aux.imaginario = x.imaginario - y.imaginario;
		
	return aux;
}
Complexo multcomp(Complexo x, Complexo y)
{
	Complexo res;
	
	res.real =       ( (x.real * y.real) - (x.imaginario * y.imaginario) );
	res.imaginario = ( (x.real * y.imaginario) + (x.imaginario * y.real) );
	
	return res;
}

int main()
{
	Complexo x, y, res;
	char op;
	
	printf("Digite os valores de a e b (x = a + bi): "); 
	scanf("%lf%lf", &x.real, &x.imaginario);
	
	printf("Digite os valores de c e d (y = c + di): "); 
	scanf("%lf%lf", &y.real, &y.imaginario);
	
	printf("Digite a operação (+, - ou *): ");
	scanf(" %c", &op);
	
	switch(op) {
		case ('+') :
		
			res = somcmp(x, y);
			break;
		
		
		case ('-') :
		
			res = subComplexo(x, y);
			break;
		
		case ('*') :
		
			res = multcomp(x, y);
			break;
	}
	printf("Resultado: %.1f + %.1fi", res.real, res.imaginario);
}
