//Obs: Até 0 ele fica infinitamente até dar erro. Com 0,1 ou mais parece mais válido o teste.
#include <iostream>
using namespace std;

float medidasRecursivas(float alturaMax, float salto, float posicaoMarca) {
    cout << "Salto/altura atual: " << salto << "\t\tposição da marca: " << posicaoMarca << endl;
    if (salto/2>0.1) {
        if (salto != alturaMax) {
            medidasRecursivas(alturaMax, salto/2, posicaoMarca+salto/2);
        }
        medidasRecursivas(alturaMax, salto/2, posicaoMarca-salto/2);
    }
}

int main(){
  medidasRecursivas(30, 30, 15);
  return 0;
}
