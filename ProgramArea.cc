/*!
  \file ProgramArea.cc
  \brief Implementazione di ProgramArea
  \author Andrea Zanelli
  \date 18-12-2008
*/

#ifndef PROGRAMAREA_CC_INCLUSION_GUARD
#define PROGRAMAREA_CC_INCLUSION_GUARD

#include "ProgramArea.h"


/* ProgramArea() **************************************************************/
ProgramArea::ProgramArea() 
  : is_start_function(false),
    current_function(""),
    inside_function(false) {
  return;
}


/* string get_instruction(const vector<string>::size_type& index) const *******/
string
ProgramArea::get_instruction(const unsigned int& index) const {
  if(index >= program.size())
    throw string("l'istruzione richiesta e` fuori dall'area del programma");
  return program[index];
}


/* unsigned int get_function_index(const string& name) const ******************/
unsigned int
ProgramArea::get_function_index(string name) const {
  map<string, pair<unsigned int,unsigned int> >::const_iterator iter;
  delete_space(name);
  iter = functions.find(name);
  if(iter == functions.end())
    throw string("la funzione richiesta non esiste: " + name);
  return (iter->second).first;
}


/* unsigned int get_function_end_index(const string& name) const **************/
unsigned int
ProgramArea::get_function_end_index(string name) const {
  map<string, pair<unsigned int, unsigned int> >::const_iterator iter;
  delete_space(name);
  iter = functions.find(name);
  if(iter == functions.end())
    throw string("la funzione richiesta non esiste: " + name);
  return (iter->second).second;
}


/* unsigned int get_label_index(const string& label) const ********************/
unsigned int 
ProgramArea::get_label_index(const string& label) const {
  map<string, unsigned int>::const_iterator iter;
  iter = labels.find(label);
  if(iter == labels.end())
    throw string("etichetta inesistente nel programma: " + label);
  return iter->second;
}


/* void add_instruction(const string& instruction) ****************************/
void
ProgramArea::add_instruction(const string& instruction) {
  // interno di una funzione
  if(inside_function) {
    // dichiarazione di fine fuznione
    if(instruction == ".end method") {
      inside_function = false;
      is_start_function = false;
      // mette l'indice dell'ultima istruzione in functions
      map<string, pair<unsigned int,unsigned int> >::iterator iter;
      iter = functions.find(current_function);
      if(iter == functions.end())
        throw string("direttiva .end method di fine funzione senza " +
            string("una direttiva .method di inizio funzione") );
      else
        (iter->second).second = program.size()-1;
      current_function = "";
    }
    else {
      // istruzione normale
      program.push_back(instruction);
      control_label();
      // prima istruzione della funzione
      if(is_start_function) {
        functions.insert(std::make_pair( current_function, 
                std::make_pair(program.size()-1, int()) ));
        is_start_function = false;
      }
    }
  } // end if(inside_function)

  // inizio di una funzione
  else if(instruction.substr(0,22) == ".method public static ") {
    is_start_function = true;
    inside_function = true;
    current_function = instruction.substr(22);
    delete_space(current_function);
  } // end else if(instruction.substr(0,22) == ...)

  // errore
  else {
    throw string("istruzione fuori da una funzione: " + instruction);
  }

  return;
} // end of method add_instruction(const string& instruction)


/* unsigned int get_instructions_size() const *********************************/
unsigned int 
ProgramArea::get_instructions_size() const {
  return static_cast<unsigned int>(program.size());
}


/* unsigned int get_functions_size() const ************************************/
unsigned int 
ProgramArea::get_functions_size() const {
  return static_cast<unsigned int>(functions.size());
}


/* void control_label() *******************************************************/
void 
ProgramArea::control_label() {
  // viene utilizzata l'ipotesi che tra l'istruzione e un argomento c'e` sempre
  // uno spazio e che un etichetta e` sempre all'inizio dell'istruzione. 
  // percio`, se c'e` un'istruzione che nell'argomento ha "due punti" (ad
  // esempio, una stringa contentente i :), e` sempre preceduta da uno spazio,
  // cosi` si puo` distinguere l'etichetta dall'argomento.
  string::size_type loc = program.back().find(':');
  string::size_type loc_space = program.back().find(' ');
  if(loc != string::npos && (loc_space == string::npos || loc < loc_space)) {
    // inserisce in labels l'etichetta
    labels.insert( std::make_pair(
        program.back().substr(0, loc), 
        program.size()-1 ) );
    // elimina l'etichetta dall'istruzione
    if(loc == program.back().size()-1)
      program.back().erase(0, loc+1);
    else if(program.back().at(loc+1) == ' ')
      program.back().erase(0, loc+2);
    else
      program.back().erase(0, loc+1);
  }
  return;
}


/* void delete_space(string& str) const ***************************************/
void 
ProgramArea::delete_space(string& str) const {
  string::size_type pos = str.find(" ");
  while(pos != string::npos) {
    str.erase(pos, 1);
    pos = str.find(" ", pos);
  }
  return;
}


#endif // PROGRAMAREA_CC_INCLUSION_GUARD
