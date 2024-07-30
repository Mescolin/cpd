/*

Exercíco 4:
Faça um programa que abra um arquivo texto cujo nome será fornecido pelo usuário e apresente um
sumário com as seguintes informações: o número de linhas presentes no arquivo, o número de
caracteres, o número de vogais e o número de consoantes.

*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string nome_arquivo;
    cin >> nome_arquivo;

    ifstream fin(nome_arquivo);
    char c;
    int num_linhas = 0;
    int num_caracteres = 0;
    int num_vogais = 0;
    int num_consoantes = 0;

    if (fin.is_open()) {
        while (fin.get(c)) {
            num_caracteres++;
            if (c == '\n')
                num_linhas++;
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                    num_vogais++;
                else
                    num_consoantes++;
            }
        }
        if (c != '\n')
            num_linhas++;
        
        fin.close();

        cout << "numero de linhas: " << num_linhas << endl;
        cout << "numero de caracteres: " << num_caracteres << endl;
        cout << "numero de vogais: " << num_vogais << endl;
        cout << "numero de consoantes: " << num_consoantes << endl;
    } else {
        cout << "arquivo digitado errado ou nao existe" << endl;
    }

    return 0;
}
