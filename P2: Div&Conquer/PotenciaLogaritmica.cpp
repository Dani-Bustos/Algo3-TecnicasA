#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i<b;i++)
typedef long long ll;
using namespace std;
const long long INDEF = -1;


//Idea: Vamos a explotar que : a^b = (a^(b/2))^2 si el b es impar usamos que a*a^(b-1) = a^b
//dado que a es fijo, tomamos que solo importa el b
//complejidad : T(b) = Θ(1) + T(b/2); -> complejidad : O(log(b)) 

ll solve(int a, int b){
    if(b == 1){
        return a;
    }else{
        ll sig = solve(a,b/2); //Division entera, no olvidar
        
        if( b % 2 == 1) return a*sig*sig; //esto se podria hacer con la funcion tmb, da tiempo cte igualmente
        if(b % 2 == 0) return sig*sig;
    }
        
}


int main(){
    int a; int b;
    
    cin >> a >> b;
   
    
    cout << solve(a,b);
}

