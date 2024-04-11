#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)
typedef long long ll;
using namespace std;
const long long INDEF = -1;

vector<vector<int>> prodMat(vector<vector<int>> &matA, vector<vector<int>> &matB);
vector<vector<int>> potencia(vector<vector<int>> &a, int n);
vector<vector<int>> sumMat(vector<vector<int>> &a , vector<vector<int>> &b);
vector<vector<int>> solve(int n, vector<vector<int>> &a);
typedef vector<vector<int>> matrix;
//asumiendo que potencia y suma son Θ(1) ,junto con producto da : T(N) = T(N/2) + Θ(1) -> por el teo maestro es : Θ(log(n))

int main(){
    int n; cin >> n;
    //manipulacion de bits checkae que sea una potencia de 2
    //explotamos que el punter a la string es siempre true para  mostrar msj si da errors
    assert( ( (n&(n-1) ) == 0 )  && "no es potencia de 2 el numero"); 
    vector<vector<int>> matriz(4,vector<int>(4));
    
    fore(i,0,4){
        fore(j,0,4){
            cin >> matriz[i][j];
        }
    }
    
    matrix res = solve(n,matriz);
    fore(i,0,4){fore(j,0,4){ cout << res[i][j] << " ";} cout << "\n";}
}

vector<vector<int>> prodMat(vector<vector<int>> &matA, vector<vector<int>> &matB){
    
    vector<vector<int>> mul(4,vector<int>(4,0));
    for( int i=0;i<4;i++){   
       
        for( int j=0;j<4;j++){    
            
          
            for(int k=0;k<4;k++)    
            {    
                mul[i][j]+= matA[i][k]*matB[k][j];    
            }    
        }    
    }
    return mul;
}

vector<vector<int>> potencia(vector<vector<int>> &a, int n){
        vector<vector<int>> res(4,vector<int>(4));
        fore(i,0,4)fore(j,0,4) res[i][j] = a[i][j];
    fore(i,0,n-1){
       res = prodMat(res,a); 
    }
    return res;
}
vector<vector<int>> sumMat(vector<vector<int>> &a , vector<vector<int>> &b){
    vector<vector<int>> res(4,vector<int>(4,0));
    fore(i,0,4){
        fore(j,0,4){
            res[i][j] = a[i][j] + b[i][j];
        }
    }
    return res;
}

vector<vector<int>> solve(int n, vector<vector<int>> &a){
    if(n ==1){
        return a;
    }else{
        vector<vector<int>> B = solve(n/2,a);
        
        matrix pot = potencia(a,n/2);
        matrix prod = prodMat(pot,B);
        // B*A^n/2 + B       
        return sumMat(prod ,B);
    }

}