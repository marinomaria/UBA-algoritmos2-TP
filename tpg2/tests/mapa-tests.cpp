#include "gtest-1.8.1/gtest.h"
#include "../src/Mapa.h"

TEST(Mapa, crearMapa) {
    set<int> v = {1,2,3};
    set<int> h = {3,8,15};
    Mapa m = Mapa(v, h);

    EXPECT_TRUE(m.hayRio(Casilla(1,5)));
    EXPECT_TRUE(m.hayRio(Casilla(3,3)));
    EXPECT_TRUE(m.hayRio(Casilla(4,8)));
    EXPECT_FALSE(m.hayRio(Casilla(10,5)));
}

TEST(Mapa, unirMapa) {
    set<int> v1 = {1,2,3};
    set<int> h1 = {3,8,15};
    set<int> v2 = {4,8,3};
    set<int> h2 = {2,5,15};
    Mapa m1 = Mapa(v1, h1);
    Mapa m2 = Mapa(v2, h2);

    set<int> vUnion = {1,2,3,4,8};
    set<int> hUnion = {3,8,15,2,5};
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