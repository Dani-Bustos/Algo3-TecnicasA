#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b; i++)
using namespace std;

//Llamados recursivos sin podas: Ω(2^n)
//instancais de funcion : O(n**2);
vector<int> asteroides; vector<vector<int>> MEMO;
const int NegINF = -1e9; const int INDEF = -1;

int AstroTrade(int i,int amount){
    //Si no puedo  vender todos los asteorides que tengo con el tiempo que me queda, ya no es una sol optima
    if (amount < 0 || amount > asteroides.size() - i ){
        return NegINF;
    }else if(MEMO[i][amount] != INDEF){
        return MEMO[i][amount];
    }else if( i == asteroides.size()){
        MEMO[i][amount] = 0;
    }
    else{
        MEMO[i][amount] = max(AstroTrade(i+1,amount+ 1) - asteroides[i], max(AstroTrade(i+1,amount),AstroTrade(i+1,amount -1) + asteroides[i]));
    
    }

    return MEMO[i][amount];
}


int main(){
    int n;
    cin >> n;
    asteroides.resize(n);
    MEMO.resize(n + 1,vector<int>(n + 1,INDEF));
    fore(i,0,n){
        cin >> asteroides[i];
    }
    cout << AstroTrade(0,0);
    //algoritmo bottom up(TODO)
    
}