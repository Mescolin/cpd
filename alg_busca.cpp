#include <bits/stdc++.h>

using namespace std;

const int TAM = 100;

bool busca_seq(int *v, int n, int valor, int &qtde);
bool busca_seq_ord(int *v, int n, int valor);
bool busca_binaria(int *v, int n, int valor);

int main() {
    srand(time(NULL));
    int v[TAM];
    bool encontrado = false;

    for(int i = 0; i < TAM; i++) {
        v[i] = rand()%TAM + 1;
        cout << v[i] << " ";
    }
    cout << endl;
    sort(v, v+TAM);
    for(int i = 0; i < TAM; i++)
        cout << v[i] << " ";
    cout << endl;

    int valor;
    cin >> valor;

    int q;
    cout << (busca_seq(v, TAM, valor, q) ? "" : "nao ") << "encontrado\n";

    cout << "\nQuantidade: " << q << endl << endl;

    cout << (busca_binaria(v, TAM, valor) ? "" : "nao ") << "encontrado\n";

    return 0;
}

bool busca_seq(int *v, int n, int valor, int &qtde) { 
    int cont = 0;

    cont += 2;  // inicialização da estrutura de repetição    
    for(int i = 0; i < n; i++) {
        cont++;     // i < n
        cont += 2;  // v[i] == valor
        if(v[i] == valor) {
            cont++;
            qtde = cont;
            return true;
        }
        cont += 2;  // i = i + 1;
    }
    
    cont++;
    qtde = cont;
    return false;
}

bool busca_seq_ord(int *v, int n, int valor) { 
    for(int i = 0; i < n && valor >= v[i]; i++) {
        if(v[i] == valor)
            return true;
    }
    
    return false;
}

bool busca_binaria(int *v, int n, int valor) {
    int e = 0, d = n-1, m;
    while(e <= d) {
        m = (e+d)/2;
        if(v[m] == valor)
            return true;
        else if(valor < v[m])
            d = m - 1;
        else
            e = m + 1;
    }

    return false;
}       