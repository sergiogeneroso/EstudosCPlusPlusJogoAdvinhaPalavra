#include <iostream>
#include <cstdlib>

using namespace std;

int numero_maximo_tentativas;

bool acertou = false;

int tentativas = 0;

double pontos = 1000.0;

int numeroSecreto;

void imprimirCabecalho()
{
    cout << "********************************************" << endl;
    cout << "** Bem-vindudos ao jogo da adivinhacao! **" << endl;
    cout << "********************************************" << endl;

    cout << "Escolha o seu nivel de dificuldade: " << endl;
    cout << "Facil (F), Medio (M), Dificil (D)" << endl;
}

void configurarDificuldade()
{
    char dificuldade;

    cin >> dificuldade;

    if (dificuldade == 'F')
    {
        numero_maximo_tentativas = 15;
    }
    else if (dificuldade == 'M')
    {
        numero_maximo_tentativas = 10;
    }
    else
    {
        numero_maximo_tentativas = 5;
    }
}

void gerarNumeroSecreto()
{
    numeroSecreto = rand() % 100;
}

bool validarAcerto(int chute)
{
    acertou = chute == numeroSecreto;

    bool maior = chute > numeroSecreto;

    if (acertou)
    {
        cout << "Parabens voce acertou o numero secreto" << endl;
        return true;
    }
    else if (maior)
    {
        cout << "Seu chute foi maior que o numero secreto!" << endl;
        return false;
    }
    else
    {
        cout << "Seu chute foi menor que o numero secreto!" << endl;
        return false;
    }
}

void processarTentativas()
{
    int chute;

    for (tentativas = 1; tentativas <= numero_maximo_tentativas; tentativas++)
    {

        cout << "Qual seu chute? ";

        cin >> chute;

        double pontos_perdidos = abs((chute - numeroSecreto)) / 2.0;

        pontos = pontos - pontos_perdidos;

        cout << "O valor do seu chute e: " << chute << endl;

        if (validarAcerto(chute))
            break;
    }
}

void imprimirRodaPe()
{
    cout << "Fim de jogo." << endl;
    if (acertou)
    {
        cout << "Voce acertou em: " << tentativas << " tentativas." << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de: " << pontos << " pontos." << endl;
    }
    else
    {
        cout << "Voce perdeu! Tente novamente!" << endl;
    }
}

int main()
{
    imprimirCabecalho();

    configurarDificuldade();

    gerarNumeroSecreto();

    processarTentativas();
    
    imprimirRodaPe();
}