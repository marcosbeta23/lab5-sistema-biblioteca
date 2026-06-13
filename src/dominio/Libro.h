#pragma once
#include <string>
#include "Material.h"

class Libro : public Material {
private:
    std::string autor;
    int cantPaginas;

public:
    Libro(std::string codigo, std::string titulo, int anioPublicacion, std::string autor, int cantPaginas);
    ~Libro();

    std::string getAutor() const;
    int getCantPaginas() const;

    DtDatosEspecificos getDatosEspecificos() const override;
    std::string getTipoMaterial() const override;
};
