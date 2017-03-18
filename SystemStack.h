/*!
  \file SystemStack.h
  \brief Interfaccia di SystemStack
  \author Andrea Zanelli
  \date 20-12-2008
*/

#ifndef SYSTEMSTACK_H_INCLUSION_GUARD
#define SYSTEMSTACK_H_INCLUSION_GUARD

#include <stdint.h>
#include <list>
#include <string>

#include "ActivationRecord.h"

using std::list;
using std::string;


/*!
  \class SystemStack
  \brief Rappresenta lo stack di sistema (uno stack di record di attivazione)

  Stack di AR (Activation Record, record di attivazione) che permette di
  eseguire operazioni sul PC (program counter), sulle variabili locali e sullo
  stack degli operandi dell'AR in cima allo stack.
*/
class SystemStack {

  public:
    /* METODI PUBBLICI */

    /**
     * Restituisce true se lo Stack e` vuoto, false altrimenti.
     */
    inline
    bool empty() {
      return system_stack.empty();
    }

    /**
     * Aggiunge un record di attivazione vuoto in cima allo Stack.
     */
    inline
    void push_ar() {
      system_stack.push_back(ActivationRecord());
      return;
    }

    /**
     * Elimina il record di attivazione in cima allo Stack. Se lo Stack e` vuoto
     * viene lanciata un'eccezione di tipo std::string con la descrizione
     * dell'errore.
     */
    inline
    void pop_ar(){
      system_stack.pop_back();
      return;
    }

    /**
     * Setta il valore del PC del RdA in cima allo Stack con il valore passato
     * <tt>value</tt>.
     */
    inline
    void pc_set(const unsigned int& value) {
      system_stack.back().pc_set_value(value);
      return;
    }

    /**
     * Restituisce il valore del PC del RdA in cima allo Stack.
     */
    inline
    unsigned int pc_get() const {
      return system_stack.back().pc_get_value();
    }

    /**
     * Incrementa di 1 il valore del PC del RdA in cima allo Stack, e
     * restituisce il valore incrementato.
     */
    inline
    unsigned int pc_inc() {
      return system_stack.back().pc_inc();
    }

    /**
     * Setta la variabile locale di indice <tt>index</tt> del RdA in cima allo
     * Stack, con il valore <tt>value</tt> di tipo int (occupa quindi un posto
     * tra le variabili locali).
     */
    inline
    void local_variable_set_int(const uint16_t& index, const int32_t& value){
      system_stack.back().variable_set_int(index,value);
      return;
    }

    /**
     * Setta la variabile locale di indice <tt>index</tt> del RdA in cima allo
     * Stack, con il valore <tt>value</tt> di tipo long (occupa quindi due posti 
     * tra le variabili locali).
     */
    inline
    void local_variable_set_long(const uint16_t& index, const int64_t& value){
      system_stack.back().variable_set_long(index,value);
      return;
    }

    /**
     * Restituisce il valore della variabile locale di indice <tt>index</tt> e
     * tipo int del RdA in cima allo Stack. In caso di errore lancia una
     * eccezione di tipo std::string con la descrizione dell'errore.
     */
    inline
    int32_t local_variable_get_int(const uint16_t& index) const {
      return system_stack.back().variable_get_int(index);
    }

    /**
     * Restituisce il valore della variabile locale di indice <tt>index</tt> e
     * tipo long del RdA in cima allo Stack. In caso di errore lancia
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    inline
    int64_t local_variable_get_long(const uint16_t& index) const {
      return system_stack.back().variable_get_long(index);
    }

    /**
     * Mette sullo stack degli operandi del RdA in cima allo Stack il valore
     * <tt>value</tt> di tipo int.
     */
    inline
    void op_stack_push_int(const int32_t& value) {
      system_stack.back().op_stack_push_int(value);
      return;
    }

    /**
     * Mette sullo stack degli operandi del RdA in cima allo Stack il valore
     * <tt>value</tt> di tipo long; da notare che il tipo long occupa due slot
     * sullo stack degli operandi.
     */
    inline
    void op_stack_push_long(const int64_t& value) {
      system_stack.back().op_stack_push_long(value);
      return;
    }

    /**
     * Mette sullo stack degli operandi del RdA in cima allo Stack il 
     * riferimento <tt>value</tt> di tipo void*, che punta ad una valore di 
     * tipo <tt>type</tt>.
     */
    inline
    void op_stack_push_ref(const string& type, void* value) {
      system_stack.back().op_stack_push_ref(type,value);
      return;
    }

    /**
     * Restituisce il valore dell'elemento di tipo int in cima allo stack degli
     * operandi del RdA in cima allo Stack.
     * Se in cima allo stack degli operandi non c'e` un elemento di tipo int 
     * viene lanciata un'eccezione di tipo std::string con la descrizione
     * dell'errore.
     */
    inline
    int32_t op_stack_top_int() const {
      return system_stack.back().op_stack_top_int();
    }

    /**
     * Restituisce il valore dell'elemento di tipo long in cima allo stack degli
     * operandi del RdA in cima allo Stack.
     * Se in cima allo stack degli operandi non c'e` un elemento di tipo long 
     * viene lanciata un'eccezione di tipo std::string con la descrizione
     * dell'errore.
     */
    inline
    int64_t op_stack_top_long() const {
      return system_stack.back().op_stack_top_long();
    }

    /**
     * Restituisce il valore dell'elemento di tipo ref in cima allo stack degli
     * operandi del RdA in cima allo Stack.
     * Se in cima allo stack degli operandi non c'e` un elemento di tipo ref 
     * viene lanciata un'eccezione di tipo std::string con la descrizione
     * dell'errore.
     */
    inline
    void* op_stack_top_ref() const {
      return system_stack.back().op_stack_top_ref();
    }

    /**
     * Restituisce il tipo dell'oggetto puntato dall'elemento di tipo ref in 
     * cima allo stack degli operandi del RdA in cima allo Stack. Se in cima 
     * allo stack degli operandi non c'e` un elemento di tipo ref 
     * viene lanciata un'eccezione di tipo std::string con la descrizione
     * dell'errore.
     */
    inline
    string op_stack_top_ref_type() const {
      return system_stack.back().op_stack_top_ref_type();
    }

    /**
     * Restituisce "true" se lo stack degli operandi del RdA in cima allo Stack
     * e` vuoto, false altrimenti.
     */
    inline
    bool op_stack_empty() const {
      return system_stack.back().op_stack_empty();
    }

    /**
     * Toglie il primo elemento sullo stack degli operandi che occupa uno slot 
     * (int o ref). Se in cima e` presente un elemento che occupa due posizioni 
     * viene lanciata un'eccezione di tipo std::string con la descrizione
     * dell'errore.
     * NOTA: se viene tolto un elemento di tipo "ref" (un riferimento) NON viene
     * distrutto l'oggetto puntato dal riferimento.
     */
    inline
    void op_stack_pop() {
      system_stack.back().op_stack_pop();
      return;
    }

    /**
     * Toglie il primo elemento sullo stack degli operandi che occupa due slot 
     * (long). Se in cima e` presente un elemento che occupa un posto viene 
     * lanciata un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    inline
    void op_stack_pop2() {
      system_stack.back().op_stack_pop2();
      return;
    }

    /**
     * Duplica e mette sullo stack degli operandi l'elemento che occupa una
     * posizione (int o ref). Se in cima allo stack degli operandi e` presente
     * un elemento che occupa due posizioni, o se lo stack e` vuoto viene
     * lanciata un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    inline
    void op_stack_dup() {
      system_stack.back().op_stack_dup();
      return;
    }

    /**
     * Duplica e mette sullo stack degli operandi l'elemento che occupa due
     * posizioni (long). Se in cima allo stack degli operandi e` presente un
     * elemento che occupa una posizione, o se lo stack e` vuoto viene lanciata
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    inline
    void op_stack_dup2() {
      system_stack.back().op_stack_dup2();
      return;
    }

    /**
     * Scambia il primo elemento sullo stack degli operandi con il secondo,
     * entrambi gli elementi devono occupare una posizione (tipo int o ref).
     * Se i primi due elementi in cima allo stack degli operandi non occupano,
     * una posizione, o se lo stack contiene meno di due elementi, viene
     * lanciata un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    inline
    void op_stack_swap() {
      system_stack.back().op_stack_swap();
      return;
    }

    /**
     * Utilizzato per il passaggio di parametri nelle chiamate a funzione.\\
     * Prende l'elemento di tipo int sullo stack degli operandi del RdA
     * "vecchio" (cioe` NON il RdA in cima allo stack di sistema, ma il
     * precedente), e lo mette nella variabile locale <tt>index</tt> del RdA
     * in cima allo stack. In caso di errori (il tipo non e` esatto) viene
     * lanciata un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    inline
    void parameter_pass_int(const uint16_t& index) {
      list<ActivationRecord>::reverse_iterator r_iter = system_stack.rbegin();
      ++r_iter;
      this->local_variable_set_int(index, r_iter->op_stack_top_int());
      r_iter->op_stack_pop();
      return;
    }

    /**
     * Utilizzato per il passaggio di parametri nelle chiamate a funzione.\\
     * Prende l'elemento di tipo long sullo stack degli operandi del RdA
     * "vecchio" (cioe` NON il RdA in cima allo stack di sistema, ma il
     * precedente), e lo mette nella variabile locale <tt>index</tt> del RdA
     * in cima allo stack. In caso di errori (il tipo non e` esatto) viene
     * lanciata un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    inline
    void parameter_pass_long(const uint16_t& index) {
      list<ActivationRecord>::reverse_iterator r_iter = system_stack.rbegin();
      ++r_iter;
      this->local_variable_set_long(index, r_iter->op_stack_top_long());
      r_iter->op_stack_pop2();
      return;
    }

  private:
    /* VARIABILI PRIVATE */

    //! Stack di record di attivazione (ActivationRecord)
    list<ActivationRecord> system_stack;

};


#endif // SYSTEMSTACK_H_INCLUSION_GUARD
