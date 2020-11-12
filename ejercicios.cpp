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
    int f,c =0;
    for(f=0; f<t.size(); f++){
        for(c=0; c<t[0].size(); c++){
            if(enRangoToroide(f,c,t) && !(t[f][c] == false)){
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
    for(int i=0; i<t.size(); i++){
        for(int j=0; j<t[i].size(); j++){
            if(t[i][j]) {
                vAux.first = i;
                vAux.second = j;
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
    resp = (cantidadVivas(t)/superficieTotal(t)); //superficieTotal != 0
    return resp;
}

// EJERCICIO 5
int cantidadVecinosVivos(toroide const &t, int f, int c) {
    int resp = vecinosVivos(t,f,c);
    return resp;
}

// EJERCICIO 6
bool evolucionDePosicion(toroide const &t, posicion x) {
	bool resp = debeVivir(t, get<0>(x), get<1>(x));
    return resp;
}

// EJERCICIO 7
void evolucionToroide(toroide &t){
    toroide tAux = t;
    for(int i=0; i<t.size(); i++) {
        for (int j = 0; j < t[i].size(); j++) {
            tAux[i][j] = debeVivir(t,i,j);
        }
    }
    t=tAux;
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

    p=0;

    while(!toroideMuerto(tAux)){
        evolucionToroide(tAux);
        p++;

        if(tAux == t) return true;
    }

    return false;
}

// EJERCICIO 10
bool primosLejanos(toroide const &t, toroide const &u) {
	bool resp = false;
    // Implementacion
    return resp;
}

// EJERCICIO 11
int seleccionNatural(vector <toroide> ts) {
    int resp = -1;
	// Implementacion
    return resp;
}

// EJERCICIO 12
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out;
    // Implementacion
    return out;
}

// EJERCICIO 13
bool vistaTrasladada(toroide const &t, toroide const &u){
	bool resp = false;
    // Implementacion
    return resp;
}

// EJERCICIO 14
int menorSuperficieViva(toroide const &t){
	int resp = -1;
	// Implementacion
	return resp;
}
