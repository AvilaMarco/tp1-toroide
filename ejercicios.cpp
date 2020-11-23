#include <algorithm>
#include <utility>
#include "ejercicios.h"
#include "auxiliares.h"
#include <iostream>
#include <vector>

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    bool resp = false;
    resp = esToroide(t);
    return resp;
}

// EJERCICIO 2
bool toroideMuerto(toroide const &t) {
    bool resp = true;
    int f, c;
    for (f = 0; f < filas(t); f++) {
        for (c = 0; c < columnas(t); c++) {
            if (t[f][c]) {
                resp = false;
            }
        }
    }

    return resp;
}

// EJERCICIO 3
vector<posicion> posicionesVivas(toroide const &t) {
    vector<posicion> vivos;
    pair<int, int> vAux;
    for (int f = 0; f < filas(t); f++) {
        for (int c = 0; c < columnas(t); c++) {
            if (t[f][c]) {
                vAux.first = f;
                vAux.second = c;
                vivos.push_back(vAux);
            }
        }
    }
    return vivos;
}

// EJERCICIO 4
float densidadPoblacion(toroide const &t) {
    //pre: esToroide(t)
    float resp = -1;
    float cantVivas = (float) cantidadVivas(t);
    float sup = (float) superficieTotal(t);
    resp = (cantVivas / sup); //superficieTotal != 0
    return resp;
}

// EJERCICIO 5
int cantidadVecinosVivos(toroide const &t, int f, int c) {
    int resp = vecinosVivos(t, f, c);
    return resp;
}

// EJERCICIO 6
bool evolucionDePosicion(toroide const &t, posicion x) {
    bool resp = debeVivir(t, get<0>(x), get<1>(x));
    return resp;
}

// EJERCICIO 7
void evolucionToroide(toroide &t) {
    toroide tAux = t;
    for (int f = 0; f < filas(t); f++) {
        for (int c = 0; c < columnas(t); c++) {
            tAux[f][c] = debeVivir(t, f, c);
        }
    }
    t = tAux;
}

// EJERCICIO 8
toroide evolucionMultiple(toroide const &t, int k) {
    toroide out = t;
    // Implementacion
    for (int i = 1; i <= k; ++i) {
        evolucionToroide(out);
    }
    return out;
}

// EJERCICIO 9
bool esPeriodico(toroide const &t, int &p) {
    //pre: t muere o es Evolución ciclica
    toroide tAux = t;

    int pAux = 0;

    do {
        evolucionToroide(tAux);
        pAux++;
    } while (!toroideMuerto(tAux) && tAux != t);

    if (t == tAux) p = pAux;

    return t == tAux;
}

// EJERCICIO 10
bool primosLejanos(toroide const &t, toroide const &u) {
    bool resp = false;
    //pre: t muere o es Evolución ciclica; entonces el u tendria
    //que estar entre t y t (t -> u -> t)

    resp = EvolucionPrimosLejanos(t, u) || EvolucionPrimosLejanos(u, t);

    return resp;
}

// EJERCICIO 11
int seleccionNatural(vector<toroide> ts) {
    int resp = -1;
    vector<int> listaEnteros;
    int i, cantVivos = 0, indexSeleccion = 0;

    do {
        cantVivos = 0;
        for (i = 0; i < ts.size(); i++) {
            if (!toroideMuerto(ts[ts.size() - 1 - i])) {
                evolucionToroide(ts[ts.size() - 1 - i]);
                cantVivos++;
                indexSeleccion = ts.size() - 1 - i;
            }
        }
    } while (cantVivos > 1);

    // Implementacion
    return indexSeleccion;
}

// EJERCICIO 12
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out;
    out = t;
    int f, c;

    for (f = 0; f < filas(t); f++) {
        for (c = 0; c < columnas(t); c++) {
            if (t[f][c] && u[f][c]) out[f][c] = true;
            else out[f][c] = false;
        }
    }
    return out;
}

// EJERCICIO 13
bool vistaTrasladada(toroide const &t, toroide const &u) {
    //pre: misma dimension t y u
    bool resp = false;
    int cantVivasT = cantidadVivas(t);
    if (cantVivasT == cantidadVivas(u)) {
        if (cantVivasT == 1) resp = true;
        int i = 0, f = 0, c = 0, k = 0, l = 0;
        while (!resp && i < cantVivasT) {
            posiblesValoresTraslado(t, u, f, c, k, l);
            resp = esTraslado(t, u, k, l);
            i++;
        }
    }
    //else resp = false

    return resp;
}

// EJERCICIO 14
int menorSuperficieViva(toroide const &t) {
    int resp = -1;
    toroide auxT = t;

    int toroideAlturaMin = filas(t);
    for (int i = 0; i < filas(t); ++i) {
        int primerViva = primeraVivaDesde(auxT, "arriba");
        int ultimaViva = primeraVivaDesde(auxT, "abajo");
        int alturaToroide = ultimaViva - primerViva + 1;
        if (toroideAlturaMin > alturaToroide) {
            toroideAlturaMin = alturaToroide;
        }
        auxT = trasladarHaciaArriba(auxT);
    }

    int toroideAnchoMin = columnas(t);
    for (int i = 0; i < columnas(t); ++i) {
        int primerViva = primeraVivaDesde(auxT, "izquierda");
        int ultimaViva = primeraVivaDesde(auxT, "derecha");
        int anchoToroide = ultimaViva - primerViva + 1;
        if (toroideAnchoMin > anchoToroide) {
            toroideAnchoMin = anchoToroide;
        }
        auxT = trasladarHaciaDerecha(auxT);
    }

    resp = toroideAlturaMin * toroideAnchoMin;
    return resp;
}
