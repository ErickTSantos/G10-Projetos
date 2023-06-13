#ifndef __Fready__
#define __Fready__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Lista de presença
typedef struct presentes{
    char email[20];
    time_t tempo;
    struct presentes *next;
}presentes;

typedef struct precensa{
    char email[20];
    time_t entrada;
    time_t saida;
    struct precensa *next;
}precensa;

//tipo de senha
typedef struct senhassalvas {
    char email[100];
    char senha[100];
    char papel [10];//residente,preceptor,adm
    struct senhassalvas* next;
}senhassalvas;

//lista para o histórico de cada preceptor
typedef struct historico{
    time_t entrada;
    time_t saida;
    struct historico *next;
}historico;

//Estrutura de dados do aluno
typedef struct {
    char nome [101];
    char email [20];
    char cpf [15];
    char papel[12]; //residente,preceptor,adm
    char email_preceptor[20]; // id do preceptor que está supervisionando o residente
    char especializacao [20];
    //Acrescentar possível imagem para o sensor
    struct historico *lista_de_Presenca;
}residente;

//Estrutura de dados do medico
typedef struct {
    char nome [101];
    char email [20];
    char cpf [12];
    char papel[10]; //residente,preceptor,adm
    char CRM [14]; // CRM/PE 111111
    char especializacao [20];
}medico;

//Estrutura de dados da ADM
typedef struct {
    char nome[101];
    char email[20];
    char cpf[12];
    char papel[10];//residente,preceptor,adm
}adm;

//Lista que contem os alunos para simulação do armazenamento do banco de dados
typedef struct lista_aluno{
    residente* aluno;
    struct lista_aluno* next;
}lista_aluno;

//Lista que contem os preceptores para simulação do armazenamento do banco de dados
typedef struct lista_medico {
    medico* preceptor;
    struct lista_medico *next;
}lista_medico;

typedef struct lista_adm {
    adm* administrador;
    struct lista_adm *next;
}lista_adm;

void trocar_senha(char email[20]);
int verificadordesenhas(char login[20],char senha [20]);
void lg_residente (char email[20], lista_aluno* lista_de_alunos);
void lg_medico(char email[20], lista_aluno* lista_de_alunos,lista_medico* lista_de_medicos);
void lg_adm(char email[20], lista_aluno* lista_de_alunos,lista_medico* lista_de_medicos, lista_adm* lista_de_adm);
#endif