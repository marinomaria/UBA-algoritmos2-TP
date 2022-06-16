#ifndef TP_SIMCITY_SIMCITY_H
#define TP_SIMCITY_SIMCITY_H

#include "Tipos.h"
#include "Mapa.h"
using namespace std;

class SimCity {
public:
    SimCity(Mapa m);

    void avanzarTurno();

    Mapa mapa() const;

    map<Casilla, Nat> casas() const;

    map<Casilla, Nat> comercios() const;

    // Hay comercio en p
    Nat nivelComercio(Casilla p) const;

    Nat nivelCasa(Casilla p) const;

    void unir(SimCity& s2);

    // Estas funciones no están en la especificación pero
    // son necesaria para la interfaz con aed2_servidor
    Nat popularidad() const;

    void agregarCasa(Casilla p);

    void agregarComercio(Casilla p);

    Nat antiguedad() const;

private:
    Nat _turnoActual;
    map<SimCity*, int> _uniones;
    map<Casilla, Nat> _casas;
    map<Casilla, Nat> _comercios;
    Mapa _mapa;
};

#endif //TP_SIMCITY_SIMCITY_H
