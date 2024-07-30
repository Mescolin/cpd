/*

Exercício 5:
Faça um programa que receba do usuário o nome de dois arquivos texto e crie um terceiro cujo
conteúdo compreende a concatenação do conteúdo dos dois arquivos, ou seja, o conteúdo do
primeiro arquivo seguido do conteúdo do segundo.

*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string nome_arquivo1, nome_arquivo2, nome_arquivo_concatenado;
    string linha;

    cin >> nome_arquivo1;
    cin >> nome_arquivo2;
    cin >> nome_arquivo_concatenado;
    
    ifstream fin1(nome_arquivo1);
    if (!fin1.is_open()) {
        return 1;
    }
    
    ifstream fin2(nome_arquivo2);
    if (!fin2.is_open()) {
        fin1.close();
        return 1;
    }
    
    ofstream fout(nome_arquivo_concatenado);
    if (!fout.is_open()) {
        fin1.close();
        fin2.close();
        return 1;
    }
    
    while (getline(fin1, linha)) {
        fout << linha << endl;
    }
    
    while (getline(fin2, linha)) {
        fout << linha << endl;
    }
    
    fin1.close();
    fin2.close();
    fout.close();
    
    cout << endl;

    return 0;
}
