#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaFready.h"

//funções do APP


void lg_medico (char email, char papel) {
    // Busca nos arquivos o email e nível do médico
    lista_aluno *alunos = NULL;
    // Busca no BD os alunos que estão sobre sua supervisão
    
    int opcao; //Entra no Menu do Médico
    do {
        printf("\nMenu do Médico\n");
        printf("1. Visualizar lista de alunos sob sua supervisão\n");
        printf("2. Visualizar frequência de um aluno\n");
        printf("0. Sair\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: //Nesse caso, como busquei nos residente a lista de alunos que são supervisionados pelo médico,é apenas processo de impressão
                printf("\nLista de alunos sob sua supervisão:\n");
                lista_aluno *aluno_atual = alunos;
                // while (aluno_atual != NULL) {
                //     if (strcmp(aluno_atual->aluno.email_preceptor,email)==1){
                //         printf("ID: %d\nNome: %s\n", aluno_atual->aluno.email, aluno_atual->aluno.nome);
                //     }
                //     aluno_atual = aluno_atual->next;
                // }
                break;
            case 2: //Escolhe o ID do aluno através da função 'encontrar_aluno_por_email() e retorna um struct residente com a estrutura do aluno.
                printf("\nDigite o ID do aluno para visualizar a frequência: ");
                int id_aluno;
                scanf("%d", &id_aluno);
                residente aluno_frequencia = encontrar_aluno_por_email(id_aluno);
                residente *ponteiro=&aluno_frequencia;
                if (ponteiro == NULL) { //Condição para não encontrar o aluno
                    printf("Aluno não encontrado!\n");
                    break;
                }
                printf("\nFrequência de %s:\n", ponteiro->nome); //Mostra o nome do aluno e abaixo segue o histórico pela função while.
                // historico *presenca_atual = ponteiro->Head;// No While ele irá rodar todas as presenças que o aluno tem.
                // while (presenca_atual != NULL) {
                //     printf("Entrada: %sSaida: %sDuração: %ld segundos\n", ctime(&(presenca_atual->entrada)), ctime(&(presenca_atual->saida)), presenca_atual->saida - presenca_atual->entrada);
                //     presenca_atual = presenca_atual->next;
                // }
                break;
            case 0:
                printf("\nSaindo do Menu do Médico.\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    // Libera a memória alocada
    liberar_lista_alunos(alunos);
}

void lg_adm (char email, char papel) {
    // Importar todos os residente do banco de residente para conseguir trabalhar neles
    lista_aluno* lista_atual_residente=NULL;
    lista_medico* lista_atual_preceptor=NULL;
    int opcao;
    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Visualizar lista de residentes e seus preceptores\n");
        printf("2 - Visualizar faltas dos residentes\n");
        printf("3 - Visualizar hierarquias e residente estatisticos\n");
        printf("4 - Visualizar hierarquias e residente estatisticos\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Lista de residentes e seus preceptores:\n");
                // Visualizar lista de residentes e seus preceptores através de uma varredura de todos os residente do arquivo que ainda estão ativos.
                break;
            case 2:
                printf("Faltas dos residentes:\n");
                // Visualizar faltas dos residentes, buscar e exibir as faltas dos residentes
                break;
            case 3:
                printf("Hierarquias e residente estatisticos:\n");
                // Visualizar hierarquias e residente estatisticos, busca e exibi as hierarquias e residente estatisticos
                break;
            case 4:
                printf("Cancele ou retome a inscrição do lg_residente ou aluno\n");
                //Nessa seção será possível vizualizar os status de todas as pessoas inscritas no programa de residência do Hospital das Clínicas, podendo ser encerrada ou acrescentada.
                //Após realizar as alterações, iremos atualizar o banco de residente.
                break;
            case 5:
                // Sair
                printf("Encerrando sessao do lg_adm...\n");
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }
}

residente encontrar_aluno_por_email(char email){
    //aqui o sistema irá realizar uma busca e retornar os residente do aluno
    residente aluno;
    //iguala os residente a struct aluno e a retorna.
    return (aluno);
}
