#pragma once
#include <string>

class DtFuncionario {
public:
    std::string id;
    std::string nombre;
    int nroEmpleado;

    DtFuncionario();
    DtFuncionario(std::string id, std::string nombre, int nroEmpleado);
};
