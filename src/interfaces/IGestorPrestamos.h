#pragma once
#include <string>
#include "../datatypes/DtLector.h"
#include "../datatypes/DtMaterialResumen.h"
#include "../datatypes/DtPrestamosLector.h"

class IGestorPrestamos {
public:
    virtual ~IGestorPrestamos() {}

    virtual DtLector ingresarIdLector(std::string id) = 0;
    virtual DtMaterialResumen ingresarCodigoMaterial(std::string codigo) = 0;

    virtual void ingresarDatosPrestamo(
        std::string fechaPrestamo,
        int diasPermitidos
    ) = 0;

    virtual void confirmarRegistroPrestamo() = 0;

    virtual DtPrestamosLector ingresarIdLectorConsulta(std::string id) = 0;
    virtual DtPrestamosLector consultarPrestamosLector() = 0;
};
