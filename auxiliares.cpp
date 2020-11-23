#include "definiciones.h"
#include "ejercicios.h"
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
    int var = (t.size() + f) % t.size();
    return var;
}

int columnaToroide(int c, toroide t) {
    int var = (t[0].size() + c) % t[0].size();
    return var;
}

int vecinosVivos(toroide t, int f, int c) {
    int cantVecinasVivas = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((j != 0 || i != 0) && t[filaToroide(f + i, t)][columnaToroide(c + j, t)]) {
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

//ejercicio1
int filas(vector<vector<bool>> t) { return t.size(); }

int columnas(vector<vector<bool>> t) {
    if (t.size() > 0) return t[0].size();
    else return 0;
}

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
/*
//ejercicio 2
bool enRango(int i, vector<bool> s) { return i < s.size(); }

bool enRangoToroide(int f, int c, vector<vector<bool>> t) {
    return f < t.size() && enRango(c, t[f]);
}*/

//ejercicio 3
int cantidadVivas(toroide t) {
    int cantVivas = 0;
    for (int i = 0; i < t.size(); i++) {
        for (int j = 0; j < t[i].size(); j++) {
            if (t[i][j]) {
                cantVivas++;
            }
        }
    }
    return cantVivas;
}

//ejercicio 4
int superficieTotal(toroide t) {
    //pre: esToroide(t)
    return (t.size() * t[0].size());
}

//ejercicio 10
bool EvolucionPrimosLejanos(toroide const &t1, toroide const &t2) {
    //t1 -> t2
    bool primosLejanos = false;
    toroide tAux = t1;
    evolucionToroide(tAux);

    while (!toroideMuerto(tAux) && !primosLejanos && t1 != tAux) {
        if (t2 == tAux) primosLejanos = true;
        evolucionToroide(tAux);
    }
    return primosLejanos;
}



//ejercicio 13

void posiblesValoresTraslado(toroide t, toroide u, int &f, int &c, int &k, int &l) {
    int i = 0, j = 0, o = 0, p = 0;
    for (i = 0; i < t.size() && k == 0 && l == 0; i++) {
        for (j = 0; j < t[0].size() && k == 0 && l == 0; j++) {
            if (t[i][j]) {
                for (o = f; o < u.size() && !(k == i - o && l == j - p); o++) {
                    for (p = c; p < u[0].size() && !(k == i - o && l == j - p); p++) {
                        if (u[o][p]) {
                            k = i + o;
                            l = p + j;
                            f = o;
                            c = p;
                        }
                    }
                }
            }
        }
    }
}

bool esTraslado(toroide t, toroide u, int k, int l) {
    int i = 0, j = 0;
    bool traslado = true;
    for (i = 0; i < t.size() && traslado; i++) {
        for (j = 0; j < t[0].size() && traslado; j++) {
            traslado = (t[i][j] == u[(i + k + t.size()) % t.size()]
            [(j + l + t[0].size()) % t[0].size()]);
        }
    }
    return traslado;
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