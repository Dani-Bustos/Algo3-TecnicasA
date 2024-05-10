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
bool DFS(int actual,vector<bool> & marcas, digraph & G, stack<int> &camino,vector<int> & descomp);
vector<int> reconstruyeCiclo(stack<int> &camino){
    vector<int> ciclo;
    int cabeza = camino.top();
    ciclo.push_back(cabeza);
    camino.pop();
    while(camino.top() != cabeza){
            ciclo.push_back(camino.top());
            camino.pop();
    } 
    ciclo.push_back(cabeza);
    return ciclo;
    
}
pair<vector<int>,bool> Ciclos(digraph &G){
    vector<bool> marcas (G.cantVertices(),false);
    stack<int> camino;vector<int> descomp;
    pair<vector<int>,bool> res; 
    int i = 0;
    //Asi exploramos todas las partes conexas
    while(i < G.cantVertices() && res.second == false ){
        bool act = DFS(i,marcas,G,camino,descomp);
        if(act){
            return {reconstruyeCiclo(camino),true};
        }
       // Si el ciclo no esta ,vamos a la siguiente parte conexa
        while(i< G.cantVertices() && marcas[i] == true){
            i++;
        }
        
        while(!camino.empty()){
            camino.pop();
        }// O(1), es un solo elemento 

    }
    return {descomp,false};
}

//Esta funcion nos dice si hay o no un ciclo,a la vez que nos genera la descomposicion / o el camino potencial

bool DFS(int actual,vector<bool> & marcas, digraph & G,stack<int> &camino,vector<int> &descomp){
    camino.push(actual);
    if(marcas[actual] == true){
        
        return true;
    }
    marcas[actual] = true;
    if(G.vecindarioDe(actual).size() == 0){
        camino.pop();
        G.InutilizarVertice(actual);
        descomp.push_back(actual);
        return false;
    
    }else {
        bool res;
        auto vecindario = G.vecindarioDe(actual);
        for(auto vecino : vecindario){
            res = DFS(vecino,marcas, G,camino,descomp);
            if(res) return true;
            
            
        }
        //Si borramos a todos nuestros hijos, tenemos que sacarnos a nosotros
        if(G.vecindarioDe(actual).size() == 0){
            camino.pop();
            G.InutilizarVertice(actual);
            descomp.push_back(actual);
        }
        
        return false;
    }
}

int main(){
    
    int n,m;
    cin >> n >> m;
    digraph G(n);
    fore(i,0,m){
        edge temp;
        cin >> temp.first >> temp.second;
        G.insertar(temp);
    }
    auto res = Ciclos(G);
    string ans = res.second? "true hay ciclo" : "false, no hay ciclo";
    cout << ans << "\n";
    for(auto x : res.first){
        cout << x << " ";
    }
    return 0;
}