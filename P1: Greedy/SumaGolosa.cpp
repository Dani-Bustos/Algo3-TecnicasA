#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b; i++)
using namespace std;

//Complejidad : O(nlogn)
// Idea: tomar los dos mas chicos, sumarselo al resultado, insertar la ultima suma de nuevo al arbol
//repetir. Es siempre optimo sumar los 2 mas pequeños hasta ahora
int solve(multiset<int> &nums){
     //nlog(n)
    int res = 0;int act = 0;
    int total = nums.size();
    //-1 porque el primer paso borra dos elementos de un saque
    fore(i,0,total-1){
        auto it = nums.begin();//O(logn)
        act = *it; it++;
        act+= *(it);
        res += act;
        it--;
        nums.erase(it);
        it = nums.begin(); //O(logn)
        nums.erase(it); //O(logn)
        nums.insert(act);
    }
    return res;
}


int main(){
    int n; cin >> n;
    multiset<int> nums; 
    fore(i,0,n){ 
        int temp; 
        cin >> temp; 
        nums.insert(temp);
    }
    cout << solve(nums);
    

}
 