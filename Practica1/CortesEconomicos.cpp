#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b; i++)
using namespace std;

 const int INDEF = -1; const int INF = 1e9;
vector<int> cortes;
vector<vector<int>> MEMO;
int solve(int i , int j){    
    if(i == j){
        return 0;
    }else{
    bool algunoCumplio = false;
    int mini = INF;
    fore(k,0,cortes.size()){
            
        if(cortes[k] > cortes[i] && cortes[k] < cortes[j]){
            algunoCumplio = true;
          
            mini = min(mini,solve(i,k) + solve(k,j));
            
        }
            
    }    
    return algunoCumplio? mini + cortes[j] - cortes[i]: 0;
    }
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
   cout << solve(0,n+1);

}