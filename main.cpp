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
#include <exception>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include <vector>
#include <future>
#include <mutex>

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
void operacionesBasicas();
double suma(double, double);
double resta(double, double);
double multiplicacion(double, double);
double division(double, double);
// Fisica
void movimientoRectilineoUniforme();
void movimientoRectilineoUniformementeAcelerado();
void velocidadMovimientoCircularUniforme();
void velocidadAngularMovimientoCircularUniforme();
void periodoMovimientoCircularUniforme();
void aceleracionCentripetaMovimientoCircularUniforme();
void velocidadesXY_TiroParabolico();
void velocidadInicialY_TiroParabolico();
void alturaMaximaTiroParabolico();
void alcanceTiroParabolico();
void fuerza();
void peso();
void friccion();
void fuerzaElastica();
void trabajo();
void energiaCinetica();
void energiaPotencial();
void energiaPotencialElastica();
void potencia();
// Metodos Numericos
void derivacionFuncionEvaluada();
// Operaciones Simples
void Suma (int a, int b, int Result);
void Suma (double a, double b, double Result);
void Resta (int a, int b, int Result);
void Resta (double a, double b, double Result);
void Multiplicacion (int a, int b, int Result);
void Multiplicacion (double a, double b, double Result);
void Division (int a, int b, int Result);
void Division (double a, double b, double Result);

// Mutex Guard
mutex guardia;

void velocidadX_TiroParabolico(double &velocidadX, double velocidadI, double angulo)
{
    guardia.lock();
    velocidadX = velocidadI * cos(angulo);
    guardia.unlock();
}
void velocidadY_TiroParabolico(double &velocidadY, double velocidadI, double angulo, double aceleracion, double tiempo)
{
    guardia.lock();
    double velocidadIY = 0;
    velocidadIY = velocidadI * sin(angulo);
    velocidadY = velocidadIY + (aceleracion * tiempo);
    guardia.unlock();
}

// ---- Excepciones personalizadas ----

// Excepcion para el volumen negativo
struct ExcepcionVolumenNegativo : public exception
{
    const char *what() const throw()
    {
        return "!!! ERROR: El volumen es negativo, no se puede resolver la ecuacion !!!";
    }
};
struct ExcepcionTiempoNegativo : public exception
{
    const char *what() const throw()
    {
        return "!!! ERROR: El tiempo es negativo, no se puede resolver la operacion !!!";
    }
};
struct ExcepcionMasaNegativa : public exception
{
    const char *what() const throw()
    {
        return "!!! ERROR: La masa es negativa, no se puede resolver la operacion !!!";
    }
};
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

    //Variables para Operaciones Simples
    int aI=0 ,bI=0 ,ResultI=0;
    double aD=0 ,bD=0 ,ResultD=0;
    
    // do while para ciclar el menu
    do
    {
        try
        {
            cout << "================================================================" << endl;
            cout << "============ Bienvenido a la Calculadora Formularia ============" << endl;
            cout << "================================================================" << endl;
            cout << "Escoge una opcion del menu" << endl;
            cout << "[1] Algebra" << endl;
            cout << "[2] Geometria" << endl;
            cout << "[3] Aritmetica" << endl;
            cout << "[4] Fisica" << endl;
            cout << "[5] Metodos Numericos" << endl;
            cout << "[6] Operaciones simples" << endl;
            cout << "[7] Salir" << endl;
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
                    throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
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
                        throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
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
                        throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
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
                        throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
                        break;
                    }
                    break;

                default:
                    throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
                    break;
                }
                break;

            case 3:
                cout << "====== Formulas de Aritmetica ======" << endl;
                cout << "[1] Aritmetica de dos fracciones" << endl;
                cout << "[2] Operaciones basicas de dos numeros" << endl;
                cin >> choice2;
                // Switch para utilizar el procedimiento escogido
                switch (choice2)
                {
                case 1:
                    aritmeticaFracciones();
                    break;
                case 2:
                    operacionesBasicas();
                    break;

                default:
                    throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
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
                        throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
                        break;
                    }
                    break;
                case 4:
                    cout << "====== Tiro Parabolico ======" << endl;
                    cout << "[1] Velocidad en X y Y" << endl;
                    cout << "[2] Velocidad inicial en Y" << endl;
                    cout << "[3] Altura maxima" << endl;
                    cout << "[4] Alcance" << endl;
                    cin >> choice3;

                    switch (choice3)
                    {
                    case 1:
                        velocidadesXY_TiroParabolico();
                        break;
                    case 2:
                        velocidadInicialY_TiroParabolico();
                        break;
                    case 3:
                        alturaMaximaTiroParabolico();
                        break;
                    case 4:
                        alcanceTiroParabolico();
                        break;

                    default:
                        throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
                        break;
                    }
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
                    throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
                    break;
                }
                break;

            case 5:
                cout << "====== Metodos Numericos ======" << endl;
                cout << "[1]  Derivacion de una funcion(evaluada)" << endl;
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                    derivacionFuncionEvaluada();
                    break;
                default:
                    throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
                    break;
                }
                break;

            case 6:
                cout << "====== Operaciones Simples ======" << endl;
                cout << "[1] Suma Enteros" << endl;
                cout << "[2] Suma con decimales" << endl;
                cout << "[3] Resta Enteros" << endl;
                cout << "[4] Resta con decimales" << endl;
                cout << "[5] Multiplicacion Enteros" << endl;
                cout << "[6] Multiplicacion con decimales" << endl;
                cout << "[7] Division Enteros" << endl;
                cout << "[8] Division con decimales" << endl;
                cin >> choice2;
                switch(choice2)
                {
                case 1:
                    cout<<"Favor de introducir el primer valor"<<endl;
                    cin>>aI;
                    cout<<"Favor de introducir el segundo valor"<<endl;
                    cin>>bI;
                    Suma(aI,bI,ResultI);
                    break;
                case 2:
                    cout<<"Favor de introducir el primer valor"<<endl;
                    cin>>aI;
                    cout<<"Favor de introducir el segundo valor"<<endl;
                    cin>>bI;
                    Suma(aD,bD,ResultD);
                    break;
                case 3:
                    cout<<"Favor de introducir el primer valor"<<endl;
                    cin>>aI;
                    cout<<"Favor de introducir el segundo valor"<<endl;
                    cin>>bI;
                    Resta(aI,bI,ResultI);
                    break;
                case 4:
                    cout<<"Favor de introducir el primer valor"<<endl;
                    cin>>aI;
                    cout<<"Favor de introducir el segundo valor"<<endl;
                    cin>>bI;
                    Resta(aD,bD,ResultD);
                    break;
                case 5:
                    cout<<"Favor de introducir el primer valor"<<endl;
                    cin>>aI;
                    cout<<"Favor de introducir el segundo valor"<<endl;
                    cin>>bI;
                    Multiplicacion(aI,bI,ResultI);
                    break;
                case 6:
                    cout<<"Favor de introducir el primer valor"<<endl;
                    cin>>aI;
                    cout<<"Favor de introducir el segundo valor"<<endl;
                    cin>>bI;
                    Multiplicacion(aD,bD,ResultD);
                    break;
                case 7:
                    cout<<"Favor de introducir el primer valor"<<endl;
                    cin>>aI;
                    cout<<"Favor de introducir el segundo valor"<<endl;
                    cin>>bI;
                    Division(aI,bI,ResultI);
                    break;
                case 8:
                    cout<<"Favor de introducir el primer valor"<<endl;
                    cin>>aI;
                    cout<<"Favor de introducir el segundo valor"<<endl;
                    cin>>bI;
                    Division(aD,bD,ResultD);
                    break;
                default:
                    throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
                    break;
                }
                break;

            case 7:
                break;
            default:
                throw invalid_argument("!!! ERROR: Esa opcion no esta en el menu !!!");
                break;
            }
        }
        catch (ExcepcionVolumenNegativo &excepcionVolumenNegativo)
        {
            cout << excepcionVolumenNegativo.what() << endl;
        }
        catch (ExcepcionTiempoNegativo &excepcionTiempoNegativo)
        {
            cout << excepcionTiempoNegativo.what() << endl;
        }
        catch (ExcepcionMasaNegativa &excepcionMasaNegativa)
        {
            cout << excepcionMasaNegativa.what() << endl;
        }
        catch (invalid_argument &ia)
        {
            cout << ia.what() << endl;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }

    } while (choice != 7);

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
    double *PTRVARIABLES = new double[3];
    // 0 radiobase, 1 altura, 2 volumen
    cout << "Introduce el radio de la base" << endl;
    cin >> PTRVARIABLES[0];
    cout << "Introduce la altura" << endl;
    cin >> PTRVARIABLES[1];
    PTRVARIABLES[2] = ((M_PI * (pow(PTRVARIABLES[0], 2) * PTRVARIABLES[1])) / 3);

    if (PTRVARIABLES[2] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionVolumenNegativo();
    }

    cout << "El volumen es: " << PTRVARIABLES[2] << endl;
    delete[] PTRVARIABLES;
}

// Volumen de un tronco de cono
void volumenTroncoCono()
{

    double *PTRVARIABLES = new double[4];
    // 0 radiobase, 1 radioBaseMenor, 2 altura, 3 volumen
    cout << "Introduce el radio mayor del cono" << endl;
    cin >> PTRVARIABLES[0];
    cout << "Introduce el radio menor del cono" << endl;
    cin >> PTRVARIABLES[1];
    cout << "Introduce la altura del cono" << endl;
    cin >> PTRVARIABLES[2];
    PTRVARIABLES[3] = ((PTRVARIABLES[2] * M_PI * ((pow(PTRVARIABLES[0], 2)) + (pow(PTRVARIABLES[1], 2)) + (PTRVARIABLES[0] * PTRVARIABLES[1]))) / 3);

    if (PTRVARIABLES[3] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionVolumenNegativo();
    }

    cout << "El volumen es: " << PTRVARIABLES[3] << endl
         << endl;
    delete[] PTRVARIABLES;
}

// Volumen de una esfera
void volumenEsfera()
{
    double *PTRVARIABLES = new double[2];
    // 0 radio, 1 volumen

    cout << "Introduce el radio de la esfera" << endl;
    cin >> PTRVARIABLES[0];
    PTRVARIABLES[1] = ((4 * M_PI * (pow(PTRVARIABLES[0], 3))) / 3);

    if (PTRVARIABLES[1] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionVolumenNegativo();
    }

    cout << "El volumen es: " << PTRVARIABLES[1] << endl
         << endl;
    delete[] PTRVARIABLES;
}

// Volumen de una Piramide Cuadrada
void volumenPiramideCuadrada()
{
    double *PTRVARIABLES = new double[3];
    // 0 lado, 1 altura, 2 volumen

    cout << "Introduce el lado de la base" << endl;
    cin >> PTRVARIABLES[0];
    cout << "Introduce la altura" << endl;
    cin >> PTRVARIABLES[1];
    PTRVARIABLES[2] = (((pow(PTRVARIABLES[0], 2)) * PTRVARIABLES[1]) / 3);

    if (PTRVARIABLES[2] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionVolumenNegativo();
    }

    cout << "El volumen es: " << PTRVARIABLES[2] << endl
         << endl;
    delete[] PTRVARIABLES;
}

// Volumen de un Tetraedro Regular
void volumenTetraedroRegular()
{
    double *PTRVARIABLES = new double[2];
    // 0 lado, 1 volumen

    cout << "Introduce el lado de la base" << endl;
    cin >> PTRVARIABLES[0];
    PTRVARIABLES[1] = ((pow(PTRVARIABLES[0], 3)) * ((sqrt(2)) / 12));

    if (PTRVARIABLES[1] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionVolumenNegativo();
    }

    cout << "El volumen es: " << PTRVARIABLES[1] << endl
         << endl;
    delete[] PTRVARIABLES;
}

// Volumen de un Tetraedro con base Regular
void volumenTetraedroBaseRegular()
{
    double *PTRVARIABLES = new double[3];
    // 0 lado, 1 altura, 2 volumen

    cout << "Introduce el lado de la base" << endl;
    cin >> PTRVARIABLES[0];
    cout << "Introduce la altura del tetraedro" << endl;
    cin >> PTRVARIABLES[1];

    PTRVARIABLES[2] = (PTRVARIABLES[1] * (pow(PTRVARIABLES[0], 2)) * ((sqrt(3)) / 12));

    if (PTRVARIABLES[2] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionVolumenNegativo();
    }

    cout << "El volumen es: " << PTRVARIABLES[2] << endl
         << endl;
    delete[] PTRVARIABLES;
}

// Volumen de un casquete usando apotema
void volumenCasqueteApotema()
{
    double *PTRVARIABLES = new double[3];
    // 0 apotema, 1 altura, 2 volumen

    cout << "Introduce el radio de la base del casquete (apotema)" << endl;
    cin >> PTRVARIABLES[0];
    cout << "Introduce la altura del casquete" << endl;
    cin >> PTRVARIABLES[1];
    PTRVARIABLES[2] = (((M_PI * PTRVARIABLES[1]) * ((3 * (pow(PTRVARIABLES[0], 2))) + (pow(PTRVARIABLES[1], 2)))) / 6);

    if (PTRVARIABLES[2] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionVolumenNegativo();
    }

    cout << "El volumen es: " << PTRVARIABLES[2] << endl
         << endl;
    delete[] PTRVARIABLES;
}

// Volumen de un casquete desde el radio de la esfera
void volumenCasqueteEsfera()
{
    double *PTRVARIABLES = new double[3];
    // 0 radio, 1 altura, 2 volumen

    cout << "Introduce el radio de la esfera" << endl;
    cin >> PTRVARIABLES[0];
    cout << "Introduce la altura del casquete" << endl;
    cin >> PTRVARIABLES[1];
    PTRVARIABLES[2] = (((M_PI * (pow(PTRVARIABLES[1], 2))) * ((3 * PTRVARIABLES[0]) - PTRVARIABLES[1])) / 3);

    if (PTRVARIABLES[2] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionVolumenNegativo();
    }

    cout << "El volumen es: " << PTRVARIABLES[2] << endl
         << endl;
    delete[] PTRVARIABLES;
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

    if (fraccionA.denominador == 0 || fraccionB.denominador == 0)
    {
        throw invalid_argument("!!! ERROR: El denominador es igual a cero, no se puede resolver la operacion !!!");
    }

    resultado = fraccionA + fraccionB;
    cout << "La suma es: " << resultado << endl;
    resultado = fraccionA - fraccionB;
    cout << "La resta es: " << resultado << endl;
    resultado = fraccionA / fraccionB;
    cout << "La division es: " << resultado << endl;
    resultado = fraccionA * fraccionB;
    cout << "La multiplicacion es: " << resultado << endl;
}

void operacionesBasicas()
{
    // Arreglo de 4 funciones
    double (*(functions[4]))(double, double) = {suma, resta, multiplicacion, division};

    double x = 0;
    double y = 0;

    int choice = 0;

    cout << "Operacion a realizar:" << endl;
    cout << "[1] Suma" << endl;
    cout << "[2] Resta" << endl;
    cout << "[3] Multiplicacion" << endl;
    cout << "[4] Division" << endl;

    cin >> choice;

    cout << "Ingresa tu primer numero" << endl;
    cin >> x;
    cout << "Ingresa tu segundo numero" << endl;
    cin >> y;

    double res = functions[choice - 1](x, y);
    cout << "El resultado de la operacion es: " << res << endl;
}
double suma(double x, double y)
{
    return x + y;
}

double resta(double x, double y)
{
    return x - y;
}

double multiplicacion(double x, double y)
{
    return x * y;
}

double division(double x, double y)
{
    if (y == 0)
    {
        throw invalid_argument("!!! ERROR: Se esta intentando dividir entre cero !!!");
    }

    return x / y;
}

/*
================
***FISICA***
================
*/

// Movimiento Rectilineo Uniforme
void movimientoRectilineoUniforme()
{
    double *PTRVARIABLES = new double[4];
    // 0 posicionF, 1 posicionI, 2 velocidad, 3 tiempo

    cout << "Introduce la posicion inicial (en m): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce la velocidad (en m/s):";
    cin >> PTRVARIABLES[2];
    cout << "Introduce el tiempo (en s): ";
    cin >> PTRVARIABLES[3];

    if (PTRVARIABLES[3] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionTiempoNegativo();
    }

    PTRVARIABLES[0] = PTRVARIABLES[1] + (PTRVARIABLES[2] * PTRVARIABLES[3]);
    cout << "La posicion final es: " << PTRVARIABLES[0] << " m" << endl;
    delete[] PTRVARIABLES;
}

void movimientoRectilineoUniformementeAcelerado()
{
    double *PTRVARIABLES = new double[6];
    // 0 posicionF, 1 velocidadF, 2 posicionI, 3 velocidadI, 4 aceleracion, 5 tiempo

    cout << "Introduce la posicion inicial (en m): ";
    cin >> PTRVARIABLES[2];
    cout << "Introduce la velocidad inicial (en m/s): ";
    cin >> PTRVARIABLES[3];
    cout << "Introduce la aceleracion (en m/s^2): ";
    cin >> PTRVARIABLES[4];
    cout << "Introduce el tiempo (en s): ";
    cin >> PTRVARIABLES[5];

    if (PTRVARIABLES[5] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionTiempoNegativo();
    }

    PTRVARIABLES[0] = PTRVARIABLES[2] + (PTRVARIABLES[3] * PTRVARIABLES[5]) + ((PTRVARIABLES[4] * pow(PTRVARIABLES[5], 2)) / 2);
    PTRVARIABLES[1] = PTRVARIABLES[3] + (PTRVARIABLES[4] * PTRVARIABLES[5]);
    cout << "La posicion final es: " << PTRVARIABLES[0] << " m" << endl;
    cout << "La velocidad final es: " << PTRVARIABLES[1] << " m/s" << endl;
    delete[] PTRVARIABLES;
}

void velocidadMovimientoCircularUniforme()
{
    double *PTRVARIABLES = new double[3];
    // 0 velocidad, 1 velocidadAngular, 2 radioCurvatura

    cout << "Introduce la velocidad angular (en rad/s): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce el radio de curvatura (en m): ";
    cin >> PTRVARIABLES[2];

    PTRVARIABLES[0] = (PTRVARIABLES[1] * PTRVARIABLES[2]);
    cout << "La velocidad es: " << PTRVARIABLES[0] << " m/s" << endl;
    delete[] PTRVARIABLES;
}

void velocidadAngularMovimientoCircularUniforme()
{
    double *PTRVARIABLES = new double[2];
    // 0 velocidadAngular, 1 frecuecia

    cout << "Introduce la frecuencia (en Hz): ";
    cin >> PTRVARIABLES[1];

    PTRVARIABLES[0] = ((2 * M_PI) * PTRVARIABLES[1]);
    cout << "La velocidad angular es: " << PTRVARIABLES[0] << " m/s" << endl;
    delete[] PTRVARIABLES;
}

void periodoMovimientoCircularUniforme()
{
    double *PTRVARIABLES = new double[2];
    // 0 periodo, 1 frecuecia

    cout << "Introduce la frecuencia (en Hz): ";
    cin >> PTRVARIABLES[1];

    PTRVARIABLES[0] = 1 / PTRVARIABLES[1];
    cout << "El periodo es: " << PTRVARIABLES[0] << " s" << endl;
    delete[] PTRVARIABLES;
}

void aceleracionCentripetaMovimientoCircularUniforme()
{
    double *PTRVARIABLES = new double[3];
    // 0 aceleracionCentripeta, 1 velocidad, 2 radio

    cout << "Introduce la velocidad (en m/s): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce el radio de la curvatura (en m): ";
    cin >> PTRVARIABLES[2];

    PTRVARIABLES[0] = (pow(PTRVARIABLES[1], 2)) / PTRVARIABLES[2];
    cout << "La aceleracion centripeta es: " << PTRVARIABLES[0] << " m/s^2" << endl;
    delete[] PTRVARIABLES;
}

void velocidadesXY_TiroParabolico()
{
    double velocidadX = 0, velocidadY = 0, velocidadI = 0, angulo = 0, anguloRad = 0, aceleracion = 0, tiempo = 0;
    cout << "Introduce la velocidad inicial (en m/s): ";
    cin >> velocidadI;
    cout << "Introduce el angulo: ";
    cin >> angulo;
    cout << "introduce la aceleracion (en m/s^2): ";
    cin >> aceleracion;
    cout << "Introduce el intervalo de tiempo (en s): ";
    cin >> tiempo;

    if (tiempo < 0)
    {
        throw ExcepcionTiempoNegativo();
    }

    anguloRad = (angulo * M_PI) / 180;

    thread velocidadEjeX(velocidadX_TiroParabolico, ref(velocidadX), velocidadI, anguloRad);
    thread velocidadEjeY(velocidadY_TiroParabolico, ref(velocidadY), velocidadI, anguloRad, aceleracion, tiempo);

    velocidadEjeX.join();
    velocidadEjeY.join();

    cout << "La velocidad en el eje X es: " << velocidadX << " m/s" << endl;
    cout << "La velocidad en el eje Y es: " << velocidadY << " m/s" << endl;
}

void velocidadInicialY_TiroParabolico()
{
    double *PTRVARIABLES = new double[4];
    // 0 velocidadIY, 1 velocidadI, 2 angulo, 3 anguloRad

    cout << "Introduce la velocidad inicial (en m/s): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce el angulo: ";
    cin >> PTRVARIABLES[2];

    PTRVARIABLES[3] = (PTRVARIABLES[2] * M_PI) / 180;

    PTRVARIABLES[0] = PTRVARIABLES[1] * sin(PTRVARIABLES[3]);
    cout << "La velocidad inicial en el eje Y es: " << PTRVARIABLES[0] << " m/s" << endl;
    delete[] PTRVARIABLES;
}

void alturaMaximaTiroParabolico()
{
    double *PTRVARIABLES = new double[4];
    // 0 alturaMaxima, 1 velocidadI, 2 angulo, 3 anguloRad

    cout << "Introduce la velocidad inicial (en m/s): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce el angulo de la direccion de lanzamiento: ";
    cin >> PTRVARIABLES[2];

    PTRVARIABLES[3] = (PTRVARIABLES[2] * M_PI) / 180;

    PTRVARIABLES[0] = ((pow(PTRVARIABLES[1], 2)) * (pow(sin(PTRVARIABLES[3]), 2))) / (2 * 9.81);
    cout << "La altura maxima es: " << PTRVARIABLES[0] << " m" << endl;
    delete[] PTRVARIABLES;
}

void alcanceTiroParabolico()
{
    double *PTRVARIABLES = new double[4];
    // 0 alturaMaxima, 1 velocidadI, 2 angulo, 3 anguloRad

    cout << "Introduce la velocidad inicial (en m/s): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce el angulo de la direccion de lanzamiento: ";
    cin >> PTRVARIABLES[2];

    PTRVARIABLES[3] = (PTRVARIABLES[2] * M_PI) / 180;

    PTRVARIABLES[0] = ((pow(PTRVARIABLES[1], 2)) * (pow(sin(PTRVARIABLES[3]), 2))) / (9.81);
    cout << "La altura maxima es: " << PTRVARIABLES[0] << " m" << endl;
    delete[] PTRVARIABLES;
}

void fuerza()
{
    double *PTRVARIABLES = new double[3];
    // 0 fuerza, 1 masa, 2 aceleracion

    cout << "Introduce la masa (en kg): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce la aceleracion (en m/s^2): ";
    cin >> PTRVARIABLES[2];

    if (PTRVARIABLES[1] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionMasaNegativa();
    }

    PTRVARIABLES[0] = PTRVARIABLES[1] * PTRVARIABLES[2];
    cout << "La fuerza resultante es: " << PTRVARIABLES[0] << " N" << endl;
    delete[] PTRVARIABLES;
}

void peso()
{
    const double ConstanteGravitatoria = 9.81;
    double *PTRVARIABLES = new double[2];
    // 0 peso, 1 masa

    cout << "Introduce la masa (en Kg): ";
    cin >> PTRVARIABLES[1];

    if (PTRVARIABLES[1] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionMasaNegativa();
    }

    PTRVARIABLES[0] = PTRVARIABLES[1] * ConstanteGravitatoria;
    cout << "El peso es: " << PTRVARIABLES[0] << " N" << endl;
    delete[] PTRVARIABLES;
}

void friccion()
{
    double *PTRVARIABLES = new double[3];
    // 0 fuerzaFriccion, 1 coeficienteRoce, 2 fuerzaNormal

    cout << "Introduce el coeficiente de friccion: ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce la fuerza normal (en N): ";
    cin >> PTRVARIABLES[2];

    PTRVARIABLES[0] = PTRVARIABLES[2] * PTRVARIABLES[1];
    cout << "La fuerza de friccion es: " << PTRVARIABLES[0] << " N" << endl;
    delete[] PTRVARIABLES;
}

void fuerzaElastica()
{
    double *PTRVARIABLES = new double[3];
    // 0 fuerzaElastica, 1 constanteElasticaResorte, 2 deformacionResorte

    cout << "Introduce la constante elastica del resorte (en N/m): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce la deformacion del resorte (en m): ";
    cin >> PTRVARIABLES[2];

    PTRVARIABLES[0] = PTRVARIABLES[1] * PTRVARIABLES[2];
    cout << "La fuerza elastica es: " << PTRVARIABLES[0] << " N" << endl;
    delete[] PTRVARIABLES;
}

void trabajo()
{
    double *PTRVARIABLES = new double[5];
    // 0 trabajo, 1 fuerza, 2 desplazamiento, 3 angulo, 4 anguloRad

    cout << "Introduce la fuerza (en N): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce el desplazamiento (en m): ";
    cin >> PTRVARIABLES[2];
    cout << "Introduce el angulo entre la direccion de la fuerza y el desplazamiento: ";
    cin >> PTRVARIABLES[3];

    PTRVARIABLES[4] = (PTRVARIABLES[3] * M_PI) / 180;

    PTRVARIABLES[0] = PTRVARIABLES[1] * PTRVARIABLES[2] * cos(PTRVARIABLES[4]);
    cout << "EL trabajo es: " << PTRVARIABLES[0] << " J" << endl;
    delete[] PTRVARIABLES;
}

void energiaCinetica()
{
    double *PTRVARIABLES = new double[3];
    // 0 energiaCinetica, 1 masa, 2 velocidad

    cout << "Introduce la masa (en kg): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce la velocidad (en m/s): ";
    cin >> PTRVARIABLES[2];

    if (PTRVARIABLES[1] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionMasaNegativa();
    }

    PTRVARIABLES[0] = (PTRVARIABLES[1] / 2) * (pow(PTRVARIABLES[2], 2));
    cout << "La energia cinetica es: " << PTRVARIABLES[0] << " J" << endl;
    delete[] PTRVARIABLES;
}

void energiaPotencial()
{
    double *PTRVARIABLES = new double[3];
    // 0 energiaPotencial, 1 masa, 2 altura

    cout << "Introduce la masa (en kg): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce la altura (en m): ";
    cin >> PTRVARIABLES[2];

    if (PTRVARIABLES[1] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionMasaNegativa();
    }

    PTRVARIABLES[0] = PTRVARIABLES[1] * PTRVARIABLES[2] * 9.81;
    cout << "La energia potencial es: " << PTRVARIABLES[0] << " J" << endl;
    delete[] PTRVARIABLES;
}

void energiaPotencialElastica()
{
    double *PTRVARIABLES = new double[3];
    // 0 energiaPotencialElastica, 1 constanteElastica, 2 deformacionResorte

    cout << "Introduce la constante elastica del resorte (en N/m): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce la deformacion del resorte (en m): ";
    cin >> PTRVARIABLES[2];

    PTRVARIABLES[0] = (PTRVARIABLES[1] / 2) * (pow(PTRVARIABLES[2], 2));
    cout << "La energia potencial elastica es: " << PTRVARIABLES[0] << " J" << endl;
    delete[] PTRVARIABLES;
}

void potencia()
{
    double *PTRVARIABLES = new double[3];
    // 0 potencia , 1 trabajo, 2 tiempo

    cout << "Introduce la cantidad e trabajo (en J): ";
    cin >> PTRVARIABLES[1];
    cout << "Introduce el intervalo de tiempo (en s): ";
    cin >> PTRVARIABLES[2];

    if (PTRVARIABLES[2] < 0)
    {
        delete[] PTRVARIABLES;
        throw ExcepcionTiempoNegativo();
    }

    PTRVARIABLES[0] = PTRVARIABLES[1] / PTRVARIABLES[2];
    cout << "La potencia es: " << PTRVARIABLES[0] << " Watts" << endl;
    delete[] PTRVARIABLES;
}
/*
=======================
***METODOS NUMERICOS***
=======================
*/

void derivacionFuncionEvaluada()
{

    int grado = 0;

    cout << "Vamos a introducir tu funcion, por pasos" << endl;
    cout << "Introduce el grado de tu funcion: ";
    cin >> grado;

    //  Creamos un vector que a su vez almacenara mas vectores y estos ultimos vectores almacenaran valores double
    // Esto para almacenar primero cuantas incognitas de n grado vamos a tener y luego de esto asignarle el coeficiente a cada incognita
    // Ejemplo:
    // vector incognitasYSusCoeficientes =  {vector<2,3,4,5>, vector<5>, vector<6, 1>, vector<2,5>}
    // En el ejemplo tenemos un vector padre que almacenara mas vectores, cada vector almacenado representa un grado de x incognita, y cada valor
    // de determinado vector sera un coeficiente de una incognita de dicho grado
    // Siguiendo el ejemplo, nuestra funcion es de grado 3, tenemos cuatro incognitas de grado 0, una de grado 1, dos de grado 2 y dos de grado 3.
    vector<vector<double>> incognitasYSusCoeficientes;

    // Ciclo para ir cambiando la incognita de grado n a n+1
    for (int i = 0; i < grado + 1; i++)
    {
        cout << "Introduce cuantas incognitas de grado [" << i << "] tienes" << endl;
        double temp = 0;
        cin >> temp;

        // Creamos un vector temporal para almacenar los coeficientes de las incognitas
        vector<double> vectortemp;
        // Como es un vector temporal, lo estaremos reestableciendo cada vez que se inicie un nuevo ciclo
        vectortemp.clear();

        if (grado == 0 && temp == 0)
        {
            throw invalid_argument("!!! ERROR: No hay nada que calcular !!!");
        }

        if (temp == 0)
        {
            incognitasYSusCoeficientes.push_back(vectortemp);
        }
        else if (temp > 0)
        {
            cout << "Introduce los coeficientes de tus incognitas de grado [" << i << "] que tienes" << endl;
            // Ciclo para almacenar los coeficientes de la incognita de grado n
            for (int y = 0; y < temp; y++)
            {
                double coeficientetemp = 0;
                cout << "Incognita [" << y + 1 << "]: ";
                cin >> coeficientetemp;
                // A nuestro vector temporal le introduciremos los coeficientes de las incognitas de grado n
                vectortemp.push_back(coeficientetemp);
            }
            // Ya que introducimos todos los coeficientes de las incognitas de grado n al vector temporal, dicho vector lo almacenaremos
            // en el vector principal "incognitasYSusCoeficientes"
            incognitasYSusCoeficientes.push_back(vectortemp);
        }
        else if (temp < 0)
        {
            throw invalid_argument("!!! ERROR: No puede haber cantidad de incognitas negativas. !!!");
        }
    }

    double temp = 0;

    for (int i = 0; i < incognitasYSusCoeficientes.size(); i++)
    {
        for (int y = 0; y < incognitasYSusCoeficientes.at(i).size(); y++)
        {
            temp += incognitasYSusCoeficientes.at(i).size();
        }
    }

    if (temp == 0)
    {
        throw invalid_argument("!!! ERROR: No hay nada que calcular !!!");
    }

    /*
    cout << incognitasYSusCoeficientes.size() << endl;
    cout << incognitasYSusCoeficientes.at(0).size() << endl;
    cout << incognitasYSusCoeficientes.at(1).size() << endl;
    cout << incognitasYSusCoeficientes.at(2).size() << endl;
    cout << "==========" << endl;

    cout << incognitasYSusCoeficientes.at(0).at(0) << endl;
    cout << incognitasYSusCoeficientes.at(1).at(0) << endl;
    cout << incognitasYSusCoeficientes.at(1).at(1) << endl;
    cout << incognitasYSusCoeficientes.at(2).at(0) << endl;
    cout << incognitasYSusCoeficientes.at(2).at(1) << endl;
    cout << incognitasYSusCoeficientes.at(2).at(2) << endl;
    cout << "==========" << endl;
    */

    cout << "Esta seria tu funcion: ";
    // Ciclo para mostrar la funcion dada por partes ya expresada normalmente
    // El primer ciclo va del numero maximo de grado hasta cero, es decir si es de grado 4, va de  4,3,2,1,0
    // Se le resta una unidad por que los arrays o vectores comienzan del 0
    for (int i = incognitasYSusCoeficientes.size() - 1; i >= 0; i--)
    {
        // Ciclo para repasar cada conjunto de coeficientes de las incognitas de grado n
        // Va de 0 al tamaño del conjunto de coeficientes de la incognita i que esta en el primer ciclo
        // Siguiendo el ejemplo de que es grado 4, en el primer ciclo i va a tener el valor de 3 y en el segundo accesaremos al vector en la posicion 3 del
        // vector principal y obtendremos su tamaño
        for (int y = 0; y < incognitasYSusCoeficientes.at(i).size(); y++)
        {

            // Si el coeficiente es negativo, lo mostraremos tal cual ya que c++ lo muestra con su signo
            if (incognitasYSusCoeficientes.at(i).at(y) < 0)
            {
                cout << incognitasYSusCoeficientes.at(i).at(y) << "(x^" << i << ")";
            }
            // Si el coeficiente es positivo, agregaremos el signo de + para que la expresion tenga sentido
            else
            {
                cout << "+" << incognitasYSusCoeficientes.at(i).at(y) << "(x^" << i << ")";
            }
        }
    }
    cout << endl;

    double hTamañodepaso = 0;
    double xI = 0, xIMenosUno = 0, xIMenosDos = 0, xIMasUno = 0, xIMasDos = 0;
    double resultadoDerivada = 0;

    // Variables para almacenar el valor de la funcion evaluada con distintos valores
    double xIMenosUnoEvaluado = 0, xIMenosDosEvaluado = 0, xIMasUnoEvaluado = 0, xIMasDosEvaluado = 0;

    cout << "=========" << endl;
    cout << "Centradas" << endl;
    cout << "=========" << endl;
    cout << "Introduce el valor en el quieres evaluar la derivada: ";
    cin >> xI;
    cout << "Introduce el tamaño de paso: ";
    cin >> hTamañodepaso;

    xIMenosDos = (xI - (hTamañodepaso * 2));
    xIMenosUno = (xI - (hTamañodepaso * 1));
    xIMasUno = (xI + (hTamañodepaso * 1));
    xIMasDos = (xI + (hTamañodepaso * 2));

    // Ciclo para evaluar la funcion con distintos valores
    for (int i = incognitasYSusCoeficientes.size() - 1; i >= 0; i--)
    {
        for (int y = 0; y < incognitasYSusCoeficientes.at(i).size(); y++)
        {
            xIMenosUnoEvaluado += ((incognitasYSusCoeficientes.at(i).at(y)) * (pow(xIMenosUno, i)));
            xIMenosDosEvaluado += ((incognitasYSusCoeficientes.at(i).at(y)) * (pow(xIMenosDos, i)));
            xIMasUnoEvaluado += ((incognitasYSusCoeficientes.at(i).at(y)) * (pow(xIMasUno, i)));
            xIMasDosEvaluado += ((incognitasYSusCoeficientes.at(i).at(y)) * (pow(xIMasDos, i)));
        }
    }

    resultadoDerivada = (-(xIMasDosEvaluado) + (8 * xIMasUnoEvaluado) - (8 * xIMenosUnoEvaluado) + (xIMenosDosEvaluado)) / (12 * hTamañodepaso);

    cout << "El resultado de la derivada es: " << resultadoDerivada << endl;
}

/*
=======================
***OPERACIONES SIMPLES***
=======================
*/


void Suma (int a, int b, int Result){
    Result = a+b;
    cout<<"El resultado de tu suma es "<<Result;
}

void Suma (double a, double b, double Result){
    Result = a+b;
    cout<<"El resultado de tu suma es "<<Result;
}

void Resta (int a, int b, int Result){
    Result = a-b;
    cout<<"El resultado de tu resta es "<<Result;
}

void Resta (double a, double b, double Result){
    Result = a-b;
    cout<<"El resultado de tu resta es "<<Result;
}

void Multiplicacion (int a, int b, int Result){
    Result = a*b;
    cout<<"El resultado de tu Multiplicacion es "<<Result;
}

void Multiplicacion (double a, double b, double Result){
    Result = a*b;
    cout<<"El resultado de tu Multiplicacion es "<<Result;
}

void Division (int a, int b, int Result){
    Result = a/b;
    cout<<"El resultado de tu Division es "<<Result;
}

void Division (double a, double b, double Result){
    Result = a/b;
    cout<<"El resultado de tu Division es "<<Result;
}
