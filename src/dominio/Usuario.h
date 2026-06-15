#pragma once
#include <string>

class Usuario {
protected:
    std::string id;
    std::string nombre;
    std::string contrasena;
    bool sesionActiva;

public:
    Usuario(std::string id, std::string nombre, std::string contrasena);
    virtual ~Usuario();

    std::string getId() const;
    std::string getNombre() const;

    bool validarContrasena(std::string contrasena) const;
    bool tieneSesionActiva() const;
    void setSesionActiva(bool activa);

    virtual std::string getTipoUsuario() const = 0;
};
