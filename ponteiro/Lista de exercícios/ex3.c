#include<stdio.h>
int main(){
int valor=5;
int *valorptr;
valorptr = &valor;



valor == &valorptr; // A vari�vel valor armazena um int e nao um endere�o - FALSO
valor == *valorptr; // O conteudo apontado pelo ponteiro � o mesmo que o de valor - CORRETO
valorptr == &valor; // O endere�o armazenado pelo ponteiro � o mesmo que o de valor - CORRETO
valorptr == *valor; // O endere�o que o ponteiro aponta nao pode ser comparado ao conte�do de valor e valor nao eh um vetor - FALSA
}
