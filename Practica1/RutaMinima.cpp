#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a;i<b;i++)

//Complejidad Temporal : O(n!*n) 
//generamos todos los posibles ordenes de la imagen, y los checkeamos con la formula de suma en tiempo n
//Complejidad Espacial : O(n**2 + n) = O(n**2) : Guardamos el tablero y las soluciones de tamaño n,
bool solValida(vector<vector<int>> &tablero, vector<int> solution){
    int res = 0;
    res += tablero[solution[tablero.size()-1]][solution[0]];
    fore(i,0,tablero.size()-1){
        res += tablero[solution[i]][solution[i+1]];
    }
    return res;


}

int best = 1e9;
void solve(vector<int> &solParcial,queue<int> &numsPosibles, vector<int> &res, vector<vector<int>> &T){
    if(numsPosibles.size() == 0){
        int sum = solValida(T,solParcial);
        if(sum < best ){
            res = solParcial;
            best = sum;
        }
        return;
    }else{
        int first = numsPosibles.front(); 
        do {
           int act = numsPosibles.front();
            numsPosibles.pop();
            solParcial.push_back(act);
            solve(solParcial,numsPosibles,res,T);
            solParcial.pop_back();
            numsPosibles.push(act);
            
        }while(not numsPosibles.empty() && numsPosibles.front() != first);
    }
}

int main(){
    int n;
    cin >> n;
    
    queue<int> nums;
    fore(i,0,n){
        nums.push(i);
    }
    vector<vector<int>> tablero(n);
    vector<int> res;; 
   fore(i,0,n){
        vector<int> fila(n);
        fore(j,0,n){
           
            cin >> fila[j];        
        }
        tablero[i] = fila;    
   } 
    vector<int> parcial;
    solve(parcial,nums,res,tablero);
    fore(i,0,n){
        cout << res[i] + 1 << " ";
    }

}