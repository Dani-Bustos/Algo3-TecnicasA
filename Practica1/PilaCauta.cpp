#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a;i<b;i++)
using namespace std;

const int INDEF = -1; const int NEGINF = -1e9; const int INF = 1e9;
vector<int> pesos; vector<int> soportes; vector<vector<int>> memo;
int solve(int i,int tol){
  if(tol < 0){
    return NEGINF ;
  }else if(i == pesos.size()){
    return 0;
  }else if( memo[i][tol] != INDEF){
    return memo[i][tol];
  }else{
    //solo nos interesa el menor de los soportes, ya que ese nos condiciona todo lo demas
    int nuevo_soporte = (tol- pesos[i] > soportes[i] ? soportes[i] : tol-pesos[i]); 
    memo[i][tol] = max(solve(i+1,nuevo_soporte) + 1,solve(i+1,tol));
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
  memo.resize(n,vector<int>(maxSoporte,INDEF));
  cout << solve(0,INF); //nunca nada va a ser mas grande que eso
     
}