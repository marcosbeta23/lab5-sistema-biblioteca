#include "Menu.h"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

#include "../utils/FabricaSistema.h"`n#include "../utils/DatosPrueba.h"
#include "../datatypes/DtLector.h"
#include "../datatypes/DtFuncionario.h"
#include "../datatypes/DtMaterialResumen.h"
#include "../datatypes/DtMaterialDetalle.h"
#include "../datatypes/DtPrestamosLector.h"
#include "../datatypes/DtPrestamo.h"

using namespace std;

Menu::Menu() {
    FabricaSistema* fabrica = FabricaSistema::getInstancia();

    gestorSesion = fabrica->getIGestorSesion();
    gestorUsuarios = fabrica->getIGestorUsuarios();
    gestorMateriales = fabrica->getIGestorMateriales();
    gestorPrestamos = fabrica->getIGestorPrestamos();
    relojSistema = RelojSistema::getInstancia();
}

void Menu::mostrarOpciones() const {
    cout << endl;
    cout << "==============================================" << endl;
    cout << "     SISTEMA DE GESTION DE BIBLIOTECA" << endl;
    cout << "==============================================" << endl;
    cout << "1. Iniciar sesion" << endl;
    cout << "2. Cerrar sesion" << endl;
    cout << "3. Registrar lector" << endl;
    cout << "4. Registrar funcionario" << endl;
    cout << "5. Registrar material" << endl;
    cout << "6. Registrar prestamo" << endl;
    cout << "7. Consultar prestamos de lector" << endl;
    cout << "8. Ver informacion de material" << endl;
    cout << "9. Modificar fecha del sistema" << endl;
    cout << "10. Consultar fecha del sistema" << endl;
    cout << "11. Cargar datos de prueba" << endl;
    cout << "0. Salir" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "Seleccione una opcion: ";
}

void Menu::ejecutar() {
    int opcion = -1;

    do {
        mostrarOpciones();
        cin >> opcion;
        cin.ignore();

        try {
            switch (opcion) {
                case 1:
                    opcionIniciarSesion();
                    break;
                case 2:
                    opcionCerrarSesion();
                    break;
                case 3:
                    opcionRegistrarLector();
                    break;
                case 4:
                    opcionRegistrarFuncionario();
                    break;
                case 5:
                    opcionRegistrarMaterial();
                    break;
                case 6:
                    opcionRegistrarPrestamo();
                    break;
                case 7:
                    opcionConsultarPrestamosLector();
                    break;
                case 8:
                    opcionVerInformacionMaterial();
                    break;
                case 9:
                    opcionModificarFechaSistema();
                    break;
                case 10:
                    opcionConsultarFechaSistema();
                    break;
                case 11:
                    opcionCargarDatosPrueba();
                    break;
                case 0:
                    cout << "Saliendo del sistema..." << endl;
                    break;
                default:
                    cout << "Opcion invalida." << endl;
                    break;
            }
        } catch (const exception& e) {
            cout << endl;
            cout << "ERROR: " << e.what() << endl;
        }

        if (opcion != 0) {
            pausar();
        }

    } while (opcion != 0);
}

void Menu::opcionIniciarSesion() {
    string id;
    string contrasena;

    cout << endl;
    cout << "--- Iniciar sesion ---" << endl;

    cout << "Id: ";
    getline(cin, id);

    cout << "Contrasena: ";
    getline(cin, contrasena);

    bool resultado = gestorSesion->iniciarSesion(id, contrasena);

    if (resultado) {
        cout << "Sesion iniciada correctamente." << endl;
    } else {
        cout << "Credenciales invalidas." << endl;
    }
}

void Menu::opcionCerrarSesion() {
    cout << endl;
    cout << "--- Cerrar sesion ---" << endl;

    gestorSesion->cerrarSesion();

    cout << "Sesion cerrada correctamente." << endl;
}

void Menu::opcionRegistrarLector() {
    string id;
    string nombre;
    string contrasena;
    string fechaRegistro;
    char confirma;

    cout << endl;
    cout << "--- Registrar lector ---" << endl;

    cout << "Id: ";
    getline(cin, id);

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Contrasena: ";
    getline(cin, contrasena);

    cout << "Fecha de registro (dd/mm/aaaa): ";
    getline(cin, fechaRegistro);

    DtLector datos = gestorUsuarios->ingresarDatosLector(id, nombre, contrasena, fechaRegistro);

    cout << endl;
    cout << "Datos ingresados:" << endl;
    cout << "Id: " << datos.id << endl;
    cout << "Nombre: " << datos.nombre << endl;
    cout << "Fecha registro: " << datos.fechaRegistro << endl;

    cout << "Confirmar registro? (s/n): ";
    cin >> confirma;
    cin.ignore();

    if (confirma == 's' || confirma == 'S') {
        gestorUsuarios->confirmarRegistroLector();
        cout << "Lector registrado correctamente." << endl;
    } else {
        cout << "Registro cancelado. Los datos temporales quedaran sin confirmar." << endl;
    }
}

void Menu::opcionRegistrarFuncionario() {
    string id;
    string nombre;
    string contrasena;
    int nroEmpleado;
    char confirma;

    cout << endl;
    cout << "--- Registrar funcionario ---" << endl;

    cout << "Id: ";
    getline(cin, id);

    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Contrasena: ";
    getline(cin, contrasena);

    cout << "Numero de empleado: ";
    cin >> nroEmpleado;
    cin.ignore();

    DtFuncionario datos = gestorUsuarios->ingresarDatosFuncionario(id, nombre, contrasena, nroEmpleado);

    cout << endl;
    cout << "Datos ingresados:" << endl;
    cout << "Id: " << datos.id << endl;
    cout << "Nombre: " << datos.nombre << endl;
    cout << "Numero empleado: " << datos.nroEmpleado << endl;

    cout << "Confirmar registro? (s/n): ";
    cin >> confirma;
    cin.ignore();

    if (confirma == 's' || confirma == 'S') {
        gestorUsuarios->confirmarRegistroFuncionario();
        cout << "Funcionario registrado correctamente." << endl;
    } else {
        cout << "Registro cancelado. Los datos temporales quedaran sin confirmar." << endl;
    }
}

void Menu::opcionRegistrarMaterial() {
    string codigo;
    string titulo;
    int anioPublicacion;
    int opcionTipo;
    char confirma;

    cout << endl;
    cout << "--- Registrar material ---" << endl;

    cout << "Codigo: ";
    getline(cin, codigo);

    cout << "Titulo: ";
    getline(cin, titulo);

    cout << "Anio de publicacion: ";
    cin >> anioPublicacion;
    cin.ignore();

    gestorMateriales->ingresarDatosGeneralesMaterial(codigo, titulo, anioPublicacion);

    cout << "Tipo de material:" << endl;
    cout << "1. Libro" << endl;
    cout << "2. Revista" << endl;
    cout << "Seleccione tipo: ";
    cin >> opcionTipo;
    cin.ignore();

    if (opcionTipo == 1) {
        string autor;
        int cantPaginas;

        gestorMateriales->indicarTipoMaterial("Libro");

        cout << "Autor: ";
        getline(cin, autor);

        cout << "Cantidad de paginas: ";
        cin >> cantPaginas;
        cin.ignore();

        DtMaterialDetalle detalle = gestorMateriales->ingresarDatosLibro(autor, cantPaginas);

        cout << endl;
        cout << "Material ingresado:" << endl;
        cout << "Codigo: " << detalle.codigo << endl;
        cout << "Titulo: " << detalle.titulo << endl;
        cout << "Tipo: " << detalle.tipo << endl;
        cout << "Autor: " << detalle.datosEspecificos.dato1 << endl;
        cout << "Paginas: " << detalle.datosEspecificos.dato2 << endl;

    } else if (opcionTipo == 2) {
        int nroEdicion;
        char mensual;
        bool esMensual;

        gestorMateriales->indicarTipoMaterial("Revista");

        cout << "Numero de edicion: ";
        cin >> nroEdicion;
        cin.ignore();

        cout << "Es mensual? (s/n): ";
        cin >> mensual;
        cin.ignore();

        esMensual = (mensual == 's' || mensual == 'S');

        DtMaterialDetalle detalle = gestorMateriales->ingresarDatosRevista(nroEdicion, esMensual);

        cout << endl;
        cout << "Material ingresado:" << endl;
        cout << "Codigo: " << detalle.codigo << endl;
        cout << "Titulo: " << detalle.titulo << endl;
        cout << "Tipo: " << detalle.tipo << endl;
        cout << "Numero edicion: " << detalle.datosEspecificos.dato1 << endl;
        cout << "Es mensual: " << detalle.datosEspecificos.dato2 << endl;

    } else {
        throw runtime_error("Tipo de material invalido.");
    }

    cout << "Confirmar registro? (s/n): ";
    cin >> confirma;
    cin.ignore();

    if (confirma == 's' || confirma == 'S') {
        gestorMateriales->confirmarRegistroMaterial();
        cout << "Material registrado correctamente." << endl;
    } else {
        cout << "Registro cancelado. Los datos temporales quedaran sin confirmar." << endl;
    }
}

void Menu::opcionRegistrarPrestamo() {
    string idLector;
    string codigoMaterial;
    string fechaPrestamo;
    int diasPermitidos;
    char confirma;

    cout << endl;
    cout << "--- Registrar prestamo ---" << endl;

    cout << "Id del lector: ";
    getline(cin, idLector);

    DtLector lector = gestorPrestamos->ingresarIdLector(idLector);

    cout << "Lector encontrado: " << lector.id << " - " << lector.nombre << endl;

    cout << "Codigo del material: ";
    getline(cin, codigoMaterial);

    DtMaterialResumen material = gestorPrestamos->ingresarCodigoMaterial(codigoMaterial);

    cout << "Material encontrado: " << material.codigo << " - " << material.titulo << endl;

    cout << "Fecha del prestamo (dd/mm/aaaa): ";
    getline(cin, fechaPrestamo);

    cout << "Dias permitidos: ";
    cin >> diasPermitidos;
    cin.ignore();

    gestorPrestamos->ingresarDatosPrestamo(fechaPrestamo, diasPermitidos);

    cout << "Confirmar prestamo? (s/n): ";
    cin >> confirma;
    cin.ignore();

    if (confirma == 's' || confirma == 'S') {
        gestorPrestamos->confirmarRegistroPrestamo();
        cout << "Prestamo registrado correctamente." << endl;
    } else {
        cout << "Prestamo cancelado. Los datos temporales quedaran sin confirmar." << endl;
    }
}

void Menu::opcionConsultarPrestamosLector() {
    string idLector;

    cout << endl;
    cout << "--- Consultar prestamos de lector ---" << endl;

    cout << "Id del lector: ";
    getline(cin, idLector);

    gestorPrestamos->ingresarIdLectorConsulta(idLector);
    DtPrestamosLector resultado = gestorPrestamos->consultarPrestamosLector();

    cout << endl;
    cout << "Lector: " << resultado.idLector << " - " << resultado.nombreLector << endl;

    if (resultado.prestamos.empty()) {
        cout << "El lector no tiene prestamos registrados." << endl;
    } else {
        cout << "Prestamos:" << endl;

        for (const DtPrestamo& prestamo : resultado.prestamos) {
            cout << "- Material: " << prestamo.codigoMaterial
                 << " | Titulo: " << prestamo.tituloMaterial
                 << " | Fecha: " << prestamo.fechaPrestamo
                 << " | Dias: " << prestamo.diasPermitidos
                 << endl;
        }
    }
}

void Menu::opcionVerInformacionMaterial() {
    string codigo;

    cout << endl;
    cout << "--- Ver informacion de material ---" << endl;

    vector<DtMaterialResumen> materiales = gestorMateriales->solicitarListaMateriales();

    if (materiales.empty()) {
        cout << "No hay materiales registrados." << endl;
        return;
    }

    cout << "Materiales disponibles:" << endl;

    for (const DtMaterialResumen& material : materiales) {
        cout << "- " << material.codigo << " | " << material.titulo << endl;
    }

    cout << "Ingrese codigo del material: ";
    getline(cin, codigo);

    DtMaterialDetalle detalle = gestorMateriales->verInformacionMaterial(codigo);

    cout << endl;
    cout << "Informacion del material:" << endl;
    cout << "Codigo: " << detalle.codigo << endl;
    cout << "Titulo: " << detalle.titulo << endl;
    cout << "Anio publicacion: " << detalle.anioPublicacion << endl;
    cout << "Tipo: " << detalle.tipo << endl;
    cout << "Puntaje promedio: " << detalle.puntajePromedio << endl;

    if (detalle.tipo == "Libro") {
        cout << "Autor: " << detalle.datosEspecificos.dato1 << endl;
        cout << "Cantidad de paginas: " << detalle.datosEspecificos.dato2 << endl;
    } else if (detalle.tipo == "Revista") {
        cout << "Numero de edicion: " << detalle.datosEspecificos.dato1 << endl;
        cout << "Es mensual: " << detalle.datosEspecificos.dato2 << endl;
    }
}

void Menu::opcionModificarFechaSistema() {
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;

    cout << endl;
    cout << "--- Modificar fecha del sistema ---" << endl;

    cout << "Dia: ";
    cin >> dia;

    cout << "Mes: ";
    cin >> mes;

    cout << "Anio: ";
    cin >> anio;

    cout << "Hora: ";
    cin >> hora;

    cout << "Minuto: ";
    cin >> minuto;
    cin.ignore();

    relojSistema->modificarFecha(dia, mes, anio, hora, minuto);

    cout << "Fecha del sistema modificada correctamente." << endl;
    cout << "Nueva fecha: " << relojSistema->consultarFecha() << endl;
}

void Menu::opcionConsultarFechaSistema() {
    cout << endl;
    cout << "--- Consultar fecha del sistema ---" << endl;
    cout << "Fecha actual del sistema: " << relojSistema->consultarFecha() << endl;
}

void Menu::opcionCargarDatosPrueba() {
    cout << endl;
    cout << "--- Cargar datos de prueba ---" << endl;

    DatosPrueba::cargarDatosPrueba();

    cout << "Datos de prueba cargados correctamente." << endl;
    cout << endl;
    cout << "Usuario funcionario inicial:" << endl;
    cout << "Id: admin" << endl;
    cout << "Contrasena: admin" << endl;
    cout << endl;
    cout << "Lectores cargados:" << endl;
    cout << "- lec1 / Lector Uno" << endl;
    cout << "- lec2 / Lector Dos" << endl;
    cout << endl;
    cout << "Materiales cargados:" << endl;
    cout << "- LIB1 / Libro de prueba" << endl;
    cout << "- REV1 / Revista de prueba" << endl;
}

void Menu::pausar() const {
    cout << endl;
    cout << "Presione ENTER para continuar...";
    cin.get();
}

