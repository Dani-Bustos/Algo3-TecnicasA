#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)
typedef long long ll;
using namespace std;
const long long INDEF = -1;
vector<vector<int>> mat;
int num = 1;
//Idea :                                              
//Complejidad :                                                           
void solve(int i0,int j0,int n){ 
    
    if(n == 2){
        //completa el cuadrado en todos lados , menos el tapado
        fore(i,0,n){
            fore(j,0,n){
                if(mat[i0+i][j0 + j] != INDEF){
                    mat[i0 + i][j0 + j] = num;
                    
                }
            }
        }
        num++;
    }else{
        //pone una l en el medio, definis las zonas , exploras+
    }
    
}

int main(){
    int n; cin >> n;
    //es requiere del problema que sea potencia de 2;
    assert(( n != 0 && n & (n-1)) == 0 && "NO ES POTENCIA DE 2");
        
    mat.resize(n,vector<int>(n,INDEF));
    mat[0][0] = 0;
    

}

