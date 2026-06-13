#pragma once

#include <map>
#include <string>
#include "../interfaces/IGestorUsuarios.h"
#include "../dominio/Usuario.h"
#include "../dominio/Lector.h"
#include "../dominio/Funcionario.h"

class GestorUsuarios : public IGestorUsuarios {
private:
    static GestorUsuarios* instancia;

    std::map<std::string, Usuario*> usuarios;

    bool datosTempLectorValidos;
    std::string tempIdLector;
    std::string tempNombreLector;
    std::string tempContrasenaLector;
    std::string tempFechaRegistro;

    bool datosTempFuncionarioValidos;
    std::string tempIdFuncionario;
    std::string tempNombreFuncionario;
    std::string tempContrasenaFuncionario;
    int tempNroEmpleado;

    GestorUsuarios();

public:
    static GestorUsuarios* getInstancia();

    ~GestorUsuarios();

    DtLector ingresarDatosLector(
        std::string id,
        std::string nombre,
        std::string contrasena,
        std::string fechaRegistro
    ) override;

    void confirmarRegistroLector() override;

    DtFuncionario ingresarDatosFuncionario(
        std::string id,
        std::string nombre,
        std::string contrasena,
        int nroEmpleado
    ) override;

    void confirmarRegistroFuncionario() override;

    Usuario* find(std::string id);
    Lector* findLector(std::string id);
    Funcionario* findFuncionario(std::string id);
    Usuario* findActivo();
    Funcionario* getFuncionarioActivo();

    bool existeUsuario(std::string id);
    bool existeNroEmpleado(int nroEmpleado);

    void addUsuario(Usuario* usuario);
};
