#pragma once
#include <string>

class DtMaterialResumen {
public:
    std::string codigo;
    std::string titulo;

    DtMaterialResumen();
    DtMaterialResumen(std::string codigo, std::string titulo);
};
