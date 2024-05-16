#include<stdio.h>
int main(){
// p++:

// Esta express�o incrementa o ponteiro p.
// Primeiro, o valor atual de p � usado na express�o (por exemplo, se p est� sendo atribu�do a outra vari�vel, o valor antes do incremento � o que ser� atribu�do), depois p � incrementado para apontar para o pr�ximo elemento do tipo ao qual ele aponta.

int arr[3] = {10, 20, 30};
int *p = arr;
printf("%d\n", *p); // Imprime 10
p++;
printf("%d\n", *p); // Imprime 20


// (*p)++:

// Esta express�o incrementa o valor armazenado na localiza��o de mem�ria apontada por p.
// Primeiro, o valor apontado por p � usado na express�o, depois o valor na mem�ria apontada por p � incrementado.
int arr[3] = {10, 20, 30};
int *p = arr;
printf("%d\n", *p); // Imprime 10
(*p)++;
printf("%d\n", *p); // Imprime 11


//*(p++):

// Esta express�o usa o valor apontado por p na posi��o atual e, em seguida, incrementa o ponteiro p.
// Primeiro, o valor apontado por p � usado na express�o, depois o ponteiro p � incrementado para apontar para o pr�ximo elemento do tipo ao qual ele aponta.
int arr[3] = {10, 20, 30};
int *p = arr;
printf("%d\n", *p); // Imprime 10
printf("%d\n", *(p++)); // Imprime 10, depois p � incrementado
printf("%d\n", *p); // Imprime 20

// Resumo das Diferen�as
// p++: Incrementa o ponteiro p ap�s seu valor atual ser usado.
// (*p)++: Incrementa o valor na mem�ria apontada por p.
// *(p++): Usa o valor apontado por p e depois incrementa o ponteiro p.

}
