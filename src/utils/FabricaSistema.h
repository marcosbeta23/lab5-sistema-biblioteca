#pragma once

#include "../interfaces/IGestorSesion.h"
#include "../interfaces/IGestorUsuarios.h"
#include "../interfaces/IGestorMateriales.h"
#include "../interfaces/IGestorPrestamos.h"

class FabricaSistema {
private:
    static FabricaSistema* instancia;

    FabricaSistema();

public:
    static FabricaSistema* getInstancia();

    IGestorSesion* getIGestorSesion();
    IGestorUsuarios* getIGestorUsuarios();
    IGestorMateriales* getIGestorMateriales();
    IGestorPrestamos* getIGestorPrestamos();
};
