/**
 * @file Alphabet.cc
 * @author Ancor González Carballo
 * @brief Contiene la declaración de la clase DFA
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*----------    LIBRARIES DECLARATION   ----------*/
#include <utility>
#include <iostream>
#include <fstream>
#include <vector>

#pragma once
#include "Alphabet.h"
#include "State.h"

class DFA {

  private:
    Alphabet alpha_;
    std::set <State> states_;
    unsigned int States_num; 
    std::set <State> acepted_states_;
    State  initial_state_;
    std::string in_file_;

  public:
    // Constructor and Destructor
    DFA();
    DFA(const DFA&);
    ~DFA();

    // Getters and std::Setters
    void set_DFA(std::string&);
    Alphabet get_Alphabet(void) const;
    void set_Alphabet(void);
    std::set <State> get_States(void) const;
    void set_States(std::set <State>&);
    unsigned int get_States_Num(void) const;
    void set_States_Num(unsigned int);
    std::set <State> get_Acepteded_States(void) const;
    void set_Acepteded_States(std::set <State>&);
    State get_Initial_State(void) const;
    void set_Initial_State(State);
    std::string get_Input_File(void) const;
    void set_Input_File(std::string&);

    // Functions
    void DrawDFA(std::string&);

    // Read and Write   
    void Write_DFA(void) const;
    void Read_File(void);
    
};