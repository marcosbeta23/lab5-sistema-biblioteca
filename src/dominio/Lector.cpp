#include "Lector.h"

Lector::Lector(std::string id, std::string nombre, std::string contrasena, std::string fechaRegistro)
    : Usuario(id, nombre, contrasena), fechaRegistro(fechaRegistro), prestamos() {}

Lector::~Lector() {}

std::string Lector::getFechaRegistro() const {
    return fechaRegistro;
}

void Lector::addPrestamo(Prestamo* prestamo) {
    prestamos.push_back(prestamo);
}

std::vector<Prestamo*> Lector::getPrestamos() const {
    return prestamos;
}

DtLector Lector::getDtLector() const {
    return DtLector(id, nombre, fechaRegistro);
}

std::string Lector::getTipoUsuario() const {
    return "Lector";
}
