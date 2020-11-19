#include <bits/stdc++.h>

using namespace std;
#define N 3

int contador = 0;

struct Node{
    Node* p;
    int mat[N][N];
    int x, y;
    int custo;
    int nivel;
};

// Função para alocar um novo nó
Node* novoNo(int mat[N][N], int x, int y, int novoX, int novoY, int nivel, Node* p){
    Node* node = new Node;
    node->p = p;
    memcpy(node->mat, mat, sizeof node->mat);
    swap(node->mat[x][y], node->mat[novoX][novoY]);
    node->custo = INT_MAX;
    node->nivel = nivel;
    node->x = novoX;
    node->y = novoY;

    return node;
}

// baixo, esquerda, cima, direita
int linha[] = { 1, 0, -1, 0 };
int coluna[] = { 0, -1, 0, 1 };

int calcularCusto(int inicial[N][N], int final[N][N]){
    int count = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (inicial[i][j] && inicial[i][j] != final[i][j])
           count++;
    return count;
}

int validarCoordenadas(int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < N);
}

void iteracao(Node* raiz){
    if (raiz == NULL)
        return;
    iteracao(raiz->p);
    contador++;
}

//Comparação para ordenação
struct comp{
    bool operator()(const Node* esquerda, const Node* direita) const{
        return (esquerda->custo + esquerda->nivel) > (direita->custo + direita->nivel);
    }
};

void bfs(int inicial[N][N], int x, int y, int final[N][N]){
    //Criando uma fila de prioridade para armazenar os nós
    priority_queue<Node*, std::vector<Node*>, comp> pq;

    //Criando um nó raiz e calculando seu custo
    Node* raiz = novoNo(inicial, x, y, x, y, 0, NULL);
    raiz->custo = calcularCusto(inicial, final);

    //Adicionando raiz na lista de nós
    pq.push(raiz);

    while (!pq.empty()){
        //Encontrar o nó com menor custo
        Node* min = pq.top();

        //O nó encontrado é removido da lista de nós ativos.
        pq.pop();

        //Se for o nó resposta, contamos as iterações
        if (min->custo == 0){
            iteracao(min);
            return;
        }

        //Percorremos os filhos do nó min, o máximo de filhos é 4
        for (int i = 0; i < 4; i++){
            if (validarCoordenadas(min->x + linha[i], min->y + coluna[i])){
                //Criando um nó filho e calculando seu custo
                Node* filho = novoNo(min->mat, min->x,
                              min->y, min->x + linha[i],
                              min->y + coluna[i],
                              min->nivel + 1, min);
                filho->custo = calcularCusto(filho->mat, final);

                //Adicionar o filho na lista de nós ativos
                pq.push(filho);
            }
        }
    }
}

int main(){
    int inicial[N][N] =
    {
        {1, 0, 3},
        {4, 2, 5},
        {7, 8, 6}
    };

    int final[N][N] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 0}
    };

    //x e y são as coordenadas do espaço em branco
    int x = 1, y = 2;

    bfs(inicial, x, y, final);

    printf("Números de jogadas = %d\n\n", contador);

    return 0;
}
