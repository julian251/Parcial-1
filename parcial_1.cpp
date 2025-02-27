#include <iostream>
#include <cmath>
// Definir la estructura de un punto en 2D
struct Point{
    double x, y;
};
// Definición de funciones

// Definición de la función para calcular distancia
double calcularDistancia(Point *pP1, Point *pP2);
// Definición de la función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int n);
// Definicion de la función para calcular la distancia más cercana desde un punto específico
double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano);

/*BONO:
Escribir una función que reciba un arreglo de puntos y devuelva la distancia total de los puntos que conforman el arreglo si estos fueran recorridos en orden.
*/

// Definición de la función para mostrar el punto más cercano y la distancia
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia);
// Función principal
int main(){
    int n;
    std::cout << "Ingrese el número de puntos (mínimo 2): ";
    // Leer el número de puntos
    std::cin >> n;
    // Se usa un ciclo while para que se pueda ingresar un numero de puntos valido sin necesidad de volver a ejecutar el programa
    while  (n < 2){ 
        std::cout << "\nSe necesitan al menos 2 puntos para calcular las distancias.\n";
        std::cin >> n;
    }
    Point puntos[n]; // Arreglo de estructuras para almacenar las coordenadas (x, y)
    // Leer los puntos (manual o predeterminado)
    leerPuntos(puntos, n);
    // Ingresar el punto del usuario
    Point pUsuario;
    std::cout << "Ingrese las coordenadas del punto desde el que calcular la distancia\n";
    std::cout << "Punto x: ";
    std::cin >> pUsuario.x;
    std::cout << "Punto y: ";
    std::cin >> pUsuario.y;
    // Calcular la distancia más cercana
    int indiceMasCercano;
    double distancia;
    distancia=calcularDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);
    // Mostrar el resultado
    mostrarResultado(puntos, indiceMasCercano, distancia);
    return 0;
}

// Función para calcular distancia
double calcularDistancia(const Point pP1, const Point pP2){//se toman las direcciones para ahorrar espacio en memoria
    return sqrt(pow((pP1.x-pP2.x),2)+pow((pP1.y-pP2.y),2));
}

// Función para leer las coordenadas de varios puntos
void leerPuntos(Point puntos[], int n){
    char respuesta;
    std::cout << "¿Desea ingresar los puntos manualmente? (s/n): ";
    // Leer la respuesta del usuario
    std::cin >> respuesta;
    if (respuesta == 's' || respuesta == 'S'){
        for (int i=0; i<n; i++){
            // Ingresar coordenada x en la posición i-esima
            std::cout << "Ingrese las coordenadas del punto\n";
            // Registro punto x
            std::cout << "Punto " <<i + 1 << " (x): ";
            std::cin >> puntos[i].x;
            // Registro punto y
            std::cout << "Punto " <<i + 1 << " (y): ";
            std::cin >> puntos[i].y;
        }
    }
    else{
        // Usar puntos predeterminados
        std::cout << "Usando puntos predeterminados...\n";
        puntos[0] = {0, 0};  // Punto 1 (0, 0)
        puntos[1] = {3, 4};  // Punto 2 (3, 4)
        puntos[2] = {6, 8};  // Punto 3 (6, 8)
        puntos[3] = {9, 12}; // Punto 4 (9, 12)
    }
}

double calcularDistanciaMasCercana(Point puntos[], int n, const Point &pUsuario, int &indiceMasCercano){
    double distancia, distancia_min;
    distancia_min = calcularDistancia(puntos[0], pUsuario);
    indiceMasCercano = 0;
    for(int i=1; i < n; i++){
        distancia =calcularDistancia(puntos[i], pUsuario);
        if (distancia < distancia_min){
            distancia_min=distancia;
            indiceMasCercano=i;
        }
    }
    return distancia_min;
}
void mostrarResultado(Point puntos[], int indiceMasCercano, double distancia)
{
    std::cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y << ")\n";
    std::cout << "La distancia al punto más cercano es: " << distancia << std::endl;
}