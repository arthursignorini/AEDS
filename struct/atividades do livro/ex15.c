#include <stdio.h>
#include <string.h>

// Defini��es das estruturas
typedef struct {
    int cod_cozinheiro;
    char nome_cozinheiro[50];
} Cozinheiro;

typedef struct {
    int cod_receita;
    char nome_receita[50];
    float calorias;
    int cod_cozinheiro;
} Receita;

typedef struct {
    int cod_ingrediente;
    char descricao_ingrediente[50];
} Ingrediente;

typedef struct {
    int cod_ingrediente[3];
    int cod_receita;
    int quantidade[3];
    char medida[3][50];
} Ingrediente_receita;

// Fun��o para preencher informa��es sobre os cozinheiros
void preencher_cozinheiro(Cozinheiro cozinheiro[])
{
    for(int i = 0; i < 3; i++){
        printf("Digite o nome do cozinheiro: ");
        fgets(cozinheiro[i].nome_cozinheiro, 50, stdin);
        printf("Digite o c�digo desse cozinheiro: ");
        scanf("%d", &cozinheiro[i].cod_cozinheiro);
        getchar();
        printf("\n");
    }
}

// Fun��o para preencher informa��es sobre os ingredientes
void preencher_ingrediente(Ingrediente ingrediente[], int tam)
{
    for(int i = 0; i < tam; i++){
        printf("Digite a descri��o do ingrediente: ");
        fgets(ingrediente[i].descricao_ingrediente, 50, stdin);
        printf("Digite o c�digo desse ingrediente: ");
        scanf("%d", &ingrediente[i].cod_ingrediente);
        getchar();
        printf("\n");
    }
}

// Fun��o para preencher informa��es sobre as receitas
void preencher_receita(Receita receita[], Ingrediente_receita ingrediente_receita[])
{
    for(int i = 0; i < 20; i++){
        int ing;
        printf("Digite o nome da receita: ");
        fgets(receita[i].nome_receita, 50, stdin);
        printf("Digite o c�digo da receita: ");
        scanf("%d", &receita[i].cod_receita);
        getchar();
        printf("Digite a quantidade de calorias a cada 100g: ");
        scanf("%f", &receita[i].calorias);
        getchar();
        printf("Digite o c�digo do cozinheiro: ");
        scanf("%d", &receita[i].cod_cozinheiro);
        getchar();
        printf("Digite quantos ingredientes voc� vai usar: ");
        scanf("%d", &ing);
        if(ing > 3){
            printf("Voc� pode cadastrar no m�ximo 3 por receita.\n");
            ing = 3;
        }
        ingrediente_receita[i].cod_receita = receita[i].cod_receita;
        for(int cont = 0; cont < ing; cont++){
            printf("Digite o c�digo de um ingrediente: ");
            scanf("%d", &ingrediente_receita[i].cod_ingrediente[cont]);
            printf("Digite a quantidade: ");
            scanf("%d", &ingrediente_receita[i].quantidade[cont]);
            getchar();
            printf("Digite a medida: ");
            fgets(ingrediente_receita[i].medida[cont], 50, stdin);
        }
        printf("\n");
    }
}

// Fun��o para contar o n�mero de receitas elaboradas por um cozinheiro espec�fico
int contar_receitas_cozinheiro(int codigo, Receita receita[])
{
    int cont = 0;
    for(int i = 0; i < 20; i++){
        if(codigo == receita[i].cod_cozinheiro){
            cont++;
        }
    }
    return cont;
}

// Fun��o para mostrar todas as receitas cujo total de calorias esteja dentro de um intervalo especificado
void mostrar_receitas_intervalo(float calorias_min, float calorias_max, Receita receita[], Ingrediente_receita ingrediente_receita[], Ingrediente ingrediente[], int tam_ingredientes)
{
    printf("Receitas dentro do intervalo de calorias %.2f - %.2f:\n", calorias_min, calorias_max);
    for(int i = 0; i < 20; i++)
    {
        if(receita[i].calorias >= calorias_min && receita[i].calorias <= calorias_max)
        {
            printf("Nome da receita: %s", receita[i].nome_receita);
            printf("C�digo da receita: %d\n", receita[i].cod_receita);
            printf("Calorias: %.2f\n", receita[i].calorias);
            printf("C�digo do cozinheiro: %d\n", receita[i].cod_cozinheiro);
            printf("Ingredientes:\n");
            for(int j = 0; j < 3; j++)
            {
                if(ingrediente_receita[i].cod_ingrediente[j] != 0)
                {
                    for(int t = 0; t < tam_ingredientes; t++)
                    {
                        if(ingrediente_receita[i].cod_ingrediente[j] == ingrediente[t].cod_ingrediente)
                        {
                            printf("  - %s, Quantidade: %d, Medida: %s", ingrediente[t].descricao_ingrediente, ingrediente_receita[i].quantidade[j], ingrediente_receita[i].medida[j]);
                        }
                    }
                }
            }
            printf("\n\n");
        }
    }
}

// Fun��o principal
int main()
{
    Cozinheiro cozinheiro[3];
    preencher_cozinheiro(cozinheiro);

    int tam;
    printf("Digite quantos ingredientes voc� quer cadastrar: ");
    scanf("%d", &tam);
    getchar();
    Ingrediente ingrediente[tam];
    preencher_ingrediente(ingrediente, tam);

    Receita receita[20];
    Ingrediente_receita ingrediente_receita[20];
    preencher_receita(receita, ingrediente_receita);

    // Mostrar total de receitas elaboradas por cada cozinheiro
    printf("\nTotal de receitas elaboradas por cada cozinheiro:\n");
    for (int i = 0; i < 3; i++) {
        int total = contar_receitas_cozinheiro(cozinheiro[i].cod_cozinheiro, receita);
        printf("Cozinheiro: %s - Total de receitas: %d\n", cozinheiro[i].nome_cozinheiro, total);
    }

    // Mostrar receitas dentro de um intervalo espec�fico de calorias
    float calorias_min, calorias_max;
    printf("\nDigite o intervalo de calorias (m�nimo e m�ximo): ");
    scanf("%f %f", &calorias_min, &calorias_max);
    mostrar_receitas_intervalo(calorias_min, calorias_max, receita, ingrediente_receita, ingrediente, tam);

    return 0;
}
