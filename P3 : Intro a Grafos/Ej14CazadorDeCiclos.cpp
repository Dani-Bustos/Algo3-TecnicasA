#include<bits/stdc++.h> 
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)

typedef pair<int,int> edge;
struct graph {
   vector<unordered_set<int>>  representacion;
   graph(int v){
    representacion.resize(v);
   } 
   void insertar(edge vw){
    representacion[vw.first].insert(vw.second);
    representacion[vw.second].insert(vw.first);
   }
    
   unordered_set <int> vecindarioDe(int vertice){
        return representacion[vertice];
    }
};

struct digraph{
    vector<unordered_set<int>> Salida;
    digraph(int vertices){
        Salida.resize(vertices);
    }
    void insertar(edge vw){
        Salida[vw.first].insert(vw.second);
    }
    
    unordered_set <int> vecindarioDe(int vertice){
        return Salida[vertice];
    }
};
//Basicamente es un DFS, funciona en O(n +m)

vector<int> diGraphCycle(int actual,vector<bool> & marcas, digraph & G,vector<int> &camino){
    camino.push_back(actual);
    if(marcas[actual]){       
        return camino;
    }else if(G.vecindarioDe(actual).size() == 0){
        marcas[actual] = true;
        //por aca no era
        camino.pop_back();
        return {-1};
    }else{
        
        marcas[actual] = true;
        for(auto vecino : G.vecindarioDe(actual)){
           vector<int> res;
           res = diGraphCycle(vecino,marcas,G,camino);
           if(res[0] != -1){
            return res;
           }
           
        }
        //Saco este nodo, porque nadie de aca llega a hacer un ciclo
        //lo planteo asi, porque de otra manera no atajamos el caso en el que el ciclo esta solo en la raiz
        camino.pop_back();
        return {-1};
    }
}


int main(){
    int n,m;
    cin >>n >> m; 
    digraph G(n);
    fore(i,0,m){
        edge a;
        cin >> a.first >> a.second;
        G.insertar(a);
    }
    vector<bool> marcas (n,false);
    vector<int> camino;
    auto resultado = diGraphCycle(0,marcas,G,camino);
    for(auto x : resultado){
        cout << x << " ";
    }
}