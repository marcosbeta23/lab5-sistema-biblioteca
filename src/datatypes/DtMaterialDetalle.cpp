#include "DtMaterialDetalle.h"

DtMaterialDetalle::DtMaterialDetalle()
    : codigo(""), titulo(""), anioPublicacion(0), tipo(""), puntajePromedio(0), datosEspecificos() {}

DtMaterialDetalle::DtMaterialDetalle(
    std::string codigo,
    std::string titulo,
    int anioPublicacion,
    std::string tipo,
    float puntajePromedio,
    DtDatosEspecificos datosEspecificos
) : codigo(codigo),
    titulo(titulo),
    anioPublicacion(anioPublicacion),
    tipo(tipo),
    puntajePromedio(puntajePromedio),
    datosEspecificos(datosEspecificos) {}
