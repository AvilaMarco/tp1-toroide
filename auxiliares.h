//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
bool esToroide(vector<vector<bool>> t);
bool enRangoToroide(int f, int c, vector<vector<bool>> t);
int cantidadVivas(toroide t);
int superficieTotal(toroide t);

int vecinosVivos(toroide t, int j, int c);

bool debeVivir(toroide t, int f, int c);

bool esEvolucionToroide(toroide tf, toroide ti);
bool todosValidos(vector<toroide> ts);
bool sonTicksConsecutivos(vector<toroide> ts);
bool esEvolucionNivelK(toroide tf, toroide ti, int k);

bool EvolucionPrimosLejanos(toroide const &t1, toroide const &t2);

void posiblesValoresTraslado(toroide t, toroide u, int& f, int& c, int& k, int& l);
bool esTraslado(toroide t, toroide u, int k, int l);

#endif //REUNIONESREMOTAS_AUXILIARES_H
