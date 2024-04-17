#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;
typedef long long ll;

const int INDEF = -1;
vector<int> a; vector<int> b;
//recurrencia dada por T(N) = 
//Idea: Busqueda binaria dentro de busqueda binaria. Agarramos un elemento de la izquierda,
// binariamente buscamos en el otro cuantos tiene por detras, si nos pasamos tenemos que agarrar uno mas chico, si nos falta, uno mas grande

int binary(vector<int> &arr,int target){
    int l = 0; int r = arr.size();
    int mid = l +(r - l)/2;
    while(l <= r){
        if(arr[mid] == target){
            return mid;
            
        }else if(arr[mid] < target){
            l = mid + 1;
        }else if(arr[mid] > target){
            r = mid - 1;
        }
        mid = l +(r-l)/2;
    }    
    return mid;
}





int main(){
    
    int n,m; cin >> n >> m;
    a.resize(n);//b.resize(m);
    fore(i,0,n) {cin >> a[i];}
    //fore(i,0,m) cin >> b[i];
    //DEBEN ESTAR ORDENADOS POR REQUIERE
    sort(a.begin(),a.end());
    //sort(b.begin(),b.end());
    cout << binary(a,m);
    
    

}


