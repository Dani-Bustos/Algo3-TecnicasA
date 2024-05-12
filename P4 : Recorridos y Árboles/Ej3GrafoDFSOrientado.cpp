#include "Allgraphs.h"
#include<bits/stdc++.h> 
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)

int padre(pair<int,int> & p){return p.first;}
int valor(pair<int,int> &p){return p.second;}

//O(n + m) DFS
digraph OrientacionConexa(graph & G){
    stack<pair<int,int>> AProcesar; vector<int> marcas (G.cantVertices(),false);
    vector<int> DFSTree;
    digraph Orientacion(G.cantVertices());
    
    pair<int,int> raiz = {0,0}; AProcesar.push(raiz);
    
    while(not AProcesar.empty()){
        pair<int,int> actual = AProcesar.top(); AProcesar.pop();
        //Si ya me lo encontre, aca hay una backedge. Lo agrego al grafo orientado segun lo especificado
        if(marcas[valor(actual)]){
            Orientacion.insertar({valor(actual),padre(actual)});
            continue;
        } 
        
        marcas[valor(actual)] = true;
        
        if(valor(actual) != padre(actual)) Orientacion.insertar({padre(actual),valor(actual)});

        for(int vecino : G.vecindarioDe(valor(actual))){
            if(not marcas[vecino]){
                AProcesar.push({valor(actual),vecino});
            }
        }


    }
    return Orientacion;
}

int main(){
    
    int n,m;
    cin >> n >> m;
    graph G(n);
    fore(i,0,m){
        edge temp;
       cin >> temp.first >> temp.second;
        G.insertar(temp);
    }
    //G debe ser conexo y debe admitir una orientacion conexa
    auto res = OrientacionConexa(G);
    for(auto x : res.DarListaDeAristas()){
        cout << x.first << " " << x.second << "\n";
    }
}