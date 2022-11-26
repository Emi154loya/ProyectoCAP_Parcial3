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

// --Funciones y procedimientos
// Algebra
void formulaGral();
// Geometria
void volumenCono();
void volumenTroncoCono();
void volumenEsfera();
void volumenPiramideCuadrada();
void volumenTetraedroRegular();
void volumenTetraedroBaseRegular();
void volumenCasqueteApotema();
void volumenCasqueteEsfera();
// Aritmetica
void aritmeticaFracciones();
// Fisica
void movimientoRectilineoUniforme();
void movimientoRectilineoUniformementeAcelerado();
void velocidadMovimientoCircularUniforme();
void velocidadAngularMovimientoCircularUniforme();
void periodoMovimientoCircularUniforme();
void aceleracionCentripetaMovimientoCircularUniforme();
void tiroParabolico();
void fuerza();
void peso();
void friccion();
void fuerzaElastica();
void trabajo();
void energiaCinetica();
void energiaPotencial();
void energiaPotencialElastica();
void potencia();

struct Fraccion
{
    int numerador = 0, denominador = 0;

    Fraccion(int N, int D)
    {
        numerador = N;
        denominador = D;
    }

    Fraccion operator+(Fraccion a)
    {
        Fraccion resultado(0, 0);
        if (denominador == 0 || a.denominador == 0)
        {
            throw invalid_argument("!!! ERROR: El denominador no puede ser 0 !!!");
        }
        if (denominador == a.denominador)
        {
            resultado.numerador = numerador + a.numerador;
            resultado.denominador = denominador;
        }
        else
        {
            resultado.numerador = (numerador * a.denominador) + (a.numerador * denominador);
            resultado.denominador = denominador * a.denominador;
        }
        return resultado;
    }

    Fraccion operator-(Fraccion a)
    {
        Fraccion resultado(0, 0);
        if (denominador == 0 || a.denominador == 0)
        {
            throw invalid_argument("!!! ERROR: El denominador no puede ser 0 !!!");
        }
        if (denominador == a.denominador)
        {
            resultado.numerador = numerador - a.numerador;
            resultado.denominador = denominador;
        }
        else
        {
            resultado.numerador = (numerador * a.denominador) - (a.numerador * denominador);
            resultado.denominador = denominador * a.denominador;
        }
        return resultado;
    }

    Fraccion operator/(Fraccion a)
    {
        Fraccion resultado(0, 0);

        resultado.numerador = numerador * a.denominador;
        resultado.denominador = denominador * a.numerador;

        if (resultado.denominador == 0)
        {
            throw invalid_argument("!!! ERROR: El denominador resultante es cero !!!");
        }

        return resultado;
    }

    Fraccion operator*(Fraccion a)
    {
        Fraccion resultado(0, 0);
        if (denominador == 0 || a.denominador == 0)
        {
            throw invalid_argument("!!! ERROR: El denominador no puede ser 0 !!!");
        }

        resultado.numerador = numerador * a.numerador;
        resultado.denominador = denominador * a.denominador;

        return resultado;
    }

    // Funciones friend para sobrecargar los operadores stream
    friend std::ostream &operator<<(std::ostream &os, Fraccion &obj)
    {
        os << obj.numerador << " / " << obj.denominador << endl;
        return os;
    }
    void print() { cout << numerador << " / " << denominador << endl; }
};

int main()
{
    int choice = 0;
    int choice2 = 0;
    int choice3 = 0;

    // do while para ciclar el menu
    do
    {
        cout << "================================================================" << endl;
        cout << "============ Bienvenido a la Calculadora Formularia ============" << endl;
        cout << "================================================================" << endl;
        cout << "Escoge una opcion del menu" << endl;
        cout << "[1] Algebra" << endl;
        cout << "[2] Geometria" << endl;
        cout << "[3] Aritmetica" << endl;
        cout << "[4] Fisica" << endl;
        cout << "[5] Salir" << endl;
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
                catch (invalid_argument &e)
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
            cout << "[2] Volumen de una esfera" << endl;
            cout << "[3] Volumen de una piramide cuadrada" << endl;
            cout << "[4] Volumen de un Tetraedro (Piramide triangular)" << endl;
            cout << "[5] Volumen de un Casquete" << endl;
            cin >> choice2;
            // Switch para utilizar el procedimiento escogido
            switch (choice2)
            {
            case 1:
                // Switch para desplegar menu Cono
                cout << "====== Formula del cono ======" << endl;
                cout << "[1] Volumen cono completo" << endl;
                cout << "[2] Volumen tronco de cono" << endl;
                cin >> choice3;
                // Switch para utilizar el procedimiento escogido
                switch (choice3)
                {
                case 1:
                    volumenCono();
                    break;
                case 2:
                    volumenTroncoCono();
                    break;
                default:
                    break;
                }
                break;
            case 2:
                volumenEsfera();
                break;
            case 3:
                volumenPiramideCuadrada();
                break;
            case 4:
                // Switch para desplegar menu Tetraedro
                cout << "====== Tipos de Tetraedro ======" << endl;
                cout << "[1] Volumen regular (caras iguales)" << endl;
                cout << "[2] Volumen con base regular" << endl;
                cin >> choice3;
                // Switch para utilizar el procedimiento escogido
                switch (choice3)
                {
                case 1:
                    volumenTetraedroRegular();
                    break;
                case 2:
                    volumenTetraedroBaseRegular();
                    break;

                default:
                    break;
                }
                break;
            case 5:
                // Switch para desplegar menu Casquetes
                cout << "====== Tipos de Casquetes ======" << endl;
                cout << "[1] Volumen a partir del apotema (radio de la base del casquete)" << endl;
                cout << "[2] Volumen a partir del radio de la esfera" << endl;
                cin >> choice3;
                // Switch para utilizar el procedimiento escogido
                switch (choice3)
                {
                case 1:
                    volumenCasqueteApotema();
                    break;
                case 2:
                    volumenCasqueteEsfera();
                    break;

                default:
                    break;
                }
                break;

            default:
                break;
            }
            break;

        case 3:
            cout << "====== Formulas de Aritmetica ======" << endl;
            cout << "[1] Aritmetica de dos fracciones" << endl;
            cin >> choice2;
            // Switch para utilizar el procedimiento escogido
            switch (choice2)
            {
            case 1:
                aritmeticaFracciones();
                break;

            default:
                break;
            }
            break;
        case 4:
            cout << "====== Formulas de Fisica ======" << endl;
            cout << "[1]  Movimiento rectilineo uniforme" << endl;
            cout << "[2]  Movimiento rectilineo uniformemente acelerado" << endl;
            cout << "[3]  Movimiento circular uniforme" << endl;
            cout << "[4]  Tiro parabolico" << endl;
            cout << "[5]  Fuerza" << endl;
            cout << "[6]  Peso" << endl;
            cout << "[7]  Friccion" << endl;
            cout << "[8]  Fuerza elastica" << endl;
            cout << "[9]  Trabajo" << endl;
            cout << "[10] Energia cinetica" << endl;
            cout << "[11] Energia potencial" << endl;
            cout << "[12] Energia potencial elastica" << endl;
            cout << "[13] Potencia" << endl;
            cin >> choice2;
            switch (choice2)
            {
            case 1:
                movimientoRectilineoUniforme();
                break;
            case 2:
                movimientoRectilineoUniformementeAcelerado();
                break;
            case 3:
                cout << "====== Movimiento Circular Uniforme ======" << endl;
                cout << "[1] Velocidad" << endl;
                cout << "[2] Velocidad angular" << endl;
                cout << "[3] Periodo" << endl;
                cout << "[4] Aceleracion centripeta" << endl;
                cin >> choice3;
                switch (choice3)
                {
                case 1:
                    velocidadMovimientoCircularUniforme();
                    break;
                case 2:
                    velocidadAngularMovimientoCircularUniforme();
                    break;
                case 3:
                    periodoMovimientoCircularUniforme();
                    break;
                case 4:
                    aceleracionCentripetaMovimientoCircularUniforme();
                    break;
                default:
                    break;
                }
                break;
            case 4:
                tiroParabolico();
                break;
            case 5:
                fuerza();
                break;
            case 6:
                peso();
                break;
            case 7:
                friccion();
                break;
            case 8:
                fuerzaElastica();
                break;
            case 9:
                trabajo();
                break;
            case 10:
                energiaCinetica();
                break;
            case 11:
                energiaPotencial();
                break;
            case 12:
                energiaPotencialElastica();
                break;
            case 13:
                potencia();
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }
    } while (choice != 5);

    return 0;
}

/*
================
****ALGEBRA*****
================
*/

// Formula General
void formulaGral()
{
    double termCuadratico = 0, termLineal = 0, termIndepend = 0, res1 = 0, res2 = 0, discriminante = 0;

    cout << "Introduce el coeficiente del termino cuadratico" << endl;
    cin >> termCuadratico;
    cout << "Introduce el coeficiente del termino lineal" << endl;
    cin >> termLineal;
    cout << "Introduce el coeficiente del termino independiente" << endl;
    cin >> termIndepend;

    discriminante = (pow(termLineal, 2)) - (4 * termCuadratico * termIndepend);

    if (discriminante < 0)
    {
        throw invalid_argument("!!! ERROR: El discriminante es negativo, no se puede resolver la ecuacion !!!");
    }

    // Discriminante sumado
    res1 = ((-1 * termLineal) + (sqrt(discriminante))) / (2 * termCuadratico);
    // Discriminante restado
    res2 = ((-1 * termLineal) - (sqrt(discriminante))) / (2 * termCuadratico);

    // X sumado
    cout << "x+ = " << res1 << endl;
    // X restado
    cout << "x- = " << res2 << endl;
}

/*
===============
***GEOMETRIA***
===============
*/

// Volumen de un cono
void volumenCono()
{
    double radioBase = 0, altura = 0, volumen = 0;

    cout << "Introduce el radio de la base" << endl;
    cin >> radioBase;
    cout << "Introduce la altura" << endl;
    cin >> altura;
    volumen = ((M_PI * (pow(radioBase, 2) * altura)) / 3);

    cout << "El volumen es: " << volumen << endl;
}

// Volumen de un tronco de cono
void volumenTroncoCono()
{
    double radioBase = 0, radioBaseMenor = 0, altura = 0, volumen = 0;

    cout << "Introduce el radio mayor del cono" << endl;
    cin >> radioBase;
    cout << "Introduce el radio menor del cono" << endl;
    cin >> radioBaseMenor;
    cout << "Introduce la altura del cono" << endl;
    cin >> altura;
    volumen = ((altura * M_PI * ((pow(radioBase, 2)) + (pow(radioBaseMenor, 2)) + (radioBase * radioBaseMenor))) / 3);

    cout << "El volumen es: " << volumen << endl
         << endl;
}

// Volumen de una esfera
void volumenEsfera()
{
    double radio = 0, volumen = 0;

    cout << "Introduce el radio de la esfera" << endl;
    cin >> radio;
    volumen = ((4 * M_PI * (pow(radio, 3))) / 3);

    cout << "El volumen es: " << volumen << endl
         << endl;
}

// Volumen de una Piramide Cuadrada
void volumenPiramideCuadrada()
{
    double lado = 0, altura = 0, volumen = 0;

    cout << "Introduce el lado de la base" << endl;
    cin >> lado;
    cout << "Introduce la altura" << endl;
    cin >> altura;
    volumen = (((pow(lado, 2)) * altura) / 3);

    cout << "El volumen es: " << volumen << endl
         << endl;
}

// Volumen de un Tetraedro Regular
void volumenTetraedroRegular()
{
    double lado = 0, volumen = 0;

    cout << "Introduce el lado de la base" << endl;
    cin >> lado;
    volumen = ((pow(lado, 3)) * ((sqrt(2)) / 12));

    cout << "El volumen es: " << volumen << endl
         << endl;
}

// Volumen de un Tetraedro con base Regular
void volumenTetraedroBaseRegular()
{
    double lado = 0, altura = 0, volumen = 0;

    cout << "Introduce el lado de la base" << endl;
    cin >> lado;
    cout << "Introduce la altura del tetraedro" << endl;
    cin >> altura;

    volumen = (altura * (pow(lado, 2)) * ((sqrt(3)) / 12));

    cout << "El volumen es: " << volumen << endl
         << endl;
}

// Volumen de un casquete usando apotema
void volumenCasqueteApotema()
{
    double altura = 0, apotema = 0, volumen = 0;

    cout << "Introduce el radio de la base del casquete (apotema)" << endl;
    cin >> apotema;
    cout << "Introduce la altura del casquete" << endl;
    cin >> altura;
    volumen = (((M_PI * altura) * ((3 * (pow(apotema, 2))) + (pow(altura, 2)))) / 6);

    cout << "El volumen es: " << volumen << endl
         << endl;
}

// Volumen de un casquete desde el radio de la esfera
void volumenCasqueteEsfera()
{
    double altura = 0, radio = 0, volumen = 0;

    cout << "Introduce el radio de la esfera" << endl;
    cin >> radio;
    cout << "Introduce la altura del casquete" << endl;
    cin >> altura;
    volumen = (((M_PI * (pow(altura, 2))) * ((3 * radio) - altura)) / 3);

    cout << "El volumen es: " << volumen << endl
         << endl;
}

/*
================
***ARITMETICA***
================
*/

// Aritmetica de dos fracciones
void aritmeticaFracciones()
{
    Fraccion fraccionA(0, 0), fraccionB(0, 0), resultado(0, 0);

    cout << "Introduce el numerador de tu primera fraccion: ";
    cin >> fraccionA.numerador;
    cout << "Introduce el denominador de tu primera fraccion: ";
    cin >> fraccionA.denominador;
    cout << "Introduce el numerador de tu segunda fraccion: ";
    cin >> fraccionB.numerador;
    cout << "Introduce el denominador de tu segunda fraccion: ";
    cin >> fraccionB.denominador;

    resultado = fraccionA + fraccionB;
    cout << "La suma es: " << resultado << endl;
    resultado = fraccionA - fraccionB;
    cout << "La resta es: " << resultado << endl;
    resultado = fraccionA / fraccionB;
    cout << "La division es: " << resultado << endl;
    resultado = fraccionA * fraccionB;
    cout << "La multiplicacion es: " << resultado << endl;
}

/*
================
***FISICA***
================
*/

// Movimiento Rectilineo Uniforme
void movimientoRectilineoUniforme()
{
    double posicionF = 0, posicionI = 0, velocidad = 0, tiempo = 0;

    cout << "Introduce la posicion inicial (en m): ";
    cin >> posicionI;
    cout << "Introduce la velocidad (en m/s):";
    cin >> velocidad;
    cout << "Introduce el tiempo (en s): ";
    cin >> tiempo;

    posicionF = posicionI + (velocidad * tiempo);
    cout << "La posicion final es: " << posicionF << "m" << endl;
}

void movimientoRectilineoUniformementeAcelerado()
{
    double posicionF = 0, velocidadF = 0, posicionI = 0, velocidadI = 0, aceleracion = 0, tiempo = 0;
    cout << "Introduce la posicion inicial (en m): ";
    cin >> posicionI;
    cout << "Introduce la velocidad inicial (en m/s): ";
    cin >> velocidadI;
    cout << "Introduce la aceleracion (en m/s^2): ";
    cin >> aceleracion;
    cout << "Introduce el tiempo (en s): ";
    cin >> tiempo;

    posicionF = posicionI + (velocidadI * tiempo) + ((aceleracion * pow(tiempo, 2)) / 2);
    velocidadF = velocidadI + (aceleracion * tiempo);
    cout << "La posicion final es: " << posicionF << "m" << endl;
    cout << "La velocidad final es: " << velocidadF << "m/s" << endl;
}

void velocidadMovimientoCircularUniforme()
{
}
void velocidadAngularMovimientoCircularUniforme()
{
}
void periodoMovimientoCircularUniforme()
{
}
void aceleracionCentripetaMovimientoCircularUniforme()
{
}
void tiroParabolico()
{
}
void fuerza()
{
}
void peso()
{
}
void friccion()
{
}
void fuerzaElastica()
{
}
void trabajo()
{
}
void energiaCinetica()
{
}
void energiaPotencial()
{
}
void energiaPotencialElastica()
{
}
void potencia()
{
}
