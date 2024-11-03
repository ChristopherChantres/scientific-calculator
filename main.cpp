#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void get_slope();
void menu();

int main() {
    menu();
    get_slope();
    return 0;
}

void get_slope() {
    float x1, y1, x2, y2;
    float result = 0;
    char comma; // To read and ignore the comma
    string input1, input2; // Input treated as string
    
    cout << "Utiliza el siguiente formato: 1,2 | 5,9 | 8,4" << endl;
    cout << "--> Ingresa las coordenadas del primer punto (x1, y1): ";
    getline(cin, input1); // Read the entire line as a string
    
    cout << "--> Ingresa las coordenadas del segundo punto (x2, y2): ";
    getline(cin, input2); // Read the entire line as a string

    // Using stringstream to parse the input based on the comma delimiter
    stringstream ss1(input1);
    stringstream ss2(input2);

    ss1 >> x1 >> comma >> y1;
    ss2 >> x2 >> comma >> y2;
    
    result = (y2 - y1) / (x2 - x1);

    cout << "\n==> La pendiente es: " << "m = " << result;
}

void menu(){
    cout << "======================================" << endl;
    cout << "         MENU DE OPCIONES            " << endl;
    cout << "======================================" << endl;
    cout << "1. Obtener la potencia n de un número." << endl;
    cout << "2. Obtener la pendiente de una recta a través de dos puntos (x, y)." << endl;
    cout << "3. Ecuaciones cuadráticas (reales)." << endl;
    cout << "4. Ecuaciones cuadráticas (complejas)." << endl;
    cout << "5. Producto cruz de dos vectores de dimensión 3." << endl;
    cout << "6. Determinar si una matriz de n x n es simétrica." << endl;
    cout << "7. Resolución de sistemas de ecuaciones de 3 incógnitas." << endl;
    cout << "======================================" << endl;
    cout << "Seleccione una opción: ";
}