#include "DatosPrueba.h"

#include <stdexcept>

#include "../controladores/GestorUsuarios.h"
#include "../controladores/GestorMateriales.h"
#include "../controladores/GestorPrestamos.h"
#include "../dominio/Funcionario.h"
#include "../dominio/Lector.h"
#include "../dominio/Libro.h"
#include "../dominio/Revista.h"
#include "../dominio/Prestamo.h"
#include "../utils/RelojSistema.h"

bool DatosPrueba::cargados = false;

void DatosPrueba::cargarDatosPrueba() {
    if (cargados) {
        throw std::runtime_error("Los datos de prueba ya fueron cargados.");
    }

    GestorUsuarios* gestorUsuarios = GestorUsuarios::getInstancia();
    GestorMateriales* gestorMateriales = GestorMateriales::getInstancia();
    GestorPrestamos* gestorPrestamos = GestorPrestamos::getInstancia();
    RelojSistema* reloj = RelojSistema::getInstancia();

    reloj->modificarFecha(13, 6, 2026, 10, 30);

    Funcionario* admin = new Funcionario(
        "admin",
        "Administrador",
        "admin",
        1
    );

    Lector* lector1 = new Lector(
        "lec1",
        "Lector Uno",
        "1234",
        "01/06/2026"
    );

    Lector* lector2 = new Lector(
        "lec2",
        "Lector Dos",
        "1234",
        "05/06/2026"
    );

    gestorUsuarios->addUsuario(admin);
    gestorUsuarios->addUsuario(lector1);
    gestorUsuarios->addUsuario(lector2);

    Libro* libro1 = new Libro(
        "LIB1",
        "Libro de prueba",
        2020,
        "Autor Uno",
        120
    );

    Revista* revista1 = new Revista(
        "REV1",
        "Revista de prueba",
        2024,
        3,
        true
    );

    libro1->setRegistrador(admin);
    revista1->setRegistrador(admin);

    gestorMateriales->addMaterial(libro1);
    gestorMateriales->addMaterial(revista1);

    Prestamo* prestamo1 = new Prestamo(
        reloj->consultarFecha(),
        7
    );

    prestamo1->setLector(lector1);
    prestamo1->setMaterial(libro1);
    prestamo1->setFuncionario(admin);

    lector1->addPrestamo(prestamo1);
    gestorPrestamos->addPrestamo(prestamo1);

    cargados = true;
}
