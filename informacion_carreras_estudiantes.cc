#include <iostream>
#include <string>
#include <vector>
#include <utility>
/*
Registrar una carrera (nombre, año de creación) y los estudiantes inscritos (nombre y matrícula).

Calcular cuántos años lleva activa la carrera.

Mostrar toda la información registrada.

Buscar una carrera por nombre y mostrar los estudiantes que tiene.
*/
struct InformacionEstudiantes
{
    std::vector<std::pair<std::string, float>> info_estudiante; //(nombre, matricula)
};
struct InformacionCarrera
{
    std::string nombre_carrera;
    int anio_de_creacion;
    struct InformacionEstudiantes estudiante;
};

struct InformacionCarrera SolicitarDatos();
void MostrarInformacion(std::vector<struct InformacionCarrera> carrera, int AniosCarreraActiva);
int AniosCarreraActiva(int anio_de_creacion);
void BuscarCarrera(std::vector<struct InformacionCarrera> carrera);

int main()
{
    int anios_activa;
    struct InformacionCarrera carrera;
    std::vector<struct InformacionCarrera> registro_carrera;
    carrera = SolicitarDatos();
    registro_carrera.push_back(carrera);
    anios_activa = AniosCarreraActiva(carrera.anio_de_creacion);
    MostrarInformacion(registro_carrera, anios_activa);
    BuscarCarrera(registro_carrera);

    return 0;
}

struct InformacionCarrera SolicitarDatos()
{
    std::string nombre_estudiante;
    float matricula;
    int contador = 0;
    int decision;
    struct InformacionCarrera carrera;
    std::cout << "Ingrese el nombre de la carrera: ";
    std::getline(std::cin, carrera.nombre_carrera);
    std::cout << "Ingrese el anio de creacion: ";
    std::cin >> carrera.anio_de_creacion;

    std::cout << "Registro de estudiantes " << std::endl;
    do
    {
        std::cin.ignore();
        std::cout << "Ingrese nombre del estudiante: ";
        std::getline(std::cin, nombre_estudiante);
        std::cout << "Ingrese la matricula del estudiante: ";
        std::cin >> matricula;
        carrera.estudiante.info_estudiante.push_back({nombre_estudiante, matricula});

        std::cout << "Desea agregar mas estudiantes? (SI = 1, NO = 0): ";
        std::cin >> decision;

    } while (decision != 0);

    return carrera;
}

void MostrarInformacion(std::vector<struct InformacionCarrera> carrera, int AniosCarreraActiva)
{
    std::cout << "Informacion registrada" << std::endl;
    for (auto info : carrera)
    {
        std::cout << "Carrera: " << info.nombre_carrera << std::endl;
        std::cout << "Anio de creacion: " << info.anio_de_creacion << std::endl;
        std::cout << "Anios activa la carrera: " << AniosCarreraActiva << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "Estudantes de la carrera  " << info.nombre_carrera << std::endl;
        std::cout << "Cantidad de estudiantes: " << info.estudiante.info_estudiante.size() << std::endl;
        for (auto estudiante : info.estudiante.info_estudiante)
        {
            std::cout << "Nombre del estudiante: " << estudiante.first << std::endl;
            std::cout << "Matricual del estudiante: " << estudiante.second << std::endl;
        }
    }
}

int AniosCarreraActiva(int anio_de_creacion)
{
    int anio_actual = 2025;

    return anio_actual - anio_de_creacion;
}

void BuscarCarrera(std::vector<struct InformacionCarrera> carrera)
{
    std::string buscar;
    std::cout << "Ingrese la carrera que desea buscar: ";
    std::cin >> buscar;

    for (int i = 0; i < carrera.size(); i++)
    {
        if (buscar == carrera[i].nombre_carrera)
        {
            for (auto carrera : carrera)
            {
                for (auto estudiante : carrera.estudiante.info_estudiante)
                {
                    std::cout << "Nombre del estudiante: " << estudiante.first << std::endl;
                    std::cout << "Matricual del estudiante: " << estudiante.second << std::endl;
                }
            }
        }
        else
        {
            std::cout << "No coincidencias" << std::endl;
        }
    }
}