//Alunos: Beatriz e Geremias
 #include <stdio.h>
 #include <stdlib.h>

 #define tamBalde 10
 #define qtdBaldes 10

 typedef struct {
     int topo;
     int balde[tamBalde];
 }bucket;

 //Heap Sort para ordenação
 void heap(int vet[], int tam){
   int i = tam/2;
   int pai, filho, t;
   while(1){
       if(i>0){
           i--;
           t = vet[i];
       }
       else{
           tam--;
           if(tam==0)
               break;
           t = vet[tam];
           vet[tam] = vet[0];
       }
       pai = i;
       filho = i * 2 + 1;
       while(filho<tam){
           if((filho+1<tam) && (vet[filho+1]>vet[filho]))
               filho++;
           if(vet[filho]>t){
               vet[pai] = vet[filho];
               pai = filho;
               filho = pai * 2 + 1;
           }
           else
               break;
       }
       vet[pai] = t;
   }
 }

 //Algoritmo do Bucket Sort
 void bucket_sort(int v[],int tam){
     bucket b[qtdBaldes];
     int i,j,k;
     for(i=0;i<qtdBaldes;i++){
         b[i].topo=0;
     }
    //Verificação do balde de cada elemento. Principal trecho do código e de complexida O(n)
    for(i=0;i<tam;i++){
        j=qtdBaldes-1;
         while(1){
             if(j<0)
                 break;
             if(v[i]>=tamBalde*j){
                 b[j].balde[b[j].topo]=v[i];
                 (b[j].topo)++;
                 break;
             }
             j--;
         }
     }

    //Chama o heap para ordenação
    for(i=0;i<qtdBaldes;i++){
        int l;
        if(b[i].topo){
            heap(b[i].balde,b[i].topo);
        }
        printf ("Balde %d: ",i);
        for(l=0;l<b[i].topo;l++){
            printf ("%d ", b[i].balde[l]);
        }
        printf ("\n\n");
    }
    i=0;
    //Os vetores do balde voltam ao vetor, agora ordenados.
    for(j=0;j<qtdBaldes;j++){
        for(k=0;k<b[j].topo;k++){
            v[i]=b[j].balde[k];
            i++;
        }
    }
 }


 //MAIN
 void main(){
     int v[8] = {29,25,3,49,9,37,21,43};
     int i;
     bucket_sort(v,8);
     printf ("Vetor ordenado: ");
     for(i=0;i<8;i++){
         printf ("%d ", v[i]);
     }
     printf ("\n");
     return 0;
 }
