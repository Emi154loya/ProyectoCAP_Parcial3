#include <iostream>
#include <thread>
#include <stdexcept>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

// Funciones y procedimientos
// Algebra
void formulaGral();
// Geometria
void volumenCubo();

int main()
{
    int choice=0;
    int choice2=0;

    cout << "================================================================" << endl;
    cout << "============ Bienvenido a la Calculadora Formularia ============" << endl;
    cout << "================================================================" << endl;
    cout << "Escoge una opcion del menu" << endl;
    cout << "[1] Algebra" << endl;
    cout << "[2] Geometria" << endl;
    cin >> choice;

    // Switch para desplegar segundo menu
    switch (choice)
    {
    case 1:
        cout << "====== Formulas de algebra ======" << endl;
        cout << "[1] Formula general" << endl;
        cin >> choice2;
        // Switch para utilizar el procedimiento escogido
        switch (choice2)
        {
        case 1:
            formulaGral();
            break;
        
        default:
            break;
        }
        break;

    case 2:
        cout << "====== Formulas de geometria ======" << endl;
        cout << "[1] Volumen de un cono" << endl;
        cin >> choice2;
        // Switch para utilizar el procedimiento escogido
        switch (choice2)
        {
        case 1:
            volumenCubo();
            break;
        
        default:
            break;
        }

    default:
        break;
    }
    

    return 0;
}

/*
================
****ALGEBRA*****
================
*/

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

/*
================
***GEOMETRIA****
================
*/

// Volumen de un cubo
void volumenCubo(){
    double radioBase=0, altura=0, volumen=0;

    cout << "Introduce el radio de la base" << endl;
    cin >> radioBase;
    cout << "Introduce la altura" << endl;
    cin >> altura;
    volumen=((M_PI*(pow(radioBase, 2)*altura))/3);

    cout << "El volumen es: " << volumen << endl;
}