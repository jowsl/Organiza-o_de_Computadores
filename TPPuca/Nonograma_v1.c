    // Jouberth Matheus Simão Pereira nº23.2.4011
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdio_ext.h>
    #include <math.h>
    #include <unistd.h> // so serve pra colocar um timing no "salvar"

    // C O R E S 
    // cores e formato de texto
    #define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
    #define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
    #define ANSI_COLOR_BLACK      "\x1b[30m"
    #define ANSI_COLOR_RED        "\x1b[31m"
    #define ANSI_COLOR_GREEN      "\x1b[32m"
    #define ANSI_COLOR_YELLOW     "\x1b[33m"
    #define ANSI_COLOR_BLUE       "\x1b[34m"
    #define ANSI_COLOR_MAGENTA    "\x1b[35m"
    #define ANSI_COLOR_CYAN       "\x1b[36m"
    #define ANSI_COLOR_WHITE      "\x1b[37m"
    #define ANSI_BG_COLOR_BLACK   "\x1b[40m"
    #define ANSI_BG_COLOR_RED     "\x1b[41m"
    #define ANSI_BG_COLOR_GREEN   "\x1b[42m"
    #define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
    #define ANSI_BG_COLOR_BLUE    "\x1b[44m"
    #define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
    #define ANSI_BG_COLOR_CYAN    "\x1b[46m"
    #define ANSI_BG_COLOR_WHITE   "\x1b[47m"

    // macros para facilitar o uso
    #define BOLD(string)       ANSI_BOLD             string ANSI_RESET
    #define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
    #define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
    #define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
    #define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
    #define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
    #define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
    #define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
    #define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET
    #define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET
    #define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
    #define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
    #define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
    #define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
    #define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
    #define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
    #define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
    #define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
    #define BG_WHITE(string)   ANSI_BG_COLOR_WHITE   string ANSI_RESET



    // Protótipos (descrições na implementação se necessário.)
    int** criaMatriz(int m, int n);
    void liberaMatriz(int** matriz, int m);
    void ignoraDoisPrimeiros(FILE *arquivo);
    void* alocMat(int y, int x, int typeSize);
    void printarTudo(char **matrizJogo, int lin, int col, int maiorValorX, int maiorValorY, int *quantosPorLinhaX,int *quantosPorLinhaY, int **xCab, int **yCab, char *vetLetrasX, char *vetLetrasY);
    void printaMatrizComVet(int** matriz, int m, int *n);
    void resolver(); // sem garabarito ainda.
    int funcaoSalvar(FILE *arquivo,char nomeArquivo[50], char **matJogo, int lin, int col); // não implementada ainda.
    void comandoParaCoord(char Comando[50], int coord[2]); 
    void marcandoTabela(int coord[2], char **matJogo, char Comando[50]);


    int main(int argc, char *argv[]){
        
        if (argc < 2){ //argv[0] deve ser nome do programa e argv[1] deve ser o nome do arquivo.
            printf("\n\tErro!\n\tVerifique se foi digitado corretamente o nome do arquivo e executável do programa.\n\n");
            return 0;
        }

        // Principais Variáveis
        int **yCab, **xCab, *quantosPorLinhaX, *quantosPorLinhaY;
        int lin, col, maiorValorY=0, maiorValorX=0, coord[2];
        char **matJogo,  *xVetLetras, *yVetLetras, Comando[50], nomeArquivo[50];

        FILE *arquivo = fopen(argv[1], "r");
        if (arquivo == NULL){
            printf("Não foi possível abrir seu arquivo. Tente novamente!");
            return 0;
        }
          
        // lê as dimensões do jogo e valida
        fscanf(arquivo, "%d %d", &lin, &col); 
        if( lin > 26 || col > 26){
            printf("\nErro! \nAs dimensões máximas são 26x26! Verifique o arquivo e tente novamente.\n\n");
            return 0;
        }

        // aloca e preenche esses vetores com as letras do alfabeto.
        xVetLetras = malloc(col * sizeof(char));
        yVetLetras = malloc(lin * sizeof(char));
        for( int i=0; i < lin; i++){  
            yVetLetras[i] = 65 + i;
        }
        for (int  j = 0; j < col; j++){  
            xVetLetras[j] = 65 + j; // 65 é o valor decimal de 'A' na tabela ASCII.
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
            }
        }
        
        printf(BG_WHITE(BLACK(BOLD("\n\tBem vindo ao Nonograma!\t"))) "\n");
        printf("\tDigite 'x' , '-' ou '.' seguido das coordenadas referentes a colunas e linhas respectivamente para marcar as casas.");
        printf((BG_WHITE(BLACK(BOLD("\n\tC O M A N D O S\t"))) "\n"));
        printf("\t"BOLD(RED("  .  "))"\t\tPara marcar as casas como em branco.\n""\t"BOLD(RED("  x  "))"\t\tmarca as casas como 'coloridas'.\n""\t"BOLD(RED("  -  "))"\t\tmarca casas que não devem ser marcadas.'\n");
        printf("\t"BOLD(RED("resolver "))"\tPara que o programa resolva o jogo para você.\n");
        printf("\t"BOLD(RED("salvar   "))"\tPara salvar o jogo.\n");
        printf("\t"BOLD(RED("sair     "))"\tPara sair do jogo.\n\n");

        while(1)
        {
            printf("Digite um comando: ");
            fgets(Comando, 50, stdin);
            Comando[strcspn(Comando, "\n")] = 0; // Remove o '\n' do final da string
            if (strcmp(Comando, "sair") == 0){
                printf("Deseja fechar o jogo?\n"BOLD(GREEN("(S) Sim"))"\n"BOLD(RED("(N) Não \n")));
                char sn;
                scanf("%c", &sn);
                __fpurge(stdin);
                if (sn == 'S' || sn == 's'){
                    printf("\n\tFechando o jogo...");
                    printf(BG_WHITE(BLACK(BOLD("\n\tObrigado por jogar!\t"))) "\n");
                    return -1;
                }
                else if (sn == 'N' || sn == 'n')  continue;
                else {printf("Comando inválido!"); break;}
            }
            else if (strcmp(Comando, "resolver") == 0){
                resolver();
                return 0;
            }
            else if (strncmp(Comando, "salvar ", 7) == 0){  
                // o 'n' do str'n'cmp é a quantidade de caracteres que serão comparados.Vale pro str'n'cpy tbm.
                strncpy(nomeArquivo, &Comando[7], 50-1);   // copia o nome do arquivo para a variável nomeArquivo.
                nomeArquivo[sizeof(nomeArquivo)-1] = '\0'; // arquivo tenha um '\0' no final.
                printf("debug nomeArquivo: %s\n", nomeArquivo); // DEBUG
                funcaoSalvar(arquivo, nomeArquivo, matJogo, lin, col);
            }
            
            else if ((Comando[0] == 'x') || (Comando[0] == '-') || (Comando[0] == '.'))
            {
                // checagens, primeira se o comando no indice 2 e 3 do vetor 'Comando' estão OK
                if ((Comando[1] != ' ') || (Comando[2] < 'A' || Comando[2] > 'Z') || (Comando[3] < 'A' || Comando[3] > 'Z')){
                    printf("Comando inválido! Tente novamente e verifique se as cordenadas estão corretas.\n");
                } else if ((Comando[2] - 'A' >= lin) || (Comando[3] - 'A' >= col)) {
                        printf("Comando inválido! As coordenadas inseridas estão fora do tabuleiro.\n");
                    }
                    else
                    {
                        printf("Comando válido!\n");
                    comandoParaCoord(Comando, coord);
                    marcandoTabela(coord, matJogo,Comando);
                    }

                    for(int i = 0; i < lin; i++){   // print para debugs
                        for(int j = 0; j < col; j++)
                            printf("%2c ", matJogo[i][j]); // DEBUG
                    printf("\n"); // DEBUG
                    }
            }   
            else{
                    printf("Comando inválido! Tente novamente.\n");
                }
        }



        quantosPorLinhaX = malloc(col * sizeof(int));
        quantosPorLinhaY= malloc(lin * sizeof(int));


        int num, contLin=0, contCol=0;
        while ((contLin < lin || contCol < col) && fscanf(arquivo, "%d%*[^\n]", &num) == 1) {  // %*[^\n] "%*" ignora o que vem depois do %d até o \n   
            if (contLin < lin) {                                                               // especificado em [^\n].
                quantosPorLinhaY[contLin] = num; // salva os valores da primeira linha (quantidade de números por linha). para matriz yCab.
                if (num > maiorValorY) {  // salva o maior valor para definir o espaçamento do cabeçalho.
                    maiorValorY = num; // linhas
                }
                contLin++;
            } else if (contCol < col) { 
                quantosPorLinhaX[contCol] = num; // salva os valores da segunda linha (quantidade de números por coluna). para matriz xCab.
                if (num > maiorValorX) {
                    maiorValorX = num; // colunas
                }
                contCol++;
            }
        } // a função desse while é salvar os valores de x e y em vetores e salvar o maior valor de cada um para definir o cabeçalho corretamente.



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

void marcandoTabela(int coord[2], char **matJogo,char Comando[50]){
    matJogo[coord[0]][coord[1]] = Comando[0];
    printf("matJogo[%d][%d] alterado para %c\n", coord[0], coord[1], Comando[0]);
}

void printarTudo(char **matrizJogo, int lin, int col, int maiorValorX, int maiorValorY, int *quantosPorLinhaX, int *quantosPorLinhaY, int **xCab, int **yCab, char *vetLetrasX, char *vetLetrasY) {

// Print do xCab dos infernos.
    for (int k = maiorValorX - 1; k >= 0; k--){ // aqui so usei ao contrário para printar os valores de cima para baixo.
        for (int s = 0; s < maiorValorY; s++) {
            printf("   "); // espaço pra alinhar
        }
    printf("    "); // alinhamento antes de printar algo

    for (int j = 0; j < col; j++) {
        if (k < quantosPorLinhaX[j]) {
            printf("%-3d", xCab[j][k]); // Use a largura de campo especificada
        } else {
            printf("%-3c", 32); // Use a largura de campo especificada com espaços
        }
    }
    printf("\n");
}

    for (int s = 0; s < maiorValorY; s++) {
        printf("   ");
    }
    printf("    "); //alinhamento antes de priintar algo
    for (int j = 0; j < col; j++) {
        printf("%-3c", vetLetrasX[j]);
    }
    printf("\n");


    // Print vetor letras Y e matriz do jogo
    for (int i = 0; i < lin; i++) {
    // Se a linha atual tem menos valores do que o máximo, imprima espaços extras
        for (int j = 0; j < maiorValorY - quantosPorLinhaY[i]; j++) {
            printf("   ");
    }
    // Imprima os números da direita para a esquerda
        for (int j = 0; j < quantosPorLinhaY[i]; j++){
        printf("%3d", yCab[i][j]);
        }
    printf("%-1c", 32); // necessário pra simular o mesmo efeito que a distancia entre caractere um em cima do outro.
    printf("%-3c", vetLetrasY[i]); // do eixo Y
        for (int j = 0; j < col; j++) {
            printf("%-3c", matrizJogo[i][j]);
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

    int funcaoSalvar(FILE *arquivo,char nomeArquivo[50],char **matJogo, int lin, int col){
        rewind(arquivo); // retorna o ponteiro do arquivo para o inicio.
        FILE *arquivoSalvar = fopen(nomeArquivo, "w+");
        if (arquivoSalvar == NULL){
            printf("Não foi possível criar o arquivo. Tente novamente!");
            return 1; // retorna 1 q vai cair no while(1) novamente.
        }
        //Copiando tudo de um arquivo para o outro.
        char c;
        while ((c = fgetc(arquivo)) != EOF) {
            if (c == 'x' || c == '-' || c == '.') {
                break; // Sai do loop se o caractere for 'x', '-' e '.'
            }
            fputc(c, arquivoSalvar);
        }
        for (int i = 0; i < lin; i++){
            for (int j = 0; j < col; j++){
                fputc(matJogo[i][j], arquivoSalvar);
            }
            fputc('\n', arquivoSalvar);
        }
        fclose(arquivoSalvar);
        return 1;        
    }

    void comandoParaCoord(char Comando[50], int coord[2]){
        coord[0] = Comando[2] - 65;
        coord[1] = Comando[3] - 65;
        printf("Coordenadas: %d %d\n", coord[0], coord[1]);
    }