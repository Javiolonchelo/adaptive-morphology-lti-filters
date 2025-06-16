#ifndef MENU_H
#define MENU_H

#include <chrono>
#include <thread>

#include "Parameters.h"

/**
 * @brief Esta función sirve para implementar un menú cuando es ejecutado desde la línea de comandos. Esta función no
 * está implementada, y sirve como mero intermediario entre `main()` y el algoritmo.
 *
 * @param inputSignal Vector donde se almacenará la señal de entrada generada.
 * @param targetTime Vector donde se almacenará la señal objetivo.
 * @param L Longitud de las señales.
 * @param filterName Nombre del filtro a buscar.
 * @param outputFile Nombre del archivo de salida.
 * @param mode Modo de operación del menú.
 * @return 0 si se ejecuta correctamente, 1 si ocurre algún error.
 */
int Menu(std::vector<double>& inputSignal,
         std::vector<double>& targetTime,
         unsigned int&        L,
         std::string          filterName,
         std::string          outputFile,
         int                  mode);

#endif
