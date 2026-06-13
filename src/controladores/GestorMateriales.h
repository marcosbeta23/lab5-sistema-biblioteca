#pragma once

#include <map>
#include <string>
#include <vector>

#include "../interfaces/IGestorMateriales.h"
#include "../dominio/Material.h"
#include "../dominio/Libro.h"
#include "../dominio/Revista.h"
#include "../dominio/Funcionario.h"
#include "GestorUsuarios.h"

class GestorMateriales : public IGestorMateriales {
private:
    static GestorMateriales* instancia;

    std::map<std::string, Material*> materiales;
    GestorUsuarios* gestorUsuarios;

    bool datosGeneralesValidos;
    std::string tempCodigo;
    std::string tempTitulo;
    int tempAnioPublicacion;

    bool tipoValido;
    std::string tempTipo;

    bool datosEspecificosValidos;
    std::string tempAutor;
    int tempCantPaginas;
    int tempNroEdicion;
    bool tempEsMensual;

    GestorMateriales();

public:
    static GestorMateriales* getInstancia();

    ~GestorMateriales();

    void ingresarDatosGeneralesMaterial(
        std::string codigo,
        std::string titulo,
        int anioPublicacion
    ) override;

    void indicarTipoMaterial(std::string tipo) override;

    DtMaterialDetalle ingresarDatosLibro(
        std::string autor,
        int cantPaginas
    ) override;

    DtMaterialDetalle ingresarDatosRevista(
        int nroEdicion,
        bool esMensual
    ) override;

    void confirmarRegistroMaterial() override;

    std::vector<DtMaterialResumen> solicitarListaMateriales() override;
    DtMaterialResumen seleccionarMaterial(std::string codigo) override;
    DtMaterialDetalle verInformacionMaterial(std::string codigo) override;

    Material* findMaterial(std::string codigo);
    bool existeMaterial(std::string codigo);

    void addMaterial(Material* material);
};
