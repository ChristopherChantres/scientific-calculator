#include <iostream>
#include <sstream>
#include <string>
#include <cmath> // Math operations
#include <cstdlib> // System operations --> system()
using namespace std;

// Letting know the compiler what functions we'll use (in advance)
void clear_console();
void finish_execution();
void menu();
void get_power();
void get_slope();
void get_quadratic_for_reals();

int main() {
    char start_again;

    do
    {
        clear_console();
        int user_option;

        menu(); // Show user option
        cin >> user_option;

        switch (user_option)
        {
        case 1:
            clear_console();
            get_power();
            clear_console();
            break;
        case 2:
            clear_console();
            get_slope();
            clear_console();
            break;
        case 3:
            clear_console();
            get_quadratic_for_reals();
            clear_console();
            break;
        case 4:
            // quadratic (complex)
        case 5:
            // cross product
        case 6:
            // matrix symetry
        case 7:
            // systems of equations
        default:
            // call other function
            break;
        }

        cout << "\n--> Deseas hacer otra operación? (Y/N): ";
        cin >> start_again;

    } while (start_again == 'Y' || start_again == 'y');

    cout << "\nBye! :)" << endl;
    return 0;
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

// Clears console for Windows and Unix/Linux/Mac
void clear_console() {
	#ifdef _WIN32
    	system("cls"); // Windows
	#else
    	system("clear"); // Unix/Linux/Mac
	#endif
}

// Call this function to finish the execution of other functions from the MENU
void finish_execution() {
    cout << "\nPresiona ENTER para regresar al menu: ";
    cin.ignore(); // Ignore any characters in the buffer
    cin.get(); // Wait until the user press ENTER
}


void get_slope() {
    float x1, y1, x2, y2;
    float result = 0;
    char comma; // To read and ignore the comma
    string input1, input2; // Input treated as string
    
    cout << "Utiliza el siguiente formato: 1,2 | 5,9 | 8,4" << endl << endl;
    
    cout << "--> Ingresa las coordenadas del primer punto (x1, y1): ";
    getline(cin, input1); // Read the entire line as a string
    
    cout << "--> Ingresa las coordenadas del segundo punto (x2, y2): ";
    getline(cin, input2); // Read the entire line as a string

    // Using stringstream to parse the input based on the comma delimiter
    stringstream ss1(input1);
    stringstream ss2(input2);

    ss1 >> x1 >> comma >> y1;
    ss2 >> x2 >> comma >> y2;

    if (x2 - x1 == 0) {
        cout << "\n* ERROR: División por cero. Los puntos tienen la misma coordenada x." << endl;
    } else {
        result = (y2 - y1) / (x2 - x1);
        cout << "\n==> La pendiente es: " << "m = " << result << endl;
    }

    finish_execution();
}

void get_power() {
    float base, expo;
    cout << "--> Ingresa la base: ";
    cin >> base;
    cout << "--> Ingresa el exponente: ";
    cin >> expo;
    
    float res = pow(base, expo);
    cout << "\n==> Resultado: " << res << endl;
    finish_execution();
}

void get_quadratic_for_reals(){
    float a, b, c;
    cout << "Ingresa el valor de a: ";
    cin >> a;
    cout << "Ingresa el valor de b: ";
    cin >> b;
    cout << "Ingresa el valor de c: ";
    cin >> c;
   
    if (a == 0) {
        cout << "No es ecuación cuadrática, tiene que ser diferente de 0." << endl;
    }
        float discriminating = b*b - 4 * a * c;
        if (discriminating > 0) {
            float raiz1 = (-b + sqrt(discriminating)) / (2 * a);
            float raiz2 = (-b - sqrt(discriminating)) / (2 * a);
            cout << "Raíces reales y distintas: " << endl;
            cout << "Raíz 1 = " << raiz1 << endl;
            cout << "Raíz 2 = " << raiz2 << endl;
    } else if (discriminating == 0) {
        float raiz = -b / (2 * a);
        cout << "Raíz real doble: " << raiz << endl;
    } else {
        cout << "Esta ecuación tiene raíces complejas por lo que es imposible resolverla unicamente con números reales." << endl;
    }

    finish_execution();
}
