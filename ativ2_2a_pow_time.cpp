#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

using namespace  std;

int main(){
    int a = 9, b = 15;
    double resultado = 1;
    clock_t Ticks[2];
    double Tempo;
    Ticks[0] = clock();
    for(int i=0; i<b;i++){
        resultado = resultado * a;
    }
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) * 1000000.0/CLOCKS_PER_SEC;
    printf("Resultado = %lf\n", resultado);
    printf ("Tempo de execucao: %.6lf microssegundos\n\n",Tempo);
}
