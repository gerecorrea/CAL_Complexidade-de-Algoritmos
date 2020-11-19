#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef unsigned int uint128_t __attribute__((mode(TI)));

bool millerrabin(int n, int s);
bool witness (int a, int n,int k, int m);

int main(){
//o k máximo é a quantidade de vez que eu consegui dividir n-1 por 2
// o m é o maior ímpar encontrado, ou seja, não divide mais por 2

//s são testes para o teste, sendo um pequeno, um médio e um grande
// Ou seja, cada valor testado será testado 3 vezes.

    int primos[20] = {1009, 1013, 1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 
    1069, 1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123};
    int naoprimos[20] = {1007,1011,1015,1025,1027,1035,1043,1045,1053,1055,1057,1067,
    1071,1073,1075,1079,1083,1085,1099,1233};
    int s[3] = {3,7,13};

    cout << endl << "QUE SABEMOS QUE SÃO PRIMOS " << endl << endl;
    for(int i=0; i<20; i++){
        for(int j=0; j<3; j++){
                cout << primos[i] << " com s=" << s[j] <<" é primo? " << millerrabin(primos[i],s[j]) << endl;
        }
        cout << endl;
    }
    
    cout << endl << "QUE SABEMOS QUE NÃO SÃO PRIMOS: " << endl << endl;
    for(int i=0; i<20; i++){
        for(int j=0; j<3; j++){
                cout << naoprimos[i] << " com s=" << s[j] <<" é primo? " << millerrabin(naoprimos[i],s[j]) << endl;
        }
        cout << endl;
    }
    
}

bool millerrabin(int n, int s){
    int aux = n-1, k=0,a;
    //(2^k) * m = n - 1
    while(aux%2==0){
        aux/=2;
        k++;
    }
    int m = aux;
    for(int j=1; j<=s; j++){
        a = rand()%(n-1) + 2; //2<=a<=n-2
        if(!witness(a,n,k,m))
            return false;
    }
    return true;
}

bool witness (int a, int n, int k, int m){
    uint128_t b = (uint128_t) pow (a,m);
    //unsigned long long int b = pow(a,m);
    b = (uint128_t)b%n;
    if (b == 1 || b == n-1)
        return true;
    for(int j=1; j<k; j++){
        if(b == -1 || b == n-1)
            return true;
        else{
            b =  (uint128_t)pow(b,2);
            b =  (uint128_t)b%n;
        }
    }
    return false;
}
