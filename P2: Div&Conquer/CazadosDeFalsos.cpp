#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;
typedef long long ll;

const int INDEF = -1;
vector<vector<bool>> mat;
//recurrencia dada por T(N) = T(N/4) + Θ(1) -> (teo. maestro) Θ(log(n))
//Idea: partir la matriz en 4, fijarse en "O(1)" con la funcion conjunciones SUbmatriz para que cuarto hay un false
//explorar recursivamente en esa direccion
bool conjuncionSubmatriz(int i0,int i1,int j0,int j1){
    bool res = true;
    for(int i = i0 ; i < (i0 == i1 ?  i0 + 1: i1); i++){
        for(int j = j0; j <(j0 == j1 ?  j0 + 1:  j1) ;j++){
            res = res && mat[i][j];
            if(res == false) return res;
        }
    }
    return res;
}

pair<int,int> solve(int i0,int i1,int j0,int j1){
    //estamos en una matriz de 1x1, la 2da condicion hace falta por casos borde
    if((i0 + 1 == i1 && j0 + 1 == j1) || (i0 == i1 && j0 == j1)){
        //si la matriz es de 1x1, quiero ver que el falso este
        if (mat[i0][j0] == false) return {i0,j0}; 
        else return {-1,-1};

    }else{
        int ideltaMitad =  (i1-i0)/2;
        int jdeltaMitad = (j1-j0)/2;
        int iHalf = i0 + ideltaMitad;
        int jHalf = j0 + jdeltaMitad;
        //Arriba a la izquierda
        if(not conjuncionSubmatriz(i0,iHalf,j0,jHalf)){
           return solve(i0,i0+ideltaMitad,j0,jHalf);
        
        }//Abajo a la izquierda
        else if(not conjuncionSubmatriz(iHalf,i1,j0,jHalf)){
            return solve(i0 + ideltaMitad,i1,j0,jHalf);
        
        }//Arriba derecha
        else if( not conjuncionSubmatriz(i0,iHalf,jHalf,j1)){
            return solve(i0,iHalf,jHalf,j1);
        
        }//Abajo derecha
        else if( not conjuncionSubmatriz(iHalf,i1,jHalf,j1)){
            return solve(iHalf,i1,jHalf,j1);
            
        }
        //no habia falsos
        return {-1,-1};
            
    }
}

int main(){
    
    int n; cin >> n;
    
    mat.resize(n,vector<bool>(n,false));
    fore(i,0,n) {
        fore(j,0,n){ 
            int temp;
            cin >> temp;
            mat[i][j] = temp;        
            }

    }
   pair<int,int> res = solve(0,n,0,n);
   cout << res.first << " " << res.second;
}


