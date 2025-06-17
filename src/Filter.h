#ifndef FILTER_H
#define FILTER_H
#define ENABLE_COLOR_OUTPUT

#include <cassert>
#include <queue>
#include <set>

#include "Parameters.h"

class Filter {
 public:
  ///////////////////////////////////////////////////////////////////////////
  /** @name Constructores */
  /** @{ */

  /**
   * @brief Construye un filtro con capacidad para procesar señales de
   * longitud L.
   *
   * @param L Longitud de la señal de entrada.
   */
  Filter(unsigned int L);

  /**
   * @brief Construye un filtro a partir de un objeto JSON.
   *
   * @param json Objeto JSON con la información del filtro.
   */
  Filter(const Json::Value& json);

  /** @} */  ////////////////////////////////////////////////////////////////
  /** @name Operadores genéticos */
  /** @{ */

  /**
   * @brief Escoge una arista aleatoria, cambia su tipo e inicializa su valor.
   */
  void mutateEdges();

  /**
   * @brief Escoge una arista de ganancia aleatoria y le suma un valor
   * aleatorio.
   */
  void mutateGains();

  /**
   * @brief Escoge una arista de retardo aleatoria y le asigna un valor entero
   * aleatorio.
   */
  void mutateDelays();

  /**
   * @brief Escoge una arista aleatoria y muta la arista recíproca.
   *
   * @details Decimos que la arista recíproca de una arista \f$ (i,j) \f$ es
   * la arista \f$ (j,i) \f$. Tenemos tres casos posibles:
   *          1. La arista seleccionada es de ganancia. Entonces convierte su
   * recíproca en retardo y la inicializa.
   *          2. La arista seleccionada es de retardo. Entonces comprueba si
   * la recíproca puede ser una ganancia (es decir, \f$ (j,i) \f$ queda por
   * encima de la diagonal) y la inicializa.
   *          3. Si en el caso anterior la recíproca no puede ser una
   * ganancia, entonces convierte la arista actual en ganancia y la recíproca
   * en retardo, e inicializa ambas.
   */
  void mutateReciprocal();

  /**
   * @brief Escoge dos aristas contiguas del tipo indicado y las fusiona en
   * una sola arista.
   *
   * @param type Tipo de la nueva arista. `1` para ganancia y `2` para
   * retardo.
   */
  void mutateMerge(const unsigned int type);

  /**
   * @brief Escoge dos aristas contiguas y las intercambia.
   */
  void mutateConsecutiveEdges();

  /**
   * @brief Coge todos los retardos que entran a un mismo nodo, hace que vayan a
   * un nodo sin entradas ni salidas y conecta como única salida de este nodo el
   * nodo escogido con el valor de retardo de una de las aristas.
   */
  void mutateMergeUsingLonelyNodeAsSink();

  /**
   * @brief Coge todos los retardos que salen de un mismo nodo, hace que surjan
   * desde un nodo sin entradas ni salidas y conecta como única entrada de este
   * nodo el nodo escogido con el valor de retardo de una de las aristas.
   */
  void mutateMergeUsingLonelyNodeAsSource();

  /**
   * @brief Realiza el cruce entre dos filtros y genera un nuevo filtro. Debe
   * ser llamado por el filtro hijo.
   *
   * @details El cruce consiste en cruzar las matrices de adyacencia de los
   * filtros progenitores a partir de una columna de posición aleatoria. Es
   * decir, la matriz de adyacencia del hijo se obtiene usando la matriz del
   * primer progenitor desde la columna 0 hasta la columna de cruce, y la
   * matriz del segundo progenitor desde la columna de cruce hasta la última
   * columna.
   *
   * @param parent_1 El primer filtro progenitor.
   * @param parent_2  El segundo filtro progenitor.
   */
  void crossover(const Filter& parent_1, const Filter& parent_2);

  /** @} */  ////////////////////////////////////////////////////////////////
  /** @name Evaluación */

  /**
   * @brief Calcula el fitness del filtro utilizando señales en el dominio de
   * la tiempo.
   *
   * @param input Señal de entrada del filtro.
   * @param target Espectro de la señal de salida deseada.
   */
  void computeFitness(std::vector<double>& input, std::vector<double>& target);

  ///////////////////////////////////////////////////////////////////////////
  /** @name Utilidades*/
  /** @{ */

  /**
   * @brief Exporta el código de un filtro en C, teniendo en cuenta que los
   * delays usarán buffers.
   *
   * @return std::string
   */
  std::string exportCode();

  /**
   * @brief Imprime las matrices de la SFG del filtro.
   *
   * @details Imprime tanto la capa de tipo como la capa de valor. El color de
   * cada elemento sigue la siguiente leyenda:
   *      - Color por defecto. No existe arista.
   *      - <span style="color:blue;">Azul</span>: Retardo.
   *      - <span style="color:green;">Verde</span>: Ganancia.
   *      - <span style="color:red;">Rojo</span>: Valor de ganancia en la
   * diagonal o debajo de ella. Esto indica que el filtro puede no ser
   * computable. Por diseño, este caso no debería darse. Sirve para detectar
   * errores.
   *
   * @return std::string Representación de la SFG del filtro.
   */
  std::string toString();

  /**
   * @brief Obtiene el valor de fitness del filtro. Debe haber sido calculado
   * previamente.
   *
   * @return double
   */
  double getFitness();

  /**
   * @brief Obtiene un objeto JSON que describe al filtro.
   *
   * @return Json::Value
   *
   * @code{.json}
   * {
   *     "N"             : int,              // Tamaño de la matriz cuadrada (N x N)
   *     "fitness"       : double,           // Valor de fitness calculado
   *     "output"        : [ double, ... ],  // Última señal de salida obtenida
   *     "type_layer"    : [ int, ... ] ,    // Matriz de tipos (type_layer[i*N + j])
   *     "value_layer"   : [ double, ... ]   // Matriz de valores (value_layer[i*N + j])
   * }
   * @endcode
   */
  Json::Value getJson();

  /** @} */  ////////////////////////////////////////////////////////////////

  unsigned int type_layer[Params::N][Params::N];
  double       value_layer[Params::N][Params::N];

 private:
  double       fitness;
  unsigned int L;
  double       previousError;

  std::vector<std::vector<double>>                   state;
  std::vector<double>                                output;
  std::vector<std::pair<unsigned int, unsigned int>> edges;
  std::vector<std::pair<unsigned int, unsigned int>> gains;
  std::vector<std::pair<unsigned int, unsigned int>> delays;
  std::vector<std::vector<unsigned int>>             incomingEdges;
  std::vector<std::vector<unsigned int>>             outgoingEdges;

  void changeGainToDelay(const unsigned int i, const unsigned int j);
  void changeDelayToGain(const unsigned int i, const unsigned int j);
  void removeGain(const unsigned int i, const unsigned int j);
  void removeDelay(const unsigned int i, const unsigned int j);
  void removeUnkown(const unsigned int i, const unsigned int j);
  void removeUnkown(const std::pair<unsigned int, unsigned int> id);
  void addGain(const unsigned int i, const unsigned int j);
  void addDelay(const unsigned int i, const unsigned int j);
  void addUnknown(const unsigned int i, const unsigned int j);
  void addUnknown(const std::pair<unsigned int, unsigned int> id);
};

#endif
