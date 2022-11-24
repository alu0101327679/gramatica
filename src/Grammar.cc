/**
 * @file Alphabet.cc
 * @author Ancor González Carballo
 * @brief Contiene la implementación de la clase Gramatica
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Grammar.h"
#include <stdio.h>
#include <cstring>

/**
 * @brief Constructor por defecto
 */
Grammatica::Grammatica () :
V_(),
g_alphabet_(),
S_(),
P_()
{}

// /**
//  * @brief Constructor parametrizado con un objeto de referencia
//  * @param aux Nfa pasado por refencia
//  */
// Grammatica::Grammar (Grammar& aux) :
// V_(),
// g_alphabet_(),
// S_(),
// P_()
// {
//   V_ = aux.V_;
//   g_alphabet_ = aux.g_alphabet_;
//   S_ = aux.S_;
//   P_ = aux.P_;
// }

/**
 * @brief Costruye el NFA a traves del nombre de un fichero de entrada
 * @param in_file 
 */
Grammatica::Grammatica (std::string& in_file):
V_(),
g_alphabet_(),
S_(),
P_()
{
    Generador_Gramatica(in_file);

}

/**
 * @brief Destructor por defecto
 */
Grammatica::~Grammatica () {}

/**
 * @brief Se encarga de convertir la gramatica de entrada en una gramactica que cumpla FNC ejecutando las dos partes del algoritmo por separado
 */
void Grammatica::Convert_CNF (void) {

  New_No_Terminal_Symbol();
  Create_Group();
}

/**
 * @brief Primera parte del alogritmo de FNC que se encarga de crear los nuevos estados no terminales y sustituir las reglas de produccion correspondientes
 */
void Grammatica::New_No_Terminal_Symbol (void) {
 
  std::set <std::pair <std::string, std::vector <char>>> aux_new_no_ter;
  // Se crean los nuevos estados no terminales 
  for (std::pair <std::string, std::vector <char>> pai: P_) {
    if (pai.second.size() >= 2)
      for (char c: pai.second)
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
          std::pair <std::string, std::vector <char>> aux_pair;
          std::string aux_string = "Q";
          std::vector <char> aux_char;
          aux_string += c;
          aux_pair.first = aux_string;
          aux_char.push_back(c);
          aux_pair.second = aux_char;
          aux_new_no_ter.insert(aux_pair);  
        }
  }

  // Se añaden estos al conjunto de symbolos no terminales
  for (std::pair <std::string, std::vector <char>> pai: aux_new_no_ter)
    V_.insert(pai.first);

  // Se modifican las reglas de produccion que ya teniamos 
  for (std::pair <std::string, std::vector <char>> pai: P_) {
    if (pai.second.size() == 1) {
      aux_new_no_ter.insert(pai);
    } else if (pai.second.size() >= 2) {
      std::pair <std::string, std::vector <char>> aux_pair;
      aux_pair.first = pai.first;
      std::vector <char> aux_char;
      for (long unsigned int i = 0; i < pai.second.size(); i++) {
        if ((pai.second[i] >= 'a' && pai.second[i] <= 'z') || (pai.second[i] >= '0' && pai.second[i] <= '9')) {
          std::string aux_string = "Q";
          aux_string += pai.second[i];
          for (std::string str: V_)
            if (str == aux_string) {
              aux_char.push_back(str[0]);
              aux_char.push_back(str[1]);
            }
        } else {
          aux_char.push_back(pai.second[i]);
        }
      }
      aux_pair.second = aux_char;
      aux_new_no_ter.insert(aux_pair);
    }
  }

  P_ = aux_new_no_ter;
}

/**
 * @brief Segundo parte del algortimo FNC que se encarga de crear agrupaciones de pares y crear sus producciones correspondientes
 */
void Grammatica::Create_Group (void) {

  std::stack <std::string> aux_stack;
  std::set <std::pair <std::string, std::vector <char>>> aux_new_no_ter;
  int name_cont = 0;

  for (std::pair <std::string, std::vector <char>> pai: P_) {
    if (Size_Check(pai.second)) {
      aux_new_no_ter.insert(pai);
    } else {
      for (long unsigned int i = 0; i < pai.second.size(); i++) {
        if (pai.second[i] == 'Q') {
          std::string aux_string;
          aux_string = pai.second[i];
          aux_string += pai.second[i + 1];
          aux_stack.push(aux_string);
          i++;
        } else {
          std::string aux_string;
          aux_string = pai.second[i];
          aux_stack.push(aux_string);
        }
      }
      bool first = true;
      while (!aux_stack.empty()) {
        if (first == true) {
          std::string aux_string1 = aux_stack.top();
          aux_stack.pop();
          std::string aux_string2 = aux_stack.top();
          aux_stack.pop();
          std::string new_Name = "Z";
          int sum = 97 + name_cont;
          new_Name += sum;
          name_cont++;
          aux_stack.push(new_Name);
          std::string production = aux_string2 + aux_string1;
          std::pair <std::string, std::vector <char>> aux_pair;
          aux_pair.first = new_Name;
          for (char c: production)
            aux_pair.second.push_back(c);
          aux_new_no_ter.insert(aux_pair);
          first = false;
        } else {
          std::string aux_string1 = aux_stack.top();
          aux_stack.pop();
          std::string aux_string2 = aux_stack.top();
          aux_stack.pop();
          if (aux_stack.empty()) {
            std::string production = aux_string2 + aux_string1;
            std::pair <std::string, std::vector <char>> aux_pair;
            aux_pair.first = pai.first;
            for (char c: production)
              aux_pair.second.push_back(c);
            aux_new_no_ter.insert(aux_pair);
          } else {
            std::string new_Name = "Z";
            int sum = 97 + name_cont;
            new_Name += sum;
            name_cont++;
            aux_stack.push(new_Name);
            std::string production = aux_string2 + aux_string1;  
            std::pair <std::string, std::vector <char>> aux_pair;
            aux_pair.first = new_Name;
            for (char c: production)
              aux_pair.second.push_back(c);
            aux_new_no_ter.insert(aux_pair);
          }
        }
      }    
    }
  }
  for (std::pair <std::string, std::vector <char>> pai: aux_new_no_ter)
    V_.insert(pai.first);

  P_ = aux_new_no_ter;
}

/**
 * @brief Metodo que se encarga de comprobar si la regla actual solamente tiene o una o dos symbolos terminales
 * @param check_string Contiene la palabra que vamos a analizar 
 */
bool Grammatica::Size_Check (std::vector <char> check_string) const {
   
   if (check_string.size() == 1)
    return true;
  else if (check_string.size() == 2)
    return true;
  else if (check_string.size() == 3 && (check_string[0] == 'Q' || check_string[1] == 'Q'))
    return true;
  else if (check_string.size() == 4 && (check_string[0] == 'Q' && check_string[2] == 'Q'))
    return true;
  else 
    return false;
}

/**
 * @brief Metodo que se encarga de leer de un fichero de entrada la gramatica y detecta si es correcta y no y dice sus posibles fallos
 * @param in_file Cadena de caracteres que contiene el nombre del fichero de donde se leera la gramatica
 */
void Grammatica::Generador_Gramatica (std::string& in_file) {
  
  std::ifstream ifs (in_file, std::ios::in);

  if (ifs.fail()) {
    std::cout << "Error el documento que trata de abrir no es valido, por favor introuduzca uno que si lo sea y reintentelo." << "\n\n";
    exit(2);
  } else { 
    std::string aux_string;
  
    do {
      getline(ifs, aux_string);
    } while ((aux_string[0] == '/' && aux_string[1] == '/'));

    int n_Symbol = stoi(aux_string);
    aux_string = "";
    std::string aux_chain;

    for (long unsigned int i = 0; i < n_Symbol; i++) {
      ifs >> aux_string;
      aux_chain += aux_string;
    }
    g_alphabet_.Alphabet_Create(aux_chain);

    int n_states;
    ifs >> n_states;
    aux_string = "";

    for (long unsigned int i = 0; i < n_states; i++) {
      ifs >> aux_string;
      V_.insert(aux_string);
    }

    aux_string = "";
    ifs >> aux_string;

    bool check = false;
    for (std::string est: V_)
      if (est == aux_string)
        check = true;
    
    if (check == true) {
      S_ = aux_string;
    } else {
      std::cout << " El symbolo inicial no pertenece al conjunto V, porfavor corrijalo." << "\n\n";
      exit(2);
    }

    int n_rules;
    ifs >> n_rules;
    std::string transition;
    check = false;
    aux_string = "";

    std::vector <char> aux_vector;

    for (long unsigned int i = 0; i < n_rules; i++) {
      ifs >> aux_string; 
      for (std::string str: V_) 
        if (aux_string == str) {
          check = true;
          break;
        }
      if (check == false) {
          std::cout << " El symbolo no terminal es incorrecto por cantidad de caracteres que posee, por favor corrijalo." << "\n\n";
          exit(2);  
      } else {
          transition = aux_string;
      }
      check = false;
      ifs >> aux_string;
      if (aux_string[0] == '-' && aux_string[1] == '>') {
        ifs >> aux_string;
      } else {
        std::cout << " La forma de expresar la transicion no es la correcta, por favor corrijala." << "\n\n";
        exit(2);  
      }
      for (long unsigned int j = 0; j < aux_string.size(); j++) {
        if ((aux_string[j] >= 'a' && aux_string[j] <= 'z') || (aux_string[j] >= '0' && aux_string[j] <= '9') || aux_string[j] == '~') {
          check = true;
        } else if ((aux_string[j] >= 'A' && aux_string[j] <= 'Z')) {
          for (std::string str: V_) {
            if (str[0] == aux_string[j]) {
              check = true;
            }
            if(str[0] == aux_string[j] && str[0] == aux_string[j + 1]) {
              check = true;
              j++;
              break;
            }
          }
        } else {
          check = false;
        }
        if (check == false) {
          std::cout << " Alguno de los symbolos que se quieren emplear como transición no pertencen a el conjunto de simolos terminales o no terminales," << "\n";
          std::cout << " por favor corrijalo." << "\n\n";
          exit(2);
        }
      }
      check = false;
      for(char est: aux_string)
        aux_vector.push_back(est);
      
    std::pair <std::string, std::vector <char>>  aux_pair (transition, aux_vector);
    P_.insert(aux_pair);
    aux_vector.clear();
    }
    aux_string = "";
    ifs >> aux_string;
    if (aux_string != "") {
      std::cout << "Error por introducir una cantidad invalida de elementos, por favor corrijalo para poder continuar. " << "\n\n";
      exit(2);
    }
  }
}

/**
 * @brief Hacemos lo mismo que en Create_CNF_File pero imprimiendo en el fichero 
          todos los conjuntos como en el fichero de entrada
 * 
 * @param in_file 
 */
void Grammatica::Modificacion(std::string& in_file) {
  std::ofstream ofs (in_file, std::ios::out);
   if (ofs.fail()) {
    std::cout << "Error el documento que trata de usar para guardar no es valido, por favor introduzca uno que si lo sea."
         << "\n\n";
    exit(2);
  } else {
    ofs << g_alphabet_.get_Alphabet().size() << "\n";
    for (char simbolo: g_alphabet_.get_Alphabet())
      ofs << simbolo << "\n";
    // ofs << "\n";
    ofs << V_.size() << "\n";
    for (std::string simbolo: V_)
      ofs << simbolo << "\n";
    // ofs << "\n";
    ofs << S_ << "\n";
    ofs << P_.size() << "\n";
    for (std::pair <std::string, std::vector <char>> regla: P_) {
      ofs << regla.first << " -> ";
      for (char simbolo: regla.second)
        ofs << simbolo;
      ofs << "\n";
    }
  }
  
}

/**
 * @brief Metodo que se encarga de imprimir el fichero de salida de tipo .gra
 * @param out_file Nombre del fichero que se va a utilizar para gurardar la salida de datos
 */
void Grammatica::Create_CNF_File (std::string& out_file) const {

  std::ofstream os (out_file, std::ios::out);

  if (os.fail()) {
    std::cout << "Error el documento que trata de usar para guardar no es valido, por favor introduzca uno que si lo sea."
         << "\n\n";
    exit(2);
  } else {

    int cont = 0;
    for (std::string str: V_) 
      if (str == S_)
        Write(str, cont, os);

    cont = 0;
    for (std::string str: V_) 
      if (str.size() == 1 && str != S_) 
        Write(str, cont, os);

    cont = 0;
    for (std::string str: V_) 
      if (str[0] == 'Q') 
        Write(str, cont, os);

    cont = 0;
    for (std::string str: V_) 
      if (str[0] == 'Z') 
        Write(str, cont, os);
  }
}

/**
 * @brief Metodo que se encarga de imprimir las reglas de produccion de un symbolo concreto 
 * @param str symbolo del que se van a imprimir sus reglas de produccion
 * @param cont Numero de reglas hasta el momento para evitar imprimir la barra por ultima vez
 * @param os Fichero de salida donde se va a escribir las reglas de produccion
 */
void Grammatica::Write (std::string& str, int& cont, std::ofstream& os) const {
  os << str <<  " -> ";
  for (std::pair <std::string, std::vector <char> > pai: P_) 
    if (str == pai.first) 
      cont++;
  int i = 0;
  for (std::pair <std::string, std::vector <char> > pai: P_) {
    if (str == pai.first) {
      for(char c: pai.second)
        os << c;
    i++;
    if (i != cont)
      os << " | ";
    }
  }
  cont = 0;
  os << "\n";
}