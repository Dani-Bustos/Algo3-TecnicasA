#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i = a; i< b; i++)

vector<int> Espacio;
vector<vector<int>> MEMO;
int INV =  -1;
bool solve(int,int);

int main(){
    int n,k;
    
    cin >> n >> k;
    
   
    fore(i,0,n){
        int temp;
        cin >> temp;
        Espacio.push_back(temp);
    }
    //Botom up memoria n*k
    /*
    MEMO.resize( n + 1, vector<int>(n+1,INV));
    
   
   
   
    fore(j,0,k+1){
        MEMO[0][j] = (j == 0);
    }
    fore(i,1,n+1){
        fore(j,0,k+1){
            MEMO[i][j] = MEMO[i-1][j] || (j - Espacio[i-1] >= 0 && MEMO[i-1][j-Espacio[i-1]]);
        }
    }
    
   
    
    cout << MEMO[n][k];
    */
    //Bottom up memoria k
    //Solo necesitamos acordarnos del "piso previo" de la matriz, ya que la recursion solo depende de una variable
    vector<bool> act(k+1,false);
    vector<bool> prev(k+1,false);
    prev[0] = true;
    fore(i,0, n){
       fore(j,1,k+1){
        act[j] = prev[j] || (j - Espacio[i] >= 0 && prev[j-Espacio[i]]);
       }
        prev = act;
    }
    cout << act[k];
}

bool solve(int i,int k){
    //TOP DOWN
    if(k < 0) return false;
    if (i == -1) return k == 0;
    if(MEMO[i][k] != INV) return MEMO[i][k];
    MEMO[i][k] = solve(i - 1,k) || solve(i-1,k-Espacio[i]);
    return MEMO[i][k]; 
       
    
}

