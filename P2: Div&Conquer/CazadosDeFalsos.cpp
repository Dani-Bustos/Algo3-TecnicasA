#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;
typedef long long ll;

const int INDEF = -1;
vector<vector<bool>> mat;

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
        if(conjuncionSubmatriz()) 
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


