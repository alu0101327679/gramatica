/**
 * @file Grammar2CNF.cc
 * @author Ancor González Carballo
 * @brief Contiene la función main del programa
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include "NFA.h"
#include "Grammar.h"
#include "utils.h"

int main (int argc, char* argv[]) {

  std::string ayuda = "--help";

  if (argc == 1) {
    Uso();
  } else if (argc == 2 && argv[1] == ayuda) {
   // system("clear");
    Ayuda();
  } else if (argc == 3) {
  //  system("clear");
    std::string name_file_in = argv[1];
    std::string name_file_out = argv[2];
    Grammatica grammar(name_file_in);
    grammar.Convert_CNF();
    grammar.Modificacion(name_file_out);
    std::cout << "\n\n"<< "El fichero de salida ha sido escrito con exito."   << "\n\n";
  } else {
    //system("clear");
    std::cout << "Se ha introducido un numero invalido o erroneo de argumentos, por favor vuelva a intentarlo"  << "\n\n";
  }
}
