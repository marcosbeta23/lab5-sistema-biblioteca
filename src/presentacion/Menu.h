#pragma once

#include "../interfaces/IGestorSesion.h"
#include "../interfaces/IGestorUsuarios.h"
#include "../interfaces/IGestorMateriales.h"
#include "../interfaces/IGestorPrestamos.h"
#include "../utils/RelojSistema.h"

class Menu {
private:
    IGestorSesion* gestorSesion;
    IGestorUsuarios* gestorUsuarios;
    IGestorMateriales* gestorMateriales;
    IGestorPrestamos* gestorPrestamos;
    RelojSistema* relojSistema;

    void mostrarOpciones() const;

    void opcionIniciarSesion();
    void opcionCerrarSesion();
    void opcionRegistrarLector();
    void opcionRegistrarFuncionario();
    void opcionRegistrarMaterial();
    void opcionRegistrarPrestamo();
    void opcionConsultarPrestamosLector();
    void opcionVerInformacionMaterial();
    void opcionModificarFechaSistema();
    void opcionConsultarFechaSistema();
    void opcionCargarDatosPrueba();

    void pausar() const;

public:
    Menu();
    void ejecutar();
};
