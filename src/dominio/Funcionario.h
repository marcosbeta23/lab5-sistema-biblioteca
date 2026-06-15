#pragma once
#include <string>
#include "Usuario.h"
#include "../datatypes/DtFuncionario.h"

class Funcionario : public Usuario {
private:
    int nroEmpleado;

public:
    Funcionario(std::string id, std::string nombre, std::string contrasena, int nroEmpleado);
    ~Funcionario();

    int getNroEmpleado() const;
    DtFuncionario getDtFuncionario() const;
    std::string getTipoUsuario() const override;
};
