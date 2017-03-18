/*!
  \file GlobalVariablesArea.cc
  \brief Implementazione di GlobalVariablesArea
  \author Andrea Zanelli
  \date 19-11-2008
*/

#ifndef GLOBALVARIABLESAREA_CC_INCLUSION_GUARD
#define GLOBALVARIABLESAREA_CC_INCLUSION_GUARD

#include "GlobalVariablesArea.h"


/* void add_variable_S(const string& name, const int16_t& value) **************/
void
GlobalVariablesArea::add_variable_S(const string& name, const int16_t& value) {
  variables_s.insert(make_pair(name,value));
  return;
}


/* void add_variable_C(const string& name, const uint16_t& value) *************/
void 
GlobalVariablesArea::add_variable_C(const string& name, const uint16_t& value) {
  variables_c.insert(make_pair(name,value));
  return;
}


/* void add_variable_I(const string& name, const int32_t& value) **************/
void
GlobalVariablesArea::add_variable_I(const string& name, const int32_t& value) {
  variables_i.insert(make_pair(name,value));
  return;
}


/* void add_variable_J(const string& name, const int64_t& value) **************/
void
GlobalVariablesArea::add_variable_J(const string& name, const int64_t& value) {
  variables_j.insert(make_pair(name,value));
  return;
}


/* void set_variable_S(const string& name, const int16_t& value) **************/
void 
GlobalVariablesArea::set_variable_S(const string& name, const int16_t& value) {
  map<string,int16_t>::iterator iter = variables_s.find(name);
  if(iter == variables_s.end())
    throw string("variabile globale inesistente: " + name + " S");
  else
    iter->second = value;
  return;
}


/* void set_variable_C(const string& name, const uint16_t& value) **************/
void 
GlobalVariablesArea::set_variable_C(const string& name, const uint16_t& value) {
  map<string,uint16_t>::iterator iter = variables_c.find(name);
  if(iter == variables_c.end())
    throw string("variabile globale inesistente: " + name + " C");
  else
    iter->second = value;
  return;
}


/* void set_variable_I(const string& name, const int32_t& value) **************/
void 
GlobalVariablesArea::set_variable_I(const string& name, const int32_t& value) {
  map<string,int32_t>::iterator iter = variables_i.find(name);
  if(iter == variables_i.end())
    throw string("variabile globale inesistente: " + name + " I");
  else
    iter->second = value;
  return;
}


/* void set_variable_J(const string& name, const int64_t& value) **************/
void 
GlobalVariablesArea::set_variable_J(const string& name, const int64_t& value) {
  map<string,int64_t>::iterator iter = variables_j.find(name);
  if(iter == variables_j.end())
    throw string("variabile globale inesistente: " + name + " J");
  else
    iter->second = value;
  return;
}


/* int16_t get_variable_S(const string& name) const ***************************/
int16_t 
GlobalVariablesArea::get_variable_S(const string& name) const {
  map<string,int16_t>::const_iterator iter = variables_s.find(name);
  if(iter == variables_s.end())
    throw string("variabile globale inesistente: " + name + " S");
  return iter->second;
}


/* uint16_t get_variable_C(const string& name) const **************************/
uint16_t 
GlobalVariablesArea::get_variable_C(const string& name) const {
  map<string,uint16_t>::const_iterator iter = variables_c.find(name);
  if(iter == variables_c.end())
    throw string("variabile globale inesistente: " + name + " C");
  return iter->second;
}


/* int32_t get_variable_I(const string& name) const ***************************/
int32_t 
GlobalVariablesArea::get_variable_I(const string& name) const {
  map<string,int32_t>::const_iterator iter = variables_i.find(name);
  if(iter == variables_i.end())
    throw string("variabile globale inesistente: " + name + " I");
  return iter->second;
}


/* int64_t get_variable_J(const string& name) const ***************************/
int64_t
GlobalVariablesArea::get_variable_J(const string& name) const {
  map<string,int64_t>::const_iterator iter = variables_j.find(name);
  if(iter == variables_j.end())
    throw string("variabile globale inesistente: " + name + " J");
  return iter->second;
}


#endif // GLOBALVARIABLESAREA_CC_INCLUSION_GUARD
