#include <iostream>
#include <time.h>
#include <string>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    string baralho[2][52];
    string mao[4][11];
    bool cartasDistribuidas[2][52] = {false};

    //cartas
    for (int n = 0; n < 4; n++)
    {
        for (int c = 0; c < 13; c++)
        {
            for (int b = 0; b < 2; b++)
            {
                baralho[b][n * 13 + c] = to_string(n + 1) + "-" + (c < 9 ? "0" : "") + to_string(c + 1) + "-" + to_string(b + 1);
            }
        }
    }

    //randomizar cartas
    srand(time(0));
    for (int j = 0; j < 4; j++)
    {
        for (int c = 0; c < 11; c++)
        {
            int n = rand() % 2;
            int i = rand() % 52;
            while (cartasDistribuidas[n][i])
            {
                n = rand() % 2;
                i = rand() % 52;
            }
            mao[j][c] = baralho[n][i];
            cartasDistribuidas[n][i] = true;
        }
    }

    //exibir
    for (int j = 0; j < 4; j++)
    {
        cout << "Mão do jogador" << j + 1 << " :" << endl;
        for (int c = 0; c < 11; c++)
        {
            cout << mao[j][c] << endl;
        }
        cout << endl;
    }
    return 0;
}

