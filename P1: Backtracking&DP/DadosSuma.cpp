#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)

using namespace std;
const int INDEF = -1;
int k;;//caras del dado  
vector<vector<int>> MEMO;
//sin podas sencillas, hay Ω(k^n) llamados recursivos y O(n*(min(n*k,s))) instancias.
// --> hay superposición de subproblemas  si n*min(n*k,s) << k^n (se prueba inductivamente)
int f(int dados,int num){
    //si restamos de mas o si no hay mas dados o si ya llegamos pero hay mas dados o si es imposible llegar al numero con el maximo posible, cortamos
    if(num < 0 || (dados == 0 && num > 0) || (num == 0 && dados> 0) || num > dados*k){
        return 0;
    }else if(num == 0 && dados == 0){
        return 1;
    }else if(MEMO[dados-1][num-1] != INDEF){
        return MEMO[dados-1][num-1];
    }else{
        int sum = 0;
        fore(i,1,k+1){
            sum+=f(dados-1, num - i);
        }
        MEMO[dados-1][num-1] = sum;
        return MEMO[dados-1][num-1];
    }
}
int g(int dados,int num,int caras){
    if( (num <= 0  && dados > 0)  || (num > 0 && dados == 0)){
        return 0;
    }else if(num == 0 && dados == 0){
        return 1;
    }else{
        int sum = 0;
        fore(i,1,caras+1){
            sum+= g(dados-1,num-i,caras-1);
        }  
        return sum;
    }
}   

int main(){
    int n,s; //dados,caras,suma objetivo
    cin >> n >> k >> s;
    //si la suma se pasa de lo maximo posible, no nos interesa, la funcion nos va a dar 0
    MEMO.resize(n,vector<int>(min(n*k,s),INDEF));
    cout << g(n,s,k);

}
