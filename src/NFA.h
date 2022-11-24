/**
 * @file Alphabet.cc
 * @author Ancor González Carballo
 * @brief Contiene la declaración de la clase NFA
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <fstream>

#pragma once 
#include "Alphabet.h"
#include "State.h"
#include "DFA.h"

class NFA {

  private:
    Alphabet alphabet_;
    std::set <State> states_;
    State initial_;
    std::set <State> acept_;
    unsigned int States_num;

  public:
    // Constructor and Destructor
    NFA();
    NFA(NFA&);
    NFA(std::string&);
    ~NFA();

    // Getters and Setters
    Alphabet get_Alphabet(void) const;
    void set_Alphabet(const Alphabet&);
    std::set <State> get_States(void) const;
    void set_States(const std::set <State>&);
    State get_Initial(void) const;
    void set_Initial(const State&);
    std::set <State> get_Acepted(void) const;
    void set_Acepted(const std::set <State>&);
    unsigned int get_States_Num(void) const;

    // Functions
    void Generate_NFA(std::string&);
    std::set <State> Epsilon_Clausure(std::set<State>&);
    std::set <State> Move(std::set<State>&, char);
    void UnMark(std::set<State>&);
    bool Is_In(State, std::set<State>) const;
    bool Mark(State, std::set<State>) const;
    void Create_NFA_File(std::string&) const;

    // Read and Write
    void Write_DFA(DFA&, std::string&);
    void Write_DFA(DFA, std::string&);
    
  };