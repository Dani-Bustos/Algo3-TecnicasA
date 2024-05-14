#include "Allgraphs.h"
#include<bits/stdc++.h> 
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)
const int SIN_DEFINIR = -1;
struct verticeFrontera{
    int vertice;
    int frontera;
    verticeFrontera(int valor = SIN_DEFINIR , int nivel = -1){
        vertice = valor;
        frontera = nivel;
    }
};

void BFS( weighted_graph & G){
    //vertice , nivel de frontera, padre
    queue<pair<verticeFrontera,int>> aProcesar;
    
    //vertice padre, nivel de frontera, peso de la arista
    vector<pair<verticeFrontera,int>> bfsTree (G.cantVertices());

    verticeFrontera raiz(0,0); aProcesar.push({raiz,-1});
    while(not aProcesar.empty()){
        int v, lvl, p;
        v = aProcesar.front().first.vertice; lvl = aProcesar.front().first.frontera; 
        p = aProcesar.front().second;
        aProcesar.pop();
        if( bfsTree[v].first.vertice == SIN_DEFINIR){

        }


        
    }
}



int main(){
    
    int n,m;
    cin >> n >> m;
    weighted_graph G(n);
    fore(i,0,m){
        edge temp; int peso;
        cin >> temp.first >> temp.second >> peso;
        G.insertar(temp,peso);
    }
    
    
}