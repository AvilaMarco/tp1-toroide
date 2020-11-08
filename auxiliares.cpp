#include "definiciones.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios

pair<int, int> mp(int a, int b) {
    return make_pair(a, b);
}

//No pueden usar esta función para resolver el TPI.
//Tampoco pueden usar iteradores, como usa esta función.
vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}

//ejercicio1
int filas(vector<vector<bool>> t) { return t.size();}
int columnas(vector<vector<bool>> t){
    if(t.size() > 0) return t[0].size();
    else return 0;
}
bool esRectangulo(vector<vector<bool>> r){
    if(filas(r)>0 && columnas(r) >0) {
        for (int f = 0; f<r.size(); f++){
            if(!(r[0].size() == r[f].size())) return false;
        }
    }
    return true;
}
bool esToroide(vector<vector<bool>> t){
    bool result;
    result = esRectangulo(t) && filas(t) >= 3 && columnas(t) >=3;
    return result;
}

//ejercicio 2
bool enRango(int i, vector<bool> s){return i<s.size();}
bool enRangoToroide(int f, int c, vector<vector<bool>> t){
    return f<t.size() && enRango(c, t[f]);
}

//ejercicio 3
int cantidadVivas(toroide t){
    int cantVivas = 0;
    for(int i=0; i<t.size(); i++) {
        for (int j = 0; j < t[i].size(); j++) {
            if (t[i][j]) {
                cantVivas++;
            }
        }
    }
    return cantVivas;
}

//ejercicio 4
int superficieTotal(toroide t){
    //pre: esToroide(t)
    return (t.size() * t[0].size());
}

//ejercicio 13

int filaToroide(int f, toroide t){
    int var = (t.size() + f) % t.size() ;
    return var;
}

int columnaToroide(int c, toroide t){
    int var = (t[0].size() + c) % t[0].size();
    return var;
}

bool vivaToroide(int f, int c, toroide t){
    return enRangoToroide(filaToroide(f, t),columnaToroide(c,t),t) && t[filaToroide(f,t)][columnaToroide(c,t)];
}

bool vecinaViva(toroide t, int f,int c,int i, int j){
    return vivaToroide(f+i, c+j, t);
}

//ejercicio 5
int vecinosVivos(toroide t, int f, int c){
    int cantVecinasVivas = 0;
    for(int i=-1; i<=1; i++) {
        for (int j = -1; j <=1; j++) {
            if ((j != 0 || i != 0) && vecinaViva(t,f,c,i,j)) {
                cantVecinasVivas++;
            }
        }
    }
    return cantVecinasVivas;
}

//ejercicio 6
bool debeVivir(toroide t, int j, int c){
    if(t[j][c]){
        if(vecinosVivos(t,j,c)==2 || vecinosVivos(t,j,c)==3) return true;
        else return false; //vecinosVivos < 2 || vecinosVivos > 3
    }else if(vecinosVivos(t,j,c)==3){
        return true;
    }else return false;
}




