#pragma once
#include <string>
#include <vector>
#include "../datatypes/DtMaterialResumen.h"
#include "../datatypes/DtMaterialDetalle.h"

class IGestorMateriales {
public:
    virtual ~IGestorMateriales() {}

    virtual void ingresarDatosGeneralesMaterial(
        std::string codigo,
        std::string titulo,
        int anioPublicacion
    ) = 0;

    virtual void indicarTipoMaterial(std::string tipo) = 0;

    virtual DtMaterialDetalle ingresarDatosLibro(
        std::string autor,
        int cantPaginas
    ) = 0;

    virtual DtMaterialDetalle ingresarDatosRevista(
        int nroEdicion,
        bool esMensual
    ) = 0;

    virtual void confirmarRegistroMaterial() = 0;

    virtual std::vector<DtMaterialResumen> solicitarListaMateriales() = 0;
    virtual DtMaterialResumen seleccionarMaterial(std::string codigo) = 0;
    virtual DtMaterialDetalle verInformacionMaterial(std::string codigo) = 0;
};
