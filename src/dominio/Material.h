#pragma once
#include <string>
#include <vector>
#include "../datatypes/DtDatosEspecificos.h"
#include "../datatypes/DtMaterialResumen.h"
#include "../datatypes/DtMaterialDetalle.h"

class Puntaje;
class Funcionario;

class Material {
protected:
    std::string codigo;
    std::string titulo;
    int anioPublicacion;
    Funcionario* registradoPor;
    std::vector<Puntaje*> puntajes;

public:
    Material(std::string codigo, std::string titulo, int anioPublicacion);
    virtual ~Material();

    std::string getCodigo() const;
    std::string getTitulo() const;
    int getAnioPublicacion() const;

    void setRegistrador(Funcionario* funcionario);
    Funcionario* getRegistrador() const;

    void addPuntaje(Puntaje* puntaje);
    float calcularPuntajePromedio() const;

    DtMaterialResumen getDtResumen() const;
    DtMaterialDetalle getDtDetalle() const;

    virtual DtDatosEspecificos getDatosEspecificos() const = 0;
    virtual std::string getTipoMaterial() const = 0;
};
