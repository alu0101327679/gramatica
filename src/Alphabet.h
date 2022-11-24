/**
 * @file Alphabet.cc
 * @author Ancor González Carballo
 * @brief Contiene la declaración de la clase Alphabet
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <set>
#include <string>
#pragma once 


class Alphabet{

  private:
    std::set <char> alphabet_;

  public:
    // Constructor and Destructor
    Alphabet();
    Alphabet(std::string&);
    Alphabet(const Alphabet&);
    ~Alphabet() {};

    // Getters
    const std::set<char>& get_Alphabet(void) const;

    // Functions
    void Alphabet_Create(std::string);
    int size(void) const;

    // Read and Write
    void Alphabet_Write(void) const;

};