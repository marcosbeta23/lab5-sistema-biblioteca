#pragma once
#include <string>
#include "DtDatosEspecificos.h"

class DtMaterialDetalle {
public:
    std::string codigo;
    std::string titulo;
    int anioPublicacion;
    std::string tipo;
    float puntajePromedio;
    DtDatosEspecificos datosEspecificos;

    DtMaterialDetalle();
    DtMaterialDetalle(
        std::string codigo,
        std::string titulo,
        int anioPublicacion,
        std::string tipo,
        float puntajePromedio,
        DtDatosEspecificos datosEspecificos
    );
};
