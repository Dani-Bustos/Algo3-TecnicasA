#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b; i++)
using namespace std;

vector<int> monedas;
const int INF = 1e9;
vector<int> res; int best = INF;
int bestCant = INF;

pair<int,int> cc(int k,vector<int> &monedas){
    if(monedas.size() == 0 && k > 0){
       return {INF,INF};   
    }else if(monedas.size() == 0 && k <= 0 ){
        return {abs(k),0};
    }else{
        int coin = monedas[monedas.size()-1];
        monedas.pop_back();
        pair<int,int> f1 = cc(k-coin,monedas);
        pair<int,int> f2 = cc(k,monedas);
        int cant = min(f1.first,f2.first);
            
        pair<int,int> f;
        f1.first <= f2.first ? f = f1 : f = f2;
        
            
                
    }

}


int main(){
    int n,k;
    cin >> n >> k;
    fore(i,0,n){
        int temp; cin >> temp;
        monedas.push_back(temp);
    }
    cout << cc(k,n) <<" " << best;

}