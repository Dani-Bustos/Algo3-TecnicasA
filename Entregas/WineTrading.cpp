#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)
typedef long long ll;
using namespace std;
const long long INDEF = -1;

//Complejidad : O(t*n) con t los test cases

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); //Cosas de c++ para leer y printear mas rapido
    int n;
    cin >> n;
    while(n != 0){
        //el resultado puede superar 1e8
        long long res = 0;
        vector<int> a(n); 
        long long act = 0;       
        fore(i,0,n) cin >> a[i];
        //Siempre vamos a tener que mover el 100% del vino, y la unica decision no optima es
        //acarrearlo por mas del tiempo necesario, entonces vamos dejando el vino mientras avanzamos, y ponemos
        //en nuestra "mochila" todos lo que vemos, ya que al siempre dejarlo a la primera que vemos, lo dejamos en su lugar optimo
        fore(i,0,n){
            res +=abs(act);
            act += a[i];
            
        }        
        cout << res << "\n";    
        cin >> n;
    }
}

