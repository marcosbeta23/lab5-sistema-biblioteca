#include "Puntaje.h"

Puntaje::Puntaje(int valor, Lector* lector, Material* material)
    : valor(valor), lector(lector), material(material) {}

Puntaje::~Puntaje() {}

int Puntaje::getValor() const {
    return valor;
}

Lector* Puntaje::getLector() const {
    return lector;
}

Material* Puntaje::getMaterial() const {
    return material;
}
