#include<stdio.h>

int main()
{
// C�DIGO 1 - acrescenta 1 no valor de ptr e o printa no final
int *ptr, i;
ptr = (int *) malloc(sizeof(int));
*ptr = 10;
for(i=0;i<5;i++){
*ptr=*ptr+1;
}
printf("\nptr: %d", *ptr);
free(ptr);

// C�DIGO 2 - acrescenta 1 no endere�o e o printa no final - muda o endere�o cujo o ponteiro aponta
int *ptr, i;
ptr = (int *) malloc(sizeof(int));
*ptr = 10;
for(i=0;i<5;i++){
ptr=ptr+1;
}
printf("\nptr: %p", ptr);
free(ptr);

}
