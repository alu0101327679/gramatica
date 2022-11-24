/**
 * @file Alphabet.cc
 * @author Ancor González Carballo
 * @brief Contiene la implementación de utils
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "utils.h"

/**
 * @brief Funcion que se encarga de mostrar un mensaje como si se tratase de un greep
 */
void Uso (void) {
  
  std::cout << "\n" << " Modo de empleo: ./Grammar2CNF input.gra output.nfa " << "\n";
  std::cout << " Pruebe './Grammar2CNF --help' para mas informacion." << "\n\n";
}

/**
 * @brief Descripcion de como funciona el programa 
 */
void Ayuda(void) {
  std::cout << "  Para la correcta ejecucion del programa debemos seguir los siguientes pasos:" << "\n\n";
  std::cout << "    1. Se debe pasar como parametros al ejecutar el programa, el nombre del fichero del que desea leer y en el que se va a guardar." << "\n\n";
  std::cout << "       - Se hara de la siguiente forma: ./program fichero_entrada.gra fichero_salida.gra" <<"\n\n";
  std::cout << "    2. El programa se encargara de transformar el fichero de entrada en uno de salida reconocible por el programa Grammar, " << "\n";
  std::cout << "    por ello es de vital importancia que el fichero de salida termine en .gra en caso contrario no sera reconocido por " << "\n";
  std::cout << "    el otro programa." << "\n\n";
  std::cout << "    3. En cuanto al fichero de entrada se permitira una mayor flexibilidad ya que su entrada .gra pudiera ser tambien de " << "\n";
  std::cout << "    tipo .txt. " << "\n\n";
  std::cout << "    4. El fichero de entrada debe seguir el formato siguiente y ante cualquier posible error pues no se obtendrá una buena salida:" << "\n\n";
  std::cout << "      - Primera linea: numero de symbolos del alfabeto." << "\n";
  std::cout << "      - N lineas: symbolos del alfabeto." << "\n";
  std::cout << "      - Siguiente linea: numero de symbolos no terminales." << "\n";
  std::cout << "      - M lineas: nombre (symbolo) de cada estado." << "\n";
  std::cout << "      - Siguiente linea: nombre del symbolo inicial." << "\n";
  std::cout << "      - Siguiente linea: numero de reglas." << "\n";
  std::cout << "      - F lineas: reglas de producción de cada symbolo." << "\n";
  Ejemplo();
}

/**
 * @brief Pausa durante un instante el programa 
 */
void press_to_continue (void) {

  std::cout << "    Pulsa para ver un ejemplo : ";
  do {} while (std::cin.get() != '\n');
}

/**
 * @brief Despues de la pausa del program se muestra un ejemplo del mismo 
 */
void Ejemplo (void) {
  
  std::cout << "\n\n";
  std::cout << "Un ejemplo:\n";
  std::cout << "3\na\nb\nc\n3\nS\nX\nY\nS\n";
  std::cout << "13\nS -> aXbX\nS -> abX\nS -> aXb\nS -> ab\n";
  std::cout << "X -> aY\nX -> bY\nX -> a\nX -> b\nY -> aY\nY -> bY\nY -> a\n";
  std::cout << "Y -> b\nY -> c\n\n";
}