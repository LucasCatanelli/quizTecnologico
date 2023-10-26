#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pergunta {
    char desc[500], opcaoA[100], opcaoB[100], opcaoC[100], opcaoD[100], resposta_final;
};

struct Resultado_Questao {
	
    int pontuacao;
    char nome[100], sobrenome[100];
};

int main() {
    struct Pergunta perguntas[4];

    struct Pergunta pergunta1 = 
	{
        "1. Smartphones, iPad, iPhone, os celulares surgem em 1992 criados pela IBM e so foram se potencializando ate se tornarem o que sao hoje. Um computador de 'bolso' capaz de acessar internet, ouvir musicas, telefonar, tirar fotografias e muito mais.\n\n1.Qual empresa lançou o primeiro smartphone?",
        "A) Apple",
        "B) Samsung",
        "C) Xiaomi",
        "D) IBM",
        'D'
    };
    perguntas[0] = pergunta1;

    struct Pergunta pergunta2 = 
	{
        "2. O abaco foi uma das primeiras maquinas de computar, instrumento mecanico que tem origem chinesa no seculo V. Ele realizava operacoes algebricas como se fosse uma calculadora.\n\n2.Qual a origem do abaco?",
        "A) Russa",
        "B) Chinesa",
        "C) Brasileira",
        "D) Colombiana",
        'B'
    };
    perguntas[1] = pergunta2;

    struct Pergunta pergunta3 = 
	{
        "3. O primeiro computador a ser comercializado, fabricado nos Estados Unidos em 1951 ele marcou o inicio da comercializacao de computadores como conhecemos hoje.\n\n3.Qual ano de fabricacao do UNIVAC?",
        "A) 1951",
        "B) 1923",
        "C) 1955",
        "D) 2000",
        'A'
    };
    perguntas[2] = pergunta3;

    struct Pergunta pergunta4 = 
	{
        "4. ENIAC foi o primeiro computador digital eletronico criado, em 1946, a pedido do exercito americano para seu laboratorio de pesquisas balisticas. ENIAC possuia 30 toneladas e ocupava 180 metros quadrados.\n\n4.Qual era o peso do ENIAC?",
        "A) 30 toneladas",
        "B) 20 kg",
        "C) 100 kg",
        "D) 30 kg",
        'A'
    };
    perguntas[3] = pergunta4;

    int numPerguntas = 4, numeroParticipantes;

    printf("Seja Bem-vindo ao Quiz da Tecnologia!\n");

    printf("Quantos participantes vao responder o quiz? : ");
    scanf("%d", &numeroParticipantes);

    FILE *arquivoResultado_Questao = fopen("resultados2.csv", "a");

    if (arquivoResultado_Questao == NULL) {
        printf("Nao foi possivel abrir o arquivo que contem os resultados.\n");
        return 1;
    }

    for (int x = 0; x < numeroParticipantes; x++) {
        printf("\nDados do Participante %d:\n", x + 1);

        struct Resultado_Questao resultadoAtual;
        	printf("Nome do participante: ");
        	scanf("%s", resultadoAtual.nome);

        printf("Sobrenome do participante: ");
        scanf("%s", resultadoAtual.sobrenome);

        resultadoAtual.pontuacao = 0;

        for (int i = 0; i < numPerguntas; i++) {
            printf("\n%s\n", perguntas[i].desc);
            printf("%s\n%s\n%s\n%s\n", perguntas[i].opcaoA, perguntas[i].opcaoB, perguntas[i].opcaoC, perguntas[i].opcaoD);

            char resposta;
            printf("Responda utilizando em MAIUSCULO (A/B/C/D): ");
            scanf(" %c", &resposta);

            if (resposta == perguntas[i].resposta_final) {
                resultadoAtual.pontuacao++;
                printf("Parabens!! Sua resposta esta correta!\n");
            } else {
                printf("Infelizmente sua resposta esta incorreta. A resposta correta e: %c\n", perguntas[i].resposta_final);
            }
        }

        fprintf(arquivoResultado_Questao, "Nome do Participante: %s %s, Pontuacao do Participante: %d\n", resultadoAtual.nome, resultadoAtual.sobrenome, resultadoAtual.pontuacao);
    }

    fclose(arquivoResultado_Questao);

    return 0;
}
