/*
Exercício 7:
Escreva um programa que crie dois arquivos texto com 50 números reais aleatórios em cada com
duas casas decimais. Crie um terceiro arquivo cujo conteúdo será o conteúdo dos dois arquivos (100
números), porém ordenados de forma decrescente

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

// Busca sequencial ordenada
bool busca_seq_ord(float *v, int n, float valor) {
    for(int i = 0; i < n && valor >= v[i]; i++) {
        if(v[i] == valor)
            return true;
    }
    return false;
}

// Ordenação por inserção
void ordenar_vetor(float *v, int n) {
    for (int i = 1; i < n; ++i) {
        float chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] < chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }
}

int main() {

    srand(time(nullptr));

    ofstream fout1("numeros_aleatorios1.txt");
    ofstream fout2("numeros_aleatorios2.txt");

    for (int i = 0; i < 50; ++i) {
        float numero = rand() % 401 - 100 + (rand() % 100) / 100.00f;
        fout1 << fixed << setprecision(2) << numero << endl;
    }
    fout1.close();

    for (int i = 0; i < 50; ++i) {
        float numero = rand() % 401 - 100 + (rand() % 100) / 100.00f;
        fout2 << fixed << setprecision(2) << numero << endl;
    }
    fout2.close();

    vector<float> numeros;
    string linha;
    ifstream fin1("numeros_aleatorios1.txt");
    ifstream fin2("numeros_aleatorios2.txt");

    while (getline(fin1, linha)) {
        float numero = stof(linha);
        numeros.push_back(numero);
    }
    fin1.close();

    while (getline(fin2, linha)) {
        float numero = stof(linha);
        numeros.push_back(numero);
    }
    fin2.close();

    ordenar_vetor(numeros.data(), numeros.size());

    ofstream fout_ordenado("numeros_ordenados.txt");
    
    for (float num : numeros) {
        fout_ordenado << fixed << setprecision(2) << num << endl;
    }
    fout_ordenado.close();

    cout << endl;

    return 0;
}
