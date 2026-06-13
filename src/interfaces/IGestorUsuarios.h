#pragma once
#include <string>
#include "../datatypes/DtLector.h"
#include "../datatypes/DtFuncionario.h"

class IGestorUsuarios {
public:
    virtual ~IGestorUsuarios() {}

    virtual DtLector ingresarDatosLector(
        std::string id,
        std::string nombre,
        std::string contrasena,
        std::string fechaRegistro
    ) = 0;

    virtual void confirmarRegistroLector() = 0;

    virtual DtFuncionario ingresarDatosFuncionario(
        std::string id,
        std::string nombre,
        std::string contrasena,
        int nroEmpleado
    ) = 0;

    virtual void confirmarRegistroFuncionario() = 0;
};
