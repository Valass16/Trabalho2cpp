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
    limparConsola();
}

void opcao2() {
    limparConsola();
    cout << "\n=== INVERTE LETRAS ===\n";

    cout << "Digite uma palavra: ";

    string palavra;

    getline(cin, palavra);
 
    // Inverter a palavra

    string invertida = palavra;

    reverse(invertida.begin(), invertida.end());
 
    cout << "Palavra invertida: " << invertida << endl;
    pausar();
    limparConsola();
}

void opcao3() {
    limparConsola();
cout << "\n=== ALTERNA MAIÚSCULAS E MINÚSCULAS ===\n";

    cout << "Digite uma palavra ou frase: ";

    string texto;

    getline(cin, texto);
 
    // Alternar maiúsculas e minúsculas

    for (size_t i = 0; i < texto.size(); ++i) {

         if (isalpha(texto[i])) {

             if (islower(texto[i]))

                 texto[i] = toupper(texto[i]);

             else

                 texto[i] = tolower(texto[i]);

         }

     }
 
    cout << "Resultado: " << texto << endl;
    pausar();
    limparConsola();
}

void opcao4() {
    limparConsola();
    cout << "\nSair do programa.\n";
    pausar();
    limparConsola();
}

void mostrarMenu() {
    cout << "\n========================================\n";
    cout << "           MENU PRINCIPAL\n";
    cout << "========================================\n";
    cout << "1. Opção 1 - Jogo do quente ou frio\n";
    cout << "2. Opção 2 - Inverte letras\n";
    cout << "3. Opção 3 - Alterna maiúsculas e minúsculas\n";
    cout << "4. Sair do programa\n";
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