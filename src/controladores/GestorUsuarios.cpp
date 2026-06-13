#include "GestorUsuarios.h"
#include <stdexcept>

GestorUsuarios* GestorUsuarios::instancia = nullptr;

GestorUsuarios::GestorUsuarios()
    : usuarios(),
      datosTempLectorValidos(false),
      tempIdLector(""),
      tempNombreLector(""),
      tempContrasenaLector(""),
      tempFechaRegistro(""),
      datosTempFuncionarioValidos(false),
      tempIdFuncionario(""),
      tempNombreFuncionario(""),
      tempContrasenaFuncionario(""),
      tempNroEmpleado(0) {}

GestorUsuarios* GestorUsuarios::getInstancia() {
    if (instancia == nullptr) {
        instancia = new GestorUsuarios();
    }

    return instancia;
}

GestorUsuarios::~GestorUsuarios() {
    for (auto& par : usuarios) {
        delete par.second;
    }
}

DtLector GestorUsuarios::ingresarDatosLector(
    std::string id,
    std::string nombre,
    std::string contrasena,
    std::string fechaRegistro
) {
    if (getFuncionarioActivo() == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (id.empty() || nombre.empty() || contrasena.empty() || fechaRegistro.empty()) {
        throw std::runtime_error("Los datos del lector no pueden ser vacios.");
    }

    if (existeUsuario(id)) {
        throw std::runtime_error("Ya existe un usuario con ese id.");
    }

    tempIdLector = id;
    tempNombreLector = nombre;
    tempContrasenaLector = contrasena;
    tempFechaRegistro = fechaRegistro;
    datosTempLectorValidos = true;

    return DtLector(id, nombre, fechaRegistro);
}

void GestorUsuarios::confirmarRegistroLector() {
    if (getFuncionarioActivo() == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (!datosTempLectorValidos) {
        throw std::runtime_error("No existen datos temporales de lector para confirmar.");
    }

    if (existeUsuario(tempIdLector)) {
        throw std::runtime_error("Ya existe un usuario con ese id.");
    }

    Lector* lector = new Lector(
        tempIdLector,
        tempNombreLector,
        tempContrasenaLector,
        tempFechaRegistro
    );

    usuarios[tempIdLector] = lector;

    tempIdLector = "";
    tempNombreLector = "";
    tempContrasenaLector = "";
    tempFechaRegistro = "";
    datosTempLectorValidos = false;
}

DtFuncionario GestorUsuarios::ingresarDatosFuncionario(
    std::string id,
    std::string nombre,
    std::string contrasena,
    int nroEmpleado
) {
    if (getFuncionarioActivo() == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (id.empty() || nombre.empty() || contrasena.empty()) {
        throw std::runtime_error("Los datos del funcionario no pueden ser vacios.");
    }

    if (nroEmpleado <= 0) {
        throw std::runtime_error("El numero de empleado debe ser mayor que cero.");
    }

    if (existeUsuario(id)) {
        throw std::runtime_error("Ya existe un usuario con ese id.");
    }

    if (existeNroEmpleado(nroEmpleado)) {
        throw std::runtime_error("Ya existe un funcionario con ese numero de empleado.");
    }

    tempIdFuncionario = id;
    tempNombreFuncionario = nombre;
    tempContrasenaFuncionario = contrasena;
    tempNroEmpleado = nroEmpleado;
    datosTempFuncionarioValidos = true;

    return DtFuncionario(id, nombre, nroEmpleado);
}

void GestorUsuarios::confirmarRegistroFuncionario() {
    if (getFuncionarioActivo() == nullptr) {
        throw std::runtime_error("Debe existir un funcionario con sesion activa.");
    }

    if (!datosTempFuncionarioValidos) {
        throw std::runtime_error("No existen datos temporales de funcionario para confirmar.");
    }

    if (existeUsuario(tempIdFuncionario)) {
        throw std::runtime_error("Ya existe un usuario con ese id.");
    }

    if (existeNroEmpleado(tempNroEmpleado)) {
        throw std::runtime_error("Ya existe un funcionario con ese numero de empleado.");
    }

    Funcionario* funcionario = new Funcionario(
        tempIdFuncionario,
        tempNombreFuncionario,
        tempContrasenaFuncionario,
        tempNroEmpleado
    );

    usuarios[tempIdFuncionario] = funcionario;

    tempIdFuncionario = "";
    tempNombreFuncionario = "";
    tempContrasenaFuncionario = "";
    tempNroEmpleado = 0;
    datosTempFuncionarioValidos = false;
}

Usuario* GestorUsuarios::find(std::string id) {
    auto it = usuarios.find(id);

    if (it == usuarios.end()) {
        return nullptr;
    }

    return it->second;
}

Lector* GestorUsuarios::findLector(std::string id) {
    Usuario* usuario = find(id);

    if (usuario == nullptr) {
        return nullptr;
    }

    return dynamic_cast<Lector*>(usuario);
}

Funcionario* GestorUsuarios::findFuncionario(std::string id) {
    Usuario* usuario = find(id);

    if (usuario == nullptr) {
        return nullptr;
    }

    return dynamic_cast<Funcionario*>(usuario);
}

Usuario* GestorUsuarios::findActivo() {
    for (auto& par : usuarios) {
        if (par.second->tieneSesionActiva()) {
            return par.second;
        }
    }

    return nullptr;
}

Funcionario* GestorUsuarios::getFuncionarioActivo() {
    Usuario* usuarioActivo = findActivo();

    if (usuarioActivo == nullptr) {
        return nullptr;
    }

    return dynamic_cast<Funcionario*>(usuarioActivo);
}

bool GestorUsuarios::existeUsuario(std::string id) {
    return usuarios.find(id) != usuarios.end();
}

bool GestorUsuarios::existeNroEmpleado(int nroEmpleado) {
    for (auto& par : usuarios) {
        Funcionario* funcionario = dynamic_cast<Funcionario*>(par.second);

        if (funcionario != nullptr && funcionario->getNroEmpleado() == nroEmpleado) {
            return true;
        }
    }

    return false;
}

void GestorUsuarios::addUsuario(Usuario* usuario) {
    if (usuario == nullptr) {
        throw std::runtime_error("No se puede agregar un usuario nulo.");
    }

    if (existeUsuario(usuario->getId())) {
        throw std::runtime_error("Ya existe un usuario con ese id.");
    }

    usuarios[usuario->getId()] = usuario;
}
