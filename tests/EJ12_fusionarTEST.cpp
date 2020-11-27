#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(fusionarTEST, sinInterseccion){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, true, true},
                  {true, false, true},
                  {true, true, false}};

    toroide tout = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, mismoToroide){
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t2 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};

    toroide tout = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, interseccionConTodasVivas){
    toroide t1 = {
            {true, false, false,false},
            {false, true, false, false},
            {false, false, true, false},
            {false, false, true, true}};

    toroide t2 = {
            {true, true, true, true},
            {true, true, true, true},
            {true, true, true,true},
            {true, true, true,true}};

    toroide tout = {
            {true, false, false,false},
            {false, true, false, false},
            {false, false, true, false},
            {false, false, true, true}};

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}

TEST(fusionarTEST, interseccionNoCuadrados){
    toroide t1 = {
            {true, true, false},
            {false, true, false},
            {true, true, true},
            {true, true, false},
            {false, true, true}};
    toroide t2 = {
            {false, true, true},
            {true, true, true},
            {true, true, true},
            {false, true, true},
            {true, true, false}};

    toroide tout = {
            {false, true, false},
            {false, true, false},
            {true, true, true},
            {false, true, false},
            {false, true, false}};

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}