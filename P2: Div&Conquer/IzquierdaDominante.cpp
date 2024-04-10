#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)

using namespace std;
const long long INDEF = -1;
vector<int> a;
//idea, mirar si el actual es "mas izquierda", luego mirar si sus mitades lo son recursivamente
// caso base : cuando el intervalo es de rango uno, es mas izquierda
//complejidad : T(N) = Θ(n) + 2*T(n/2) -> complejidad = O(n*log(n))
 
//las cuentas aca es porque es una implementacion inplace
bool solve(int posInicial, int posFinal){
    if(posFinal == posInicial + 1){
        return true;
    }else{
        int sumR = 0; int sumL = 0; 
        // lo utilizamos para calcular inplace
        int Intervalo = (posFinal - posInicial) / 2;
        fore(j,posInicial,posInicial + Intervalo ){
            sumL += a[j];
        }
        fore(j,posInicial + Intervalo , posFinal){
            sumR += a[j];
        }
        bool res = solve(posInicial,posInicial + Intervalo) && solve(posInicial + Intervalo, posFinal);
        return sumL > sumR && res;
}
}

int main(){
    int n;
    //n debe ser potencia de 2

    cin >> n;
    a.resize(n); fore(i,0,n) cin >> a[i];
    string res =  solve(0,n)? "true" : "false";
    cout << res;
}

