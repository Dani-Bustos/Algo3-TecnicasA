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

    int cantVertices(){
        return representacion.size();
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
vector<int> DFS(int actual,vector<bool> & marcas, graph & G,vector<int> &camino);

vector<int> Ciclos(graph &G){
    vector<bool> marcas (G.cantVertices(),false);
    vector<int> camino;
    vector<int> res; res.push_back(-1);
    int i = 0;
    //Asi exploramos todas las partes conexas
    while(i < G.cantVertices() && res[0] == -1 ){
        res = DFS(i,marcas,G,camino);
        while(i< G.cantVertices() || marcas[i] == false){
            i++;
        }
        camino.clear(); // O(1), es un solo elemento si falla

    }
    return res;
}

vector<int> DFS(int actual,vector<bool> & marcas, graph & G,vector<int> &camino){
    camino.push_back(actual);
    if(marcas[actual]){       
        return camino;
    }else if(marcas[actual]){
        //por aca no era        
        camino.pop_back();
        return {-1};
    }else{
        marcas[actual] = true;
        for(auto vecino : G.vecindarioDe(actual)){
           vector<int> res;
           //Como este no es mas digrafo, hay que considerar que un ciclo no es una ida y vuelta
          if( camino.size() < 1|| camino[camino.size()-2] != vecino){
            
            res = DFS(vecino,marcas,G,camino);
            if(res[0] != -1){
                return res;
            }
          }
        }
        camino.pop_back();
        return {-1};    
    }
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
    auto res = Ciclos(G);
    for(auto x : res){
        cout << x << " ";
    }
    
}