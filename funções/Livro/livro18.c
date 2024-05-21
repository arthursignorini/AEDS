#include <stdio.h>
#include <stdbool.h>

// Fun��o para verificar se um n�mero � primo
bool eh_primo(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Sub-rotina para encontrar e imprimir os tr�s primeiros n�meros primos acima de 100
void mostrar_primos() {
    int count = 0;
    int num = 101; // Inicia com o primeiro n�mero acima de 100

    while (count < 3) {
        if (eh_primo(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n");
}

int main() {
    printf("Os tr�s primeiros n�meros primos acima de 100 s�o: ");
    mostrar_primos();
    return 0;
}
