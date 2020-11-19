#include <iostream>
#include <cmath>
using namespace std;
long long int limite = 500;//n

int main() {
	int contador=0;
	bool v[500]={false};
	v[0]=true;
	v[1]=true;
	for(int i=2; i<=floor(sqrt(limite)); i++){
		if(v[i] == false){
			for(int j=i*i; j<=limite; j+=i){
				v[j]=true;
			}
		}
	}

	//printando os valores
	for(int i=0; i<limite; i++){
		if(v[i] == false){
			cout << i << endl;
			contador++;
		}
	}
	cout << "Foram encontrados " << contador << " números primos" <<endl;
}
