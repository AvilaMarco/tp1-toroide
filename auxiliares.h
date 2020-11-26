//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"
#include <string>

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
bool esToroide(vector<vector<bool>> t);
//borrar eventualmente
bool enRangoToroide(int f, int c, vector<vector<bool>> t);
int cantidadVivas(toroide t);
int superficieTotal(toroide t);

int vecinosVivos(toroide t, int f0, int c0);
int filas(vector<vector<bool>> t);
int columnas(vector<vector<bool>> t);
bool debeVivir(toroide t, int f, int c);

bool todosValidos(vector<toroide> ts);
bool sonTicksConsecutivos(vector<toroide> ts);

bool EvolucionPrimosLejanos(toroide const &t1, toroide const &t2);

void valoresTraslado(vector<toroide>& ts, toroide t) ;
bool esTraslado(toroide t, toroide u, int k, int l);

//ejercicio 14
int primeraVivaDesde(toroide t, string inicio);
toroide trasladarHaciaArriba(toroide t);
toroide trasladarHaciaDerecha(toroide t);

#endif //REUNIONESREMOTAS_AUXILIARES_H
