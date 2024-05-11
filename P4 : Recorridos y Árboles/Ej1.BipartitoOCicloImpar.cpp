#include "Allgraphs.h"
#include<bits/stdc++.h> 
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)

vector<int> reconstruyeCiclo(stack<int> &camino){
    //Complejidad: O(n), en el peor caso todos los vertices son el ciclo
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

//Complejidad : O(n + m) es una dfs con color
//Generalizar este codigo es facil, solo hay que poner un while mas arriba que explore todas las partes conexas
vector<int> BipartitoOCicloImpar(graph &G){
    int RED = 0; int BLUE = 1; int SIN_PINTAR = -1;

    stack<int> AProcesar;
    //Lo necesito para recuperar al ciclo impar si lo hubiese
    stack<int> Visitados;
    //Las marcas me generan mi biparticion
    vector<int> marcas (G.cantVertices(),SIN_PINTAR);
    int LastColor = RED;
    int raiz = 0;
    while(raiz < G.cantVertices()){
        AProcesar.push(raiz);
        while(not AProcesar.empty()){
            int actual = AProcesar.top(); 
            AProcesar.pop();
            if(marcas[actual] != SIN_PINTAR) continue;
            
            Visitados.push(actual);  
            //Pinto de acorde a la distancia, si mi anterior era rojo yo soy azul, y viceversa
            LastColor = LastColor  == RED ? BLUE : RED;
            marcas[actual] = LastColor;
        
        
            for(auto vecino : G.vecindarioDe(actual)){
                if(marcas[vecino] == SIN_PINTAR){
                    AProcesar.push(vecino);
                //Hay un ciclo con nodos de mi mismo color
                }else if(marcas[actual] == marcas[vecino]){
               
                    Visitados.push(vecino);
                    return reconstruyeCiclo(Visitados); //Recuperar el ciclo, no es bipartito
                }   
            }
        
        }
    //Termine con esta parte conexa, vamos a la siguiente
        while( marcas[raiz] != SIN_PINTAR && raiz < G.cantVertices()) raiz++;
    }
    return marcas;
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
    auto res = BipartitoOCicloImpar(G);
    for (int vertice : res){
        cout << vertice << " ";
    }
}