#include "GestorSesion.h"
#include <stdexcept>

GestorSesion* GestorSesion::instancia = nullptr;

GestorSesion::GestorSesion()
    : gestorUsuarios(GestorUsuarios::getInstancia()) {}

GestorSesion* GestorSesion::getInstancia() {
    if (instancia == nullptr) {
        instancia = new GestorSesion();
    }

    return instancia;
}

GestorSesion::~GestorSesion() {}

bool GestorSesion::iniciarSesion(std::string id, std::string contrasena) {
    if (id.empty() || contrasena.empty()) {
        throw std::runtime_error("El id y la contrasena no pueden ser vacios.");
    }

    if (gestorUsuarios->findActivo() != nullptr) {
        throw std::runtime_error("Ya existe una sesion activa.");
    }

    Usuario* usuario = gestorUsuarios->find(id);

    if (usuario == nullptr) {
        return false;
    }

    if (!usuario->validarContrasena(contrasena)) {
        return false;
    }

    usuario->setSesionActiva(true);
    return true;
}

void GestorSesion::cerrarSesion() {
    Usuario* usuarioActivo = gestorUsuarios->findActivo();

    if (usuarioActivo == nullptr) {
        throw std::runtime_error("No existe una sesion activa.");
    }

    usuarioActivo->setSesionActiva(false);
}
