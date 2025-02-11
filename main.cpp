#include <iostream>
int main(){
    int sum, multi,res;
    float a,b, div; 
    std:: cout << "Solo sé que nada sé \n"; 
    std:: cout << "ingresa numeros: "; 
    std:: cin >> a >> b; /*>> insertar (concatena)*/
    sum = a + b; 
    res = a - b; 
    multi = a * b; 
    div = a / b;
    std:: cout << "la suma es:\n" << sum << "\n"; /*<< extracción (concatena)*/
    std:: cout << "la resta es:\n" << res << "\n"; 
    std:: cout << "la multiplicación es:\n" << multi << "\n"; 
    std:: cout << "la división es:\n" << div << "\n"; 
    return 0;
    
}