#include<bits/stdc++.h>
using namespace std;
#define fore(i,a,b) for(int i=a;i<b;i++)

int res = 0; int magicNumber = -1;
bool solValida(vector<vector<int>> &tablero){
    int prevSum = -1; 
    for(int i = 0; i < tablero[0].size(); i++){
        
        int colSum = 0;
        for(int j = 0; j < tablero[0].size();j++){
            colSum += tablero[i][j];
        }   
        if( prevSum == -1 || prevSum == colSum){
            prevSum = colSum;
        }else{
            return false;
        }
    }
    
    for(int i = 0; i < tablero[0].size(); i++){
        
        int filSum = 0;
        for(int j = 0; j < tablero[0].size();j++){
            filSum += tablero[j][i];
        }   
        if(prevSum != filSum){
            
            return false;
        }
    }
    
    
        int diagSum = 0;
        for(int i = 0; i<tablero[0].size(); i++){
            int j= i;
            diagSum += tablero[i][j];
        }
        if(diagSum != prevSum){
            return false;
        }
        diagSum = 0;
        int i = 0;
        for(int j = tablero[0].size()-1; j>= 0; j--){
            
            diagSum += tablero[i][j];
            i++;
        }
        if(diagSum != prevSum){
            return false;
        }
    return true;
}

pair<int,int> sig(pair<int,int> a,int n){
    if(a.second == n - 1 ){
        return {a.first + 1,0};
    }else{
        return {a.first,a.second + 1};
    }
}

void solve(vector<vector<int>> &T,pair<int,int> coord ,vector<int>  &numPos ){
    if(coord.first == T[0].size()){
        if(solValida(T)){
           /* fore(i,0,T.size()){
                fore(j,0,T.size()){
                    cout << T[i][j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";*/
            res += 1;
            return;
        }else{
            res += 0;
            return;
        }
    }else{
        int act = 0;
        fore(j,0, coord.second){ 
            act += T[coord.first][j];}
            
        if(act > magicNumber){
            return;
        }

        act = 0;
        fore(i,0,coord.first){ 
            act += T[i][coord.second];}           
        if(act > magicNumber){
            return;
        }
        
        for(int i = 0; i < numPos.size();i++){
            
            if (numPos[i] != -1  ) { T[coord.first][coord.second] = numPos[i] ;numPos[i] = -1 ; 
               
             

                solve(T,sig(coord,T[0].size()),  numPos);
                numPos[i] = i + 1;
                T[coord.first][coord.second] = 0;            
            }
        }
        
    }
}

int main(){
    int n;
    cin >> n;
    magicNumber = (pow(n,3) + n) / 2;
    vector<int> nums;
    vector<vector<int>> tablero(n); 
    for(int i =0; i< n;i++){
        vector<int> fila(n);
        tablero[i] = fila;

    }
    
    for(int i = 1; i <= pow(n,2); i++){
        nums.push_back(i);
    }

    solve(tablero,{0,0},nums);
    cout <<res;
    

}