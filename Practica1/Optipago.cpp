#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b; i++)
using namespace std;



//instnacias recursivas de backtracking : Ω(2^n)n

//instancais de la funcion : O(n*k) 
// entonces si n*k << 2^n hay superposicion de problemas, dp clasica con matriz. acceso en O(1)
vector<int> monedas;
const int INF = 1e9; const pair<int,int> INDEF = {-1,-1};
vector<int> res; int best = INF;
int bestCant = INF;
vector<vector<pair<int,int>>> MEMO;

pair<int,int> cc(int i,int k){
    if(k <= 0){
        return {abs(k),0};
    
    }else if(MEMO[i][k] != INDEF){
        return MEMO[i][k];
    
    }else if( k >= 0 && i == monedas.size()){
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
    pair<int,int> res = cc(0,k);
    cout << res.first <<" "  << res.second;
    //Enfoque bottom up (TODO)
    

}