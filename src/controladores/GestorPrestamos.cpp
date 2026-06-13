#include "GestorPrestamos.h"
#include <stdexcept>
#include <vector>

GestorPrestamos* GestorPrestamos::instancia = nullptr;

GestorPrestamos::GestorPrestamos()
    : prestamos(),
      gestorUsuarios(GestorUsuarios::getInstancia()),
      gestorMateriales(GestorMateriales::getInstancia()),
      tempLector(nullptr),
      tempMaterial(nullptr),
      tempFechaPrestamo(""),
      tempDiasPermitidos(0),
      datosPrestamoValidos(false),
      tempLectorConsulta(nullptr) {}

GestorPrestamos* GestorPrestamos::getInstancia() {
    if (instancia == nullptr) {
        instancia = new GestorPrestamos();
    }

    return instancia;
}

GestorPrestamos::~GestorPrestamos() {
    for (Prestamo* prestamo : prestamos) {
        delete prestamo;
    }
}

DtLector GestorPrestamos::ingresarIdLector(std::string id) {
    if (gestorUsuarios->getFuncionarioActivo() == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (id.empty()) {
        throw std::runtime_error("El id del lector no puede ser vacio.");
    }

    Lector* lector = gestorUsuarios->findLector(id);

    if (lector == nullptr) {
        throw std::runtime_error("No existe un lector con ese id.");
    }

    tempLector = lector;
    tempMaterial = nullptr;
    tempFechaPrestamo = "";
    tempDiasPermitidos = 0;
    datosPrestamoValidos = false;

    return lector->getDtLector();
}

DtMaterialResumen GestorPrestamos::ingresarCodigoMaterial(std::string codigo) {
    if (gestorUsuarios->getFuncionarioActivo() == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (tempLector == nullptr) {
        throw std::runtime_error("Primero debe ingresar un lector valido.");
    }

    if (codigo.empty()) {
        throw std::runtime_error("El codigo del material no puede ser vacio.");
    }

    Material* material = gestorMateriales->findMaterial(codigo);

    if (material == nullptr) {
        throw std::runtime_error("No existe un material con ese codigo.");
    }

    tempMaterial = material;

    return material->getDtResumen();
}

void GestorPrestamos::ingresarDatosPrestamo(
    std::string fechaPrestamo,
    int diasPermitidos
) {
    if (gestorUsuarios->getFuncionarioActivo() == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (tempLector == nullptr) {
        throw std::runtime_error("Primero debe ingresar un lector valido.");
    }

    if (tempMaterial == nullptr) {
        throw std::runtime_error("Primero debe ingresar un material valido.");
    }

    if (fechaPrestamo.empty()) {
        throw std::runtime_error("La fecha del prestamo no puede ser vacia.");
    }

    if (diasPermitidos <= 0) {
        throw std::runtime_error("Los dias permitidos deben ser mayores que cero.");
    }

    tempFechaPrestamo = fechaPrestamo;
    tempDiasPermitidos = diasPermitidos;
    datosPrestamoValidos = true;
}

void GestorPrestamos::confirmarRegistroPrestamo() {
    Funcionario* funcionarioActivo = gestorUsuarios->getFuncionarioActivo();

    if (funcionarioActivo == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (tempLector == nullptr || tempMaterial == nullptr || !datosPrestamoValidos) {
        throw std::runtime_error("No existen datos completos de prestamo para confirmar.");
    }

    Prestamo* prestamo = new Prestamo(tempFechaPrestamo, tempDiasPermitidos);

    prestamo->setLector(tempLector);
    prestamo->setMaterial(tempMaterial);
    prestamo->setFuncionario(funcionarioActivo);

    prestamos.push_back(prestamo);
    tempLector->addPrestamo(prestamo);

    tempLector = nullptr;
    tempMaterial = nullptr;
    tempFechaPrestamo = "";
    tempDiasPermitidos = 0;
    datosPrestamoValidos = false;
}

DtPrestamosLector GestorPrestamos::ingresarIdLectorConsulta(std::string id) {
    if (gestorUsuarios->getFuncionarioActivo() == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (id.empty()) {
        throw std::runtime_error("El id del lector no puede ser vacio.");
    }

    Lector* lector = gestorUsuarios->findLector(id);

    if (lector == nullptr) {
        throw std::runtime_error("No existe un lector con ese id.");
    }

    tempLectorConsulta = lector;

    std::vector<DtPrestamo> prestamosLector;
    std::vector<Prestamo*> prestamosDominio = lector->getPrestamos();

    for (Prestamo* prestamo : prestamosDominio) {
        prestamosLector.push_back(prestamo->getDtPrestamo());
    }

    return DtPrestamosLector(
        lector->getId(),
        lector->getNombre(),
        prestamosLector
    );
}

DtPrestamosLector GestorPrestamos::consultarPrestamosLector() {
    if (gestorUsuarios->getFuncionarioActivo() == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (tempLectorConsulta == nullptr) {
        throw std::runtime_error("Primero debe ingresar un lector valido para consulta.");
    }

    std::vector<DtPrestamo> prestamosLector;
    std::vector<Prestamo*> prestamosDominio = tempLectorConsulta->getPrestamos();

    for (Prestamo* prestamo : prestamosDominio) {
        prestamosLector.push_back(prestamo->getDtPrestamo());
    }

    DtPrestamosLector resultado(
        tempLectorConsulta->getId(),
        tempLectorConsulta->getNombre(),
        prestamosLector
    );

    tempLectorConsulta = nullptr;

    return resultado;
}

void GestorPrestamos::addPrestamo(Prestamo* prestamo) {
    if (prestamo == nullptr) {
        throw std::runtime_error("No se puede agregar un prestamo nulo.");
    }

    prestamos.push_back(prestamo);
}
