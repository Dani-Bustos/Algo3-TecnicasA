#include <bits/stdc++.h>
using namespace std;

//#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fore(i,a,b) for(int i=a;i<b;i++)

bool criterio( pair<pair<int,int>,string> a,  pair<pair<int,int>,string> b){
    if(a.first.first > b.first.first){
        return true;
    }else if(a.first.first < b.first.first){
        return false;
    }else{
        if(a.first.second < b.first.second){
            return true;
        }else if(a.first.second > b.first.second){
            return false;
        }else{
            return a.second < b.second;
        }
    }
}
bool critAlfabetico(pair<pair<int,int>,string> a,  pair<pair<int,int>,string> b){
   return a.second < b.second;
}

int main(){
 
 int t;
 cin >> t;
 
 fore(k,1,t+1){
    pair<pair<int,int>,string> jugadores[10];
    fore(i,0,10){
        cin >> jugadores[i].second >> jugadores[i].first.first >> jugadores[i].first.second;
    }
    
    sort(jugadores,jugadores + 10,criterio); //O(1) acotado a 10
    //por default el sort de c++ en pairs ordena por el primer elemento ,
    //y despues por el segundo. Dado que el primer elemento es una tupla,ordena de nuevo prioritarimanete por el primero y luego el segundo
    string atacantes[5]; 
    fore(i,0,5){
        atacantes[i] = jugadores[i].second;
    }

    string defensores[5];
    fore(i,5,10){
        defensores[i- 5] = jugadores[i].second;
    }
    //Ordeno las elecciones optimas por orden alfabetico
    sort(defensores,defensores + 5);
    sort(atacantes,atacantes + 5);
    cout << "Case " << k << ":" << endl; 
    cout << "(";
    fore(i,0,5){
        cout << atacantes[i] << (i != 4 ? ", " : ")"); // temas de formateo de comas y parentesis
    }
    cout << endl << "(";
    
    fore(i,0,5){
        cout << defensores[i] << (i != 4 ? ", " : ")");
    }
    cout << endl;
 }
    return 0;
  
}