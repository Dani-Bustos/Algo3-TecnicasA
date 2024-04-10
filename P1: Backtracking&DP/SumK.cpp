#include <bits/stdc++.h>
using namespace std;

#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fore(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;


const int MaxN = 1e8;
int a[MaxN];
void solve(int k, int pos, vector<int> &solParcial,vector<vector<int>> &soluciones,int n){
    if(pos == n){
        if(k == 0){
            soluciones.push_back(solParcial);

        }else{
            return;
        }

    }else if(k == 0){
        soluciones.push_back(solParcial);
        return;
    }else{
        if(k > 0){
            solParcial.push_back(a[pos]);
            solve(k - a[pos],pos + 1,solParcial,soluciones,n);
            solParcial.pop_back();
            solve(k,pos + 1,solParcial,soluciones,n);
        }else{
            return;
            
        }
    }
}

 

int main(){
 FIN
 int n,k;
 cin >> n >> k;

 vector<int> sol;
 
 fore(i,0,n){
    cin >> a[i];
 }
 vector<vector<int>> res;  
 solve(k,0,sol,res ,n);
 for(auto x : res){
    for(auto i : x){
        cout << i << " ";
    }
    cout << "\n";
 }
 
  
}