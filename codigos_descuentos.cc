#include <iostream>
#include <vector>
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

int main()
{

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

std::string GenerarCodigo(std::string prefijo);