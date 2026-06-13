#pragma once

#include <list>
#include <string>

#include "../interfaces/IGestorPrestamos.h"
#include "../dominio/Prestamo.h"
#include "../dominio/Lector.h"
#include "../dominio/Material.h"
#include "../dominio/Funcionario.h"

#include "GestorUsuarios.h"
#include "GestorMateriales.h"

class GestorPrestamos : public IGestorPrestamos {
private:
    static GestorPrestamos* instancia;

    std::list<Prestamo*> prestamos;

    GestorUsuarios* gestorUsuarios;
    GestorMateriales* gestorMateriales;

    Lector* tempLector;
    Material* tempMaterial;
    std::string tempFechaPrestamo;
    int tempDiasPermitidos;
    bool datosPrestamoValidos;

    Lector* tempLectorConsulta;

    GestorPrestamos();

public:
    static GestorPrestamos* getInstancia();

    ~GestorPrestamos();

    DtLector ingresarIdLector(std::string id) override;
    DtMaterialResumen ingresarCodigoMaterial(std::string codigo) override;

    void ingresarDatosPrestamo(
        std::string fechaPrestamo,
        int diasPermitidos
    ) override;

    void confirmarRegistroPrestamo() override;

    DtPrestamosLector ingresarIdLectorConsulta(std::string id) override;
    DtPrestamosLector consultarPrestamosLector() override;

    void addPrestamo(Prestamo* prestamo);
};
