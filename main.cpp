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
#include <math.h>
#include <vector>

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

void velocidadX_TiroParabolico(double &velocidadX, double velocidadI, double angulo)
{
    velocidadX = velocidadI * cos(angulo);
}
void velocidadY_TiroParabolico(double &velocidadY, double velocidadI, double angulo, double aceleracion, double tiempo)
{
    double velocidadIY = 0;
    velocidadIY = velocidadI * sin(angulo);
    velocidadY = velocidadIY + (aceleracion * tiempo);
}

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
        cout << "[5] Metodos Numericos" << endl;
        cout << "[6] Salir" << endl;
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
                break;
            }
            break;

        default:
            break;
        }
    } while (choice != 6);

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
    cout << "La posicion final es: " << posicionF << " m" << endl;
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
    cout << "La posicion final es: " << posicionF << " m" << endl;
    cout << "La velocidad final es: " << velocidadF << " m/s" << endl;
}

void velocidadMovimientoCircularUniforme()
{
    double velocidad = 0, velocidadAngular = 0, radioCurvatura = 0;
    cout << "Introduce la velocidad angular (en rad/s): ";
    cin >> velocidadAngular;
    cout << "Introduce el radio de curvatura (en m): ";
    cin >> radioCurvatura;

    velocidad = (velocidadAngular * radioCurvatura);
    cout << "La velocidad es: " << velocidad << " m/s" << endl;
}

void velocidadAngularMovimientoCircularUniforme()
{
    double velocidadAngular = 0, frecuencia = 0;
    cout << "Introduce la frecuencia (en Hz): ";
    cin >> frecuencia;

    velocidadAngular = ((2 * M_PI) * frecuencia);
    cout << "La velocidad angular es: " << velocidadAngular << " m/s" << endl;
}

void periodoMovimientoCircularUniforme()
{
    double periodo = 0, frecuencia = 0;
    cout << "Introduce la frecuencia (en Hz): ";
    cin >> frecuencia;

    periodo = 1 / frecuencia;
    cout << "El periodo es: " << periodo << " s" << endl;
}

void aceleracionCentripetaMovimientoCircularUniforme()
{
    double aceleracionCentripeta = 0, velocidad = 0, radio = 0;
    cout << "Introduce la velocidad (en m/s): ";
    cin >> velocidad;
    cout << "Introduce el radio de la curvatura (en m): ";
    cin >> radio;

    aceleracionCentripeta = (pow(velocidad, 2)) / radio;
    cout << "La aceleracion centripeta es: " << aceleracionCentripeta << " m/s^2" << endl;
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
    double velocidadIY = 0, velocidadI = 0, angulo = 0, anguloRad = 0;
    cout << "Introduce la velocidad inicial (en m/s): ";
    cin >> velocidadI;
    cout << "Introduce el angulo: ";
    cin >> angulo;

    anguloRad = (angulo * M_PI) / 180;

    velocidadIY = velocidadI * sin(anguloRad);
    cout << "La velocidad inicial en el eje Y es: " << velocidadIY << " m/s" << endl;
}

void alturaMaximaTiroParabolico()
{
    double alturaMaxima = 0, velocidadI = 0, angulo = 0, anguloRad = 0;
    cout << "Introduce la velocidad inicial (en m/s): ";
    cin >> velocidadI;
    cout << "Introduce el angulo de la direccion de lanzamiento: ";
    cin >> angulo;

    anguloRad = (angulo * M_PI) / 180;

    alturaMaxima = ((pow(velocidadI, 2)) * (pow(sin(anguloRad), 2))) / (2 * 9.81);
    cout << "La altura maxima es: " << alturaMaxima << " m" << endl;
}

void alcanceTiroParabolico()
{
    double alturaMaxima = 0, velocidadI = 0, angulo = 0, anguloRad = 0;
    cout << "Introduce la velocidad inicial (en m/s): ";
    cin >> velocidadI;
    cout << "Introduce el angulo de la direccion de lanzamiento: ";
    cin >> angulo;

    anguloRad = (angulo * M_PI) / 180;

    alturaMaxima = ((pow(velocidadI, 2)) * (pow(sin(anguloRad), 2))) / (9.81);
    cout << "La altura maxima es: " << alturaMaxima << " m" << endl;
}

void fuerza()
{
    double fuerza = 0, masa = 0, aceleracion = 0;
    cout << "Introduce la masa (en kg): ";
    cin >> masa;
    cout << "Introduce la aceleracion (en m/s^2): ";
    cin >> aceleracion;

    fuerza = masa * aceleracion;
    cout << "La fuerza resultante es: " << fuerza << " N" << endl;
}

void peso()
{
    double peso = 0, masa = 0;
    cout << "Introduce la masa (en Kg): ";
    cin >> masa;

    peso = masa * 9.81;
    cout << "El peso es: " << peso << " N" << endl;
}

void friccion()
{
    double fuerzaFriccion = 0, coeficienteRoce = 0, fuerzaNormal = 0;
    cout << "Introduce el coeficiente de friccion: ";
    cin >> coeficienteRoce;
    cout << "Introduce la fuerza normal (en N): ";
    cin >> fuerzaNormal;

    fuerzaFriccion = fuerzaNormal * coeficienteRoce;
    cout << "La fuerza de friccion es: " << fuerzaFriccion << " N" << endl;
}

void fuerzaElastica()
{
    double fuerzaElastica = 0, constanteElasticaResorte = 0, deformacionResorte = 0;
    cout << "Introduce la constante elastica del resorte (en N/m): ";
    cin >> constanteElasticaResorte;
    cout << "Introduce la deformacion del resorte (en m): ";
    cin >> deformacionResorte;

    fuerzaElastica = constanteElasticaResorte * deformacionResorte;
    cout << "La fuerza elastica es: " << fuerzaElastica << " N" << endl;
}

void trabajo()
{
    double trabajo = 0, fuerza = 0, desplazamiento = 0, angulo = 0, anguloRad = 0;
    cout << "Introduce la fuerza (en N): ";
    cin >> fuerza;
    cout << "Introduce el desplazamiento (en m): ";
    cin >> desplazamiento;
    cout << "Introduce el angulo entre la direccion de la fuerza y el desplazamiento: ";
    cin >> angulo;

    anguloRad = (angulo * M_PI) / 180;

    trabajo = fuerza * desplazamiento * cos(anguloRad);
    cout << "EL trabajo es: " << trabajo << " J" << endl;
}

void energiaCinetica()
{
    double energiaCinetica = 0, masa = 0, velocidad = 0;
    cout << "Introduce la masa (en kg): ";
    cin >> masa;
    cout << "Introduce la velocidad (en m/s): ";
    cin >> velocidad;

    energiaCinetica = (masa / 2) * (pow(velocidad, 2));
    cout << "La energia cinetica es: " << energiaCinetica << " J" << endl;
}

void energiaPotencial()
{
    double energiaPotencial = 0, masa = 0, altura = 0;
    cout << "Introduce la masa (en kg): ";
    cin >> masa;
    cout << "Introduce la altura (en m): ";
    cin >> altura;

    energiaPotencial = masa * altura * 9.81;
    cout << "La energia potencial es: " << energiaPotencial << " J" << endl;
}

void energiaPotencialElastica()
{
    double energiaPotencialElastica = 0, constanteElastica = 0, deformacionResorte = 0;
    cout << "Introduce la constante elastica del resorte (en N/m): ";
    cin >> constanteElastica;
    cout << "Introduce la deformacion del resorte (en m): ";
    cin >> deformacionResorte;

    energiaPotencialElastica = (constanteElastica / 2) * (pow(deformacionResorte, 2));
    cout << "La energia potencial elastica es: " << energiaPotencialElastica << " J" << endl;
}

void potencia()
{
    double potencia = 0, trabajo = 0, tiempo = 0;
    cout << "Introduce la cantidad e trabajo (en J): ";
    cin >> trabajo;
    cout << "Introduce el intervalo de tiempo (en s): ";
    cin >> tiempo;

    potencia = trabajo / tiempo;
    cout << "La potencia es: " << potencia << " Watts" << endl;
}

/*
=======================
***METODOS NUMERICOS***
=======================
*/

void derivacionFuncionEvaluada(){

    int grado=0;

    cout << "Vamos a introducir tu funcion, por pasos" << endl;
    cout << "Introduce el grado de tu funcion: ";
    cin >> grado;
    
    vector<vector<double>> incognitasYSusCoeficientes;
    
    for (int i = 0; i<grado+1; i++)
    {
        cout << "Introduce cuantas incognitas de grado [" << i << "] tienes" << endl;
        double temp=0;
        cin >> temp;
        
        vector<double> vectortemp;
        vectortemp.clear();

        cout << "Introduce los coeficientes de tus incognitas de grado [" << i << "] que tienes" << endl;
        for (int y = 0; y<temp; y++)
        {
            double coeficientetemp=0;
            cout << "Incognita [" << y+1 << "]: ";
            cin >> coeficientetemp;
            vectortemp.push_back(coeficientetemp);
        }
        incognitasYSusCoeficientes.push_back(vectortemp);
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
    for (int i = incognitasYSusCoeficientes.size()-1; i>=0; i--)
    {
        for (int y = 0; y<incognitasYSusCoeficientes.at(i).size(); y++)
        {
            

            if (incognitasYSusCoeficientes.at(i).at(y)<0)
            {
                cout << incognitasYSusCoeficientes.at(i).at(y) << "(x^" << i << ")";
            }
            else{
                cout << "+" << incognitasYSusCoeficientes.at(i).at(y) << "(x^" << i << ")";
            }
            
            
            
        }
    }
    cout << endl;


    double hTamañodepaso=0;
    double xI=0, xIMenosUno=0, xIMenosDos=0, xIMasUno=0, xIMasDos=0;
    double resultadoDerivada=0;

    double xIEvaluado=0, xIMenosUnoEvaluado=0, xIMenosDosEvaluado=0, xIMasUnoEvaluado=0, xIMasDosEvaluado=0;

    cout << "=========" << endl;
    cout << "Centradas" << endl;
    cout << "=========" << endl;
    cout << "Introduce el valor en el quieres evaluar la derivada: ";
    cin >> xI;
    cout << "Introduce el tamaño de paso: ";
    cin >> hTamañodepaso;

    xIMenosDos=(xI-(hTamañodepaso*2));
    xIMenosUno=(xI-(hTamañodepaso*1));
    xIMasUno=(xI+(hTamañodepaso*1));
    xIMasDos=(xI+(hTamañodepaso*2));

    for (int i = incognitasYSusCoeficientes.size()-1; i>=0; i--)
    {
        for (int y = 0; y<incognitasYSusCoeficientes.at(i).size(); y++)
        {
            
            xIMenosUnoEvaluado+=((incognitasYSusCoeficientes.at(i).at(y))*(pow(xIMenosUno, i)));
            xIMenosDosEvaluado+=((incognitasYSusCoeficientes.at(i).at(y))*(pow(xIMenosDos, i)));
            xIMasUnoEvaluado+=((incognitasYSusCoeficientes.at(i).at(y))*(pow(xIMasUno, i)));
            xIMasDosEvaluado+=((incognitasYSusCoeficientes.at(i).at(y))*(pow(xIMasDos, i)));
            
        }
    }

    resultadoDerivada=(-(xIMasDosEvaluado)+(8*xIMasUnoEvaluado)-(8*xIMenosUnoEvaluado)+(xIMenosDosEvaluado)) / (12*hTamañodepaso);

    cout << "El resultado de la derivada es: " << resultadoDerivada << endl;
}
