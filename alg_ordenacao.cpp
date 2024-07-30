#include <bits/stdc++.h>
#include "colors.h"

#define TAM 20

using namespace std;

void ord_selecao(int *v, int tam);

int main() {
    srand(time(NULL));
    int vet[TAM];
    for(int i = 0; i < TAM; i++) {
        vet[i] = rand()%100 + 1;
        cout << vet[i] << " ";
    }
    /*vet[19] = 0;
    cout << vet[19] << " ";*/
    cout << endl;
    
    ord_selecao(vet, TAM);

    for(int i = 0; i < TAM; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;

    return 0;
}

void ord_selecao(int *v, int tam) {
    int id_menor, menor;
    for(int j = 0; j < tam-1; j++) {
        id_menor = j;
        menor = v[id_menor];
        for(int i = j+1; i < tam; i++) {
            if(v[i] < menor) {
                menor = v[i];
                id_menor = i;
            }
        }
        v[id_menor] = v[j];
        v[j] = menor;
    }

    //cout << "v[" << id_menor << "]: " << menor << endl;
}