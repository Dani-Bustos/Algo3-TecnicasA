#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)

using namespace std;
const long long INDEF = -1;
vector<int> a;
//idea

void mergeSort(int posInicial, int posFinal);
void swap(int posA,int posB);
void mergear(int posInicial, int posFinal, int medio);




int main(){
    int n;
    cin >> n;
    a.resize(n); fore(i,0,n) cin >> a[i];
    mergeSort(0,n);
    fore(i,0,n) cout << a[i] << " ";
}
void mergeSort(int posInicial, int posFinal){
    if(posInicial >= posFinal){
        return;
    }else{
    int delta = (posFinal - posInicial )/2;
    mergeSort(posInicial, delta);
    mergeSort(delta + 1, posFinal);
    mergear(posInicial,posFinal,delta);    
    }
}

void swap(int posA,int posB){
    int temp = a[posA];
    a[posA] = a[posB];
    a[posB] = temp;
}
void mergear(int posInicial, int posFinal, int medio){
    int segundoInicio = medio + 1;
    if(a[medio] <= a[segundoInicio]){
        return;
    }


    while(posInicial <= medio && segundoInicio <=posFinal){
        if(a[posInicial] <= a[segundoInicio] ){
            posInicial++;
        }else{
            int aCambiar  = a[segundoInicio];
            int indice = segundoInicio;
            while(indice != posInicial){
                a[indice] = a[indice - 1];
                indice--;
            }
            a[posInicial] = aCambiar;
        }
        segundoInicio++; medio++; posInicial++;

    }

}
