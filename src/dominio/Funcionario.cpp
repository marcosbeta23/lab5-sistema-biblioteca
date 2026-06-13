#include "Funcionario.h"

Funcionario::Funcionario(std::string id, std::string nombre, std::string contrasena, int nroEmpleado)
    : Usuario(id, nombre, contrasena), nroEmpleado(nroEmpleado) {}

Funcionario::~Funcionario() {}

int Funcionario::getNroEmpleado() const {
    return nroEmpleado;
}

DtFuncionario Funcionario::getDtFuncionario() const {
    return DtFuncionario(id, nombre, nroEmpleado);
}

std::string Funcionario::getTipoUsuario() const {
    return "Funcionario";
}
