#include "Allgraphs.h"
#include<bits/stdc++.h> 
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)
const int INF = 1e8;

typedef struct leaf {
    int padre;
    int nivel;
    int MinimoNivelBackEdge;
    
    leaf(int p = -1,int lvl = -1,int Bck = INF){
        padre = p; nivel = lvl; MinimoNivelBackEdge = Bck;
    }
} leaf;

vector<edge> AristasPuente(graph & G){
    
    stack<pair<int,int>> AProcesar;
    vector<bool> visitados (G.cantVertices(),false);
    //El primer elemento apunta al padre, el 2do nos dice el nivel , el 3ero nos dice nuestra backedge minima
    vector<leaf> DFSTree(G.cantVertices());
    
    leaf raiz(0,0,INF);
    DFSTree[0] = raiz;
    //Hacemos dfs,
    AProcesar.push({0,0});
    while(not AProcesar.empty()){
        pair<int,int> actual = AProcesar.top(); AProcesar.pop();

        if (visitados[actual.first]) continue;
        
        visitados[actual.first] = true;
        
        for(int vecino : G.vecindarioDe(actual.first)){
            if(not visitados[vecino]){
                //Por el funcionamiento de dfs, si esta hoja tiene un padre mas profundo, entonces la va
                //A encontrar mas tarde y va a sobreescribi esta asignacion
                AProcesar.push({vecino,actual.second + 1});
                leaf nuevaHoja(actual.first,actual.second + 1,INF);
                DFSTree[vecino] = nuevaHoja;
            
            }else if(DFSTree[actual.first].padre != vecino){
                //encontramos un ciclo, iteramos por este actualizando la backedge minima
                //tenemos que comparar contra la minima previa, a que capaz que nuestra nueva backedge tiene altura mayor
                for(int x = actual.first; x != vecino ; x = DFSTree[x].padre){
                    DFSTree[x].MinimoNivelBackEdge = min(DFSTree[vecino].nivel,DFSTree[x].MinimoNivelBackEdge);
                } 
            }
        }
    }
    
    //Ahora recorremos el arbol y buscamos uno que no sea cubierto por backedges;
    vector<edge> res;
    for(int i = 0; i < DFSTree.size();i++){
        leaf x = DFSTree[i];
        if(x.MinimoNivelBackEdge == INF && x.nivel != 0){
            res.push_back({i,x.padre});
        }
    }
    return res;
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
    //G debe ser conexo
    auto res = AristasPuente(G);
    for (edge vertice : res){
        cout << vertice.first << "," << vertice.second << " ";
    }
}