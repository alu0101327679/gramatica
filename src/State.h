/**
 * @file Alphabet.cc
 * @author Ancor González Carballo
 * @brief Contiene la declaración de la clase State
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
#include "Transition.h"

class State {   

  private:
    unsigned int transition_num_;
    unsigned int ID_;
    std::string name_;
    std::set <Transition> transitions_;

  public:
    // Constructor and Destructor
    State();
    State(const State&);
    ~State();

    // Getters
    unsigned int get_Transitions_Num(void) const;
    void set_Transitions_Num(unsigned int);
    unsigned int get_ID(void) const;
    void set_ID(unsigned int);
    std::string get_Name(void) const;
    void set_Name(std::string);
    std::set <Transition> get_Transitions(void) const;
    void set_all_transitions(unsigned int, std::set <Transition>&);
    void set_Transition(Transition);

    // Operators Overload
    State& operator =(const State&);
    bool operator !=(const State&) const;
    bool operator ==(const State&) const;
    bool operator <(const State&) const;

    // Read and Write
    void Write(void) const;
};