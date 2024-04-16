#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;
typedef long long ll;

const int INDEF = -1;
vector<vector<bool>> mat;
//recurrencia dada por T(N) = T(N/4) + Θ(1) 
bool conjuncionSubmatriz(int i0,int i1,int j0,int j1){
    bool res = true;
    fore(i,i0,i1){
        fore(j,j0,j1){
            res = res && mat[i][j];
            if(res == false) return res;
        }
    }
    return res;
}

pair<int,int> solve(int i0,int i1,int j0,int j1){
    if(i0 + 1 == i1 && j0 + 1 == j1){
        return mat[i0][j0] == true ? {i0,j0} : {-1,-1};

    } else{
        int ideltaMitad =  (i1-i0)/2;
        int jdeltaMitad = (j1-j0)/2;
        if(conjuncionSubmatriz(i0,i0 + ideltaMitad),j0,j0 + jdeltaMitad){
           return solve(i0,i0+ideltaMitad,j0,j0 + jdeltaMitad);
        }else if(conjuncionSubmatriz(i0 + ideltaMitad,i1,j0,j0 + jdeltaMitad){
            return solve(i0 + ideltaMitad,i1,j0,j0 + jdeltaMitad);
        }else if(conjuncionSubmatriz(i0,i0 + ideltaMitad,j0 + jdeltaMitad,j1){
            return solve(i0,i0 + ideltaMitad,j0 + jdeltaMitad,j1);
        }else if( conjuncionSubmatriz(i0 + ideltaMitad,i1,j0 + jdeltaMitad,j1){
            return solve(i0 + ideltaMitad,i1,j0 + jdeltaMitad,j1);
            
        }
            
    }
}

int main(){
    
    int n; cin >> n;
    
    mat.resize(n,vector<bool>(n,false));
    fore(i,0,n) {
        fore(j,0,n){ 
            int temp;
            cin >> temp;
            mat[i][j] = temp;        
            }

    }
    
}


