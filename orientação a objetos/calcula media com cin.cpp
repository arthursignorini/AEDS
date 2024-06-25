#include <iostream>
#include <string>

using namespace std;

class Aluno {
private:
    string nome;
    int matricula;
    double notas[10]; // Suponha que cada aluno pode ter at� 10 notas
    int quantidadeNotas;

public:
    // Construtor
    Aluno(string nome, int matricula) {
        this->nome = nome;
        this->matricula = matricula;
        quantidadeNotas = 0;
    }

    // M�todo para adicionar nota
    void adicionarNota(double nota) {
        if (quantidadeNotas < 10) {
            notas[quantidadeNotas] = nota;
            quantidadeNotas++;
        } else {
            cout << "Limite m�ximo de notas atingido (10 notas)." << endl;
        }
    }

    // M�todo para calcular a m�dia das notas
    double calcularMedia() {
        if (quantidadeNotas == 0) {
            return 0.0; // M�dia de zero se n�o houver notas
        }

        double soma = 0.0;
        for (int i = 0; i < quantidadeNotas; ++i) {
            soma += notas[i];
        }
        return soma / quantidadeNotas;
    }

    // M�todo para exibir todas as notas do aluno
    void exibirNotas() {
        cout << "Notas do aluno " << nome << " (Matr�cula: " << matricula << "):" << endl;
        for (int i = 0; i < quantidadeNotas; ++i) {
            cout << "Nota " << i + 1 << ": " << notas[i] << endl;
        }
    }
};

int main() {
    string nomeAluno;
    int matriculaAluno;
    double nota;
    char continuar;

    cout << "Digite o nome do aluno: ";
    getline(cin, nomeAluno); // L� o nome completo do aluno

    cout << "Digite a matr�cula do aluno: ";
    cin >> matriculaAluno; // L� a matr�cula do aluno

    Aluno aluno(nomeAluno, matriculaAluno); // Cria o objeto Aluno

    // Loop para adicionar notas
    do {
        cout << "Digite uma nota para o aluno: ";
        cin >> nota;
        aluno.adicionarNota(nota);

        cout << "Deseja adicionar outra nota? (s/n): ";
        cin >> continuar;
        cin.ignore(); // Limpa o buffer do teclado

    } while (continuar == 's' || continuar == 'S');

    // Exibe todas as notas e a m�dia do aluno
    cout << endl;
    aluno.exibirNotas();
    cout << "M�dia das notas: " << aluno.calcularMedia() << endl;

    return 0;
}

