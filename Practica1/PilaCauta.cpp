#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a;i<b;i++)
using namespace std;

const int INDEF = -1; const int NEGINF = -1e9; const int INF = 1e9;
vector<int> pesos; vector<int> soportes; vector<vector<int>> memo;
int solve(int i,int tol){
  if(tol < 0){
    return NEGINF;
  }else if ( i == memo.size()){
    return 0;
  }else if(memo[i][tol] != INDEF){
    return memo[i][tol];
  }else{
    int n_tol;
    if(tol == memo[0].size() - 1 ){
      n_tol = soportes[i];
     }else{
      n_tol = (tol - pesos[i] > soportes[i] ? soportes[i] :tol - pesos[i]);
     }
    memo[i][tol] = max(solve(i+1,tol),solve(i+1,n_tol) + 1);
    return memo[i][tol];
  }

  
}
int main(){
  int n; 
  cin >> n;
  pesos.resize(n); soportes.resize(n);
  int maxSoporte = 0;
  fore(i,0,n){
    cin >> pesos[i];
    
  }   
  fore(i,0,n){
    cin >> soportes[i];
    maxSoporte = max(maxSoporte,soportes[i]);
  }
  //Top down
  //complejidad espacial : O(maxSoporte*n)
  memo.resize(n,vector<int>(maxSoporte + 2,INDEF)); // queremos espacio para el soporte Maximo +1 y 0
  //cout << solve(0,maxSoporte + 1); 
  
  //bottom up , con optimizacion de memoria
  //complejidad temporal : O(maxSoporte*n);
  //complejidad epacial : O(maxSoporte*2) = O(maxSoporte)    
  
  vector<int> dp(maxSoporte+2);
  vector<int> prev(maxSoporte +2);
  for(int i = n -1;i >= 0;i--){
    fore(actTol,0,maxSoporte+2){
      int n_tol;
      if(actTol == memo[0].size() - 1 ){
        n_tol = soportes[i];
      }else{
        n_tol = (actTol - pesos[i] > soportes[i] ? soportes[i] :actTol - pesos[i]); 
      }     
      if(n_tol >= 0){
        dp[actTol] = max(prev[actTol],prev[n_tol] + 1);
      }else{
        dp[actTol] = prev[actTol];
      }
    } 
    prev = dp;
  }
  
  cout << dp[maxSoporte + 1];
 
}