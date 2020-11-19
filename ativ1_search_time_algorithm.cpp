#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
  int tamanhovetor, valor,i=-1, *vetor,m,qntd=0, flag=1, flagIgual=0;
  clock_t Ticks[2];
  double Tempo;
  FILE *arq;
    arq = fopen("atividade-1-a.txt","r");
    //arq = fopen("atividade-1-b.txt","r");
    if(arq){
        while(!feof(arq)){
            fscanf(arq,"%d",&valor);
            if(flag == 1){
              flag=0;
              vetor = (int *) malloc (sizeof(int) * valor);
              tamanhovetor = valor;
				    }
            else{
              i++;
              vetor[i] = valor;
            }
        }
		}else{
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }
    fclose(arq);
    //sort(vetor, vetor+tamanhovetor);
    cout << "Digite o numero a ser buscado: ";
    cin >> m;
    Tempo=0;
    Ticks[0] = clock();
    for(i=0; i<tamanhovetor; i++){
      if (vetor[i] == m){
        qntd++;
      }
      //else if(vetor[i]>m){
      //  break;
      //}
    }
    Ticks[1] = clock();
    Tempo = Tempo + ((Ticks[1] - Ticks[0]) * 1000000.0 / CLOCKS_PER_SEC);
    cout << endl <<"Quantidade de vezes no vetor: " << qntd << endl;
    cout << "Tempo gasto na busca: " << Tempo/10 << " microssegundos" << endl;
    free(vetor);
}
