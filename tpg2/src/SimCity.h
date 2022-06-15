#ifndef TP_SIMCITY_SIMCITY_H
#define TP_SIMCITY_SIMCITY_H

#include "Tipos.h"
#include "Mapa.h"
using namespace std;

class SimCity {
public:
    SimCity(Mapa m);

    void avanzarTurno();

    Mapa mapa();

    map<Casilla, Nat> casas();

    map<Casilla, Nat> comercios();

    Nat nivelComercio(Casilla p);

    Nat nivelCasa(Casilla p);

    void unir(SimCity s2);

    // Estas funciones no están en la especificación pero
    // son necesaria para la interfaz con aed2_servidor
    Nat popularidad();

    void agregarCasa(Casilla p);

    void agregarComercio(Casilla p);

    Nat antiguedad();

private:
    vector<SimCity*> _uniones;
    Nat _turnoActual;
    map<Casilla, Nat> _casas;
    map<Casilla, Nat> _comercios;
    Mapa _mapa;

};

#endif //TP_SIMCITY_SIMCITY_H
