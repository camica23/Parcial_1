#include <iostream>
int main(){
    int z,y,aux;
    std:: cout << "ingresa numeros:\n"; 
    std:: cin >> z >> y;
    aux = z;
    z = y; 
    y = aux;
    std:: cout << "los numeros son:\n"<< z << y <<"\n";
    return 0;
}
