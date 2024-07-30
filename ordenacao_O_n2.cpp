#include <bits/stdc++.h>
#include <chrono>

#define TAM 100000

using namespace std;
using namespace std::chrono;

/* Algoritmos de ordenação => O(n^2)*/
void ord_selecao(int *v, int tam);  
void ord_bolha(int *v, int tam);    // ineficiente => O(n^2)
void ord_insercao(int *V, int tam); // ineficiente => O(n^2)

int main() {
    srand(time(NULL));
    int vet[TAM];
    for(int i = 0; i < TAM; i++) {
        vet[i] = rand()%100 + 1;
    }
    
    auto ini = high_resolution_clock::now();
    ord_selecao(vet, TAM);
    auto fim = high_resolution_clock::now();

    duration<double> intervalo = fim - ini;

    cout << duration_cast<milliseconds>(intervalo).count() << "ms" << endl;
    cout << duration_cast<microseconds>(intervalo).count() << "us" << endl;
    cout << duration_cast<nanoseconds>(intervalo).count() << "ns" << endl;


    /*for(int i = 0; i < TAM; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;*/

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
}