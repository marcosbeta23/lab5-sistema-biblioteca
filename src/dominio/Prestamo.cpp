#include "Prestamo.h"
#include "Material.h"

Prestamo::Prestamo(std::string fechaPrestamo, int diasPermitidos)
    : fechaPrestamo(fechaPrestamo), diasPermitidos(diasPermitidos), lector(nullptr), material(nullptr), funcionario(nullptr) {}

Prestamo::~Prestamo() {}

void Prestamo::setLector(Lector* lector) {
    this->lector = lector;
}

void Prestamo::setMaterial(Material* material) {
    this->material = material;
}

void Prestamo::setFuncionario(Funcionario* funcionario) {
    this->funcionario = funcionario;
}

Lector* Prestamo::getLector() const {
    return lector;
}

Material* Prestamo::getMaterial() const {
    return material;
}

Funcionario* Prestamo::getFuncionario() const {
    return funcionario;
}

std::string Prestamo::getFechaPrestamo() const {
    return fechaPrestamo;
}

int Prestamo::getDiasPermitidos() const {
    return diasPermitidos;
}

DtPrestamo Prestamo::getDtPrestamo() const {
    if (material == nullptr) {
        return DtPrestamo("", "", fechaPrestamo, diasPermitidos);
    }

    return DtPrestamo(
        material->getCodigo(),
        material->getTitulo(),
        fechaPrestamo,
        diasPermitidos
    );
}
