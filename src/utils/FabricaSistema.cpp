#include "FabricaSistema.h"
#include "../controladores/GestorSesion.h"
#include "../controladores/GestorUsuarios.h"
#include "../controladores/GestorMateriales.h"
#include "../controladores/GestorPrestamos.h"

FabricaSistema* FabricaSistema::instancia = nullptr;

FabricaSistema::FabricaSistema() {}

FabricaSistema* FabricaSistema::getInstancia() {
    if (instancia == nullptr) {
        instancia = new FabricaSistema();
    }

    return instancia;
}

IGestorSesion* FabricaSistema::getIGestorSesion() {
    return GestorSesion::getInstancia();
}

IGestorUsuarios* FabricaSistema::getIGestorUsuarios() {
    return GestorUsuarios::getInstancia();
}

IGestorMateriales* FabricaSistema::getIGestorMateriales() {
    return GestorMateriales::getInstancia();
}

IGestorPrestamos* FabricaSistema::getIGestorPrestamos() {
    return GestorPrestamos::getInstancia();
}
