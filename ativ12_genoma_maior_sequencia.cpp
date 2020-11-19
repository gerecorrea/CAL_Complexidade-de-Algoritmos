#include <iostream>
#include <algorithm> // Para uso do max()
using namespace std;

void maiorSequencia(string genoma, string feature);

void maiorSequencia(string genoma, string feature){
	int m[genoma.size()+1][feature.size()+1];
	//Obs: usando unsigned para não dar warning de comparação entre int e uint

	//1 - Preenchendo com 0 as linhas e colunas fictícias
	for(unsigned int i = 1; i < genoma.size()+1; i++){
		m[i][0] = 0;
	}
	for(unsigned int i = 0; i < feature.size()+1; i++){
		m[0][i] = 0;
	}

	//2- Usando regra para busca dos valores
	for(unsigned int i = 1; i < genoma.size()+1; i++){
		for(unsigned int j = 1; j < feature.size()+1; j++){
			if(genoma[i] == feature[j])
				m[i][j] = m[i-1][j-1] + 1;
			else
				m[i][j] = max(m[i-1][j], m[i][j-1]);
		}
	}

	//Resultado:
	cout << endl << "Maior tamanho de subsequencia: " << m[genoma.size()][feature.size()] << endl;
}

int main(){
	string genoma("ACCUGTATAUCGUCACTU"), feature("GCAUTTC");
	maiorSequencia(genoma,feature);
}
