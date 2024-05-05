#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)
typedef long long ll;
using namespace std;
const long long INDEF = -1;

//Idea: agarrar los k mas grandes del vector , ordenado primero
//Complejidad : O(nlog(n))
//2da idea : mantener un min heap, que nunca se exceda de k elementos, ir popeando correspondientemente
// al final deben permanecer los k elementos mas grandes
//Complejidad : O(nlog(k))



int betterSolve(vector<int> &a,int k){
    //Complejidad : nlog(k)
    priority_queue<int,vector<int>,greater<int>> kMaximos;
    fore(i,0,a.size()){
        kMaximos.push(a[i]);
        //saca al mas chico del heap si ya nos pasamos de k
        if(kMaximos.size() > k){
            kMaximos.pop();
        }

    }
    int res = 0;
    //desencolar los k elementos nos cuesta klogk
    //a este punto podriamos solo iterar la representacion 
    // que es un vector en k pasos, pero no cambia la complejidad
    fore(i,0,k){
        res += kMaximos.top();
        kMaximos.pop();
    }
    return res;
    
}

int solve(vector<int> &a,int k){
    //Complejidad O(nlogn)
    sort(a.begin(),a.end());
    int  res = 0;
    for(int i = a.size()-1; i>= a.size()-k;i--){
        res += a[i];
    }
    return res;
}


int main(){
    int n,k; cin >> n >> k;
    vector<int> a(n);
    fore(i,0,n) cin >> a[i];
    
    cout << solve(a,k) << "\n";
    cout << betterSolve(a,k);
}

