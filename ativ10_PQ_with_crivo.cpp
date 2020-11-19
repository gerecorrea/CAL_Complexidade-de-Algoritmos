#include <iostream>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;
long long int limite = 500000;

list <int> crivo;
bool v[500000]={false};
void fazCrivo();
void addList();
int achaPQ(int n);

//MAIN
int main() {
    int n = 412224749; //resultado de 19073 * 21613, ambos primos.
    fazCrivo();
    addList();
    achaPQ(n);
}

void fazCrivo(){
	v[0]=true;
	v[1]=true;
	for(int i=2; i<=floor(sqrt(limite)); i++)
		if(v[i] == false)
			for(int j=i*i; j<=limite; j+=i)
				v[j]=true;
}

void addList(){
    for(int i = 2; i<limite; i++)
        if(v[i] == false){
            crivo.push_back(i);
        }
}

int achaPQ(int n){
    for(list<int>::iterator p = crivo.begin(); p!=crivo.end(); ++p){
        for(list<int>::iterator q = p; q!=crivo.end(); ++q){
            if((*p) * (*q) == n && *p != *q){
                cout << "Valores encontrados para a chave n = " << n << ". p = " << *p << " e q = " << *q << endl;
                return 1;
            }
        }
    }
    cout << "Não foi possível encontrar os valores para a chave n = 391." << endl;
    return 0;
}