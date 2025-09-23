#ifndef PARAMETERS_H
#define PARAMETERS_H

#define _USE_MATH_DEFINES
#include <json/json.h>
#include <stdlib.h>

#include <cmath>
#include <cstdint>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>

#include "omp.h"

namespace Params {

/**
 * @brief Los diferentes tipos disponibles para la señal de entrada.
 *
 * @see Helpers::randomDouble()
 * @see Params::createSignal()
 */
enum SignalType {
  IMPULSE,     ///< Impulso unitario. La primera muestra vale `1.0` y el resto `0.0`.
  WHITE_NOISE  ///< Ruido blanco. Cada muestra es un número aleatorio, usa `randomDouble()`.
};

static const SignalType   inputSignal_TYPE      = SignalType::IMPULSE;  ///< Tipo de señal de entrada.
static const unsigned int SURVIVORS             = 450;    ///< Número de individuos supervivientes de la población
static const unsigned int N                     = 15;     ///< Tamaño de la matriz cuadrada \f$ (N \times N) \f$.
static const unsigned int POPULATION_SIZE       = 1000;   ///< Tamaño de la población.
static const unsigned int MAX_DELAY             = 20;     ///< Valor máximo de retardo permitido.
static const unsigned int NUM_THREADS           = 8;      ///< Número de hilos a usar en la ejecución.
static const unsigned int MAX_DEPENDENCIES      = N;      ///< Máximo número de dependencias permitidas por nodo.
static const unsigned int MAX_GENES_CHANGED     = 5;      ///< Máximo número de genes a cambiar en una mutación.
static const unsigned int MAX_GENERATIONS       = 10000;  ///< Número máximo de generaciones a ejecutar.
static const float        CROSSOVER_RATE        = 0.4;    ///< Probabilidad de cruce.
static const float        MUTATION_RATE         = 0.4;    ///< Probabilidad de mutación.
static const float        PENALTY_NUM_GAINS     = 1e-6;   ///< Penalización por número de ganancias.
static const float        PENALTY_NUM_ADDITIONS = 1e-6;   ///< Penalización por número de sumas.
static const float        PENALTY_MEMORY        = 1e-6;   ///< Penalización por memoria ocupada.
static const float        PENALTY_MSE           = 1e2;    ///< Penalización por error cuadrático medio (MSE).
static const float        EXIT_THRESHOLD        = 0.999;  ///< Umbral de salida del algoritmo.
static const bool         PRINT_MATRIX = true;  ///< Si es `true`, imprime la matriz de conexiones en cada generación.
static const bool         SAVE_RESULTS = true;  ///< Si es `true`, guarda los resultados en un archivo JSON.
}  // namespace Params

namespace Helpers {

/*******************************************************
 * COMANDOS DE UTILIDAD PARA EL ASPECTO DE LA TERMINAL *
 *******************************************************/
#define CLEAR_SCREEN      "\033[1;1H"
#define CLEAR_SCREEN_FR   "\033[H\033[J"
#define MOVE_TO_COLUMN(x) "\033[" #x "G"
#define ERASE_LINE        "\033[A\033[K"
#define WIDTH             6

/**
 * @name DSP
 * @{
 */

/**
 * @brief Crea una señal de entrada en función del tipo escogido.
 *
 * @param result Vector donde se almacenará la señal.
 * @param signal_type Tipo de señal a crear.
 * @param L Longitud de la señal.
 */
void createSignal(std::vector<double>& result, Params::SignalType signal_type, const unsigned int L);

/**
 * @brief Filtra una señal mediante una ecuación en diferencias.
 *
 * @param in Señal de entrada del filtro.
 * @param out Señal de salida del filtro.
 * @param b Coeficientes del numerador.
 * @param a Coeficientes del denominador.
 * @param L Longitud de la señal.
 *
 * @see https://es.mathworks.com/help/matlab/ref/filter.html
 * @see Oppenheim, Alan V., Ronald W. Schafer, and John R. Buck. Discrete-Time
 * Signal Processing. Upper Saddle River, NJ: Prentice-Hall, 1999
 */
void filterUsingDifferenceEquation(std::vector<double>&      in,
                                   std::vector<double>&      out,
                                   const std::vector<double> b,
                                   const std::vector<double> a,
                                   const unsigned int        L);

/**
 * @}
 * @name Generadores de números aleatorios
 * @{
 */

/**
 * @brief Genera un número aleatorio de tipo `double` entre `min` y `max`.
 *
 * @param min Valor mínimo.
 * @param max Valor máximo.
 * @return Número aleatorio generado.
 */
double randomDouble(double min = 0, double max = 1);

/**
 * @brief Genera un número aleatorio de tipo `double` con una distribución
 * normal.
 *
 * @param mean Media de la distribución.
 * @param stddev Desviación estándar de la distribución.
 * @return `double`: Número aleatorio generado.
 */
double randomDoubleNormal(double mean = 0, double stddev = 0.01);

/**
 * @brief Genera un número aleatorio entero entre `min` y `max` (incluidos).
 *
 * @param min Valor mínimo.
 * @param max Valor máximo.
 * @return Número aleatorio entero generado.
 */
int randomInt(int min = 0, int max = INT_MAX);
/** @} */

/**
 * @name Generador de números aleatorios
 * @{
 */
static std::random_device rd;  ///< Generador de números aleatorios de la librería estándar.
static std::mt19937       gen(
    rd());  ///< Instancia del generador Mersenne-Twister. @see https://en.wikipedia.org/wiki/Mersenne_Twister

/** @} */

}  // namespace Helpers

#endif
