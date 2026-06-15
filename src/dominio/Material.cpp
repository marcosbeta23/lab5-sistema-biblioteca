#include "Material.h"
#include "Puntaje.h"

Material::Material(std::string codigo, std::string titulo, int anioPublicacion)
    : codigo(codigo), titulo(titulo), anioPublicacion(anioPublicacion), registradoPor(nullptr), puntajes() {}

Material::~Material() {}

std::string Material::getCodigo() const {
    return codigo;
}

std::string Material::getTitulo() const {
    return titulo;
}

int Material::getAnioPublicacion() const {
    return anioPublicacion;
}

void Material::setRegistrador(Funcionario* funcionario) {
    registradoPor = funcionario;
}

Funcionario* Material::getRegistrador() const {
    return registradoPor;
}

void Material::addPuntaje(Puntaje* puntaje) {
    puntajes.push_back(puntaje);
}

float Material::calcularPuntajePromedio() const {
    if (puntajes.empty()) {
        return 0;
    }

    int suma = 0;
    for (Puntaje* puntaje : puntajes) {
        suma += puntaje->getValor();
    }

    return static_cast<float>(suma) / puntajes.size();
}

DtMaterialResumen Material::getDtResumen() const {
    return DtMaterialResumen(codigo, titulo);
}

DtMaterialDetalle Material::getDtDetalle() const {
    return DtMaterialDetalle(
        codigo,
        titulo,
        anioPublicacion,
        getTipoMaterial(),
        calcularPuntajePromedio(),
        getDatosEspecificos()
    );
}
