/**
 * @file Alphabet.cc
 * @author Ancor González Carballo
 * @brief Contiene la declaración de la clase Gramatica
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <utility>
#include <iostream>
#include <fstream>
#include <utility>
#include <sstream>
#include <stack>
#include <vector>

#pragma once
#include "Alphabet.h"
#include "State.h"
#include "NFA.h"

class Grammatica {

  private:
    std::set <std::string> V_;
    Alphabet g_alphabet_;
    std::string S_;
    std::set <std::pair <std::string, std::vector <char>>> P_;

  public:
    // Constructor and Destructor
    Grammatica();
    Grammatica(Grammatica&);
    Grammatica(std::string&);
    ~Grammatica();

    // Functions
    void Convert_CNF(void);
    void New_No_Terminal_Symbol(void);
    void Create_Group(void);
    bool Size_Check(std::vector <char>) const;
    void Generador_Gramatica(std::string&);
    void Create_CNF_File(std::string&) const;
    void Modificacion(std::string&);

    // Read and Write
    void Write(std::string&, int&, std::ofstream& os) const;
};