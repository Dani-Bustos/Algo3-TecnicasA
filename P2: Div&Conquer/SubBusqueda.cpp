#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)
typedef long long ll;
using namespace std;
const long long INDEF = -1;

vector<int> a;
bool aparece(int i,int j,int elem);
int ubicar(int elem,vector<int> &arr);
//Idea: Buscamos en cada mitad del arreglo, si el elemento q buscamos esta o no, luego seguimos por la mitad adonde este
//complejidad : (la recurrencia es equivalente a una pasada del while) 
//T(n) = T(n/2) + 2*sqrt(n) = 2*sqrt(n)*∑[𝑖=1][log(n)] (1/sqrt(2))**i 
// (serie geometrica infinita da 1/1-1/sqrt(2) ~ 3.14 < 4) <= 8*sqrt(n) = O(sqrt(n))


//HAY QUE HACER DE CUENTA QUE ESTA FUNCION CUESTA O(SQRT(J-I+1))                                                                         
bool aparece(int i,int j,int elem){
    //j incluido
    fore(k,i,j+1){
        if(a[k] == elem){
            return true;
        }
    }
    return false;
}
int ubicar(int elem,vector<int> &arr){
  int l = 0; int r = arr.size();
  int  mid = l + (r-l)/2;
   // si o si lo vamos a encontrar como peor caso en log2(n), por eso i/2
   for(int i = arr.size();i >= 1;i/2){
        if(arr[mid] == elem){
            return mid;
        }//¿aparece en la izquierda?
        else if(aparece(l,mid,elem)){
            r = mid -1;
        //¿aparece en la derecha?
        }else if(aparece(mid,r-1,elem)){
            l = mid + 1;
        }
        mid = l + (r-l)/2;
   }
    //Por si no esta en el arreglo
    return -1;
}


int main(){
    int n; int e; 
    cin >> n >> e; a.resize(n); 
    fore(i,0,n) cin >> a[i]; 
    cout << ubicar(e,a);
}

