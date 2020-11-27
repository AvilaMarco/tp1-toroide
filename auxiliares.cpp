#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"
#include <string>

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

//General
int filaToroide(int f, toroide t) {
    int var = (filas(t) + f) % filas(t);
    return var;
}

int columnaToroide(int c, toroide t) {
    int var = (columnas(t) + c) % columnas(t);
    return var;
}

int vecinosVivos(toroide t, int f0, int c0) {
    int cantVecinasVivas = 0;
    for (int f = -1; f <= 1; f++) {
        for (int c = -1; c <= 1; c++) {
            if ((c != 0 || f != 0) && t[filaToroide(f0 + f, t)][columnaToroide(c0 + c, t)]) {
                cantVecinasVivas++;
            }
        }
    }
    return cantVecinasVivas;
}

bool debeVivir(toroide t, int f, int c) {
    if (t[f][c]) {
        return (vecinosVivos(t, f, c) == 2 || vecinosVivos(t, f, c) == 3);
    } else {
        return vecinosVivos(t, f, c) == 3;
    }
}

int filas(vector<vector<bool>> t) { return t.size(); }

int columnas(vector<vector<bool>> t) {
    if (t.size() > 0) return t[0].size();
    else return 0;
}

//ejercicio1
bool esRectangulo(vector<vector<bool>> r) {
    if (columnas(r) > 0 && filas(r) > 0) {
        for (int i = 0; i < r.size(); i++) {
            if (!(r[0].size() == r[i].size())) return false;
        }
    }
    return true;
}

bool esToroide(vector<vector<bool>> t) {
    bool result;
    result = esRectangulo(t) && filas(t) >= 3 && columnas(t) >= 3;
    return result;
}

//ejercicio 3
int cantidadVivas(toroide t) {
    int cantVivas = 0;
    for (int f = 0; f < filas(t); f++) {
        for (int c = 0; c < columnas(t); c++) {
            if (t[f][c]) {
                cantVivas++;
            }
        }
    }
    return cantVivas;
}

//ejercicio 4
int superficieTotal(toroide t) {
    //pre: esToroide(t)
    return (filas(t) * columnas(t));
}

//ejercicio 10
bool EvolucionPrimosLejanos(toroide const &t1, toroide const &t2) {
    //t1 -> t2
    bool primosLejanos = false;
    toroide tAux = t1;
    int p = 0;

    if(!esPeriodico(t1,p) && toroideMuerto(t2)) primosLejanos = true;

    evolucionToroide(tAux);
    while (!toroideMuerto(tAux) && !primosLejanos && t1 != tAux) {
        if (t2 == tAux) primosLejanos = true;
        evolucionToroide(tAux);
    }
    return primosLejanos || (t2 == tAux && !toroideMuerto(tAux)); //esPeriodico y son iguales
}

//ejercicio 14
int primeraVivaDesde(toroide t, string inicio) {
    int primeraViva = -1;
    bool esArriba = inicio == "arriba";
    bool esAbajo = inicio == "abajo";

    if (esArriba || esAbajo) {
        for (int f = 0; f < filas(t) && primeraViva == -1; ++f) {
            for (int c = 0; c < columnas(t); ++c) {
                if (esArriba && t[f][c]) {
                    primeraViva = f;
                } else if (esAbajo && t[filas(t) - 1 - f][c]) {
                    primeraViva = filas(t) - 1 - f;
                }
            }
        }
    } else {
        for (int c = 0; c < columnas(t) && primeraViva == -1; ++c) {
            for (int f = 0; f < filas(t); ++f) {
                if (inicio == "izquierda" && t[f][c]) {
                    primeraViva = c;
                } else if (inicio == "derecha" && t[f][columnas(t) - 1 - c]) {
                    primeraViva = columnas(t) - 1 - c;
                }
            }
        }
    }

    return primeraViva;
}

toroide trasladarHaciaArriba(toroide t) {
    for (int f = 0; f < filas(t) - 1; ++f) {
        swap(t[f], t[f + 1]);
    }
    return t;
}

toroide trasladarHaciaDerecha(toroide t) {
    for (int f = 0; f < filas(t); ++f) {
        for (int c = 0; c < columnas(t) - 1; ++c) {
            swap(t[f][c], t[f][c + 1]);
        }
    }
    return t;
}

//ejercicio 13

void valoresTraslado(vector<toroide>& ts, toroide t) {
    int f, c ;
    toroide tAux = t;
    for (f = 0; f < filas(t); f++) {
        tAux = trasladarHaciaArriba(tAux);
        ts.push_back(tAux);
        for (c = 0; c < columnas(t); c++) {
            tAux = trasladarHaciaDerecha(tAux);
            ts.push_back(tAux);
        }
    }
}