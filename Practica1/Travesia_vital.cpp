#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b; i++)
using namespace std;
//complejidad temporal : O(C((n-1 + m-1),n-1)) C es el numero combinatorio. 
// complejidad espacial: O(n*m)
// Es reordenar los movimientos de abajo y al a derecha,con elegir uno definis los otros,
// para mas info buscar problema de cuantos caminos hay de una punta de un tablero de ajedrez a la otra

const int INF = 1e9; const int INDEF = 0;
vector<vector<int>> tablero; vector<vector<int>> memo;
int solve(int i,int j){
    int res;
    if(i == tablero.size()){
        return 1;
    }else if(memo[i][j] != INDEF){
        return memo[i][j];
    }else if(j == tablero[0].size()-1){
        res =  solve(i+1,j) - tablero[i][j]; 
        
    }else if(i == tablero.size()-1){
        res =  solve(i,j+1) - tablero[i][j];

    }else{
       res = min(solve(i+1,j),solve(i,j+1)) - tablero[i][j];
    }
    memo[i][j] = res <= 0 ? 1 : res;

    return memo[i][j];
}
int main(){
    int n,m;
    cin >> n >> m;
    //asumimos indefinido como 0
    tablero.resize(n,vector<int>(m));
    memo.resize(n,vector<int>(n,INDEF));
    fore(i,0,n){
        fore(j,0,m){
            cin >> tablero[i][j];
        }
    }
    //cout << solve(0,0);
    //DP Bottom up, memoria O(n*m);
    vector<vector<int>> dp(n,vector<int>(m,INDEF));
    for(int i = n-1; i>= 0; i--){
        for(int j = m-1; j>= 0; j--){
            int res;
            if(j == tablero[0].size()-1){
                //manejamos el caso base a mano
                res = (i != n-1 ?  dp[i+1][j] - tablero[i][j] :  1 - tablero[n-1][m-1]);
        
            }else if(i == tablero.size()-1){
                res =  dp[i][j+1] - tablero[i][j];

            }else{
                res = min(dp[i+1][j],dp[i][j+1]) - tablero[i][j];
            }
            dp[i][j] = (res <= 0 ? 1 : res);
        }
    }
    cout << dp[0][0];


}