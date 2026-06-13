#include "GestorMateriales.h"
#include <stdexcept>

GestorMateriales* GestorMateriales::instancia = nullptr;

GestorMateriales::GestorMateriales()
    : materiales(),
      gestorUsuarios(GestorUsuarios::getInstancia()),
      datosGeneralesValidos(false),
      tempCodigo(""),
      tempTitulo(""),
      tempAnioPublicacion(0),
      tipoValido(false),
      tempTipo(""),
      datosEspecificosValidos(false),
      tempAutor(""),
      tempCantPaginas(0),
      tempNroEdicion(0),
      tempEsMensual(false) {}

GestorMateriales* GestorMateriales::getInstancia() {
    if (instancia == nullptr) {
        instancia = new GestorMateriales();
    }

    return instancia;
}

GestorMateriales::~GestorMateriales() {
    for (auto& par : materiales) {
        delete par.second;
    }
}

void GestorMateriales::ingresarDatosGeneralesMaterial(
    std::string codigo,
    std::string titulo,
    int anioPublicacion
) {
    if (gestorUsuarios->getFuncionarioActivo() == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (codigo.empty() || titulo.empty()) {
        throw std::runtime_error("El codigo y el titulo no pueden ser vacios.");
    }

    if (anioPublicacion <= 0) {
        throw std::runtime_error("El anio de publicacion debe ser mayor que cero.");
    }

    if (existeMaterial(codigo)) {
        throw std::runtime_error("Ya existe un material con ese codigo.");
    }

    tempCodigo = codigo;
    tempTitulo = titulo;
    tempAnioPublicacion = anioPublicacion;

    datosGeneralesValidos = true;
    tipoValido = false;
    datosEspecificosValidos = false;

    tempTipo = "";
    tempAutor = "";
    tempCantPaginas = 0;
    tempNroEdicion = 0;
    tempEsMensual = false;
}

void GestorMateriales::indicarTipoMaterial(std::string tipo) {
    if (!datosGeneralesValidos) {
        throw std::runtime_error("Primero debe ingresar los datos generales del material.");
    }

    if (tipo != "Libro" && tipo != "Revista") {
        throw std::runtime_error("Tipo de material invalido. Debe ser Libro o Revista.");
    }

    tempTipo = tipo;
    tipoValido = true;
    datosEspecificosValidos = false;
}

DtMaterialDetalle GestorMateriales::ingresarDatosLibro(
    std::string autor,
    int cantPaginas
) {
    if (!datosGeneralesValidos || !tipoValido) {
        throw std::runtime_error("Primero debe ingresar datos generales e indicar tipo de material.");
    }

    if (tempTipo != "Libro") {
        throw std::runtime_error("El tipo de material seleccionado no es Libro.");
    }

    if (autor.empty()) {
        throw std::runtime_error("El autor no puede ser vacio.");
    }

    if (cantPaginas <= 0) {
        throw std::runtime_error("La cantidad de paginas debe ser mayor que cero.");
    }

    tempAutor = autor;
    tempCantPaginas = cantPaginas;
    datosEspecificosValidos = true;

    return DtMaterialDetalle(
        tempCodigo,
        tempTitulo,
        tempAnioPublicacion,
        "Libro",
        0,
        DtDatosEspecificos(tempAutor, std::to_string(tempCantPaginas))
    );
}

DtMaterialDetalle GestorMateriales::ingresarDatosRevista(
    int nroEdicion,
    bool esMensual
) {
    if (!datosGeneralesValidos || !tipoValido) {
        throw std::runtime_error("Primero debe ingresar datos generales e indicar tipo de material.");
    }

    if (tempTipo != "Revista") {
        throw std::runtime_error("El tipo de material seleccionado no es Revista.");
    }

    if (nroEdicion <= 0) {
        throw std::runtime_error("El numero de edicion debe ser mayor que cero.");
    }

    tempNroEdicion = nroEdicion;
    tempEsMensual = esMensual;
    datosEspecificosValidos = true;

    return DtMaterialDetalle(
        tempCodigo,
        tempTitulo,
        tempAnioPublicacion,
        "Revista",
        0,
        DtDatosEspecificos(std::to_string(tempNroEdicion), tempEsMensual ? "Si" : "No")
    );
}

void GestorMateriales::confirmarRegistroMaterial() {
    Funcionario* funcionarioActivo = gestorUsuarios->getFuncionarioActivo();

    if (funcionarioActivo == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (!datosGeneralesValidos || !tipoValido || !datosEspecificosValidos) {
        throw std::runtime_error("No existen datos completos de material para confirmar.");
    }

    if (existeMaterial(tempCodigo)) {
        throw std::runtime_error("Ya existe un material con ese codigo.");
    }

    Material* material = nullptr;

    if (tempTipo == "Libro") {
        material = new Libro(
            tempCodigo,
            tempTitulo,
            tempAnioPublicacion,
            tempAutor,
            tempCantPaginas
        );
    } else if (tempTipo == "Revista") {
        material = new Revista(
            tempCodigo,
            tempTitulo,
            tempAnioPublicacion,
            tempNroEdicion,
            tempEsMensual
        );
    }

    if (material == nullptr) {
        throw std::runtime_error("No se pudo crear el material.");
    }

    material->setRegistrador(funcionarioActivo);
    materiales[tempCodigo] = material;

    tempCodigo = "";
    tempTitulo = "";
    tempAnioPublicacion = 0;
    tempTipo = "";
    tempAutor = "";
    tempCantPaginas = 0;
    tempNroEdicion = 0;
    tempEsMensual = false;

    datosGeneralesValidos = false;
    tipoValido = false;
    datosEspecificosValidos = false;
}

std::vector<DtMaterialResumen> GestorMateriales::solicitarListaMateriales() {
    std::vector<DtMaterialResumen> lista;

    for (auto& par : materiales) {
        lista.push_back(par.second->getDtResumen());
    }

    return lista;
}

DtMaterialResumen GestorMateriales::seleccionarMaterial(std::string codigo) {
    Material* material = findMaterial(codigo);

    if (material == nullptr) {
        throw std::runtime_error("No existe un material con ese codigo.");
    }

    return material->getDtResumen();
}

DtMaterialDetalle GestorMateriales::verInformacionMaterial(std::string codigo) {
    Material* material = findMaterial(codigo);

    if (material == nullptr) {
        throw std::runtime_error("No existe un material con ese codigo.");
    }

    return material->getDtDetalle();
}

Material* GestorMateriales::findMaterial(std::string codigo) {
    auto it = materiales.find(codigo);

    if (it == materiales.end()) {
        return nullptr;
    }

    return it->second;
}

bool GestorMateriales::existeMaterial(std::string codigo) {
    return materiales.find(codigo) != materiales.end();
}

void GestorMateriales::addMaterial(Material* material) {
    if (material == nullptr) {
        throw std::runtime_error("No se puede agregar un material nulo.");
    }

    if (existeMaterial(material->getCodigo())) {
        throw std::runtime_error("Ya existe un material con ese codigo.");
    }

    materiales[material->getCodigo()] = material;
}
