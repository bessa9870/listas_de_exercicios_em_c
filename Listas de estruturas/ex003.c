#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define VERMELHO "\033[31m"
#define AMARELO "\033[33m"
#define AZUL "\033[34m"
#define CIANO "\033[36m"
#define RESET "\033[0m"

#define contatos 100
#define tamanho_nome 70
#define tamanho_email 50
#define tamanho_rua 50
#define tamanho_cidade 30
#define tamanho_obs 100

/* 3. Fazer um programa para simular uma agenda de telefones. Para cada pessoa devem-
se ter os seguintes dados:

Nome
E-mail
Endereço (contendo campos para Rua, numero, complemento, bairro, cep, cidade,
estado, paıs).
Telefone (contendo campo para DDD e numero)
Data de aniversario (contendo campo para dia, mês, ano).
Observações: Uma linha (string) para alguma observação especial.
*/

typedef struct{
    char rua[tamanho_rua];
    int numero_casa;
    char complemento[tamanho_rua];
    char bairro[tamanho_rua];
    int cep;
    char cidade[tamanho_cidade];
    char estado[3];
    char pais[tamanho_cidade];
}Endereco;

typedef struct{
    int dia, mes, ano;
}Aniversario;

typedef struct{
    char nome[tamanho_nome];
    char email[tamanho_email];
    Endereco endereco;
    char telefone[20];
    Aniversario aniversario;
    char obs[tamanho_obs];
}Agenda;

//----------------FUNÇÕES AUXILIARES----------------//
void ler_char(char destino[], int tamanho);
void ler_int(int *destino);
void ler_telefone(char destino[], int tamanho);
void limpar_buffer();

//----------------FUNÇÕES DE STRUCTS----------------//
void inserir(Agenda agenda[], int *contatos_cadastrados);
void excluir(Agenda agenda[], int *contatos_cadastrados);

//----------------FUNÇÕES DE IMPRESSÃO----------------//
void imprimir_struct(Agenda agenda[], int tamanho);
void imprimir_resumida(Agenda agenda[], int tamanho);

//----------------FUNÇÕES DE BUSCA----------------//
void busca_nome(Agenda agenda[], int contatos_cadastrados);
void busca_mes(Agenda agenda[], int contatos_cadastrados);
void busca_dia(Agenda agenda[], int contatos_cadastrados);

//----------------MENU DE OPÇÕES----------------//
void menu(Agenda agenda[], int *contatos_cadastrados);

int main(){
    Agenda agenda[contatos];
    int contatos_cadastrados=0;
    setlocale(LC_ALL, "");

    menu(agenda, &contatos_cadastrados);

    return 0;
}

void ler_char(char destino[], int tamanho){
    fgets(destino,tamanho,stdin);
    size_t len = strlen(destino);
    if(len > 0 && destino[len - 1] == '\n')
        destino[len - 1] = '\0';
    else{
        limpar_buffer();
    }
}

void ler_int(int *destino){
    int leitura;
    do{
        leitura = scanf("%d", destino);
        limpar_buffer();
        if(leitura != 1)
            printf("%sEntrada inválida. Tente novamente.\n%s",VERMELHO,RESET);
    }while(leitura != 1);
}

void ler_telefone(char destino[], int tamanho){
    int valido;
    do {
        valido = 1;
        ler_char(destino, tamanho);
        int len = strlen(destino);
        if(len == 0){
            valido = 0;
        }else{
            for(int i = 0; i < len; i++){
                char letra = destino[i];
                if((letra < '0' || letra > '9') && letra != ' ' && letra != '+'){
                    valido = 0;
                    break;
                }
            }
        }
        if(valido == 0){
            printf("%sTelefone inválido! Use apenas números, espaços e +. Tente novamente:%s\n",VERMELHO,RESET);
        }
    } while(valido == 0);
}

void limpar_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void inserir(Agenda agenda[], int *contatos_cadastrados){

    if(*contatos_cadastrados > 100){
        printf("Número máximo excedido.");
        return;
    }else{
        printf("----------------------------------------\n\t %sPreenchendo cadastro %d %s \n", AZUL, (*contatos_cadastrados)+1, RESET);
        printf("%s--Nome:%s ",CIANO,RESET);
        ler_char(agenda[*contatos_cadastrados].nome, tamanho_nome);
        printf("%s--Email:%s ",CIANO,RESET);
        ler_char(agenda[*contatos_cadastrados].email, tamanho_email);
        printf("%s--Endereço\nRua onde você mora:%s ",CIANO,RESET);
        ler_char(agenda[*contatos_cadastrados].endereco.rua, tamanho_rua);
        printf("%sNúmero da sua casa:%s ",CIANO,RESET);
        ler_int(&agenda[*contatos_cadastrados].endereco.numero_casa);
        printf("%sComplemento:%s ",CIANO,RESET);
        ler_char(agenda[*contatos_cadastrados].endereco.complemento, tamanho_rua);
        printf("%sBairro onde você mora:%s ",CIANO,RESET);
        ler_char(agenda[*contatos_cadastrados].endereco.bairro, tamanho_rua);
        printf("%sSeu cep:%s ",CIANO,RESET);
        ler_int(&agenda[*contatos_cadastrados].endereco.cep);
        printf("%sCidade em que reside:%s ",CIANO,RESET);
        ler_char(agenda[*contatos_cadastrados].endereco.cidade, tamanho_cidade);
        printf("%sO seu estado (UF):%s ",CIANO,RESET);
        ler_char(agenda[*contatos_cadastrados].endereco.estado, 3);
        printf("%sPor fim, seu país de origem:%s ",CIANO,RESET);
        ler_char(agenda[*contatos_cadastrados].endereco.pais, tamanho_cidade);
        printf("%s--Número para contato. Com DDD:%s ",CIANO,RESET);
        ler_telefone(agenda[*contatos_cadastrados].telefone, 20);
        printf("%s--Data de nascimento\nDia:%s ",CIANO,RESET);
        ler_int(&agenda[*contatos_cadastrados].aniversario.dia);
        printf("%sMês:%s ",CIANO,RESET);
        ler_int(&agenda[*contatos_cadastrados].aniversario.mes);
        printf("%sAno:%s ",CIANO,RESET);
        ler_int(&agenda[*contatos_cadastrados].aniversario.ano);
        printf("%s--Alguma observação sobre este contato?%s\n",CIANO,RESET);
        ler_char(agenda[*contatos_cadastrados].obs, tamanho_obs);
        (*contatos_cadastrados)++;
    }
    system("clear");
    Agenda auxiliar;    //TInha me esquecido, mas isso aqui é pra ordenar em ordem alfabética
    for(int i=0;i<*contatos_cadastrados;i++){
        for(int j=0;j<(*contatos_cadastrados)-1;j++){
            if (strcmp(agenda[j].nome,agenda[j+1].nome) >0){
                auxiliar = agenda[j+1];
                agenda[j+1] = agenda[j];
                agenda[j] = auxiliar;
            }
        }
    }
}

void menu(Agenda agenda[], int *contatos_cadastrados){
    int opcao;
        do{
            printf("%s======================================================\n",RESET);
            printf("                %sAgenda de contatos                    \n",RESET);
            printf("%s======================================================\n",RESET);
            printf("%s1.Buscar por nome.%s\n",CIANO,RESET);
            printf("%s2.Buscar por mês de amiversário.%s\n",CIANO,RESET);
            printf("%s3.Buscar por dia e mês de aniversário.%s\n",CIANO,RESET);
            printf("%s4.Inserir contato.%s\n",CIANO,RESET);
            printf("%s5.Remover contato.%s\n",CIANO,RESET);
            printf("%s6.Mostrar contatos%s\n",CIANO,RESET);
            printf("%s7.Sair.%s\n",VERMELHO,RESET);
            puts("");
            printf("%sEscolha uma opção:%s\n",AZUL,RESET);
            ler_int(&opcao);
            system("clear");
            switch(opcao){
        case 1:
            printf("%s\t1.Buscar por nome.%s\n",CIANO,RESET);
            busca_nome(agenda, *contatos_cadastrados);   //O menu precisa entregar o endereço * com o valor
            break;
        case 2:
            printf("%s\t2.Buscar por mês de amiversário.%s\n",CIANO,RESET);
            busca_mes(agenda, *contatos_cadastrados);
            break;
        case 3:
            printf("%s\t3.Buscar por dia e mês de aniversário.%s\n",CIANO,RESET);
            busca_dia(agenda, *contatos_cadastrados);
            break;
        case 4:
            printf("%s\t4.Inserir contato.%s\n",CIANO,RESET);
            inserir(agenda, contatos_cadastrados);  //O menu já tem o mapa & vindo da main
            puts("");
            break;
        case 5:
            printf("%s\t5.Remover contato.%s\n",CIANO,RESET);
            printf("%sAtenção! Essa ação não pode ser desfeita. deseja continuar?\nDigite 1 para %sSim %sou 2 para %sNão%s\n",AMARELO,AZUL,AMARELO,VERMELHO,RESET);
            int q;
            do{
                ler_int(&q);
                if(q < 1 || q > 2)
                    printf("%sOpçaão inválida. Tente novamente%s",VERMELHO,RESET);
            }while(q < 1 || q > 2);
            if(q == 2){
                    system("clear");
                    break;
                }else
                    excluir(agenda, contatos_cadastrados);
            break;
        case 6:
            printf("%s\t6.Mostrar contatos.%s\n",CIANO,RESET);
            printf("%sDeseja ver todos os dados ou resusmidos?\n%sDigite 1 para ver todos os dados\nDigite 2 para ver dados resumidos.%s\n",CIANO,AMARELO,RESET);
            int p;
            do{
                ler_int(&p);
                system("clear");
                if(p < 1 || p > 2)
                    printf("%sOpçaão inválida. Tente novamente%s",VERMELHO,RESET);
            }while(p < 1 || p > 2);
            if(p == 1)
                imprimir_struct(agenda, *contatos_cadastrados);
            else{
                imprimir_resumida(agenda, *contatos_cadastrados);
            }
            break;
        case 7:
            printf("%s\t7.Sair.%s\n",VERMELHO,RESET);
            printf("Programa encerado.");
            return;
            break;
        default:
            printf("%sOpção inválida.%s\n",VERMELHO,RESET);
        }
    }while(opcao != 7);
}

void imprimir_struct(Agenda agenda[], int tamanho){

     if(tamanho == 0){
        printf("%sNenhum contato cadastrado.\n\n%sPressione Enter para continuar.%s",VERMELHO,AZUL,RESET);
        limpar_buffer();
        system("clear");
        return;
    }

    for(int i = 0; i < tamanho; i++){
        printf("\t %sCadastro %d %s \n", AZUL, i+1, RESET);
        printf("%sNome:%s ",CIANO,RESET);
        puts(agenda[i].nome);
        printf("%sEmail:%s ",CIANO,RESET);
        puts(agenda[i].email);
        printf("%s--Endereço\nRua onde você mora:%s ",CIANO,RESET);
        puts(agenda[i].endereco.rua);
        printf("%sNúmero da sua casa:%s %d\n",CIANO,RESET,agenda[i].endereco.numero_casa);
        printf("%sTelefone:%s ", CIANO,RESET);
        puts(agenda[i].telefone);
        printf("%sAniversário:%s %02d/%02d/%d\n", CIANO,RESET,agenda[i].aniversario.dia, agenda[i].aniversario.mes, agenda[i].aniversario.ano);
        printf("%sObservações:%s %s\n", CIANO,RESET,agenda[i].obs);
    }
        printf("\n%sPressione Enter para continuar\n.%s",AZUL,RESET);
        limpar_buffer();
        system("clear");
}

void busca_nome(Agenda agenda[], int contatos_cadastrados){

    if(contatos_cadastrados == 0){
        printf("%sNenhum contato cadastrado.\n\n%sPressione Enter para continuar.%s",VERMELHO,AZUL,RESET);
        limpar_buffer();
        system("clear");
        return;
    }

    int contador=0;
    Agenda vetor[contatos_cadastrados];
    char v_nome[tamanho_nome];

    printf("%sDigite o nome:%s",AZUL,RESET);
    ler_char(v_nome, tamanho_nome);
    for(int i=0; i< contatos_cadastrados; i++){
        if(strcmp(v_nome,agenda[i].nome) == 0){
            vetor[contador] = agenda[i];
            contador++;
        }
    }
    if(contador == 0){
        printf("%sNenhum nome encontrado\n%s",VERMELHO,RESET);
        limpar_buffer();
        system("clear");
        return;
    }else{
        imprimir_struct(vetor, contador);   //Não devo usar cocheteeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
        printf("%sPressione Enter para continuar.\n%s",AZUL,CIANO);
        limpar_buffer();
        system("clear");
    }
    system("clear");
}

void busca_mes(Agenda agenda[], int contatos_cadastrados){

    if(contatos_cadastrados == 0){
        printf("%sNenhum contato cadastrado.\n\n%sPressione Enter para continuar.%s",VERMELHO,AZUL,RESET);
        limpar_buffer();
        system("clear");
        return;
    }

    int contador=0;
    Agenda vetor[contatos_cadastrados];
    int v_mes;

    printf("%sDigite o mês de nascimento:%s",AZUL,RESET);
    ler_int(&v_mes);
    for(int i=0; i< contatos_cadastrados; i++){
        if(v_mes == agenda[i].aniversario.mes){
            vetor[contador] = agenda[i];
            contador++;
        }
    }
    if(contador == 0){
        printf("%sNenhum nome encontrado.\n%s",VERMELHO,RESET);
        limpar_buffer();
        system("clear");
        return;
    }else{
        imprimir_struct(vetor, contador);   //Não devo usar cocheteeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
        printf("%sPressione Enter para continuar\n.%s",AZUL,RESET);
        limpar_buffer();
        system("clear");
    }
    system("clear");
}

void busca_dia(Agenda agenda[], int contatos_cadastrados){

    if(contatos_cadastrados == 0){
        printf("%sNenhum contato cadastrado.\n\n%sPressione Enter para continuar.%s",VERMELHO,AZUL,RESET);
        limpar_buffer();
        system("clear");
        return;
    }

    int contador=0;
    Agenda vetor[contatos_cadastrados];
    int v_mes, v_dia;

    printf("%sDigite o mês de nascimento:%s",CIANO,RESET);
    ler_int(&v_mes);
    printf("%sDigite o dia de nascimento:%s",CIANO,RESET);
    ler_int(&v_dia);

    for(int i=0; i< contatos_cadastrados; i++){
        if(v_mes == agenda[i].aniversario.mes && v_dia == agenda[i].aniversario.dia){
            vetor[contador] = agenda[i];
            contador++;
        }
    }
    if(contador == 0){
        printf("%sNenhum nome encontrado\n%s",VERMELHO,RESET);
        limpar_buffer();
        system("clear");
        return;
    }else{
        imprimir_struct(vetor, contador);   //Não devo usar cocheteeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
        printf("%sPressione Enter para continuar\n.%s",AZUL,CIANO);
        limpar_buffer();
        system("clear");
    }
    system("clear");
}

void excluir(Agenda agenda[], int *contatos_cadastrados){

    if(*contatos_cadastrados == 0){
        printf("%sNenhum contato cadastrado.\n\n%sPressione Enter para continuar.%s",VERMELHO,AZUL,RESET);
        limpar_buffer();
        system("clear");
        return;
    }

    char v_nome[tamanho_nome];
    int indice= -1;
    int contador=0;
    printf("%sDigite o nome completo para exclusão:%s",CIANO,RESET);
    ler_char(v_nome, tamanho_nome);
    for(int i=0; i < *contatos_cadastrados; i++){
        if(strcmp(v_nome,agenda[i].nome) == 0){
            indice = i;
            break;
        }
    }
    if(indice == -1){
        printf("%sNenhum nome encontrado\n%s",VERMELHO,RESET);
        limpar_buffer();
        system("clear");
        return;
    }else{
        printf("%sNome encontrado:%s %s \n", CIANO,RESET,agenda[indice].nome);
        for(int k = indice; k < *(contatos_cadastrados)-1; k++){
            agenda[k] = agenda[k+1];
        }
    }
    (*contatos_cadastrados)--;
    printf("Contato excluído. Pressione Enter para continuar.");
    limpar_buffer();
    system("clear");
}

void imprimir_resumida(Agenda agenda[], int tamanho){

    if(tamanho == 0){
        printf("%sNenhum contato cadastrado.\n\n%sPressione Enter para continuar.%s",VERMELHO,AZUL,RESET);
        limpar_buffer();
        system("clear");
        return;
    }

    for(int i = 0; i < tamanho; i++){
        printf("\t %sCadastro %d %s \n", AZUL, i+1, RESET);
        printf("%sNome:%s ",CIANO,RESET);
        puts(agenda[i].nome);
        printf("%sEmail:%s ",CIANO,RESET);
        puts(agenda[i].email);
        printf("%sTelefone:%s \n", CIANO,RESET);
        puts(agenda[i].telefone);
    }
    printf("\n%sPressione Enter para continuar.%s",AZUL,RESET);
    limpar_buffer();
    system("clear");
}
