#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

using namespace  std;

int main(){
    int matrizA[3][3] = {{1,2,1},{2,1,2},{1,1,1}};
    int matrizB[3][3] = {{1,2,1},{2,1,2},{1,1,1}};
    int matrizC[3][3] = {{0,0,0},{0,0,0},{0,0,0}}, i, j, k;
    clock_t Ticks[2];
    double Tempo;
    Ticks[0] = clock();
    for (i=0;i<3; i++) {
      for (j=0; j<3; j++) {
        for (k=0; k<3; k++) {
          matrizC[i][j] = matrizC[i][j] + (matrizA[i][k] * matrizB[k][j]);
        }
      }
    }
    Ticks[1] = clock();
    Tempo = (Ticks[1] - Ticks[0]) * 1000000.0/CLOCKS_PER_SEC;
    cout << "Matriz Resultante" << endl;
    for (i=0; i<3; i++) {
      for (j=0; j<3; j++) {
        cout << matrizC[i][j] << " ";
      }
      cout << endl;
    }
    printf ("\nTempo de execucao: %.6lf microssegundos\n\n",Tempo);

}
