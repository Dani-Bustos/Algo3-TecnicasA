#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a;i<b;i++)
using namespace std;

const int INDEF = -1; 
vector<vector<int>> Arboles;  vector<vector<int>> MEMO;
//para cada salto que hagamos en cada altura, hay solo un arbol que tiene el maximo, lo guardamos
int maxXAltura[2002]; //acotado por consigna, + 2 porque quiero que exista la altura h y la 0


int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); //Cosas de c++ para leer y printear mas rapido
  int c; cin>> c;
  fore(dataSet,0,c){
    int t,h,f;    
    cin >> t >> h >> f;
    //limpiamos las mejoers alturas de los casos anteriores
    fore(i,0,h+2) maxXAltura[i] = 0;
    
    Arboles.clear();
    //Queremos que exista la altura 0, por eso el h +1
    Arboles.resize(t,vector<int>(h + 1 ,0));
    fore(i,0,t){
        int cantAcorns;
        cin >> cantAcorns;
        fore(j,0,cantAcorns){
            int posAcorns; cin >>  posAcorns;
            Arboles[i][posAcorns]+=1;
        }
    }
    //vamos a construir una solucion bottom up. Tomamos en cuenta el caso base de estar en altura 0
    MEMO.clear(); MEMO.resize(h+1,vector<int>(t,INDEF));
    
    fore(height,0,h+1){
        fore(actTree,0,t){
            if(height == 0){
                MEMO[0][actTree] = 0;
                maxXAltura[height] = 0;
            }else{
                MEMO[height][actTree] = Arboles[actTree][height];
                if(height -f >=0){
                    //comparamos saltar al "mejor" con solo bajar 1
                    MEMO[height][actTree] += max(MEMO[height-1][actTree],maxXAltura[height-f]);
                }else{
                    // no pudimos saltar asi que bajamos solo uno
                    MEMO[height][actTree] += MEMO[height-1][actTree];
                }
                //actualizamos el mejor puntaje de la altura actual
                maxXAltura[height] = max(maxXAltura[height],MEMO[height][actTree]);
            }
        }
    }
    
    cout << maxXAltura[h] << "\n";
 }
}