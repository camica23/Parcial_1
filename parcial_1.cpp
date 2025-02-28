// Laura Camila Andrade Campos - Alse_2025
#include <iostream>
#include <cmath>
#include <cctype> // Para poder usar el convertidor de mayúsculas a minúsculas, evitar error por insertar "S"

// Definir la estructura para representar un punto
struct Point
{
    double x, y;
};

// Función para calcular la distancia entre dos puntos
double calcularDistancia(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // Se aplica la fórmula de distancia euclidiana
}

// Función para determinar el punto más cercano
int calcularPuntoMasCercano(Point puntos[], int n, Point usuario)
{
    int indiceMasCercano = 0;
    double distanciaMinima = calcularDistancia(usuario.x, usuario.y, puntos[0].x, puntos[0].y);

    for (int i = 1; i < n; i++)
    {
        double distanciaActual = calcularDistancia(usuario.x, usuario.y, puntos[i].x, puntos[i].y);
        if (distanciaActual < distanciaMinima)
        {
            distanciaMinima = distanciaActual;
            indiceMasCercano = i;
        }
    }
    return indiceMasCercano;
}

// Función para calcular la distancia total del recorrido entre los puntos en orden
double calcularDistanciaTotal(Point puntos[], int n)
{
    double distanciaTotal = 0.0;
    for (int i = 0; i < n - 1; i++) // Se recorre el arreglo sumando la distancia entre puntos consecutivos
    {
        distanciaTotal += calcularDistancia(puntos[i].x, puntos[i].y, puntos[i + 1].x, puntos[i + 1].y);
    }
    return distanciaTotal;
}

// Función para leer los puntos, ya sea manualmente o usar predeterminados
void leerPuntos(Point puntos[], int n)
{
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    std::cin >> respuesta;

    // Convertir la respuesta a minúscula
    respuesta = tolower(respuesta);

    if (respuesta == 's')
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << "Ingrese las coordenadas del punto " << i + 1 << " (x, y): ";
            std::cin >> puntos[i].x >> puntos[i].y;
        }
    }
    else
    {
        std::cout << "Usando puntos predeterminados\n"; // Puntos establecidos para ejecutar cuando el usuario no quiera insertarlos
        puntos[0] = {0, 0};
        puntos[1] = {3, 4};
        puntos[2] = {6, 8};
        puntos[3] = {9, 12};

        for (int i = 0; i < n; i++)
        {
            std::cout << "Punto " << i + 1 << ": (" << puntos[i].x << ", " << puntos[i].y << ")\n";
        }
    }
}

int main()
{
    const int n = 4; // Número de puntos
    Point puntos[n];

    // Leer los puntos
    leerPuntos(puntos, n);

    // Leer el punto desde el cual calcular la distancia
    Point usuario;
    std::cout << "\nIngrese las coordenadas del punto desde el que calcular la distancia (x, y): ";
    std::cin >> usuario.x >> usuario.y;

    // Encontrar el punto más cercano
    int indiceMasCercano = calcularPuntoMasCercano(puntos, n, usuario);

    // Calcular la distancia al punto más cercano
    double distanciaMinima = calcularDistancia(usuario.x, usuario.y, puntos[indiceMasCercano].x, puntos[indiceMasCercano].y);

    // Mostrar resultados
    std::cout << "\nEl punto más cercano es: ("
              << puntos[indiceMasCercano].x << ", "
              << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " << distanciaMinima << "\n";

    /*Calcular la distancia total del recorrido: lo que se quiere es sumar las distancias, recorriendo
    y comparando con el siguiente punto, el ultimo punto no tiene con que compararse por eso n-1
    */
    double distanciaTotal = calcularDistanciaTotal(puntos, n);
    std::cout << "\nLa distancia total del recorrido por los puntos es: " << distanciaTotal << "\n";

    return 0;
}
