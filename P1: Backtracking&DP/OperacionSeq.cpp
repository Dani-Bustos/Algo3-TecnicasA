#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a;i<b;i++)
using namespace std;
typedef long long ll;
const int INDEF = -1; const int NEGINF = -1e9; const int INF = 1e9;
vector<int> nums; vector<vector<int>> MEMO;
ll w;
bool posible(int i,ll current){
   if(current > w){
    return false;
   }else if(i == nums.size()){  
    return current == w ;
   }else if(MEMO[i][current] != INDEF){
    return MEMO[i][current];
   }else{
    MEMO[i][current] = posible(i+1,current + nums[i]) || posible(i+1,current * nums[i]) || posible(i+1,pow(current,nums[i])) ;
    return MEMO[i][current];
   }
}
bool tieneRaizN(int num,int raiz){
    int temp = floor(pow(num,1.0/raiz));
    return pow(temp,raiz) == num;
}

vector<char> res;
//complejidad : si esta completa la matriz , esto tarda Θ(n)
vector<char> get_seq(int i = 0, int target = 0){
    if(i == nums.size()){
        return res;
    }else if(i == 0){
        return get_seq(i+1,nums[0]); //el primero siempre esta, 
    }else{
       char op = 'N'; 
       if( posible(i+1,target+nums[i]) ) {
          vector<char> res = get_seq(i+1,target+nums[i]);
            op = '+';
        } else if(posible(i+1,target*nums[i])){
            vector<char> res = get_seq(i+1,target*nums[i]);
            op = '*';
        } else if(posible(i+1,pow(target,nums[i]))){
            vector<char> res = get_seq(i+1,pow(target,nums[i]));
            op = 'p';
        }
        res.push_back(op);
        return res;
    }
}
vector<char> secuenciaOperacionesW (int target,vector<int> &numeros){
    w =target; nums = numeros;
    vector<char> sol = get_seq();
    //Como use un vector , puse las instrucciones alreves
    reverse(sol.begin(),sol.end());
    return sol;
}
int main(){
  int n;  
  cin >> n >> w;
  vector<int> numeros(n);
  fore(i,0,n){
    cin >> numeros[i];
  }
  //top down 
  /*
  MEMO.resize(n,vector<int>(w+1,INDEF));
  auto solucion = secuenciaOperacionesW(w,numeros);
  for(auto x : solucion){
    cout << x << " ";
  }
  */
  
  //bottom up , optimizacion de memoria O(2*w) = O(w)
   //complejidad temporal : O(w*n)
   //observacion, con la optimizacion de memoria no podemos  recuperar la solucion
  vector<bool> dp(w+1,false);
  vector<bool> prev(w+1,false);
  prev[w] = true;
  for(int i = n-1;i>=0;i--){
    for(int current = w;current>=0;current--){
        //checkeamos si es una instancia valida antes de acceder, usando la logica secuencial
        dp[current] = (current+numeros[i] <= w && prev[current+numeros[i]]) 
                     || (current*numeros[i] <= w && prev[current*numeros[i]]) 
                     || (pow(current,numeros[i]) <= w && prev[pow(current,numeros[i])]);
    }
    prev = dp;
  }



}