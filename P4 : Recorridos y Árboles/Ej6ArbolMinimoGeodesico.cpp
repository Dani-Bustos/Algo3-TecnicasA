#include "Allgraphs.h"
#include<bits/stdc++.h> 
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)


const int SIN_DEFINIR = -1;
struct ver_lvl_padre{
    int vertice;
    int frontera;
    int padre;
    ver_lvl_padre(int valor = SIN_DEFINIR , int nivel = -1,int p = -1){
        vertice = valor;
        frontera = nivel;
        padre = p;
    }
    //para poder asignar mas facil
    friend void tie(ver_lvl_padre& vlp, int& vertice, int& frontera, int& padre) {
        vertice = vlp.vertice;
        frontera = vlp.frontera;
        padre = vlp.padre;
    }
};


vector<ver_lvl_padre> BFS( const weighted_graph & G, int raiz){
    //vertice , nivel de frontera, padre
    queue<ver_lvl_padre> aProcesar;
    aProcesar.push(ver_lvl_padre(raiz,0,raiz));
    //vertice padre, nivel de frontera, el peso lo consulto con el indice y el padre nomas
    vector<ver_lvl_padre> bfsTree (G.cantVertices());

    
    while(not aProcesar.empty()){
        ver_lvl_padre actual = aProcesar.front(); aProcesar.pop();
        int v,lvl,padre;
        tie(actual,v,lvl,padre);
        
        if( bfsTree[v].vertice == SIN_DEFINIR){
            
            bfsTree[v] = ver_lvl_padre(v,lvl,padre) ;
             
            for(auto vecino : G.vecindarioDe(v)){
               aProcesar.push(ver_lvl_padre(vecino,lvl +1,v)); 
            } 
        //Si lo que queremos cambiar es alcanzable por nosotros de manera que se respete la "geodesia" de la raiz
        //Es decir , si por tomar este camino de menor peso, seguimos siendo el camino de menor longitud en vertices
        }else if(bfsTree[v].frontera - 1 == bfsTree[padre].frontera){
            //Si el peso este es mejor que el anterior, lo cambio
            if ( G.pesoDe({v,bfsTree[v].padre}) > G.pesoDe({v,padre}))  bfsTree[v] = ver_lvl_padre(v,lvl,padre);
           
        }


        
    }
    return bfsTree;
}



int main(){
    
    int n,m,raiz;
    cin >> n >> m >> raiz;
    weighted_graph G(n);
    fore(i,0,m){
        edge temp; int peso;
        cin >> temp.first >> temp.second >> peso;
        G.insertar(temp,peso);
    }
    auto res = BFS(G,raiz);
    for(ver_lvl_padre x : res){
        cout << x.vertice << " padre " << x.padre << " peso" <<  G.pesoDe({x.vertice,x.padre}) << "\n";
    }   
       
}