#include <stdio.h>

int divisao(int num, int denominador) {
    if (num < denominador) {
        return 0;
    } else {
        return 1 + divisao(num - denominador, denominador);
    }
}

int main() {
    int num, denominador;
    printf("Numerador: ");
    scanf("%d", &num);
    printf("Denominador: ");
    scanf("%d", &denominador);

    // Verifica��o de divis�o por zero
    if (denominador == 0) {
        printf("Erro: Divis�o por zero n�o � permitida.\n");
    } else {
        printf("A divis�o desses n�meros � %d\n", divisao(num, denominador));
    }

    return 0;
}

