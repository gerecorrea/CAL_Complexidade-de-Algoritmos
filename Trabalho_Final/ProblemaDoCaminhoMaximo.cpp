
#include <iostream>
#include <limits.h>
#include <clocale>
#include <list>
#include <stack>
#define INFINITO INT_MIN
using namespace std;


/* Algoritmo de calculo de caminho mais longo.
Implementado pela dupla Beatriz e Geremias
*/

class Adjacentes {
    int v;
    int peso;
public:
    Adjacentes(int v1, int w1){
        v = v1;
        peso = w1;}
    int getVertices() {
		return v;
	}
	int getPeso() {
		return peso;}
};

class Grafo {
    int V; // Número de vértices
    list<Adjacentes>* adj;
    void DFSOrdenacaoTopologica(int v, 
    bool visited[], stack<int>& pilha);
public:
    Grafo(int V);
    void addAresta(int u, int v, int peso);
    void maiorCaminho(int s);
};
Grafo::Grafo(int V){
    this->V = V;
    adj = new list<Adjacentes>[V];
}
void Grafo::addAresta(int u, int v, int peso){
    Adjacentes node(v, peso);
    adj[u].push_back(node);
}

//Busca em profundidade por cada vértice e empilhando para futuro processamento
void Grafo::DFSOrdenacaoTopologica(int v, bool visited[], stack<int>& pilha){
  visited[v] = true; // marca o nó atual
  list<Adjacentes>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i) {
      Adjacentes node = *i;
      if (!visited[node.getVertices()])
          DFSOrdenacaoTopologica(node.getVertices(), visited, pilha);
  }
  pilha.push(v);
}

void Grafo::maiorCaminho(int s){
  stack<int> pilha;
  int distancias[V];
	int pai[V];
	int maiorvalor, maior;

	//TOdos os vértices inicialmente não visitados
  bool* visited = new bool[V];
  for (int i = 0; i < V; i++)
      visited[i] = false;

  //Inicio a ordenação topológica do meu grafo recebido
  for (int i = 0; i < V; i++)
      if (visited[i] == false)
          DFSOrdenacaoTopologica(i, visited, pilha);

	//Inicializa as distancias como infinito
	for (int i = 0; i < V; i++){
      distancias[i] = INFINITO;
		  pai[i]= INFINITO;
	}
  distancias[s] = 0; //O vértice origem tem d = 0

  // Processa os vértices na ordem de empilhamento
  while (pilha.empty() == false) {
      int u = pilha.top();
      pilha.pop();

      // Atualiza as distâncias para todos os vértices
      list<Adjacentes>::iterator i;
      if (distancias[u] != INFINITO) {
          for (i = adj[u].begin(); i != adj[u].end(); ++i){
              if (distancias[i->getVertices()] < distancias[u] + i->getPeso()){
                  distancias[i->getVertices()] = distancias[u] + i->getPeso();
				          pai[i->getVertices()] = u;
			        }
          }
      }
  }

	//RESULTADOS

  for (int i = 0; i < V; i++){
		if(i==0){
			maiorvalor = distancias[i];
			maior = i;
		}
		else if (distancias[i] > maiorvalor)
			   maiorvalor = distancias[i];
			   maior = i;
	}

  cout << "Caminho do maior caminho de forma mais visual, sendo seu vertice pai sempre a direita: " << endl;
	cout << maior << " <--- ";
	int j=maior, auxx;

	while(pai[j]!=0){
		cout << pai[j] << " <--- ";
		auxx = pai[j];
		pai[j] = pai[auxx];
	}
	cout << pai[j] << endl;

	cout << endl << endl << "Maior caminho: " << maiorvalor << endl;
}

int main(){
  Grafo g(10);
	//(origem, destino, peso);
	/*
	  g.addAresta(0, 1, 2);
    g.addAresta(0, 2, 1);
    g.addAresta(1, 3, 3);
    g.addAresta(1, 2, 2);
    g.addAresta(2, 3, 3);
    g.addAresta(2, 4, 1);
    g.addAresta(0, 4, 5);
    g.addAresta(3, 4, 1);
    g.addAresta(3, 5, 5);
    g.addAresta(4, 5, 2);
	*/

     g.addAresta(0,1,11);
     g.addAresta(0,2,10);
     g.addAresta(1,3,2);
     g.addAresta(1,4,2);
     g.addAresta(2,3,5);
     g.addAresta(2,4,1);
     g.addAresta(3,5,20);
     g.addAresta(4,6,3);
     g.addAresta(4,7,4);
     g.addAresta(5,6,5);
     g.addAresta(5,7,30);
     g.addAresta(6,8,2);
     g.addAresta(7,8,5);
     g.addAresta(8,9,30);
     //g.addAresta(8,5,5);// Aqui crio um ciclo, entra em loop
     //g.addAresta(9,8,5);//Aqui crio um bidirecional, entra em loop



    int s = 0;
	  cout << "Algoritmo para cálculo do maior caminho." << endl << endl;
    
    g.maiorCaminho(s);

    return 0;
}
