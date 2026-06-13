#pragma once
#include <string>

class DtLector {
public:
    std::string id;
    std::string nombre;
    std::string fechaRegistro;

    DtLector();
    DtLector(std::string id, std::string nombre, std::string fechaRegistro);
};
