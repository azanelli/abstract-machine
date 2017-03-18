/*!
  \file ActivationRecord.cc
  \brief Implementazione di ActivationRecord
  \author Andrea Zanelli
  \date 21-11-2008
*/

#ifndef ACTIVATIONRECORD_CC_INCLUSION_GUARD
#define ACTIVATIONRECORD_CC_INCLUSION_GUARD

#include "ActivationRecord.h"


/* ActivationRecord() *********************************************************/
ActivationRecord::ActivationRecord()
  : program_counter(0) {
} // end of default constructor


/* ~ActivationRecord() ********************************************************/
ActivationRecord::~ActivationRecord() {
  // distrugge i puntatori nel vettore delle variabili 
  for(vector<pair<char,void*> >::size_type i = 0; 
      i < local_variables.size(); ++i ) {
    delete_variable(i);
  }
  // distrugge i puntatori nello stack degli operandi
  char top_type;
  while(!operand_stack.empty()) {
    top_type = operand_stack.top().first;
    switch(top_type) {
      // elementi da distruggere
      case 'i':
        delete static_cast<int32_t*>(operand_stack.top().third);
        operand_stack.pop();
        break;
      case 'l':
        delete static_cast<int64_t*>(operand_stack.top().third);
        operand_stack.pop();
        break;
      // elementi da NON distruggere
      case 'a':
        operand_stack.pop();
        break;
    }
  } // end while(!operand_stack.empty())
  return;
} // end of distructor


/* unsigned int pc_get_value() const ******************************************/
unsigned int
ActivationRecord::pc_get_value() const {
  return program_counter;
}


/* void pc_set_value(const unsigned int& value) *******************************/
void 
ActivationRecord::pc_set_value(const unsigned int& value) {
  program_counter = value;
  return;
}


/* unsigned int pc_inc() ******************************************************/
unsigned int
ActivationRecord::pc_inc() {
  return ++program_counter;
}


/* void op_stack_push_int(const int32_t& value) *******************************/
void
ActivationRecord::op_stack_push_int(const int32_t& value) {
  operand_stack.push(operand_stack_element('i',"",new int32_t(value)));
  return;
}


/* void op_stack_push_long(const int64_t& value) ******************************/
void
ActivationRecord::op_stack_push_long(const int64_t& value) {
  operand_stack.push(operand_stack_element('l',"",new int64_t(value)));
  return;
}


/* void op_stack_push_ref(const string& type, void* value) ********************/
void
ActivationRecord::op_stack_push_ref(const string& type, void* value) {
  operand_stack.push(operand_stack_element('a',type,value));
  return;
}


/* int32_t op_stack_top_int() const *******************************************/
int32_t
ActivationRecord::op_stack_top_int() const {
  if(operand_stack.empty() || operand_stack.top().first != 'i')
    throw string("non vi e` un elemento di tipo int sullo stack " +
        string("degli operandi") );
  return *static_cast<int32_t*>(operand_stack.top().third);
}


/* int64_t op_stack_top_long() const ******************************************/
int64_t
ActivationRecord::op_stack_top_long() const {
  if(operand_stack.empty() || operand_stack.top().first != 'l')
    throw string("non vi e` un elemento di tipo long sullo stack " +
        string("degli operandi") );
  return *static_cast<int64_t*>(operand_stack.top().third);
}


/* void* op_stack_top_ref() const *********************************************/
void*
ActivationRecord::op_stack_top_ref() const {
  if(operand_stack.empty() || operand_stack.top().first != 'a')
    throw string("non vi e` un riferimento sullo stack degli operandi");
  return operand_stack.top().third;
}


/* string op_stack_top_ref_type() const ***************************************/
string
ActivationRecord::op_stack_top_ref_type() const {
  if(operand_stack.empty() || operand_stack.top().first != 'a')
    throw string("non vi e` un riferimento sullo stack degli operandi");
  return operand_stack.top().second;
}


/* char op_stack_top_type() const *********************************************/
char
ActivationRecord::op_stack_top_type() const {
  if(operand_stack.empty())
    throw string("si e` cercato di accedere allo stack degli operandi " + 
        string("che e` vuoto"));
  return operand_stack.top().first;
}


/* bool op_stack_empty() ********************************************************/
bool
ActivationRecord::op_stack_empty() const {
  return operand_stack.empty();
}


/* void op_stack_pop() ********************************************************/
void 
ActivationRecord::op_stack_pop() {
  if(operand_stack.empty()) {
    throw string("pop sullo stack degli operandi vuoto");
  }
  // i tipi possibili sono: int ('i'), long ('l') e ref ('a');
  // gli unici che occupano "virtualmente" un posto sono int ('i') e ref ('a')
  char top_type = operand_stack.top().first;
  if(top_type == 'i') {
    delete static_cast<int32_t*>(operand_stack.top().third);
    operand_stack.pop();
  }
  else if(top_type == 'a') {
    operand_stack.pop();
  }
  else { // top_type != 'a' &&  top_type != 'i'
    throw string("si ci aspettava un int o un riferimento sullo stack " +
        string("degli operandi durante l'operazione pop") );
  }
  return;
} // end of method: void op_stack_pop()


/* void op_stack_pop2() *******************************************************/
void
ActivationRecord::op_stack_pop2() {
  if(operand_stack.empty()) {
    throw string("pop sullo stack degli operandi vuoto");
  }
  // i tipi possibili sono: int ('i'), long ('l') e ref ('a');
  // l'unico che occupa "virtualmente" due posizioni e` il long (l)
  if(operand_stack.top().first == 'l') {
    delete static_cast<int64_t*>(operand_stack.top().third);
    operand_stack.pop();
  }
  else { // operand_stack.top().first != 'l'
    throw string("si ci aspettava un long sullo stack degli operandi " +
        string("durante l'operazione pop") );
  }
  return;
} // end of method: void op_stack_pop2()


/* void op_stack_dup() ********************************************************/
void
ActivationRecord::op_stack_dup() {
  if(operand_stack.empty()) {
    throw string("accesso allo stack degli operandi vuoto");
  }
  // i tipi possibili sono: int ('i'), long ('l') e ref ('a');
  // gli unici che occupano "virtualmente" un posto sono int ('i') e ref ('a')
  char top_type = operand_stack.top().first;
  if(top_type == 'i')
    op_stack_push_int( *static_cast<int32_t*>(operand_stack.top().third) );
  else if(top_type == 'a')
    op_stack_push_ref( operand_stack.top().second, operand_stack.top().third );
  else { // top_type != 'a' &&  top_type != 'i'
    throw string("si ci aspettava un int o un riferimento sullo stack " +
        string("degli operandi") );
  }
  return;
}


/* void op_stack_dup2() *******************************************************/
void
ActivationRecord::op_stack_dup2() {
  if(operand_stack.empty()) {
    throw string("accesso allo stack degli operandi vuoto");
  }
  // i tipi possibili sono: int ('i'), long ('l') e ref ('a');
  // l'unico che occupa "virtualmente" due posti e` long ('l')
  if(operand_stack.top().first == 'l')
    op_stack_push_long( *static_cast<int64_t*>(operand_stack.top().third) );
  else {
    throw string("si ci aspettava un long sullo stack degli operandi");
  }
  return;
}


/* void op_stack_swap() *******************************************************/
void
ActivationRecord::op_stack_swap() {
  if(operand_stack.size() < 2) {
    throw string("swap sullo stack degli operandi con meno di due elementi");
  }
  // i tipi possibili sono: int ('i'), long ('l') e ref ('a');
  // gli unici che occupano "virtualmente" un posto sono int ('i') e ref ('a')
  char top_type = operand_stack.top().first;
  operand_stack_element first_el, second_el;
  if(top_type == 'i' || top_type == 'a') {
    first_el = operand_stack.top();
    operand_stack.pop();
    top_type = operand_stack.top().first;
    if(top_type == 'i' || top_type == 'a') {
      second_el = operand_stack.top();
      operand_stack.pop();
    }
    else { // top_type != 'a' &&  top_type != 'i'
      throw string("si ci aspettava un int o un riferimento sullo stack " +
        string("degli operandi") );
    }
  }
  else { // top_type != 'a' &&  top_type != 'i'
    throw string("si ci aspettava un int o un riferimento sullo stack " +
        string("degli operandi") );
  }
  operand_stack.push(first_el);
  operand_stack.push(second_el);
  return;
}


/* void variable_set_int(const uint16_t& index, const int32_t& value) *********/
void 
ActivationRecord::variable_set_int(const uint16_t& index,
    const int32_t& value) {
  if(index >= local_variables.size()) {
    // viene aggiunta una nuova variabile
    local_variables.resize(index+1);
    local_variables[index].first = 'I';
    local_variables[index].second = new int32_t(value);
  } // end if(index >= local_variables.size())
  else {
    // viene sovrascritta una variabile gia` esistente
    if(local_variables[index].second != 0 ||
        local_variables[index].first == '$') {
      delete_variable(index);
    }
    local_variables[index].first = 'I';
    local_variables[index].second = new int32_t(value);
  } // end else [if(index >= local_variables.size())]
  return;
} // end of method: void variable_set_int(...)


/* void variable_set_long(const uint16_t& index, const int64_t& value) ********/
void 
ActivationRecord::variable_set_long(const uint16_t& index,
    const int64_t& value) {
  if(index >= local_variables.size()) {
    // viene aggiunta una nuova variabile
    local_variables.resize(index+2);
    local_variables[index].first = 'J';
    local_variables[index].second = new int64_t(value);
    // "riempe" lo spazio successivo alla variabile di tipo long con un '$'
    local_variables[index+1].first = '$';
    local_variables[index+1].second = 0;
  } // end if(index+1 >= local_variables.size())
  else if(index == local_variables.size()-1) {
    // viene sovrascritta una variabile gia` esistente
    local_variables.resize(index+2);
    if(local_variables[index].second != 0 || 
        local_variables[index].first == '$') {
      delete_variable(index);
    }
    local_variables[index].first = 'J';
    local_variables[index].second = new int64_t(value);
    // "riempe" lo spazio successivo alla variabile di tipo long con un '$'
    local_variables[index+1].first = '$';
    local_variables[index+1].second = 0;
  } // end else if(index == local_variables.size()-1)
  else {
    // viene sovrascritta una variabile gia` esistente
    if(local_variables[index].second != 0 || 
        local_variables[index].first == '$') {
      delete_variable(index);
    }
    local_variables[index].first = 'J';
    local_variables[index].second = new int64_t(value);
    // "riempe" lo spazio successivo alla variabile di tipo long con un '$'
    if(local_variables[index+1].second != 0) {
      delete_variable(index+1);
    }
    local_variables[index+1].first = '$';
    local_variables[index+1].second = 0;
  } // end else
  return;
} // end of method: void variable_set_long(...)


/* int32_t variable_get_int(const uint16_t& index) ****************************/
int32_t 
ActivationRecord::variable_get_int(const uint16_t& index) const {
  if(index >= local_variables.size())
    throw string("accesso alla variabile locale " + index
        + string(" che non e` stata inizializzata") );
  else if(local_variables[index].first != 'I')
    throw string("la variabile locale " + index
        + string(" non e` di tipo int") );
  return *(static_cast<int32_t*>(local_variables[index].second));
}


/* int64_t variable_get_long(const uint16_t& index) ***************************/
int64_t
ActivationRecord::variable_get_long(const uint16_t& index) const {
  if((uint16_t)(index+1) >= local_variables.size())
    throw string("accesso alla variabile locale " + index
        + string("che non e` stata inizializzata") );
  else if(local_variables[index].first != 'J')
    throw string("la variabile locale " + index
        + string(" non e` di tipo long") );
  return *(static_cast<int64_t*>(local_variables[index].second));
}


/* void delete_variable(const uint16_t& index) ********************************/
void
ActivationRecord::delete_variable(const uint16_t& index) {
  if(local_variables[index].first == 'I') {
    local_variables[index].first = char();
    delete static_cast<int32_t*>(local_variables[index].second);
    local_variables[index].second = 0;
  }
  else if(local_variables[index].first == 'J') {
    local_variables[index].first = char();
    delete static_cast<int64_t*>(local_variables[index].second);
    local_variables[index].second = 0;
    local_variables[index+1].first = char();
    local_variables[index+1].second = 0;
  }
  else if(local_variables[index].first == '$') {
    local_variables[index-1].first = char();
    delete static_cast<int64_t*>(local_variables[index-1].second);
    local_variables[index-1].second = 0;
    local_variables[index].first = char();
    local_variables[index].second = 0;
  }
  return;
} // of method: void delete_variable(const uint16_t& index)


#endif // ACTIVATIONRECORD_CC_INCLUSION_GUARD
