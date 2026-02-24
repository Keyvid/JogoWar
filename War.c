#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

// Definição da estrutura para representar um território
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};
// Realizando batalha e suas regras
void realizarBatalha(struct Territorio *atacante, struct Territorio *defensor) {
    printf("\n=== Batalha: %s (Ataque) vs %s (Defesa) ===\n", atacante->nome, defensor->nome);
    
    if (atacante->tropas <=1){
        printf("Ataque CANCELADO! %s possui apenas %d tropa(s).\n", atacante->nome, atacante->tropas);
    }
    //Rolagem dos dados
    int dadoAtaque = (rand() % 6) + 1;
    int dadoDefesa = (rand() % 6) + 1;

    printf("Ataque tirou: %d\n", dadoAtaque);
    printf("Defesa tirou: %d\n", dadoDefesa);

    if (dadoAtaque > dadoDefesa) {
        printf("ATAQUE VENCEU! %ss cede 1 tropa para %s", defensor->nome, atacante->nome);
        defensor->tropas--;//Perdedor perde 1 tropa
        atacante->tropas++;//Ganhador ganha 1 tropa
    } else{
        printf("A DEFESA VENCEU! %s cede 1 tropa para %s.\n", atacante->nome, defensor->nome);
        atacante->tropas--;//Perdedor(ataque) perde 1
        defensor->tropas++;//Ganhador (defesa) ganha 1
    }
    
}

int main() {
    srand(time(NULL)); //Embaralhar os dados
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
int continuar = 1;
int opAtaque, opDefesa;

// Laço repetição da ação BATALHA até usuário digitar 0 para sair
while (continuar == 1) {
    printf("\n===========================\n");
    printf("      MENU DE BATALHA\n");
    printf("\n===========================\n");

    //Mostrar as opções de territórios atualizadas
    for (i = 0; i < 5; i++) {
        printf("[%d] %s (%d tropas)\n", i + 1, territorios[i].nome, territorios[i].tropas);
    }
    
    printf("\nDigite o número do território ATACANTE (1 A 5): ");
    scanf("%d", &opAtaque);

    printf("\nDigite o número do território DEFENSOR (1 A 5): ");
    scanf("%d", &opDefesa);

    // Validação para jogador não digitar número errado
    if (opAtaque < 1 || opAtaque > 5 || opDefesa < 1 || opDefesa > 5){
        printf("Opção inválida! Digite um número válido na quantidade de territórios disponíveis.\n");
        continue;
    }
    realizarBatalha(&territorios[opAtaque - 1], &territorios[opDefesa - 1]);

    printf("\nDeseja realizar outro ataque? (1 para SIM / 0 para NÃO): ");
    scanf("%d", &continuar);
}
printf("\nJogo encerrado!");
    
    return 0;
}