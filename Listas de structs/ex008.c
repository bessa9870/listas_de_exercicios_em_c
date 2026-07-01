#include <stdio.h>
#include <stdlib.h>

/*7. Escreva um trecho de código em “C” para fazer a criação dos novos tipos de dados
conforme solicitado abaixo:
Horário: composto de hora, minutos e segundos.
Data : composto de dia, mês e ano.
Compromisso: composto de uma data, horário e texto que descreve o
compromisso. Byte : usado para armazenar 8 bits (definido em função dos tipos
básicos do ”C” )*/

typedef struct{
    int hora,minuto,segundo;
}Horario;

typedef struct{
    int dia,mes,ano;
}Data;

typedef struct{
    Data data;
    Horario horario;
    char descricao[101];
}Compromisso;

typedef char Byte;
//Foi mais díficil interpretar a questão do que fazê-la
