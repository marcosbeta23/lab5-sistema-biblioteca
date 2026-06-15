#pragma once
#include <string>

class IGestorSesion {
public:
    virtual ~IGestorSesion() {}

    virtual bool iniciarSesion(std::string id, std::string contrasena) = 0;
    virtual void cerrarSesion() = 0;
};
