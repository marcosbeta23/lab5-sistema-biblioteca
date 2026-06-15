#pragma once
#include <string>

class DtPrestamo {
public:
    std::string codigoMaterial;
    std::string tituloMaterial;
    std::string fechaPrestamo;
    int diasPermitidos;

    DtPrestamo();
    DtPrestamo(std::string codigoMaterial, std::string tituloMaterial, std::string fechaPrestamo, int diasPermitidos);
};
