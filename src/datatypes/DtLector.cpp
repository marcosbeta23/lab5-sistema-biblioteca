#include "DtLector.h"

DtLector::DtLector()
    : id(""), nombre(""), fechaRegistro("") {}

DtLector::DtLector(std::string id, std::string nombre, std::string fechaRegistro)
    : id(id), nombre(nombre), fechaRegistro(fechaRegistro) {}
