#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b; i++)
using namespace std;

//Usamos una matriz para la memoizacion. 
//la matriz es de (n +1) * (n+1) porque necesitamos tener en cuenta el caso inicial, en el que siempre es valido "elegir" un edificio

int n;  const int INDEF = -1;
vector<int> alturas; vector<int> anchos;
vector<vector<int>> memo;

int longestInc(int i, int posMasAlto ){
    if(i == n ){
        return 0;
    }else if(memo[i + 1][posMasAlto + 1] != INDEF){
        return memo[i + 1][posMasAlto +1] ;
    }
    else if( posMasAlto  == INDEF || alturas[i] > alturas[posMasAlto]){
        memo[i + 1][posMasAlto+ 1] = max(longestInc(i+1,posMasAlto),longestInc(i+1,i) + anchos[i]);
    }else{
        memo[i + 1][posMasAlto + 1] = longestInc(i+1,posMasAlto);
    }
    return memo[i + 1][posMasAlto + 1];
}
int longestDec(int i, int posMasChico){
    if(i == n){
        return 0;
    }
    else if(memo[i + 1][posMasChico + 1] != INDEF){
        return memo[i + 1][posMasChico + 1];
    
    }else if( posMasChico == INDEF || alturas[posMasChico] > alturas[i]){
    
        memo[i + 1][posMasChico + 1] = max(longestDec(i + 1,posMasChico),longestDec(i + 1,i) + anchos[i]);

    }else{
        memo[i + 1][posMasChico + 1] =longestDec(i+1,posMasChico);
    }
    return memo[i + 1][posMasChico + 1];
    
}



int main(){
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); //Cosas de c++ para leer y printear mas rapido

   int t;
   cin >> t;
   fore(caso,1,t+1){
        cin >> n;
        memo.clear();
        memo.resize(n + 1,vector<int>(n+1,INDEF));
        alturas.resize(n); anchos.resize(n);
        
        fore(i,0,n ){
            cin >> alturas[i];
        }
         
        fore(i,0 ,n ){
            cin >> anchos[i];  
        }
     
        int creciente =longestInc(0,INDEF);
        memo.clear();
        memo.resize(n+1,vector<int>(n+1,INDEF));
        //limpiamos la memoizacion ya que la reusaremos
        int decreciente= longestDec(0,INDEF);
        
        if(creciente >= decreciente){
            cout << "Case " << caso << ". Increasing (" << creciente <<"). Decreasing (" << decreciente << ")." << "\n"; 
        }else{
            cout << "Case " << caso << ". Decreasing (" << decreciente <<"). Increasing (" << creciente << ")." << "\n"; 
        }
        
   }
}