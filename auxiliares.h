//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"
#include <string>

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
//Generales
int filas(vector<vector<bool>> t);
int columnas(vector<vector<bool>> t);
bool debeVivir(toroide t, int f, int c);
int filaToroide(int f, toroide t);
int columnaToroide(int c, toroide t);
// Ejercicio 1
bool esToroide(vector<vector<bool>> t);
bool esRectangulo(vector<vector<bool>> r);
// Ejercicio 3
int cantidadVivas(toroide t);
// Ejercicio 4
int superficieTotal(toroide t);
// Ejercicio 5
int vecinosVivos(toroide t, int f0, int c0);
// Ejercicio 10
bool evolucionPrimosLejanos(toroide const &t1, toroide const &t2);
// Ejercicio 13
void valoresTraslados(vector<toroide>& ts, toroide t) ;
// Ejercicio 14
int primeraVivaDesde(toroide t, string inicio);
toroide trasladarHaciaArriba(toroide t);
toroide trasladarHaciaDerecha(toroide t);

#endif //REUNIONESREMOTAS_AUXILIARES_H
