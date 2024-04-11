    #include<iostream>
    #include<string>

    using namespace std;
    string a,b;
    //Complejidad : Dada por la recurrencia de : T(N) = 4*T(n/2) + 2*n que por el teo maestro nos da Θ(n^2)
    bool solve(int posA, int posB, int largo){
        if(largo == 0){
            return false;
        }
        else if(a.substr(posA,largo) == b.substr(posB,largo)){
            return true;
        }else if(largo % 2 == 1){
            //caso donde nos queden particiones impares, ya no podemos partirlas en 2 limpiamente
            return false;
        }else {
            int deltaLargo = largo/2;
            //tanto a1 como b1, son la misma posicion inicial, con el largo reducido a la mitad
            //a2 y b2 comienzan en las posiciones actuales, desplazadas un medio de la longitud hacia adelante
            //CUIDADO por la logica secuencial de los operadores, si das vuelta el orden de ejecucion del segundo && da rechazado
            //siento que esto es una falencia de como estan armados los test
            return (solve(posA,posB,deltaLargo) && solve(posA +deltaLargo,posB+deltaLargo,deltaLargo))
                ||(solve(posA + deltaLargo,posB,deltaLargo) && solve(posA,posB + deltaLargo,deltaLargo));        
        }
    }   


    int main(){
        //a y b definidos globalmente
        cin >> a; cin >> b;
        
        if(solve(0,0,a.length())) cout<< "YES";
        else cout << "NO";
        
    }

