#include <iostream>
#include <limits>

using namespace std;

// Função para limpar o buffer de entrada
void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Função para pausar e aguardar o usuário
void pausar() {
    cout << "\nPressione Enter para continuar...";
    cin.get();
}

// Funções para cada opção do menu - personalize estas funções
void opcao1() {
    cout << "\n=== OPÇÃO 1 SELECIONADA ===\n";
    cout << "Aqui você pode colocar o código da opção 1.\n";
    // Adicione seu código aqui
    pausar();
}

void opcao2() {
    cout << "\n=== OPÇÃO 2 SELECIONADA ===\n";
    cout << "Aqui você pode colocar o código da opção 2.\n";
    // Adicione seu código aqui
    pausar();
}

void opcao3() {
    cout << "\n=== OPÇÃO 3 SELECIONADA ===\n";
    cout << "Aqui você pode colocar o código da opção 3.\n";
    // Adicione seu código aqui
    pausar();
}

void opcao4() {
    cout << "\n=== OPÇÃO 4 SELECIONADA ===\n";
    cout << "Aqui você pode colocar o código da opção 4.\n";
    // Adicione seu código aqui
    pausar();
}

void opcao5() {
    cout << "\n=== OPÇÃO 5 SELECIONADA ===\n";
    cout << "Aqui você pode colocar o código da opção 5.\n";
    // Adicione seu código aqui
    pausar();
}

// Função para mostrar o menu
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