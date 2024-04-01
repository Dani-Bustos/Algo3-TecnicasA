#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b; i++)
using namespace std;

//Complejidad espacial : O((n+2)*(n+2)) = O(n^2) 
//Temporal igual
const int INDEF = -1; const int INF = 1e9;
vector<int> cortes;
vector<vector<int>> MEMO;
int solve(int i , int j){    
    if(i == j){
        return 0;
    }else if(MEMO[i][j] != INDEF){
        return MEMO[i][j];
    }
    else{
        
        int mini = INF;
        fore(k,i+1,j){//todos los cortes posibles estan entre estos rangos, es requiere que esten ordenados los cortes     
                
                mini = min(mini,solve(i,k) + solve(k,j));
            
            
            
        }    
        mini != INF? MEMO[i][j] = mini + cortes[j] - cortes[i]: MEMO[i][j] =  0;
    }
    return MEMO[i][j];
}


int main(){
    int n; int length;
    cin >> n >> length;
    cortes.resize(n + 2); //quiero que la posicion primera y la ultima esten para poder crear una matriz para la dp

    MEMO.resize(n+2,vector<int>(n+2,INDEF));
    cortes[0] = 0;
    cortes[n + 1] = length;
    fore(i,1,n + 1){
        cin >> cortes[i];
    }
    sort(cortes.begin(),cortes.end()); //ES IMPERATIVO QUE ESTEN ORDENADOS LOS CORTES, sino hay que cambiar el funcionamiento interno del a funcion;
    //cout << solve(0,n+1);

    
   //Bottom Up
   vector<vector<int>> dp(n+2,vector<int>(n+2,INDEF));
   //para resolver una instancia de cortes de rango n, todas las instancais de cortes mas pequeñas tienen que estar ya resueltas
   //entonces,primero resolvemos todos los tamaños de corte i esimo, de manera creciente
   fore(i,0,n+2){
        fore(j,0,n+2-i){   
            int mini = INF;
            fore(k,j+1,j+i){ //todos los cortes validos estan entre mi principio y mi final(requiere orden de cortes)
             
             mini = min(mini,dp[j][k] + dp[k][j+i]);
            }
            mini != INF ? dp[j][j + i] = mini + cortes[j+i] - cortes[j] : dp[j][j+i] =0; 
        }
    }

    cout << dp[0][n+1];
}