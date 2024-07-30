/*

Exercico 6:
Crie um programa que gere 1000 números aleatórios no intervalo [−100, 300] e escreva-os em um
arquivo texto. Em seguida, leia o conteúdo deste arquivo e escreva-o em um outro arquivo de forma
que os números estejam em ordem crescente. Informe a quantidade de números distintos no
arquivo

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// busca sequencial ordenada
bool busca_seq_ord(int *v, int n, int valor) {
    for(int i = 0; i < n && valor >= v[i]; i++) {
        if(v[i] == valor)
            return true;
    }
    return false;
}

// ordenação por inserção
void ordenar_vetor(int *v, int n) {
    for (int i = 1; i < n; ++i) {
        int chave = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }
}

int main() {

    srand(time(nullptr));


    ofstream fout("numeros_aleatorios.txt");
    for (int i = 0; i < 10; ++i) {
        int numero = rand() % 401 - 100;
        fout << numero << endl;
    }
    fout.close();

    ifstream fin("numeros_aleatorios.txt");
    vector<int> numeros;
    int numero;
    while (fin >> numero) {
        if (!busca_seq_ord(numeros.data(), numeros.size(), numero)) {
            numeros.push_back(numero);
        }
    }
    fin.close();

    ordenar_vetor(numeros.data(), numeros.size());

    ofstream fout_ordenado("numeros_ordenados.txt");

    for (int num : numeros) {
        fout_ordenado << num << endl;
    }
    fout_ordenado.close();

    int qtd_distintos = numeros.size();

    cout << qtd_distintos << endl;

    return 0;
}
