#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(densidadPoblacionTEST, toroideDiagonal){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}

TEST(densidadPoblacionTEST, toroideUnaViva){
    vector<bool> a = { false, false, false, false };
    vector<bool> b = { true, false, false, false };
    toroide t = { a, b, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1/20, 0.001);
}

TEST(densidadPoblacionTEST, toroideDiezPorDiez){
    vector<bool> a = { false, false, false, false, false, false, false, false, false, false };
    vector<bool> b = { true, false, false, false, true, false, true, false, false, true }; //=4
    toroide t = { a, b, a, a , b, a , b , b, b, a }; // b*5 , 10*10
    EXPECT_NEAR(densidadPoblacion(t), 1/5, 0.001);
}

TEST(densidadPoblacionTEST, toroideMuerto){
    vector<bool> a = { false, false, false, false };
    toroide t = { a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 0, 0.01);
}