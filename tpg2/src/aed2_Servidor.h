#ifndef AED2_SERVIDOR_H
#define AED2_SERVIDOR_H

#include "Tipos.h"
#include "Servidor.h"

class aed2_Servidor {
public:
    aed2_Servidor();

    void nuevaPartida(Jugador j, set<Nat> horizontales, set<Nat> verticales);

    void agregarCasa(Jugador j, Casilla c);

    void agregarComercio(Jugador j, Casilla c);

    void avanzarTurno(Jugador j);

    void unir(Jugador j1, Jugador j2);

    set<Nat> riosHorizontales(Jugador j) const;

    set<Nat> riosVerticales(Jugador j) const;

    set<Casilla> casas(Jugador j) const;

    set<Casilla> comercios(Jugador j) const;

    Nat nivel(Jugador j, Casilla c) const;

    bool huboConstruccion(Jugador j) const;

    Nat popularidad(Jugador j) const;

    Nat antiguedad(Jugador j) const;

private:
    Servidor _server;
};

#endif // AED2_SERVIDOR_H

