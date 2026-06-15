#pragma once
#include <string>
#include "Material.h"

class Revista : public Material {
private:
    int nroEdicion;
    bool esMensual;

public:
    Revista(std::string codigo, std::string titulo, int anioPublicacion, int nroEdicion, bool esMensual);
    ~Revista();

    int getNroEdicion() const;
    bool getEsMensual() const;

    DtDatosEspecificos getDatosEspecificos() const override;
    std::string getTipoMaterial() const override;
};
