/*
    Equipo System32
    Integrantes:
        @Victor Daniel Chávez Medina
        @Erick Fernando Nevarez Avila
        @Emiliano Loya Flores
        @Luis Alan Martinez Garcia
    "No hemos brindado ni recibido asistencia no autorizada en este proyecto."
*/
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
void volumenCono();

int main()
{
    int choice=0;
    int choice2=0;

    
    // do while para ciclar el menu
    do
    {
        cout << "================================================================" << endl;
        cout << "============ Bienvenido a la Calculadora Formularia ============" << endl;
        cout << "================================================================" << endl;
        cout << "Escoge una opcion del menu" << endl;
        cout << "[1] Algebra" << endl;
        cout << "[2] Geometria" << endl;
        cout << "[3] Salir" << endl;
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
                try
                {
                    formulaGral();
                }
                catch(invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
                
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
                volumenCono();
                break;
            
            default:
                break;
            }

        case 3:            
            break;

        default:
            break;
        }
    } while (choice!=3);
    
    return 0;
}

/*
================
****ALGEBRA*****
================
*/

// Formula General
void formulaGral(){
    double termCuadratico=0, termLineal=0, termIndepend=0, res1=0, res2=0, discriminante=0;

    cout << "Introduce el coeficiente del termino cuadratico" << endl;
    cin >> termCuadratico;
    cout << "Introduce el coeficiente del termino lineal" << endl;
    cin >> termLineal;
    cout << "Introduce el coeficiente del termino independiente" << endl;
    cin >> termIndepend;
    
    discriminante=(pow(termLineal, 2))-(4*termCuadratico*termIndepend);

    if (discriminante<0)
    {
        throw invalid_argument("!!! ERROR: El discriminante es negativo, no se puede resolver la ecuacion !!!");
    }
    
    // Discriminante sumado
    res1=((-1*termLineal)+(sqrt(discriminante)))/(2*termCuadratico);
    // Discriminante restado
    res2=((-1*termLineal)-(sqrt(discriminante)))/(2*termCuadratico);

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

// Volumen de un cono
void volumenCono(){
    double radioBase=0, altura=0, volumen=0;

    cout << "Introduce el radio de la base" << endl;
    cin >> radioBase;
    cout << "Introduce la altura" << endl;
    cin >> altura;
    volumen=((M_PI*(pow(radioBase, 2)*altura))/3);

    cout << "El volumen es: " << volumen << endl;
}