#include "DtPrestamo.h"

DtPrestamo::DtPrestamo()
    : codigoMaterial(""), tituloMaterial(""), fechaPrestamo(""), diasPermitidos(0) {}

DtPrestamo::DtPrestamo(std::string codigoMaterial, std::string tituloMaterial, std::string fechaPrestamo, int diasPermitidos)
    : codigoMaterial(codigoMaterial), tituloMaterial(tituloMaterial), fechaPrestamo(fechaPrestamo), diasPermitidos(diasPermitidos) {}
