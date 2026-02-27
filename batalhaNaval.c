#include <stdio.h> // Biblioteca padrão para usar printf

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
     // Representa o tabuleiro 10x10
     int tabuleiro[10][10];

     // Inicializa o tabuleiro com 0 (água)
     for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
     }

    // Posiciona navio horizontal
    int pode_posicionar2 = 1;

    if (4 + 3 <= 10) { // verifica limite
         for(int i = 0; i < 3; i++) {
             if (tabuleiro[2][4 + i] != 0){
                pode_posicionar2 = 0;
            }
        } 
        if (pode_posicionar2){
            for (int i = 0; i < 3; i++){
           tabuleiro[2][4 + i] = 3;
            }
        }
    }
     // Verifica se pode posicionar navio vertical
    int pode_posicionar = 1;

    if (5 + 3 <= 10) { // verifica limite
         for(int i = 0; i < 3; i++) {
            if (tabuleiro[5 + i][7] != 0) {
                 pode_posicionar = 0; // já tem algo na posição
            }
         }

        if (pode_posicionar) {
            for(int i = 0; i < 3; i++) {
                tabuleiro[5 + i][7] = 3;
            }
        }
    }

    // Exibe o tabuleiro
     printf("\n Tabuleiro Batalha Naval NOVATO:\n\n");
    printf("   A B C D E F G H I J\n");

    for(int i = 0; i < 10; i++) {
       printf("%d  ", i);
         for(int j = 0; j < 10; j++) {
             printf("%d ", tabuleiro[i][j]);
         }
        printf("\n");
    }


    // Inicializa o tabuleiro com 0 (água)
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Posiciona navio horizontal
    int posicionar = 1;

    if (4 + 3 <= 10) { // verifica limite
        for(int i = 0; i < 3; i++) {
            if (tabuleiro[9][4 + i] != 0){
                posicionar = 0;
            }
        } 
        if (posicionar){
            for (int i = 0; i < 3; i++){
            tabuleiro[9][4 + i] = 3;
            }
        }
    }

    // Verifica se pode posicionar navio vertical
    int posicionar2 = 1;

    if (5 + 3 <= 10) { // verifica limite
        for(int i = 0; i < 3; i++) {
            if (tabuleiro[5 + i][9] != 0) {
                posicionar2 = 0; // já tem algo na posição
            }
        }

        if (posicionar2) {
            for(int i = 0; i < 3; i++) {
                tabuleiro[5 + i][9] = 3;
            }
        }
    }

    // Verifica se pode posicionar navio diagonal
    //navios em diagonal
    int posicionarNovato = 1;

    if(9 <= 10){
        for (int i = 0; i < 10; i++){
            if (tabuleiro[i][i] != 0){
                posicionarNovato = 0;
            }
        }

        if (posicionarNovato){
            for (int i = 0; i < 10; i++){
            tabuleiro[i][i] = 3;
            }
        }   
    }

    int podeposicionar5 = 1;
    if ( 9 <= 10){
        for (int i = 0; i < 10; i++){
            if (tabuleiro[i][9 - i] != 0)
            {
                podeposicionar5 = 1;
            }
            
        }
        if (podeposicionar5){
        
            for(int i = 0; i < 10; i++){
            tabuleiro[i][9 - i] = 3;
            }
        }
    }

    // Exibe o tabuleiro
    printf("\n Tabuleiro Batalha Naval AVENTUREIRO:\n\n");
    printf("   A B C D E F G H I J\n");

    for(int i = 0; i < 10; i++) {
        printf("%d  ", i);
        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    // Matriz que representa a habilidade CONE (1 = área afetada)
    int cone[5][5] = {
        {0,0,1,0,0},
        {0,1,1,1,0},
        {1,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    };

    // Matriz que representa a habilidade CRUZ (1 = área afetada)
    int cruz[5][5] = {
        {0,0,1,0,0},
        {0,0,1,0,0},
        {1,1,1,1,1},
        {0,0,1,0,0},
        {0,0,1,0,0}
    };

    // Matriz que representa a habilidade OCTAEDRO (2 = área afetada)
    int octaendro[5][5] = {
        {0,0,2,0,0},
        {0,2,2,2,0},
        {2,2,2,2,2},
        {0,2,2,2,0},
        {0,0,2,0,0}
    };

    // Inicializa o tabuleiro com 0 (água)
    for(int i = 0; i < 10; i++) { // Percorre as linhas
        for(int j = 0; j < 10; j++) { // Percorre as colunas
            tabuleiro[i][j] = 0; // Coloca 0 em cada posição
        }
    }

    // Define o ponto de origem de cada habilidade
    int origemconel = 1, origemconec = 2; // Origem do cone
    int origemcruzl = 6, origemcruzc = 2; // Origem da cruz
    int origemocl = 6, origemocc = 6;     // Origem do octaedro

    // =====================
    // Aplicando o CONE
    // =====================
    for(int i=0;i < 5; i++){ // Percorre linhas da matriz cone
        for(int j = 0;j < 5; j++){ // Percorre colunas da matriz cone
            if(cone[i][j] == 1){ // Se essa posição faz parte da habilidade

                int l = origemconel + i; // Calcula linha no tabuleiro
                int c = origemconec + j; // Calcula coluna no tabuleiro

                // Verifica se está dentro do limite do tabuleiro
                if(l>=0 && l<10 && c>= 0 && c<10){

                    // Verifica se a posição ainda é água
                    if(tabuleiro[l][c] == 0){
                        tabuleiro[l][c] = 5; // Marca como área do cone
                    }
                }
            }
        }
    }

    // =====================
    // Aplicando a CRUZ
    // =====================
    for(int i=0;i < 5; i++){
        for(int j = 0;j < 5; j++){
            if(cruz[i][j] == 1){ // Se faz parte da cruz

                int l = origemcruzl + i - 1; // Ajuste para centralizar
                int c = origemcruzc + j - 1; // Ajuste para centralizar

                if(l>=0 && l<10 && c>= 0 && c<10){
                    if(tabuleiro[l][c] == 0){
                        tabuleiro[l][c] = 2; // Marca como área da cruz
                    }
                }
            }
        }
    }

    // =====================
    // Aplicando o OCTAEDRO
    // =====================
    for(int i=0;i < 5; i++){
        for(int j = 0;j < 5; j++){
            if(octaendro[i][j] == 2){ // Se faz parte do octaedro

                int l = origemocl + i - 3; // Ajuste de posição
                int c = origemocc + j - 1; // Ajuste de posição

                if(l>=0 && l<10 && c>= 0 && c<10){
                    if(tabuleiro[l][c] == 0){
                        tabuleiro[l][c] = 1; // Marca como área do octaedro
                    }
                }
            }
        }
    }

    // =====================
    // Exibição do tabuleiro
    // =====================

    printf("\n Tabuleiro Batalha Naval MESTRE:\n\n"); // Título
    printf("   A B C D E F G H I J\n"); // Letras das colunas

    for(int i = 0; i < 10; i++) { // Percorre linhas
        printf("%d  ", i); // Mostra número da linha
        for(int j = 0; j < 10; j++) { // Percorre colunas
            printf("%d ", tabuleiro[i][j]); // Mostra valor da posição
        }
        printf("\n"); // Pula linha
    }

    return 0; // Finaliza o programa
}