#pragma once
#include <string>
#include <vector>
#include "Usuario.h"
#include "../datatypes/DtLector.h"

class Prestamo;

class Lector : public Usuario {
private:
    std::string fechaRegistro;
    std::vector<Prestamo*> prestamos;

public:
    Lector(std::string id, std::string nombre, std::string contrasena, std::string fechaRegistro);
    ~Lector();

    std::string getFechaRegistro() const;
    void addPrestamo(Prestamo* prestamo);
    std::vector<Prestamo*> getPrestamos() const;

    DtLector getDtLector() const;
    std::string getTipoUsuario() const override;
};
