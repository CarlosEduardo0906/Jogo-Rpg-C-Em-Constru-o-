#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERSONAGEM 1
#define TAMANHO_MAPA 3

typedef struct {
    char nome[20];
    char classe[20];
    int ordem;
    int posicao_x;
    int posicao_y;
} Personagem;

void selecionarPersonagem(Personagem* personagens, int* numPersonagens, const char* nomePersonagem, int classe, int ordem);
int escolher_classe();
int escolher_ordem();
void mostrar_resultado(int vidaHeroi, int vidaMonstro);

void exibirMapa(int posicao_x, int posicao_y) {
    char mapa[TAMANHO_MAPA][TAMANHO_MAPA] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    mapa[posicao_x][posicao_y] = 'X';

    printf("Mapa:\n");
    printf("-----------\n");
    for (int i = 0; i < TAMANHO_MAPA; i++) {
        for (int j = 0; j < TAMANHO_MAPA; j++) {
            printf("| %c ", mapa[i][j]);
        }
        printf("|\n");
        printf("-----------\n");
    }
}

int main() {
    printf("Bem-vindo ao jogo de RPG!\n\n");
    printf("Prepare-se para uma grande aventura!\n\n");
    printf("Esta é uma história de aventura e fantasia sobre um grupo de heróis que viaja por um reino mágico chamado Alveron.\n");
    printf("Eles embarcam em uma jornada épica para recuperar um artefato roubado e ajudar as cidades em necessidade.\n");
    printf("Ao longo de sua jornada, os heróis enfrentam criaturas místicas, resolvem enigmas e enfrentam desafios mortais.\n");
    printf("Com habilidades únicas e trabalho em equipe, eles superam todos os obstáculos e perigos que surgem em seu caminho.\n");
    printf("No final, os heróis triunfam sobre as forças das trevas, trazendo a paz e a esperança de volta a Alveron.\n");
    printf("Essa é uma história de coragem, amizade e determinação que jamais será esquecida.\n\n");

    char nomePersonagem[20];
    printf("Digite o nome do personagem: ");
    scanf("%s", nomePersonagem);

    int escolha;

    // Passo 1: Selecionar uma classe
    int classe = escolher_classe();

    // Passo 2: Selecionar uma ordem
    int ordem = escolher_ordem();

    Personagem personagens[MAX_PERSONAGEM];
    int numPersonagens = 0;  // Inicializado como 0

    selecionarPersonagem(personagens, &numPersonagens, nomePersonagem, classe, ordem);

    printf("Escolha o número do personagem:\n");
    for (int i = 0; i < numPersonagens; i++) {
        printf("%d - %s (%s)\n", i + 1, personagens[i].nome, personagens[i].classe);
    }
    printf("Digite o número do personagem: ");
    scanf("%d", &escolha);

    if (escolha >= 1 && escolha <= numPersonagens) {
        printf("Personagem selecionado: %s (%s)\n", personagens[escolha - 1].nome, personagens[escolha - 1].classe);
    } else {
        printf("Opção inválida!\n");
        return 1;
    }

    int posicao_x = 1;
    int posicao_y = 1;

    exibirMapa(posicao_x, posicao_y);

    while (1) {
        printf("Escolha uma ação para continuar a história:\n");
        printf("1 - Conversar com os moradores de Alveron\n");
        printf("2 - Explorar as ruínas antigas\n");
        printf("3 - Lutar contra uma criatura mística\n");
        printf("4 - Resolver um enigma desafiador\n");
        printf("5 - Enfrentar o líder das forças das trevas\n");
        printf("6 - Mover para cima\n");
        printf("7 - Mover para baixo\n");
        printf("8 - Mover para a esquerda\n");
        printf("9 - Mover para a direita\n");
        printf("Digite o número da ação: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Você decide conversar com os moradores de Alveron.\n");
                printf("Eles compartilham informações valiosas sobre o paradeiro do artefato roubado.\n");
                break;
            case 2:
                printf("Você decide explorar as ruínas antigas.\n");
                printf("Dentro das ruínas, você encontra pistas que o levam mais perto do artefato.\n");
                break;
            case 3:
                printf("Você decide lutar contra uma criatura mística.\n");
                printf("A batalha é feroz, mas você usa suas habilidades únicas para derrotá-la.\n");
                break;
            case 4:
                printf("Você decide resolver um enigma desafiador.\n");
                printf("Com sua inteligência afiada, você decifra o enigma e desbloqueia um caminho secreto.\n");
                break;
            case 5:
                printf("Você decide enfrentar o líder das forças das trevas.\n");
                printf("A batalha final é intensa, mas com a determinação do grupo, você consegue derrotá-lo.\n");
                break;
            case 6:
                if (posicao_x > 0) {
                    posicao_x--;
                } else {
                    printf("Você não pode se mover para cima.\n");
                }
                break;
            case 7:
                if (posicao_x < TAMANHO_MAPA - 1) {
                    posicao_x++;
                } else {
                    printf("Você não pode se mover para baixo.\n");
                }
                break;
            case 8:
                if (posicao_y > 0) {
                    posicao_y--;
                } else {
                    printf("Você não pode se mover para a esquerda.\n");
                }
                break;
            case 9:
                if (posicao_y < TAMANHO_MAPA - 1) {
                    posicao_y++;
                } else {
                    printf("Você não pode se mover para a direita.\n");
                }
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }

        exibirMapa(posicao_x, posicao_y);
    }

    return 0;
}

void selecionarPersonagem(Personagem* personagens, int* numPersonagens, const char* nomePersonagem, int classe, int ordem) {
    if (*numPersonagens >= MAX_PERSONAGEM) {
        printf("Número máximo de personagens alcançado!\n");
        return;
    }

    Personagem novoPersonagem;
    strcpy(novoPersonagem.nome, nomePersonagem);

    switch (classe) {
        case 1:
            strcpy(novoPersonagem.classe, "Guerreiro");
            break;
        case 2:
            strcpy(novoPersonagem.classe, "Mago");
            break;
        case 3:
            strcpy(novoPersonagem.classe, "Arqueiro");
            break;
        default:
            printf("Classe inválida!\n");
            return;
    }

    novoPersonagem.ordem = ordem;
    novoPersonagem.posicao_x = 1;
    novoPersonagem.posicao_y = 1;

    personagens[*numPersonagens] = novoPersonagem;
    (*numPersonagens)++;
}

int escolher_classe() {
    int classe;

    printf("Escolha a classe do personagem:\n");
    printf("1 - Guerreiro\n");
    printf("2 - Mago\n");
    printf("3 - Arqueiro\n");
    printf("Digite o número da classe: ");
    scanf("%d", &classe);

    return classe;
}

int escolher_ordem() {
    int ordem;

    printf("Escolha a ordem do personagem:\n");
    printf("1 - Ordem do Leão\n");
    printf("2 - Ordem do Dragão\n");
    printf("3 - Ordem da Serpente\n");
    printf("Digite o número da ordem: ");
    scanf("%d", &ordem);

    return ordem;
}

void mostrar_resultado(int vidaHeroi, int vidaMonstro) {
    if (vidaHeroi > vidaMonstro) {
        printf("Parabéns! Você venceu a batalha!\n");
    } else {
        printf("Você foi derrotado! Tente novamente!\n");
    }
}