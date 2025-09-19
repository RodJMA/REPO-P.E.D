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
    std::vector<std::pair<std::string, int>> informacion_codigos; // (cupo, porcentaje de descuento)
};

int main()
{

    return 0;
}