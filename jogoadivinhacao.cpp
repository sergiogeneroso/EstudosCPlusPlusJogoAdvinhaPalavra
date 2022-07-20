#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    cout << "********************************************" << endl;
    cout << "** Bem-vindudos ao jogo da adivinhacao! **" << endl;
    cout << "********************************************" << endl;

    cout << "Escolha o seu nivel de dificuldade: " << endl;
    cout << "Facil (F), Medio (M), Dificil (D)" << endl;

    char dificuldade;

    cin >> dificuldade;

    int numero_maximo_tentativas;

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

    const int NUMERO_SECRETO = rand() % 100;

    int chute;

    bool acertou = false;

    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numero_maximo_tentativas; tentativas++)
    {

        cout << "Qual seu chute? ";

        cin >> chute;

        double pontos_perdidos = abs((chute - NUMERO_SECRETO)) / 2.0;

        pontos = pontos - pontos_perdidos;

        cout << "O valor do seu chute e: " << chute << endl;

        acertou = chute == NUMERO_SECRETO;

        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabens voce acertou o numero secreto" << endl;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o numero secreto!" << endl;
        }
        else
        {
            cout << "Seu chute foi menor que o numero secreto!" << endl;
        }
    }

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