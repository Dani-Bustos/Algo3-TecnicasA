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
   int vertices(){
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
    int cantVertices(){
        return Salida.size();
    }
};

vector<int> DFS(int actual,vector<bool> & marcas, digraph & G,stack<int> &camino);
vector<int> diGraphCycle(digraph & G);

vector<int> diGraphCycle(digraph & G){
    vector<bool> marcas (G.cantVertices(),false);
    stack<int> camino;
    auto res = DFS(0,marcas,G,camino);
    return res;
}

vector<int> reconstruyeCiclo(stack<int> &camino){
    vector<int> ciclo;
    ciclo.push_back(camino.top());
    int cabeza = camino.top();
    camino.pop();
    while(camino.top() != cabeza){
            ciclo.push_back(camino.top());
            camino.pop();
    } 
    ciclo.push_back(cabeza);
    return ciclo;
    
}

vector<int> DFS(int actual,vector<bool> & marcas, digraph & G,stack<int> &camino){
    //Es requiere que el grado de todos sea mayor a 0
    camino.push(actual);
    if(marcas[actual]){       
        //Para recuperar el camino sin adicional, popeo hasta encontrar el princpio del ciclo
        return reconstruyeCiclo(camino);
    }else{
        
        marcas[actual] = true;
        //siempre grado mayor a 0 debe habe un ciclo
        auto vecindario = G.vecindarioDe(actual);
        auto vecino = *vecindario.begin();
        return DFS(vecino,marcas,G,camino);

           
        
        
    }
}


int main(){
    int n,m;
    cin >>n >> m; 
    digraph G(n);
    //Es requiere que todos tengan grado mayor  a 0
    fore(i,0,m){
        edge a;
        cin >> a.first >> a.second;
        G.insertar(a);
    }
   
    auto resultado = diGraphCycle(G);
    
    for(auto x : resultado){
        cout << x << " ";
    }
}