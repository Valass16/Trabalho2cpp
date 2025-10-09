#include <iostream>
#include <limits>
#include <windows.h> // Adicionado para configurar UTF-8 no Windows
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Função para limpar o buffer de entrada
void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
}

// Função para pausar e aguardar o usuário
void pausar() {
    cout << "\nPressione Enter para continuar...";
    cin.get();
}

// Função para o jogo quente ou frio
void opcao1() {
    cout << "\n=== JOGO QUENTE OU FRIO ===\n";
    srand((unsigned)time(NULL));
    int numeroSecreto = rand() % 100 + 1;
    int palpite, tentativas = 0;

    cout << "Tente adivinhar o número entre 1 e 100!\n";

    do {
        cout << "Digite seu palpite: ";
        while (!(cin >> palpite) || palpite < 1 || palpite > 100) {
            cout << "Entrada inválida! Digite um número entre 1 e 100: ";
            limparBuffer();
        }
        limparBuffer();
        tentativas++;

        int diferenca = abs(numeroSecreto - palpite);

        if (palpite == numeroSecreto) {
            cout << "Parabéns! Você acertou em " << tentativas << " tentativa(s)!\n";
        } else if (diferenca <= 5) {
            cout << "Quente! ";
            if (palpite < numeroSecreto)
                cout << "Tente um número maior.\n";
            else
                cout << "Tente um número menor.\n";
        } else if (diferenca <= 15) {
            cout << "Morno! ";
            if (palpite < numeroSecreto)
                cout << "Tente um número maior.\n";
            else
                cout << "Tente um número menor.\n";
        } else {
            cout << "Frio! ";
            if (palpite < numeroSecreto)
                cout << "Tente um número maior.\n";
            else
                cout << "Tente um número menor.\n";
        }
    } while (palpite != numeroSecreto);

    pausar();
}

void opcao2() {
    cout << "\n=== OPÇÃO 2 SELECIONADA ===\n";
    cout << "Aqui você pode colocar o código da opção 2.\n";
    pausar();
}

void opcao3() {
    cout << "\n=== OPÇÃO 3 SELECIONADA ===\n";
    cout << "Aqui você pode colocar o código da opção 3.\n";
    pausar();
}

void opcao4() {
    cout << "\n=== OPÇÃO 4 SELECIONADA ===\n";
    cout << "Aqui você pode colocar o código da opção 4.\n";
    pausar();
}

void opcao5() {
    cout << "\n=== OPÇÃO 5 SELECIONADA ===\n";
    cout << "Aqui você pode colocar o código da opção 5.\n";
    pausar();
}

// Função para mostrar o menu
void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "           MENU PRINCIPAL\n";
    cout << "========================================\n";
    cout << "1. Opção 1 - Jogo Quente ou Frio\n";
    cout << "2. Opção 2 - Descrição da opção 2\n";
    cout << "3. Opção 3 - Descrição da opção 3\n";
    cout << "4. Opção 4 - Descrição da opção 4\n";
    cout << "5. Opção 5 - Descrição da opção 5\n";
    cout << "0. Sair do programa\n";
    cout << "========================================\n";
    cout << "Digite sua opção: ";
}

int main() {
    SetConsoleOutputCP(CP_UTF8); // Garante saída UTF-8 no terminal do Windows

    int opcao;
    bool continuar = true;

    cout << "Bem-vindo ao Menu Interativo!\n";

    while (continuar) {
        mostrarMenu();

        // Validação de entrada
        while (!(cin >> opcao)) {
            cout << "Entrada inválida! Digite um número: ";
            limparBuffer();
        }

        limparBuffer(); // Limpa o buffer após a entrada válida

        // Switch para processar a opção escolhida
        switch (opcao) {
            case 1:
                opcao1();
                break;
            case 2:
                opcao2();
                break;
            case 3:
                opcao3();
                break;
            case 4:
                opcao4();
                break;
            case 5:
                opcao5();
                break;
            case 0:
                cout << "\nSaindo do programa... Até logo!\n";
                continuar = false;
                break;
            default:
                cout << "\nOpção inválida! Tente novamente.\n";
                pausar();
                break;
        }
    }

    return 0;
}