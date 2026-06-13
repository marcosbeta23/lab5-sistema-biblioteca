#include "Revista.h"

Revista::Revista(std::string codigo, std::string titulo, int anioPublicacion, int nroEdicion, bool esMensual)
    : Material(codigo, titulo, anioPublicacion), nroEdicion(nroEdicion), esMensual(esMensual) {}

Revista::~Revista() {}

int Revista::getNroEdicion() const {
    return nroEdicion;
}

bool Revista::getEsMensual() const {
    return esMensual;
}

DtDatosEspecificos Revista::getDatosEspecificos() const {
    return DtDatosEspecificos(std::to_string(nroEdicion), esMensual ? "Si" : "No");
}

std::string Revista::getTipoMaterial() const {
    return "Revista";
}
