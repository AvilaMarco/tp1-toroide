#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(posicionesVivasTEST, toroideDiagonalVivas){
    toroide t = { 
	{true, false, false},
	{false, true, false},
	{false, false, true},
	{true, false, false},
	{false, true, false},
	{false, false, true}};

    vector<posicion> vivas = {mp(0,0), mp(1,1), mp(2,2), mp(3, 0), mp(4, 1), mp(5, 2)};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

TEST(posicionesVivasTEST, toroidePosicionRepetido){
    toroide t = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};

    vector<posicion> vivas = {mp(0,0), mp(1,1), mp(2,2), mp(1, 1)};
    vector<posicion> res = posicionesVivas(t);
    //el res tendria que ser igual a vivas si le añado el (1,1)
    res.push_back(mp(1,1));
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

TEST(posicionesVivasTEST, todasMuertas){
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};

    vector<posicion> vivas = {};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

TEST(posicionesVivasTEST, vivasEnRangoToroide){
    toroide t = {
            {true, false, true},
            {false, false, false},
            {false, true, false}};

    vector<posicion> vivas = {};
    vector<posicion> res = posicionesVivas(t);

    if(cantidadVivas(t) == res.size()) {
        for (int i = 0; i < res.size(); i++) {
            if (enRangoToroide(res[i].first, res[i].second, t)
                && t[res[i].first][res[i].second])
                vivas.push_back(mp(res[i].first, res[i].second));
        }
    }

    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

