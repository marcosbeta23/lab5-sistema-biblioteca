#include "FabricaSistema.h"

FabricaSistema* FabricaSistema::instancia = nullptr;

FabricaSistema::FabricaSistema() {}

FabricaSistema* FabricaSistema::getInstancia() {
    if (instancia == nullptr) {
        instancia = new FabricaSistema();
    }

    return instancia;
}

/*
    Estos métodos se completan cuando implementemos los controladores concretos:

    - GestorSesion
    - GestorUsuarios
    - GestorMateriales
    - GestorPrestamos

    Por ahora retornan nullptr para dejar definida la estructura de la fábrica
    sin acoplarla todavía a clases que aún no existen.
*/

IGestorSesion* FabricaSistema::getIGestorSesion() {
    return nullptr;
}

IGestorUsuarios* FabricaSistema::getIGestorUsuarios() {
    return nullptr;
}

IGestorMateriales* FabricaSistema::getIGestorMateriales() {
    return nullptr;
}

IGestorPrestamos* FabricaSistema::getIGestorPrestamos() {
    return nullptr;
}
