#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b; i++)
using namespace std;



//instancias recursivas de backtracking : Ω(2^n)

//instancias de la funcion : O(n*k) 
// entonces si n*k << 2^n hay superposicion de problemas, dp clasica con matriz. acceso en O(1)
vector<int> monedas;
const int INF = 1e9; const pair<int,int> INDEF = {INF,INF};
vector<int> res; int best = INF;
int bestCant = INF;
vector<vector<pair<int,int>>> MEMO;

pair<int,int> cc(int i,int k){
    if(k <= 0){
        return {abs(k),0};
    
    }else if(MEMO[i][k] != INDEF){
        return MEMO[i][k];
    
    }else if( k > 0 && i == monedas.size()){
        MEMO[i][k] = {INF,INF};
    
    }else{
       
       pair<int,int> poner = cc(i+1,k - monedas[i]);
       pair<int,int> noPoner = cc(i+1,k);
       poner.second += 1;
       MEMO[i][k] =  min(noPoner,poner);
    }
    return MEMO[i][k];
}


int main(){
    int n,k;
    cin >> n >> k;
    MEMO.resize(n + 1,vector<pair<int,int>>(k + 1,INDEF));
    fore(i,0,n){
        int temp; cin >> temp;
        monedas.push_back(temp);
    }
    /*pair<int,int> res = cc(0,k);
    cout << res.first <<" "  << res.second;*/
    
    //Enfoque bottom up sin optimizacion de memoria
    /*
    
    MEMO.clear(); MEMO.resize(n+1,vector<pair<int,int>>(k+1,INDEF));
    //casos base
    fore(i,0,k+1){
        i == 0? MEMO[n][i] = {0,0} : MEMO[n][i] = {INF,INF};
    }
    
    for(int i = n - 1; i >= 0 ;i--){
        
        for(int j = k;j >= 0;j--){
             
             pair<int,int> poner;
             
             j - monedas[i] >= 0 ?  poner = MEMO[i+1][j - monedas[i]] : poner =  {abs(j-monedas[i]),0};
            
             pair<int,int> noPoner = MEMO[i+1][j];
             poner.second +=1;
             MEMO[i][j] = min(poner,noPoner);
        }
    }
    cout << MEMO[0][k].first << " " << MEMO[0][k].second;
    */
    //Enfoque bottom up memoria 2*k
    vector<pair<int,int>> prev(k+1,INDEF);
    vector<pair<int,int>> act(k+1,INDEF);
    prev[0] = {0,0}; 
    for(int i = n-1; i >= 0;i--){
        for(int j = k;j>= 0;j--){
            pair<int,int> poner;
            j - monedas[i] >= 0 ?  poner = prev[j - monedas[i]] : poner =  {abs(j-monedas[i]),0};
             pair<int,int> noPoner = prev[j];
             poner.second +=1;
             act[j] = min(poner,noPoner);
        }
        prev = act;
    }
    cout << act[k].first << " " << act[k].second;
}
