
#include<bits/stdc++.h> 
using namespace std;
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
    vector<unordered_set<int>> Entrada;
    //O(n)
    digraph(int vertices){
        Salida.resize(vertices);
        Entrada.resize(vertices);
    }
    //O(1) esperado
    void insertar(edge vw){
        Salida[vw.first].insert(vw.second);
        Entrada[vw.second].insert(vw.first);
    }
    //O(1)
    int cantVertices(){
        return Salida.size();
    }
    //O(1) devuelve un puntero
    unordered_set <int> vecindarioDe(int vertice){
        return Salida[vertice];
    }
    void InutilizarVertice(int vertice){
        //Lo borro de todos los vecindarios
        auto Invecinos = Entrada[vertice];
        for(auto vecino : Invecinos){
            Salida[vecino].erase(vertice);
            Entrada[vertice].erase(vecino);
        }

    }
};
