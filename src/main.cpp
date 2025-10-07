#include <iostream>
#include <limits>

using namespace std;

// Função para limpar o buffer de entrada
void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Função para limpar o console
void limparConsola() {
    cout << "\033[2J\033[1;1H";  // Sequência ANSI para limpar a tela
    cout.flush();                 // Força a limpeza do buffer
}

// Função para pausar e aguardar o usuário
void pausar() {
    cout << "\nPressione Enter para continuar...";
    cin.get(); // Remove o cin.ignore anterior que estava causando o problema
}

// Funções para cada opção do menu
void opcao1() {
    limparConsola();
    cout << "\n=== OPÇÃO 1 SELECIONADA ===\n";
    cout << "INC 1.\n";
    pausar();
    limparConsola();
}

void opcao2() {
    limparConsola();
    cout << "\n=== OPÇÃO 2 SELECIONADA ===\n";
    cout << "INC 2.\n";
    pausar();
    limparConsola();
}

void opcao3() {
    limparConsola();
    cout << "\n=== OPÇÃO 3 SELECIONADA ===\n";
    cout << "INC 3.\n";
    pausar();
    limparConsola();
}

void opcao4() {
    limparConsola();
    cout << "\n=== OPÇÃO 4 SELECIONADA ===\n";
    cout << "INC 4.\n";
    pausar();
    limparConsola();
}

void opcao5() {
    limparConsola();
    cout << "\n=== OPÇÃO 5 SELECIONADA ===\n";
    cout << "INC 5.\n";
    pausar();
    limparConsola();
}

void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "           MENU PRINCIPAL\n";
    cout << "========================================\n";
    cout << "1. Opção 1 - Descrição da opção 1\n";
    cout << "2. Opção 2 - Descrição da opção 2\n";
    cout << "3. Opção 3 - Descrição da opção 3\n";
    cout << "4. Opção 4 - Descrição da opção 4\n";
    cout << "5. Opção 5 - Descrição da opção 5\n";
    cout << "0. Sair do programa\n";
    cout << "========================================\n";
    cout << "Digite sua opção: ";
}

int main() {
    int opcao;
    bool continuar = true;

    limparConsola();
    cout << "Bem-vindo ao Menu Interativo!\nPressione Enter para começar...";
    cin.get(); // Substitui o pausar() aqui para evitar double-enter

    while (continuar) {
        limparConsola();
        mostrarMenu();
        
        cin >> opcao;
        
        if (cin.fail()) {
            cout << "Entrada inválida! Digite um número: ";
            limparBuffer();
            continue;
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
                limparConsola();
                cout << "\nA sair do programa...\n";
                continuar = false;
                break;
            default:
                cout << "\nOpção inválida! Tente novamente.\n";
                pausar();
                limparConsola();
                break;
        }
    }

    return 0;
}