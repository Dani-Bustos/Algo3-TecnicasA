#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)
typedef long long ll;
using namespace std;
const long long INDEF = -1;

//Complejidad : 4n = O(n)
//Idea, la permutacion optima resuelve dos conflictos en la palabra en lugar de de uno, hacemos esto con todas las permutaciones del mismo "tipo" de conflicto
//si al final nos queda solo un conflicto de cada tipo, necesitamos realizar un movimiento adicional para resolverlo

int main(){
    int n; cin >> n;
    vector<char> s(n),t(n);
    vector<pair<int,int>> moves;
    
    int cantA = 0; int cantB = 0;
    fore(i,0,n){
        cin >> s[i] ; 
        s[i] == 'b' ? cantB++: cantA++;
        }
    fore(i,0,n) {
        cin >> t[i];  
        t[i] == 'b' ? cantB++: cantA++;
    }
    // NO hay manera de dividirlos en pares e impares si alguna cantidad de a's o b's es impar
    if( cantA % 2 == 1 || cantB % 2 == 1){
        cout << "-1";
    }else{
        vector<int> BenS; 
        vector<int> AenS;
        int act =0;
        while(act < n){
            if(s[act] != t[act]){
                if(s[act] == 'b' && t[act] == 'a'){
                  BenS.push_back(act);
                }else{
                  AenS.push_back(act);
                }
            }
            act++;
           
        }
        while(AenS.size() > 1){
            //cambiamos con la siguiente ocurrencia del conflicto s: b, t : a, ya que en un swap arreglas dos posiciones
            
            //esta es la posicion de la 'a' en S
            int posS = AenS.back(); AenS.pop_back();
            //esta es la posicion de la  'b' que esta en T, 
            int posT = AenS.back(); AenS.pop_back();
            
            moves.push_back({posS,posT});
            swap(s[posS],t[posT]); 

        }
        while(BenS.size() > 1){
           //al reves que antes
           //cambiamos con la siguiente ocurrencia del conflicto s: a, t : b, ya que en un swap arreglas dos posiciones
           int posS = BenS.back(); BenS.pop_back();
           int posT = BenS.back(); BenS.pop_back();
           moves.push_back({posS,posT});
           swap(s[posS],t[posT]);

        }
        while(BenS.size() > 0 && AenS.size() > 0){
            //el caso en el que no hay repeticiones de conflictos es unico, necesitamos hacer 2 cambios
            int posS = BenS.back(); BenS.pop_back();
            int posT = AenS.back(); AenS.back();

            moves.push_back({posS,posS});
            swap(s[posS],t[posS]);
            moves.push_back({posS,posT});
            swap(s[posS],t[posT]);

        }
        cout << moves.size() << "\n";
        fore(i,0,moves.size()){
            cout << moves[i].first + 1 << " " << moves[i].second + 1 <<"\n";
        }
       
    }

}

