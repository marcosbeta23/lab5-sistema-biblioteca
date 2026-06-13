#include "Usuario.h"

Usuario::Usuario(std::string id, std::string nombre, std::string contrasena)
    : id(id), nombre(nombre), contrasena(contrasena), sesionActiva(false) {}

Usuario::~Usuario() {}

std::string Usuario::getId() const {
    return id;
}

std::string Usuario::getNombre() const {
    return nombre;
}

bool Usuario::validarContrasena(std::string contrasena) const {
    return this->contrasena == contrasena;
}

bool Usuario::tieneSesionActiva() const {
    return sesionActiva;
}

void Usuario::setSesionActiva(bool activa) {
    sesionActiva = activa;
}
