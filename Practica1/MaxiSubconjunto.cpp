#include <bits/stdc++.h>
using namespace std;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fore(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;


//Complejidad espacial : O(n² + k )
//Complejidad de tiempo SIN LA PODA , GENERANDO EL ARBOL COMPLETO esta implementacion poda
// O(2^n + C(n,k) *n**2 / 2) 
// Obs: solo las maneras validas de agarrar tres elementos son checkeadas cuadraticamente, /2 por la simetria


const int NINF = -1e9;
int n; int k;
int subsetSum(vector<int> &sol, vector<vector<int>> &T ){
    int res = 0;
    fore(i,0,sol.size()){
        int firstCoord = sol[i];
        fore(j,i,sol.size()){
            int secondCoord = sol[j];
            res += T[firstCoord][secondCoord]; //Usamos la simetria, reduce la complejidad de subsetSum a θ(n**2 / 2)
            i != j ? res +=T[secondCoord][firstCoord] : res+=0; //evitamos el caso de que son lo mismo

        }
    }
    return res;
}
int best = -1;
void solve(vector<int> solParcial, int i,vector<vector<int>> &T, vector<int> &res){
    if(solParcial.size() + (n - (i)) < k ){ //Si tus cantidad actual + la cantidad de elementos erstantes que podrias o no poner, no llegan a sumar k, ni te gastes
        return;
    }else if(solParcial.size() == k){
        int SumAct = subsetSum(solParcial,T);
        if( SumAct > best){
            res = solParcial;
            best = SumAct;
        }else{
            return;
        }
    }else{
        solParcial.push_back(i);
        solve(solParcial,i+1,T,res);
        solParcial.pop_back();
        solve(solParcial,i+1,T,res);
        
    }
}
int gauss(int n){

    return (n*(n+1)/2);
}
vector<vector<int>> creaMatriz(int n){
    vector<vector<int>> res(n);
    
    fore(i,0,n){
        vector<int> fil(n);
        fore(j,0,n){
            fil.push_back(0);
        }
        res[i] = fil;
    }
    return res;
}
int main(){
    cin >> n >> k;
    vector<vector<int>> Matriz = creaMatriz(n);
    
    
    
    int i = 0;
    //Hay n + n -1 + n -2 ... = (n*(n+1)) / 2 elementos distintos ya que es simetrica
    while(i < n){
        
        int j = 0 + i; //exploto la simetria
        vector<int> fil(n);
        Matriz[i] = fil;
        while(j < n){
           cin >>  Matriz[i][j];
           Matriz[j][i] = Matriz[i][j];
           j++;
        }
        
        i++;
    }   
    vector<int> res;
    vector<int> nums;
    solve(nums,0,Matriz,res);
    for( auto x : res){
        //ajusto el 0 inicial
        cout << x + 1  << " "; 
    }
    
}