    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio_ext.h>


    // Protótipos (descrições na implementação se necessário.)
    int** criaMatriz(int m, int n);
    void liberaMatriz(int** matriz, int m);
    void ignoraDoisPrimeiros(FILE *arquivo);
    void* alocMat(int y, int x, int typeSize);
    void printarTudo(char **matrizJogo, int lin, int col, int maiorValorX, int maiorValorY, int *quantosPorLinhaX,int *quantosPorLinhaY, int **xCab, int **yCab, char *vetLetrasX, char *vetLetrasY);
    void printaMatrizComVet(int** matriz, int m, int *n);
    void resolver(); // sem garabarito ainda.
    void funcaoSalvar(); // não implementada ainda.
    void comandoParaCoord(char Comando[10], int coord[2]); // não implementada ainda.
    void marcandoTabela(int coord[2], char **matJogo, char Comando[10]);


    int main(int argc, char *argv[]){
        
        if (argc < 2){ //argv[0] deve ser nome do programa e argv[1] deve ser o nome do arquivo.
            printf("\n\tErro!\n\tVerifique se foi digitado corretamente o nome do arquivo e executável do programa.\n\n");
            return 0;
        }

        // Principais Variáveis
        int **yCab, **xCab, *quantosPorLinhaX, *quantosPorLinhaY;
        int lin, col, maiorValorY=0, maiorValorX=0, coord[2];
        char **matJogo,  *xVetLetras, *yVetLetras, Comando[10];

        FILE *arquivo = fopen(argv[1], "r");
        if (arquivo == NULL){
            printf("Não foi possível abrir seu arquivo. Tente novamente!");
            return 0;
        }
        
        xVetLetras = malloc(col * sizeof(char));
        yVetLetras = malloc(lin * sizeof(char));
        fscanf(arquivo, "%d %d", &lin, &col); // lê as dimensões do jogo e valida
        if( lin > 26 || col > 26){
            printf("\nErro! \nAs dimensões máximas são 26x26! Verifique o arquivo e tente novamente.\n\n");
            return 0;
        }

        for( int i=0; i < lin; i++){  // preenche esses vetores com as letras do alfabeto.
            yVetLetras[i] = 65 + i;
        }
        for (int  j = 0; j < col; j++){  
            xVetLetras[j] = 65 + j; // 65 é o valor decimal de 'A' na tabela ASCII.
        }
        
        printf("DEBUG xVetLetras: ");
        for(int j = 0; j < col; j++){  
            printf("%c ", xVetLetras[j]);
        }
        printf("\n");

        printf("DEBUG yVetLetras: ");
        for(int i = 0; i < lin; i++){
            printf("%c ", yVetLetras[i]);
        }
        printf("\n"); //DEBUG

        // criação e preenchimento da tabela jogo.
        matJogo = (char **)calloc(lin, sizeof(char *));  //calloc aloca e inicializa a matriz com 0.
        for (int i = 0; i < lin; i++)
            matJogo[i] = (char *)calloc(col, sizeof(char));
        for(int i = 0; i < lin; i++){   // preenche a matriz com espaços em '.'.
            for(int j = 0; j < col; j++){
                if (matJogo[i][j] == 0){
                    matJogo[i][j] = 46;
                }
                printf("%2c ", matJogo[i][j]); // DEBUG
            }
            printf("\n"); // DEBUG
        }
        

        printf("\n\tBem-vindo ao Nonograma!\n\n");
        printf("Digite 'x' , '-' ou '.' seguido das coordenadas referentes a colunas e linhas respectivamente para marcar as casas.\n\n");
        printf("'.' para marcar as casas como em branco.\n 'x' marca as casas como 'coloridas'.\n '-' marca casas que não devem ser marcadas.'\n");
        printf("Digite 'resolver' para que o programa resolva o jogo para você.\n");
        printf("Digite 'salvar' para salvar o jogo.\n");
        printf("Digite 'sair' para sair do jogo.\n\n");
        printf("Você pode ler mais sobre o jogo em http://www.nonograms.org/.\n\n");

        while(1){ // verificações de commandos, se retornar algo diferente de 1, o loop sai.

            printf("Digite um comando: ");
            fgets(Comando, 10, stdin);
            Comando[strcspn(Comando, "\n")] = 0; // Remove o '\n' do final da string
            /////////////
/*REMOVER*/         if (strcmp(Comando, "fim") == 0){
            break;
            }
            ////////////
            if (strcmp(Comando, "sair") == 0){
                printf("Saindo do jogo.\n");
                return -1;
            }
            else if (strcmp(Comando, "resolver") == 0){
                resolver();
                return 0;
            }
            else if (strcmp(Comando, "salvar") == 0){
                printf("Salvando o jogo...\n");
                funcaoSalvar();
            }
            else if ((Comando[0] == 'x') || (Comando[0] == '-') || (Comando[0] == '.')){
                if ((Comando[1] != ' ') || (Comando[2] < 'A' || Comando[2] > 'Z') || (Comando[3] < 'A' || Comando[3] > 'Z')){
                    printf("Comando inválido! Tente novamente e verifique se as cordenadas estão corretas.\n");
                }else{
                    printf("Comando válido!\n");
                    comandoParaCoord(Comando, coord);
                    marcandoTabela(coord, matJogo,Comando);
                    for(int i = 0; i < lin; i++){   // print para debugs
                        for(int j = 0; j < col; j++)
                            printf("%2c ", matJogo[i][j]); // DEBUG
                    printf("\n"); // DEBUG
                    }
                }
            }
        }


        // while(1){
        // __fpurge(stdin);
        // fgets(Comando, 10, stdin);
        // if (Comando[0] == 's' && Comando[1] == 'a' && Comando[2] == 'i' && Comando[3] == 'r'){
        //     printf("Saindo do jogo...\n");
        //     return -1;
        // }
        // else if (Comando[0] == 'r' && Comando[1] == 'e' && Comando[2] == 's' && Comando[3] == 'o' && Comando[4] == 'l' && Comando[5] == 'v' && Comando[6] == 'e' && Comando[7] == 'r'){
        //     resolver();
        //     return 0;
        // }
        // else if (Comando[0] == 's' && Comando[1] == 'a' && Comando[2] == 'l' && Comando[3] == 'v' && Comando[4] == 'a' && Comando[5] == 'r'){
        //     printf("Salvando o jogo...\n");
        //     funcaoSalvar();
        // }
        // else if ((Comando[0] == 'x') || (Comando[0] == '-') || (Comando[0] == '.') && (Comando[1] == ' ') && (Comando[2] >= 65) && (Comando[2] <= 90) && (Comando[3] >= 65) && (Comando[3] <= 90)){
        //     printf("Comando válido!\n");
        // }
        // else{
        //     printf("Comando inválido! Tente novamente.\n");
        // }
        // }

    

        quantosPorLinhaX = malloc(col * sizeof(int));
        quantosPorLinhaY= malloc(lin * sizeof(int));



        // cria matriz principal onde será armazenado o jogo.

            
        ////////////////////////////////////////////////////////////////////////////////////////////

        int num, contLin=0, contCol=0;
        while ((contLin < lin || contCol < col) && fscanf(arquivo, "%d%*[^\n]", &num) == 1) {  // %*[^\n] "%*" ignora o que vem depois do %d até o \n   
            if (contLin < lin) {                                                               // especificado em [^\n].
                quantosPorLinhaY[contLin] = num;
                if (num > maiorValorY) {  // salva o maior valor para definir o espaçamento do cabeçalho.
                    maiorValorY = num; // linhas
                }
                contLin++;
            } else if (contCol < col) { 
                quantosPorLinhaX[contCol] = num;
                if (num > maiorValorX) {
                    maiorValorX = num; // colunas
                }
                contCol++;
            }
        } // a função desse while é salvar os valores de x e y em vetores e salvar o maior valor de cada um para definir o cabeçalho corretamente.

        // criação da matriz com espaços em branco do canto superior esquerdo.
        char matEspacos[maiorValorY+1][maiorValorX+1];
            for (int i = 0; i < maiorValorX+1; i++){
                for (int j = 0; j < maiorValorY+1; j++){
                    matEspacos[i][j] = '_';
                    printf("%2c ", matEspacos[i][j]);
                    }
                    printf("\n");
            }

        xCab = criaMatriz(col, maiorValorY+1);
        yCab = criaMatriz(lin, maiorValorX+1);

        ignoraDoisPrimeiros(arquivo);

        for(int i = 0; i < lin; i++){
            int ignorado; // variável para 'ignorar' o primeiro valor de cada linha.
            fscanf(arquivo, "%d", &ignorado);
            for(int j = 0; j < quantosPorLinhaY[i]; j++){
                    fscanf(arquivo, "%d", &yCab[i][j]);
            }
        }
        printaMatrizComVet(yCab, lin, quantosPorLinhaY);

        printf("\n");

        // Leitura da matriz xCab
        for(int i = 0; i < col; i++){
            int ignorado; // variável para 'ignorar' o primeiro valor de cada linha.
            fscanf(arquivo, "%d", &ignorado);
            for(int j = 0; j < quantosPorLinhaX[i]; j++){
                    fscanf(arquivo, "%d", &xCab[i][j]);
            }
        }
        printaMatrizComVet(xCab, col, quantosPorLinhaX);

        printarTudo(matJogo, lin, col, maiorValorX, maiorValorY, quantosPorLinhaX, quantosPorLinhaY, xCab, yCab, xVetLetras, yVetLetras);

        fclose(arquivo);

        liberaMatriz(xCab, col);
        liberaMatriz(yCab, lin);
        for (int i = 0; i < lin; i++)
            free(matJogo[i]);
        free(matJogo);
        free(xVetLetras);
        free(yVetLetras);
        free(quantosPorLinhaX);
        free(quantosPorLinhaY);
        
        return 0;
    }

void marcandoTabela(int coord[2], char **matJogo,char Comando[10]){
    matJogo[coord[0]][coord[1]] = Comando[0];
    printf("matJogo[%d][%d] alterado para %c\n", coord[0], coord[1], Comando[0]);
}

void printarTudo(char **matrizJogo, int lin, int col, int maiorValorX, int maiorValorY, int *quantosPorLinhaX, int *quantosPorLinhaY, int **xCab, int **yCab, char *vetLetrasX, char *vetLetrasY) {

// Print do xCab
for (int k = maiorValorX - 1; k >= 0; k--){
    // Adicione espaços para alinhar com o eixo Y
    for (int s = 0; s < maiorValorY; s++) {
        printf("  ");
    }
    printf("  "); // Espaço extra para o eixo Y

    for (int j = 0; j < col; j++) {
        if (k < quantosPorLinhaX[j]) {
            printf("%-2d ", xCab[j][k]);
        } else {
            printf("  ");
        }
    }
    printf("\n");
}

//     // Print do xCab 2
// for (int k = 0; k < maiorValorX; k++){
//     // Adicione espaços para alinhar com o eixo Y
//     for (int s = 0; s < maiorValorY; s++) {
//         printf("  ");
//     }
//     printf("  "); // Espaço extra para o eixo Y

//     for (int j = 0; j < col; j++) {
//         if (k < quantosPorLinhaX[j]) {
//             printf("%-2d ", xCab[j][k]);
//         } else {
//             printf("  ");
//         }
//     }
//     printf("\n");
// }

    // Print do xCab velho
    // for (int j = 0; j < col; j++) {
    //     for (int k = 0; k < maiorValorX; k++){
    //         if (k < quantosPorLinhaX[j]) {
    //             printf("%-2d ", xCab[j][k]);
    //         } else {
    //             printf("  ");
    //         }
    //     }
    // }
    // printf("\n");
int espacos=0;
    // while (espacos < maiorValorX+1){
    //     printf("  ");
    //     espacos++;    
    // }
    // for (int j = 0; j < col; j++) {
    //     printf("%-2d ", xCab[j][0]);
    // }
    // printf("\n");

    // Print vetor letras X
    espacos=0;
    while (espacos < maiorValorX+1){
        printf("  ");
        espacos++;    
    }
    for (int j = 0; j < col; j++) {
        printf("%-3c ", vetLetrasX[j]);
    }
    printf("\n");

    // Print vetor letras Y e matriz do jogo
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < quantosPorLinhaY[i]; j++){
            printf("%-2d", yCab[i][j]);
        }
    // Se a linha atual tem menos valores do que o máximo, imprima espaços extras
    for (int j = quantosPorLinhaY[i]; j < maiorValorY; j++) {
            printf("  ");
        }
        printf("   %-3c", vetLetrasY[i]); // do eixo Y
        for (int j = 0; j < col; j++) {
            printf("%-3c ", matrizJogo[i][j]);
        }
        printf("\n");
    }   
}

    // aloca dinamicamente uma matriz
    int** criaMatriz(int m, int n){ 
        int **matriz = malloc (m * sizeof(int*));
        for (int i = 0; i < m; i++){
            matriz[i] = malloc(n * sizeof(int));
            }
        return matriz;
    }


    void liberaMatriz(int** matriz, int m){
        for (int i = 0; i < m; i++){
            free(matriz[i]);
        }
        free(matriz);
    }

    void ignoraDoisPrimeiros(FILE *arquivo){
        fseek(arquivo, 0, SEEK_SET); // retorna o ponteiro do arquivo para o inicio.
        int ignorar1, ignorar2;
        fscanf(arquivo, "%d %d", &ignorar1, &ignorar2); // ignora os dois primeiros itens do arquivo (que é a primeira linha). 
        printf("Ignorando os dois primeiros itens do arquivo... %d %d \n", ignorar1, ignorar2); // DEBUG
    }

    void* alocMat(int y, int x, int typeSize){  // Aloca memoria para matriz de qualquer tipo.
        void** mat = NULL;
        mat = malloc(y * sizeof(void*));
        for (int i = 0; i < y; i++){
            mat[i] = malloc(x * typeSize);
        }
        return mat;
    }

    void printaMatrizComVet(int** matriz, int m, int *n){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n[i]; j++)
                    printf("%d ", matriz[i][j]);
            printf("\n");
        }
    }

    void resolver(){
        printf("Erro, programa sem gabarito!\n Obrigado por jogar!\n");
    }

    void funcaoSalvar(){
        printf("Erro, função não implementada!\n");
    }
    void comandoParaCoord(char Comando[10], int coord[2]){
        coord[0] = Comando[2] - 65;
        coord[1] = Comando[3] - 65;
        printf("Coordenadas: %d %d\n", coord[0], coord[1]);
    }