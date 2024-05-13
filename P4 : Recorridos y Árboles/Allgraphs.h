#include<bits/stdc++.h> 
using namespace std;

//Biblioteca de funcionalidades basicas para representar Grafos y Digrafos
//AUTOR : DANIEL BUSTOS

//Lo necesito para los pesos
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};




typedef pair<int,int> edge;
struct graph {
   bool weighted;
   unordered_map<pair<int,int>,int,hash_pair> pesos;
   vector<unordered_set<int>>  representacion;
   //O(n)
   graph(int v,bool pesos = false){
    representacion.resize(v);
    weighted = pesos; 

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
