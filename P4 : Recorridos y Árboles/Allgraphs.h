#include<bits/stdc++.h> 
using namespace std;

//Biblioteca de funcionalidades basicas para representar Grafos y Digrafos
//AUTOR : DANIEL BUSTOS
typedef pair<int,int> edge;
struct graph {
   vector<unordered_set<int>>  representacion;
   //O(n)
   graph(int v){
    representacion.resize(v);
   } 
   //O(1) esperado
   void insertar(edge vw){
    representacion[vw.first].insert(vw.second);
    representacion[vw.second].insert(vw.first);
   }
    //O(1) devuelve un puntero
   unordered_set <int> vecindarioDe(int vertice){
        return representacion[vertice];
    }
    //O(1)
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
    //O(d_in(v)) dado que borramos en hashmaps, podria ser mas
    void InutilizarVertice(int vertice){
        //Lo borro de todos los vecindarios
        auto Invecinos = Entrada[vertice];
        for(auto vecino : Invecinos){
            Salida[vecino].erase(vertice);
            Entrada[vertice].erase(vecino);
        }

    }
    //O(m), recorre todas las aristas
    vector<edge> DarListaDeAristas(){
        
        vector<edge> listaAristas;
        for(int i = 0;i < Salida.size();i++){
            for(auto vecino : Salida[i]){
                listaAristas.push_back({i,vecino});
            }
        }
        return listaAristas;
    }

};
