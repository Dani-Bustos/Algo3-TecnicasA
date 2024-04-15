#include<bits/stdc++.h>
#define fore(i,a,b) for(int i = a; i< b;i++)

using namespace std;
typedef long long ll;

 const int INDEF = -1;
 vector<int> monedas;

pair<vector<int>,int> mergeCount(vector<int> &fst, vector<int> &snd);
int SortCount(vector<int> &a);




int main(){
    
    int n; cin >> n;
    monedas.resize(n);
   
    fore(i,0,n) cin >> monedas[i];
    cout << SortCount(monedas) << " Y el array ordenado es \n";
    
    fore(i,0,n) cout << monedas[i] << " ";
    
}

int SortCount(vector<int> &a){
    if(a.size() == 1){
        return 0;
    }else{
    
    vector<int> PrimeraMitad;
    vector<int> SegundaMitad;
    
    fore(i,0,(a.size() +1)/2){
        PrimeraMitad.push_back(a[i]);
    }
    fore(i,(a.size() + 1) /2 , a.size()){
        SegundaMitad.push_back(a[i]);
    }
    int res = 0;
    res += SortCount(PrimeraMitad);
    res += SortCount(SegundaMitad);
    
    pair<vector<int>,int> ordenadoYCant = mergeCount(PrimeraMitad,SegundaMitad);
    a = ordenadoYCant.first;
    res += ordenadoYCant.second;
    
    return res;
    }

}

pair<vector<int>,int> mergeCount(vector<int> &fst, vector<int> &snd){
    int indFst = 0; int indSnd = 0; 
    vector<int> res; int count = 0;
    while(indFst < fst.size() && indSnd < snd.size()){
        if(fst[indFst] <= snd[indSnd]){
            res.push_back(fst[indFst]);
            indFst++;   

        }else{
            // para cada elemento que falta meter, tmb hay una pareja mas con este
            count += fst.size() -indFst;
            res.push_back(snd[indSnd]);
            indSnd++;
        }
    }
    // Dumpeamos los demas en el resultado
    if(indFst < fst.size()){
        
        while(indFst<fst.size()){
            
            res.push_back(fst[indFst]);
            indFst++;
            
        }
        
    }
    
    if(indSnd < snd.size()){
        
        while(indSnd<snd.size()){
            res.push_back(snd[indSnd]);
            indSnd++;
            
        }
        
    }
    
    return {res,count};
}
