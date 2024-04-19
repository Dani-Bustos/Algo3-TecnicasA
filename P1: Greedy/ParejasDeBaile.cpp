#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)
typedef long long ll;
using namespace std;
const long long INDEF = -1;

//Idea: usamos el orden creciente de las listas. Es un algoritmo casi identico al merge de MergeSort
//Complejidad O(min(n,m)) con n y m las longitudes de ambas listas respectivamente

int solve(vector<int> &a , vector<int> &b){
    int posA= 0; int posB= 0;
    int res = 0;
    while(posA < a.size() && posB < b.size()){
        //si pueden bailar lo hacen
        if(abs(a[posA] - b[posB]) <= 1 ){
            res++;
            posA++;
            posB++;
        //si b es mas chico lo incrementamos
        }else if (a[posA] > b[posB] ){
            posB++;
        // si a es mas chico lo incrementamos
        }else{
            posA++;
        }
    }
    return res;
}


int main(){
    int lenA,lenB; cin >> lenA >> lenB;
    vector<int> a(lenA); vector<int> b(lenB);
    fore(i,0,lenA) cin >> a[i];
    fore(i,0,lenB) cin >> b[i];
    //deben estar ordenados creciente por requiere
    sort(a.begin(),a.end()); sort(b.begin(),b.end());
    cout << solve(a,b);
    
}

