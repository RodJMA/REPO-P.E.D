#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
/*
El programa debe:

Solicitar el nombre del cliente y la cantidad de códigos de descuento que desea generar.

Generar códigos automáticos usando un prefijo de 2 letras ingresado por el usuario y un número aleatorio.

Cada código tendrá asociado un porcentaje de descuento (aleatorio entre 5% y 30%).

Guardar todos los datos en estructuras y mostrarlos al final.
*/
struct Cliente
{
    std::string nombre_cliente;
};

struct Codigos
{
    int cantidad_codigos;
    struct Cliente informacion_cliente;
    std::vector<std::pair<std::string, int>> informacion_codigo; // (codigo, porcentaje de descuento)
};

std::string SolicitarPrefijo();
std::string GenerarCodigo(std::string prefijo);
int PorcentajeDescuento(std::string numero_aleatorio);
struct Codigos SolicitarDatosGenerales();
void MostrarInformacion(std::vector<struct Codigos> codigos);

int main()
{
    srand(time(0));
    std::vector<struct Codigos> codigos_main;
    int opcion;
    do
    {

        std::cout << "1. Generar codigos \n2. Mostrar informacion \n3. Salir \nIngrese la opcion: ";
        std::cin >> opcion;
        switch (opcion)
        {
        case 1:
            codigos_main.push_back(SolicitarDatosGenerales());
            break;
        case 2:
            MostrarInformacion(codigos_main);
            break;

        default:
            std::cout << "Opcion incorrecta. Intente de nuevo" << std::endl;
            break;
        }

    } while (opcion != 3);

    return 0;
}

std::string SolicitarPrefijo()
{
    std::string prefijo;

    do
    {
        std::cout << "Ingrese dos letras: ";
        std::cin >> prefijo;

        if (prefijo.length() != 2)
        {
            std::cout << "Error. Intente de nuevo" << std::endl;
        }

    } while (prefijo.length() != 2);

    return prefijo;
};

std::string GenerarCodigo(std::string prefijo)
{
    std::string codigo;
    int numero_aleatorio = rand() % (999 - 100 + 1) + 100; // 100 al 999

    codigo = "--" + prefijo + std::to_string(numero_aleatorio) + "--";

    return codigo;
};

int PorcentajeDescuento(std::string numero_aleatorio)
{
    int porcentaje_de_descuento;
    std::string parte_extraida = numero_aleatorio.substr(5, 3);
    int parte_numerica = std::stoi(parte_extraida);

    if ((parte_numerica % 2) == 0)
    {
        porcentaje_de_descuento = rand() % (30 + 5 + 1) + 5;
    }
    else
    {
        porcentaje_de_descuento = 0;
    }

    return porcentaje_de_descuento;
};

struct Codigos SolicitarDatosGenerales()
{
    struct Codigos informacion;
    std::cout << "Ingrese su nombre: ";
    std::cin >> informacion.informacion_cliente.nombre_cliente;
    std::cout << "Ingrese la cantidad de codigos que desea generar: ";
    std::cin >> informacion.cantidad_codigos;
    for (auto i = 0; i < informacion.cantidad_codigos; i++)
    {
        informacion.informacion_codigo.push_back({GenerarCodigo(SolicitarPrefijo()), PorcentajeDescuento(GenerarCodigo(SolicitarPrefijo()))});
    }

    return informacion;
};

void MostrarInformacion(std::vector<struct Codigos> codigos)
{

    for (auto c : codigos)
    {
        std::cout << "Nombre del cliente: " << c.informacion_cliente.nombre_cliente << std::endl;
        std::cout << "Cantidad de codigos del cliente: " << c.cantidad_codigos << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;
        for (auto c_i : c.informacion_codigo)
        {
            std::cout << c_i.first << " || Porcentaje de descuento: " << c_i.second << std::endl;
        }
    }
};