#include "gtest-1.8.1/gtest.h"
#include "../src/mapa.h"

TEST(mapa, crearMapa) {
    set<Nat> v = {1,2,3};
    set<Nat> h = {3,8,15};
    mapa m = mapa(v,h);

    EXPECT_TRUE(m.hayRio(Casilla(1,5)));
    EXPECT_TRUE(m.hayRio(Casilla(3,3)));
    EXPECT_TRUE(m.hayRio(Casilla(4,8)));
    EXPECT_FALSE(m.hayRio(Casilla(10,5)));
}

TEST(mapa, unirMapa) {
    set<Nat> v1 = {1,2,3};
    set<Nat> h1 = {3,8,15};
    set<Nat> v2 = {4,8,3};
    set<Nat> h2 = {2,5,15};
    mapa m1 = mapa(v1,h1);
    mapa m2 = mapa(v2, h2);

    set<Nat> vUnion = {1,2,3,4,8};
    set<Nat> hUnion = {3,8,15,2,5};
    m1.unirMapa(m2);

    set<Casilla> hayRio = {Casilla(1,1), Casilla(4,5), Casilla(3,3)};
    set<Casilla> noHayRio = {Casilla(0,1), Casilla(10,9), Casilla(5,7)};

    for (Casilla c : hayRio) {
        EXPECT_TRUE(m1.hayRio(c));
    }

    for (Casilla c : noHayRio) {
        EXPECT_FALSE(m1.hayRio(c));
    }
}