#pragma once

#include "../interfaces/IGestorSesion.h"
#include "GestorUsuarios.h"

class GestorSesion : public IGestorSesion {
private:
    static GestorSesion* instancia;

    GestorUsuarios* gestorUsuarios;

    GestorSesion();

public:
    static GestorSesion* getInstancia();

    ~GestorSesion();

    bool iniciarSesion(std::string id, std::string contrasena) override;
    void cerrarSesion() override;
};
