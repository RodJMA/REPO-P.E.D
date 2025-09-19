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

int main()
{
    srand(time(0));

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