#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Definição da estrutura para representar um território
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    struct Territorio
        territorios[5]; // Array para armazenar os territórios
    int i;
    printf("=== SISTEMA DE CADASTRO DE TERRITÓRIOS ===\n");
    
    // Loop para cadastro dos territórios
    for (i = 0; i < 5; i++) {
        printf("=======Cadastrando Territórios=======\n");

        printf("Digite o nome do território %d: ", i + 1);
        scanf("%s", territorios[i].nome);

        printf("Digite a cor do território %d: ", i + 1);
        scanf("%s", territorios[i].cor);

        printf("Digite o número de tropas no território %d: ", i + 1);
        scanf("%d", &territorios[i].tropas); 
    };
    
    // Mostrando territórios cadastrados
    printf("\n === Territórios Cadastrados ===\n"); 
    for (i = 0; i < 5; i++) {
        printf("Território %d: \n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
        printf("=========================================\n");
    };

    
    
    return 0;
}