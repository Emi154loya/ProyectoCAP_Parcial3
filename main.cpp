#include <iostream>
#include <thread>
#include <stdexcept>
#include <cmath>
using namespace std;

// Funciones y metodos
void formulaGral();

int main()
{
    int choice=0;

    cout << "================================================================" << endl;
    cout << "============ Bienvenido a la Calculadora Formularia ============" << endl;
    cout << "================================================================" << endl;
    cout << "Escoge una opcion del menu" << endl;
    cout << "[1] Formula general" << endl;
    cout << "[2] " << endl;
    cin >> choice;

    // Switch para escoger el procedimiento a utilizar
    switch (choice)
    {
    case 1:
        formulaGral();
        break;

    default:
        break;
    }
    

    return 0;
}

// Formula General
void formulaGral(){
    double termCuadratico=0, termLineal=0, termIndepend=0, res1=0, res2=0;

    cout << "Introduce el coeficiente del termino cuadratico" << endl;
    cin >> termCuadratico;
    cout << "Introduce el coeficiente del termino lineal" << endl;
    cin >> termLineal;
    cout << "Introduce el coeficiente del termino independiente" << endl;
    cin >> termIndepend;
    
    // Discriminante sumado
    res1=((-1*termLineal)+(sqrt((pow(termLineal, 2))-(4*termCuadratico*termIndepend))))/(2*termCuadratico);
    // Discriminante restado
    res2=((-1*termLineal)-(sqrt((pow(termLineal, 2))-(4*termCuadratico*termIndepend))))/(2*termCuadratico);

    // X sumado
    cout << "x+ = " << res1 << endl;
    // X restado
    cout << "x- = " << res2 << endl;

}