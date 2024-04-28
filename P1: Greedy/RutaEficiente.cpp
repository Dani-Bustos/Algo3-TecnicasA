#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b; i++)
using namespace std;


//Complejidad : O(n)
int main(){
    int n;  int C; cin >> n >> C;
    vector<int> estaciones(n);
    
    cin >> estaciones[0];
    fore(i,1,n){
        cin >> estaciones[i];
        //es requiere que todos los rangos entre estaciones sean menor a C, sino es imposible
        assert(estaciones[i] - estaciones[i-1] <= C && "El auto no puede recorrer en un intervalo, mas que su nafta maxima");
    }
    int res = 0; //asumimos que el tanque viene cargado
    int tanque = C;
    vector<int> solEstaciones;
   
     //nos guardamos la autonomia, nos vamos fijando si nos pasamos o no en el rango que tenemos que recorrer ahora
    fore(i,0,n-1){
        int rango = estaciones[i+1] - estaciones[i];
        if( rango > tanque){
            res++;
            tanque = C - rango;
            solEstaciones.push_back(estaciones[i]);
        }else{
            tanque -= rango;
        }
    }
    //printeamos la solucion:
    cout << "paramos en : " <<res << " estaciones" <<"\n";
    fore(i,0,solEstaciones.size()) cout << solEstaciones[i] << " ";


}
 