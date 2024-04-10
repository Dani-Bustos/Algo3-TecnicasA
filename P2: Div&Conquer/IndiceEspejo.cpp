#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)

using namespace std;
const long long INDEF = -1;
vector<int> a;
//idea, explotar que el array es estrictamente creciente, mirar siempre a la mitad del arreglo actual y decidir
//si hay que bajar o subir, ya que si ya se paso en el i-esimo se va a pasar para todos lo que siguien
//analogamente si ya es muy chico en el i-esimo, es tambien muy chico en los previos

//complejidad : T(n) = Θ(1) + T(n/2); -> complejidad : O(log(n)) 

int solve(int posInicial, int posFinal){
        if(posInicial +1 == posFinal){
            return a[posInicial] == posInicial + 1 ?  posInicial + 1 :  -1;    
        }
        else{
        // lo utilizamos para calcular inplace
        int Intervalo = (posFinal - posInicial) / 2;
        //el numero q buscamos en esta posicion mediana
        int target = posInicial + Intervalo + 1;
        if(a[posInicial + Intervalo] == target){
            return target;
        }else if(a[posInicial + Intervalo] < target){
            // si el i-esimo numero es mas chico, hay que subir
            return solve(posInicial + Intervalo,posFinal);
        }else{
            // si el i-esimo numero es mas grande, hay que bajar
             return solve(posInicial,posInicial + Intervalo);
        }
        }
        
}


int main(){
    int n;
    //Debe ser dado estrictamente crecientemente
    cin >> n;
    a.resize(n); fore(i,0,n) cin >> a[i];
    //retorna -1  si no existe la posicion buscada
    cout << solve(0,n);
}

