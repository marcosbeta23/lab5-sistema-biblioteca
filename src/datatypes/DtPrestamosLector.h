#pragma once
#include <string>
#include <vector>
#include "DtPrestamo.h"

class DtPrestamosLector {
public:
    std::string idLector;
    std::string nombreLector;
    std::vector<DtPrestamo> prestamos;

    DtPrestamosLector();
    DtPrestamosLector(std::string idLector, std::string nombreLector, std::vector<DtPrestamo> prestamos);
};
