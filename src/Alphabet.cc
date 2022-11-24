/**
 * @file Alphabet.cc
 * @author Ancor González Carballo
 * @brief Contiene la implementación de la clase Alphabet
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Alphabet.h"

/**
 * @brief Constructor por defecto
 */
Alphabet::Alphabet () {}

/**
 * @brief Constructor parametrizado
 * @param alphabet nuevo alfabeto
 */
Alphabet::Alphabet (const Alphabet& alphabet) {
  alphabet_ = alphabet.get_Alphabet();
}

/** 
 * @return Atributo alfabeto 
 */
const std::set<char>& Alphabet::get_Alphabet (void) const {
  return alphabet_;
}

/** 
 * @brief Crea el alfabeto de la cadena que le es pasada
 * @param cadena Contine los symbolos de este alfabeto
 */
Alphabet::Alphabet (std::string& cadena) {
  Alphabet_Create(cadena);
}

/** 
 * @brief Imprime por pantalla el alfabeto de la cadena
 */
void Alphabet::Alphabet_Write (void) const {

  std::set <char>::iterator it = alphabet_.begin();
  int cont;
  std::cout << "{";
  for (; it != alphabet_.end(); it++) {
    std::cout << *it;
    cont++;
    if (cont < size())
      std::cout << ", ";
  }
  std::cout << "}" << std::endl;
}

/** 
 * @brief Funcion que se encarga de transformar una cadena entrante en un alfabeto
 * @param cadena Contiene los symbolos del alfabato en cada uno de sus caracteres
 */
void Alphabet::Alphabet_Create (const std::string cadena) {

  for (long unsigned int i = 0; i < cadena.length(); i++) {
    alphabet_.insert(cadena[i]);
  }
}

/**
 * @return Tamaño del alfabeto
 */
int Alphabet::size (void) const {

  std::set <char>::iterator it = alphabet_.begin();
  int size;
  for (; it != alphabet_.end(); it++) {
    size++;
  }
  return size;
}