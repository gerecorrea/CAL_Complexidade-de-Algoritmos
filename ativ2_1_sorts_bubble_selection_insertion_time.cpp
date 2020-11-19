#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

using namespace  std;
void bubble(int v[], int n);
void selection(int v[], int n);
void insertion(int v[], int n);

int main(){
    int v[100000], n = 100000, valor, v2[100000];

    for(int i=0;i<n;i++){
      valor = rand()%100000;
      v[i] = valor;
    }

    for(int i=0;i<n;i++){
        v2[i] = i;
    }
    
    printf("\n\nVetor com valores aleatórios.\n\n");
    bubble(v,n);
    selection(v,n);
    insertion(v,n);
    printf("\n\nVetor com valores na ordem crescente.\n\n");
    bubble(v2,n);
    selection(v2,n);
    insertion(v2,n);

    return 0;
}// Pior caso Tempo: comparações O(n)

void bubble(int v[], int n){
    int aux;
    clock_t Ticks[2];
    double Tempo;
    Ticks[0] = clock();
    for (int i = n - 1; i > 0; i--){
        for (int j = 0; j < i; j++){// O(n(n − 1)
            if (v[j] > v[j+1]){ // comparações
                aux = v[j]; // trocas
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) * 1000000.0/CLOCKS_PER_SEC;
    printf ("Tempo de ordenacao no Bubble sort: %.6lf microssegundos\n\n",Tempo);
}

void selection(int v[], int n){
    int x, aux;
    clock_t Ticks[2];
    double Tempo;
    Ticks[0] = clock();
    for (int i = 0; i < n; i++){ // O(n)
        x = i; // O(1)
        for (int j = i+1; j < n; j++){// O(n) * O(n / 2)
            if( v[j] < v[x] ) // Comparação
                x = j; // O(1)
        }
        aux = v[i]; // troca
        v[i] = v[x];
        v[x] = aux;
    }
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) * 1000000.0/CLOCKS_PER_SEC;
    printf ("Tempo de ordenacao no Selection: %.6lf microssegundos\n\n",Tempo);
}

void insertion(int v[], int n){
    clock_t Ticks[2];
    double Tempo;
    int x, j;
    Ticks[0] = clock();
    for (int i = 1; i < n; i++){
        x = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > x){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
    }
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) * 1000000.0/CLOCKS_PER_SEC;
    printf ("Tempo de ordenacao no Insertion: %.6lf microssegundos\n\n",Tempo);
}
