#include "DtFuncionario.h"

DtFuncionario::DtFuncionario()
    : id(""), nombre(""), nroEmpleado(0) {}

DtFuncionario::DtFuncionario(std::string id, std::string nombre, int nroEmpleado)
    : id(id), nombre(nombre), nroEmpleado(nroEmpleado) {}
