#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(menorSuperficieVivaTEST, enunciado){
    toroide t = {
            {true, false, false, true},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {true, true, false, false}};  // 4
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

TEST(menorSuperficieVivaTEST, menorSuperficieUnoVivo){
    toroide t = {
            {false, false, false, false},   // 1
            {false, false, false, false}, // 2
            {false, false, true, false}, // 3
            {false, false, false, false}};  // 4
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 1);
}

TEST(menorSuperficieVivaTEST, toroideCuadradoTresVivas){
    toroide t = {
            {true, false, false, false},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {true, false, false, true}};  // 4
    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 4);
}

TEST(menorSuperficieVivaTEST, noCuadrado){
    toroide t = {
            {false, false, false, false},   // 1
            {false, true, false, false}, // 2
            {false, false, false, true}, // 3
            {true, true, false, false}, //4
            {true, true, false, false}};  // 5

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 12);
}
