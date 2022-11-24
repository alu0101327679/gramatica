/**
 * @file Alphabet.cc
 * @author Ancor González Carballo
 * @brief Contiene la declaración de la clase Transition
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>

#pragma once

class Transition {

  private:
    char symbol_;
    unsigned int next_state_; 

  public:
    // Constructor and Destructor
    Transition();
    Transition(const Transition&);
    Transition(char b, unsigned int a);
    ~Transition();

    // Getters
    char get_Symbol(void) const;
    void set_Symbol(char);
    unsigned int get_Next_State(void) const;
    void set_Next_State(unsigned int); 

    // Operator Overload
    Transition operator =(const Transition);
    bool operator ==(const Transition&)const;
    bool operator !=(const Transition&) const;
    bool operator <(const Transition&) const;

    // Functions
    void Next_Transition(Transition&);

    // Read and Write
    void Write(void) const;
};