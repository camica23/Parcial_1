#include <iostream>
int main(){
    int z,y,aux;
    cin >> z >> y;
    aux = z;
    z = y; 
    y = aux;
    cout << z <<y;
    return 0;
}
