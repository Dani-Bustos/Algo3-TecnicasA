#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b; i++)
using namespace std;
//complejidad temporal(sin dp) : O(C((n-1 + m-1),n-1)) C es el numero combinatorio. 
//complejidad temporal(con dp) : O(n*m);
// complejidad espacial(sin optimizacion): O(n*m)
// complejidad espacial(con optimizacion): O(min(n,m))
// Es reordenar los movimientos de abajo y a la derecha,con elegir uno definis los otros,
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
    /*
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
    */
    
    
    //DP bottom up memoria O(min(n,m)) 
    // observemos, que como vamos de atras para adelante, solo necesitamos comparar entre dos instancias ya procesadas, uno hacia la derecha o uno hacia abajo.
    // hacia la derecha se puede representar como la posicion actual(ya fue procesada antes), y la derecha como uno hacia adelante(tambien procesada, ya que vamos de atras para adelante)
    // este mismo proceso inverso se puede realizar cuando tenemos menos filas que columnas    
    int memMax = min(n,m);
    vector<int> dpOPT(min(n,m),INDEF);
    if( memMax == m){
    for(int i = n-1 ; i>= 0;i--){
        for(int j = memMax-1; j>= 0;j--){
            int res;
            if(j == tablero[0].size()-1){
                res =  i!= n-1 ?dpOPT[j] - tablero[i][j] : 1-tablero[i][j]; 
        
            }else if(i == tablero.size()-1){
                res =  dpOPT[j+1] - tablero[i][j];

            }else{
                res = min(dpOPT[j],dpOPT[j+1]) - tablero[i][j];
            }
            dpOPT[j] = res <= 0 ? 1 : res;
        
        }
    }
    }else{ 
        for(int j = m-1; j>=0; j--){
            for(int i = memMax-1; i>=0;i--){
                int res;
                if(i == tablero.size()-1){
                    res = (j != m -1? dpOPT[i] - tablero[i][j]:1-tablero[i][j] );
                }else if(j == tablero[0].size()-1){
                    res = dpOPT[i+1] - tablero[i][j];
                }else{
                    res = min(dpOPT[i+1],dpOPT[i]) - tablero[i][j];
                }
                dpOPT[i] = (res <= 0 ? 1 : res);
            }
        }
    }
    cout << dpOPT[0];
}
