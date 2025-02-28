#include <iostream>

int main()
{
    int lol[10] = {10, 8, 6, 34, 2, 1, 7, 9, 89, 5};
    int x;
    int sumi = 0;
    std::cout << "Ingresa el numero a buscar:\n";
    std::cin >> x;

    for (int i = 0; i <= 9; i++)
    {
        if (lol[i] == x)
        {
            std::cout << "El número si está";
            for (int j = 0; j <= 9; j++)
            {
                sumi = lol[j] + sumi;
            }
            break; // para determinar que se acabe el ciclo
        }
        else if (i == 9)
        {
            std::cout << "El número no está";
            lol[9] = x;
            for (int j = 0; j <= 9; j++)
            {
                sumi = lol[j] + sumi;
            }
        }
    }
    std::cout << "; La suma es: " << sumi << std::endl;

    return 0;
}
