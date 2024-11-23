#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <cmath> // Math operations
#include <cstdlib> // System operations --> system()
#include <iomanip> // For std::setw()
#include <fstream> // For file handling
using namespace std;

// ---------------------------------- Structs ---------------------------------- //
struct QuadraticValues{
    float a;
    float b;
    float c;
};

struct LinearValues {
    float m;
    float b;
};

struct FunctionRanges {
    int start_range;
    int end_range;
};

// --------- Letting know the compiler what functions we'll use (in advance) --------- //
void clear_console();
void finish_execution();
void displayMatrix(const vector<vector<int>>& matrixA);
void menu();
void get_power();
void get_slope();
void get_quadratic_for_reals();
void get_quadratic_for_imaginaries();
void get_matrix_symmetry();
void tabulate_points();
void write_points_from_linear(int start_range, int end_range, float m, float b);
void write_points_from_quadratic(int start_range, int end_range, float a, float b, float c);
QuadraticValues ask_quadratic_values();
LinearValues ask_linear_values();
FunctionRanges ask_function_ranges();

// ---------------------------------- Main ---------------------------------- //
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
            clear_console();
            get_quadratic_for_imaginaries();
            clear_console();
            break;
        case 5:
            // cross product
        case 6:
            clear_console();
            get_matrix_symmetry();
            clear_console();
            break;
        case 7:
            // systems of equations
        case 8:
            clear_console();
            tabulate_points();
            clear_console();
            break;
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
    cout << "=      --- SCI-CALCULATOR ---        = " << endl;
    cout << "======================================" << endl;
    cout << "         MENU DE OPCIONES            " << endl;
    cout << "======================================" << endl;
    cout << "1. Obtener la potencia n de un numero." << endl;
    cout << "2. Obtener la pendiente de una recta a traves de dos puntos (x, y)." << endl;
    cout << "3. Ecuaciones cuadraticas (reales)." << endl;
    cout << "4. Ecuaciones cuadraticas (complejas)." << endl;
    cout << "5. Producto cruz de dos vectores de dimension 3." << endl;
    cout << "6. Determinar si una matriz de n x n es simetrica." << endl;
    cout << "7. Resolucion de sistemas de ecuaciones de 3 incognitas." << endl;
    cout << "8. Tabular resultados de ecuaciones lineales & cuadraticas (TXT)." << endl;
    cout << "======================================" << endl;
    cout << "Seleccione una opción: ";
}

// ---------------------------------- Utility Functions ---------------------------------- //
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

void displayMatrix(const vector<vector<int>>& matrixA) {
    for (int i = 0; i < matrixA.size(); i++) {
        for (int j = 0; j < matrixA.size(); j++) {
            cout << setw(4) << matrixA[i][j] << " |"; // Set a width of 4 for each element
        }
        cout << endl;
        
        // Print a separator line after each row
        for (int k = 0; k < matrixA.size(); k++) {
            cout << " -----";
        }
        cout << endl;
    }
}

void write_points_from_linear(int start_range, int end_range, float m, float b) {
    ofstream file_for_tabulation;
    file_for_tabulation.open("results_linear.txt", ios::out);

    if (file_for_tabulation.fail()) {
        cout << "\n\n==> ERROR: Mientras se guardaba el archivo" << endl;
        // return 1;  // Exit the program if the file cannot be opened
    }
    // X = 3  ==>  Y = 8

    file_for_tabulation << "------------ Puntos Tabulados ------------" << endl << endl;
    file_for_tabulation << "Rango: [" << start_range << ", " << end_range << "]" << endl;
    file_for_tabulation << "Ecuacion: y = " << m << "x" << " + " << b << endl << endl;

    for (int x = start_range; x <= end_range; x++) {
        float y = m * x + b;
        file_for_tabulation << "X = " << x << "  ==>  Y = " << y << endl;
    }

    file_for_tabulation.close();
    cout << "\n==> Puntos correctamente tabulados en el archivo results_linear.txt" << endl;
    finish_execution();
}

void write_points_from_quadratic(int start_range, int end_range, float a, float b, float c) {
    ofstream file_for_tabulation;
    file_for_tabulation.open("results_quadratic.txt", ios::out);

    if (file_for_tabulation.fail()) {
        cout << "\n\n==> ERROR: Mientras se guardaba el archivo" << endl;
        // return 1;  // Exit the program if the file cannot be opened
    }

    file_for_tabulation << "------------ Puntos Tabulados ------------" << endl << endl;
    file_for_tabulation << "Rango: [" << start_range << ", " << end_range << "]" << endl;
    file_for_tabulation << "Ecuacion: y = " << a << "x^2 + " << b << "x + " << c << endl << endl;

    for (int x = start_range; x <= end_range; x++) {
        float y = (a * pow(x, 2)) + (b * x) + c;
        file_for_tabulation << "X = " << x << "  ==>  Y = " << y << endl;
    }

    file_for_tabulation.close();
    cout << "\n==> Puntos correctamente tabulados en el archivo results_linear.txt" << endl;
    finish_execution();
}

QuadraticValues ask_quadratic_values() {
    float a, b, c;
    cout << "\n\n--> Ingresa el valor de A: ";
    cin >> a;
    cout << "--> Ingresa el valor de B: ";
    cin >> b;
    cout << "--> Ingresa el valor de C: ";
    cin >> c;

    return {a, b, c};
}

LinearValues ask_linear_values() {
    float m, b;
    cout << "\n\n--> Ingresa el valor de M: ";
    cin >> m;
    cout << "--> Ingresa el valor de B: ";
    cin >> b;

    return {m, b};
}

FunctionRanges ask_function_ranges() {
    int start_range, end_range;

    cout << "\nEscribe el rango de INICIO: ";
    cin >> start_range;
    cout << "Escribe el rango de FIN: ";
    cin >> end_range;

    return {start_range, end_range};
}

// ---------------------------------- Main Functions ---------------------------------- //
// --------- Function #1 --------- //
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

// --------- Function #2 --------- //
void get_slope() {
    float x1, y1, x2, y2;
    float result = 0;
    
    cout << "Utiliza el siguiente formato: 5 9 (cada valor separado por un espacio)" << endl << endl;
    
    cout << "--> Ingresa las coordenadas del primer punto (x1, y1): ";
    cin >> x1 >> y1;
    
    cout << "--> Ingresa las coordenadas del segundo punto (x2, y2): ";
    cin >> x2 >> y2;

    if (x2 - x1 == 0) {
        cout << "\n* ERROR: División por cero. Los puntos tienen la misma coordenada x." << endl;
    } else {
        result = (y2 - y1) / (x2 - x1);
        cout << "\n==> Resultado: " << "m = " << result << endl;
    }

    finish_execution();
}

// --------- Function #3 --------- //
void get_quadratic_for_reals(){
    float a, b, c;
    cout << "--> Ingresa el valor de a: ";
    cin >> a;
    cout << "--> Ingresa el valor de b: ";
    cin >> b;
    cout << "--> Ingresa el valor de c: ";
    cin >> c;
   
    float discriminating = (b * b) - 4 * a * c;

    if (a == 0) {
        cout << "\n* ERROR: No es una ecuación cuadrática, \"a\" tiene que ser diferente de 0." << endl;
    } else if (discriminating > 0) {
        float root1 = (-b + sqrt(discriminating)) / (2 * a);
        float root2 = (-b - sqrt(discriminating)) / (2 * a);
        cout << "\nRaíces reales y distintas: " << endl;
        cout << "--> Raíz 1 = " << root1 << endl;
        cout << "--> Raíz 2 = " << root2 << endl;
    } else if (discriminating == 0) {
        float raiz = -b / (2 * a);
        cout << "\n--> Raíz real doble: " << raiz << endl;
    } else {
        cout << "\n* ADVERTENCIA: Esta ecuación tiene raíces complejas\n  por lo que es imposible resolverla unicamente con números reales." << endl;
    }

    finish_execution();
}

// --------- Function #4 --------- //
void get_quadratic_for_imaginaries(){
    float a, b, c;
    cout << "--> Ingresa el valor de a: ";
    cin >> a;
    cout << "--> Ingresa el valor de b: ";
    cin >> b;
    cout << "--> Ingresa el valor de c: ";
    cin >> c;
   
    float discriminating = (b * b) - 4 * a * c;

    if (a == 0) {
        cout << "\n* ERROR: No es una ecuación cuadrática, \"a\" tiene que ser diferente de 0." << endl;
    } else if (discriminating < 0) {
        float root1 = (-b / (2 * a)) + (sqrt(abs(discriminating)) / (2 * a));
        float root2 = (-b / (2 * a)) - (sqrt(abs(discriminating)) / (2 * a));
        cout << "\nRaices Imaginarias: " << endl;
        cout << "--> Raíz 1 = " << root1 << "i" << endl;
        cout << "--> Raíz 2 = " << root2 << "i" << endl;
    } else {
        cout << "\n* ADVERTENCIA: Esta ecuación no tiene raices complejas.\nTe sugerimos utilizar la opción [3] del menu" << endl;
    }

    finish_execution();
}

// --------- Function #6 --------- //
void get_matrix_symmetry() {
    int matrix_size;
    int cell_value;
    bool is_symmetric = true;
    
    cout << "--> Ingresa el tamano de la matriz (max 4): ";
    cin >> matrix_size;
    
    vector<vector<int>> matrixA(matrix_size, vector<int>(matrix_size));
    vector<vector<int>> matrixAT(matrix_size, vector<int>(matrix_size));

    for (int i = 0; i < matrixA.size(); i++) {
        for (int j = 0; j < matrixA.size(); j++) {
            cout << "--> Ingresa el valor en (" << i << ", " << j << "): ";
            cin >> cell_value;
            matrixA[i][j] = cell_value;
            matrixAT[j][i] = cell_value;
        }
    }
    
    cout << "\nMatriz Original:" << endl;
    displayMatrix(matrixA);
    
    cout << "\nMatriz traspuesta para verificar simetria:" << endl;
    displayMatrix(matrixAT);
    
    for (int i = 0; i < matrixA.size(); i++) {
        for (int j = 0; j < matrixA.size(); j++) {
            if (matrixA[i][j] != matrixAT[i][j]) {
                is_symmetric = false;
            }
        }
    }
    
    if (is_symmetric) {
        cout << "\n==> La matriz es simetrica" << endl;
    } else {
        cout << "\n==> La matriz NO es simetrica" << endl;
    }

    finish_execution();    
}

// --------- Function #8 --------- //
void tabulate_points() {
    int user_response;

    cout << "------ Tabular Puntos en Archivo TXT ------" << endl << endl;
    cout << "[1] Funcion Lineal" << endl;
    cout << "[2] Funcion Cuadratica" << endl;
    cout << "\nSeleccione una opción: ";
    cin >> user_response;

    // Check if input failed (non-numeric input)
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(1000, '\n'); // Discard invalid input
        user_response = -1;
    }

    switch (user_response) {
        case 1: {
            FunctionRanges ranges = ask_function_ranges();
            LinearValues values = ask_linear_values();
            write_points_from_linear(ranges.start_range, ranges.end_range, values.m, values.b);
            break;
        }
        case 2: {
            FunctionRanges ranges = ask_function_ranges();
            QuadraticValues values = ask_quadratic_values();
            write_points_from_quadratic(ranges.start_range, ranges.end_range, values.a, values.b, values.c);
            break;
        }
        default: {
            cout << "\n\n==> ERROR: Debes ingresar una opcion valida!" << endl << endl;
            finish_execution();
            break;
        }
    }
}