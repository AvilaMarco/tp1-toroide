#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(cantidadVecinosVivosTEST, seisVivos){
    toroide t = {
            {true, false, false, false},
            {false, false, true, true},
            {false, false, false, false},
            {true, false, true, true}};

    EXPECT_EQ(cantidadVecinosVivos(t, 0, 3), 6);
}

TEST(cantidadVecinosVivosTEST, ningunVecinoVivo){
    toroide t = {
            {false, false, false, false},
            {false, false, false, true},
            {false, false, false, false},
            {true, false, true, true}};

    EXPECT_EQ(cantidadVecinosVivos(t, 1, 1), 0);
}

TEST(cantidadVecinosVivosTEST, toroideDiagonalTresVivas){
    toroide t = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};


    EXPECT_EQ(cantidadVecinosVivos(t, 1, 1), 2);
    EXPECT_EQ(cantidadVecinosVivos(t, 2, 0), 3);
}