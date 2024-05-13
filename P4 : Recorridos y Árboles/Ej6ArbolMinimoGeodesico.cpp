#include "Allgraphs.h"
#include<bits/stdc++.h> 
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)




int main(){
    
    int n,m;
    cin >> n >> m;
    graph G(n);
    fore(i,0,m){
        edge temp;
        cin >> temp.first >> temp.second;
        G.insertar(temp);
    }
    auto res = ;
    for (int vertice : res){
        cout << vertice << " ";
    }
}