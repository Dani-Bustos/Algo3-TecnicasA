#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;
typedef long long ll;

const int INDEF = -1;
vector<int> a; vector<int> b;
//Complejidad : 2log^2(n) = O(log^2(n))
//Idea: Busqueda binaria dentro de busqueda binaria. Agarramos un elemento de la izquierda,
// binariamente buscamos en el otro cuantos tiene por detras, si nos pasamos tenemos que agarrar uno mas chico, si nos falta, uno mas grande
// si los que tiene por detras de en uno mas los que tiene por detras del otro es lo que buscamos, ya esta

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
int solve(int target){
    int l = 0; int r = a.size();
    int mid = l + (r-l)/2;
    //Buscamos binariamente el suponiendo que esta en a
    while(l <= r){
        int atras = binary(b,a[mid]);
        if(mid + atras  == target){
            //ya lo encontramos
            return a[mid];
            
        }else if(mid + atras  < target){
            l = mid + 1;
        }else if(mid  + atras  > target){
            r = mid - 1;
        }
        mid = l +(r-l)/2;
    }    
     l = 0;  r = b.size();
    mid = l + (r-l)/2;
    //como no estaba en a, debe estar ahora en b. Repetimos la operacion
    while(l <= r){
        int atras = binary(a,b[mid]);
        if(mid + atras  == target){
            return b[mid];
            
        }else if(mid + atras  < target){
            l = mid + 1;
        }else if(mid  + atras > target){
            r = mid - 1;
        }
        mid = l +(r-l)/2;
    }    
}




int main(){
    int iesimo; cin >> iesimo;
    int n,m; cin >> n >> m;
    a.resize(n);b.resize(m);
    fore(i,0,n) {cin >> a[i];}
    fore(i,0,m) cin >> b[i];
    //DEBEN ESTAR ORDENADOS POR REQUIERE
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout << solve(iesimo);
    
    

}


