#include <stdio.h>

void calculoSal(float sal, int cargo){
    if (cargo==1){
        sal= (sal*0.20)+sal;
        printf("  Salário reajustado R$%.2f.\n\n", sal);
    }else{
        sal=(sal*0.18)+sal;
        printf("  Salário reajustado R$%.2f.\n\n", sal);
    }
}
int main(){
int matricula=1, cargo=1;
float sal=1.0;
while (cargo!=0&&matricula!=0&&sal!=0){
printf("Digite a matricula do funcionário: ");
scanf("%d", &matricula);
if(matricula==0)
break;
printf("\nEntre com o cargo do funcionário. \n(1) Para Operador: \n(2) Para Programador: \n(0) Para sair.\n");
scanf("%d", &cargo);
if(cargo==0)
break;
printf("\nEntre com o salário do funcionário para que seja reajustado: ");
scanf("%f", &sal);
if(sal==0)
break;
printf("\n- %d -", matricula);
calculoSal(sal, cargo);
}
    return 0;
}