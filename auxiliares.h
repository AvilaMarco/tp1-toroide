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

bool debeVivir(toroide t, int j, int c);
#endif //REUNIONESREMOTAS_AUXILIARES_H
