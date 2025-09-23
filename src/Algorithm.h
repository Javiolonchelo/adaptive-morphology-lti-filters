#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <omp.h>
#include "Filter.h"
#include "Menu.h"
#include "Parameters.h"

/**
 * @brief Esta función implementa el algoritmo propuesto.
 *
 * @param inputSignal Señal de entrada del filtro.
 * @param target Señal de salida del filtro.
 * @param L Longitud de las señales de entrada y salida.
 * @param outputFile Nombre del archivo de salida.
 * @return `int` 0 si se ejecuta correctamente, 1 si se produce algún error.
 */
int Algorithm(std::vector<double>& inputSignal,
              std::vector<double>& target,
              const unsigned int   L,
              std::string          outputFile);

#endif  // ALGORITHM_H
