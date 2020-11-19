#include <stdio.h>
#include <stdlib.h>

int fib( int n ){

    if( n == 0 || n == 1 )
        return 1;
    return fib( n-1 ) + fib( n-2 );
}

int main(){
    int resposta;
    clock_t Ticks[2];
    double Tempo;
    Ticks[0] = clock();
    resposta = fib();
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) * 1000000.0/CLOCKS_PER_SEC;
    printf ("Tempo de execução: %.6lf microssegundos\n\n",Tempo);
}
