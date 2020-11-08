#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(toroideMuertoTEST, toroideDiagonalVivas){
    toroide t = {
            {true, false, false},
            {false, true, false},
            {false, false, true},
            {true, false, false},
            {false, true, false},
            {false, false, true}};

    EXPECT_FALSE(toroideMuerto(t));
}

TEST(toroideMuertoTEST, toroidePrimeraViva){
    toroide t = {
            {true, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false}};

    EXPECT_FALSE(toroideMuerto(t));
}

TEST(toroideMuertoTEST, toroideTodosMuertos){
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false}};

    EXPECT_TRUE(toroideMuerto(t));
}
