#include <stdio.h>
int main()
{
int x, *p, **q; // Q � um ponteiro de ponteiro
p = &x;
q = &p;
x = 10;
printf("\n%d\n", **q); // Essa mudan�a faz com que seja possivel acessar o valor armazenado pela variavel que p aponta, uma vez que q � um ponteiro de ponteiro
return(0);
}

