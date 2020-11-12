#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(esPeriodicoTEST, toroideHorizontalPeriodico2){
    toroide t = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2);
}

TEST(esPeriodicoTEST, toroidePeriodico){
    toroide t = {
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, false, true, false},
            {false, true, true, true, false},
            {false, false, false, false, false} };
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 20); //20 para volver a la posicion original
}

TEST(esPeriodicoTEST, toroideHorizontalMuere){
    vector<bool> a = { false, false, false, false };
    vector<bool> b = { true, false, false, false };
    toroide t = { a, b, b, a };

    int p = 0;

    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p, 1);
}
