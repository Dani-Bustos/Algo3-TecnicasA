#include<bits/stdc++.h> 
using namespace std;

//Biblioteca de funcionalidades basicas para representar Grafos y Digrafos
//AUTOR : DANIEL BUSTOS

//Lo necesito para los pesos, implementa hasheo de pares
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
         
        
          return hash1;
    }
};


typedef pair<int,int> edge;

struct graph {
   
   vector<unordered_set<int>>  representacion;
   
   //O(n)
   graph(int v=1){
    representacion.resize(v);
   

   } 
   //O(1) esperado
   void insertar(edge vw){
    representacion[vw.first].insert(vw.second);
    representacion[vw.second].insert(vw.first);
   }
    //O(1) devuelve un puntero
   unordered_set <int> vecindarioDe (int vertice) const{
        return representacion[vertice];
    }
    //O(1)
    int cantVertices()const {
        return representacion.size();
    }
    void borrarEdge(edge vw){
        representacion[vw.first].erase(vw.second);
        representacion[vw.second].erase(vw.first);
    }
   
   

};
//heredo de grafo, ya que tienen muchas funciones repetidas
struct weighted_graph : public graph{
   graph Gsubyacente; 
   unordered_map<edge,int,hash_pair> pesos; 
  
   weighted_graph(int n = 1) : Gsubyacente(n){}
    
   
   void insertar(edge vw,int peso = 1){
    Gsubyacente.insertar(vw);
    pesos[vw] = peso;

   }
   
   void borrarEdge(edge vw){
        Gsubyacente.borrarEdge(vw);
        pesos.erase(vw);
   }
   
   int pesoDe(edge vw) const{
     if (vw.first == vw.second){
        return 0;
     }
     else if(pesos.find(vw) != pesos.end()){
        return pesos.at(vw);
     }else{
        //Capaz que lo guarde al reves, no lo se en princpio
        return pesos.at({vw.second,vw.first});
     }
   }   
    void insertar(edge vw) {
        Gsubyacente.insertar(vw);
    }

    unordered_set<int> vecindarioDe(int vertice) const {
        return Gsubyacente.vecindarioDe(vertice);
    }

    int cantVertices() const {
        return Gsubyacente.cantVertices();
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
    //O(d_in(v)) dado que borramos en hashmaps, podria ser mas, remueve el vertice dado de todos los vecindarios
    void InutilizarVertice(int vertice){
        //Lo borro de todos los vecindarios
        auto In_vecinos = Entrada[vertice];
        for(auto vecino : In_vecinos){
            Salida[vecino].erase(vertice);
            Entrada[vertice].erase(vecino);
        }

    }
    //O(m), recorre todas las aristas
    vector<edge>  DarListaDeAristas(){
        
        vector<edge> listaAristas;
        //Pongo este tipo de dato para evitar warnings del compilador
        for(long unsigned int  i = 0;i < Salida.size();i++){
            for(auto vecino : Salida[i]){
                listaAristas.push_back({i,vecino});
            }
        }
        return listaAristas;
    }

};
