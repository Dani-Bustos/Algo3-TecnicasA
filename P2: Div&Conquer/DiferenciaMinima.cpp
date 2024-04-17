#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;
typedef long long ll;

const int INDEF = -1; const int INF =1e9;
vector<int> Acrec; vector<int> Bdecrec;
//Complejidad :T(N) = T(N/2) + Θ(1)  --> log(n)
//Idea: Busqueda binaria sobre el rango de posibilidades: Si son iguales ganamos, si A es menor, capaz que subiendo el rango mejora
// Su a es mayor, capaz que bajar mejora. Usamos min para comparar las posibilidades

bool rSort(int a ,int b){
    return a>=b;
}
int solve(int l,int r){
    if(l>r){
        return INF;
    }
    int mid = l + (r-l)/2;
    int act = abs(Acrec[mid] - Bdecrec[mid]);
    int res = INF;
    if(Acrec[mid] == Bdecrec[mid]){
        return 0;
    }else if(Acrec[mid] < Bdecrec[mid]){
        res = min(solve(mid +1,r ),act);
    }else if(Acrec[mid] > Bdecrec[mid]){
        res = min(solve(l,mid-1),act);
    }
    return res;
}


int main(){
   int n; cin >> n;
   Acrec.resize(n); Bdecrec.resize(n);
   fore(i,0,n) cin >> Acrec[i];
   fore(i,0,n) cin >> Bdecrec[i];
   sort(Acrec.begin(),Acrec.end()); // debe ser creciente por requiere de consigna;
   sort(Bdecrec.begin(),Bdecrec.end(),rSort); //debe ser decreciente por requiere de consigna
   cout << solve(0,n);
   
}


