#include<bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define FAST_IO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
int n,k;
const int INF = 1e8;

//Pensamos en los estados como la posicion en la que estoy, y que cache tengo
// Para poder indexar en nuestra memoria de dp, represento el cache usando los bits de un entero.
// Si en la posicion i-esima hay un 1, esta en la cache. Si es 0, no esta

vector<int> R;

vector<vector<int>> memo;

int changeIthBit(int i, int num){
    return num ^ (1 << i); 
}

int valueIthBit(int i,int num){
    return num & (1 << i);
}

int borrarElem(int elem,int cache){
    return changeIthBit(elem-1,cache); //"Apagamos" la posicion correspondiente
}

int guardarElem(int elem, int cache){
     return changeIthBit(elem-1,cache);//"Prendemos" la posicion correspondiente
}
int isInCache(int elem, int cache){
    return valueIthBit(elem-1,cache); // Miramos si el bit esta prendido o no
}

int hitOrMiss(int i, int sizeCache, int cache){
    if(i == n) return 0;
    if(memo[i][cache] == INF){
        if(isInCache(R[i],cache)) memo[i][cache] =hitOrMiss(i+1,sizeCache, cache); // hit
        else{                                                             // miss
            int miss = 1;                                                   
            if(sizeCache < k){                                            // hay lugar en la cache
               int Ncache =  guardarElem(R[i],cache); 
               memo[i][cache] = miss + hitOrMiss(i+1,sizeCache+1,Ncache);
            }else{                                                        // no hay lugar en la cache
                int Ncache = cache;
                for(int j = 0; j < n;j++){                                // itero por lo que tengo en mi cache
                    if(isInCache(R[j],cache)){                            // voy probando cual es mejor sacar
                        Ncache = borrarElem(R[j],cache);
                        Ncache = guardarElem(R[i],Ncache);
                        memo[i][cache] =  min(memo[i][cache], hitOrMiss(i+1,sizeCache,Ncache) + miss);

                    }
                }
            }
        }
    }
    return memo[i][cache];
}


int main(){
    FAST_IO
    cin >> n >> k;
    R.assign(n,0);
    for(int i = 0; i<n ;i++){
        cin >> R[i];
    }
    int tamañoMemo = (1 << (n)); // Hay 2^n posibles estados de memoria
    memo.assign(n,vector<int>(tamañoMemo,INF));
    cout << hitOrMiss(0,0,0);       // el 0 representa la memora vacia, como son 32 bits, tengo 32 posiciones de 0s

    return 0;
    
   
   
   
   


}