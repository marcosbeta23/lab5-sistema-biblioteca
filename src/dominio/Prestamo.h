#pragma once
#include <string>
#include "../datatypes/DtPrestamo.h"

class Lector;
class Material;
class Funcionario;

class Prestamo {
private:
    std::string fechaPrestamo;
    int diasPermitidos;
    Lector* lector;
    Material* material;
    Funcionario* funcionario;

public:
    Prestamo(std::string fechaPrestamo, int diasPermitidos);
    ~Prestamo();

    void setLector(Lector* lector);
    void setMaterial(Material* material);
    void setFuncionario(Funcionario* funcionario);

    Lector* getLector() const;
    Material* getMaterial() const;
    Funcionario* getFuncionario() const;

    std::string getFechaPrestamo() const;
    int getDiasPermitidos() const;

    DtPrestamo getDtPrestamo() const;
};
