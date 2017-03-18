/*!
  \file ActivationRecord.h
  \brief Interfaccia di ActivationRecord
  \author Andrea Zanelli
  \date 21-11-2008
*/

#ifndef ACTIVATIONRECORD_H_INCLUSION_GUARD
#define ACTIVATIONRECORD_H_INCLUSION_GUARD

#include <stdint.h>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::stack;
using std::string;
using std::pair;
using std::vector;


/*!
  \class ActivationRecord
  \brief Rappresentazioni di un RdA (record di attivazione)

  Record di attivazione: con un PC, uno stack degli operandi e uno spazio per 
  le variabili locali. Il PC e` un numero intero senza segno. Lo stack degli
  operandi e` uno stack di coppie \<string,void*\>, nel puntatore va assegnato
  l'oggetto da mettere nello stack, nella stringa va indicato il tipo puntato
  dall'oggetto. Le variabili locali possono essere al massimo 65536, sono
  identificate da un indice intero e possono essere di tipo int (che occupa
  una posizione) o tipo long (che occupa due posizioni).
*/
class ActivationRecord {
  public:
    /* METODI PUBBLICI */

    /**
     * Costruttore di default: setta il PC a 0, l'area delle variabili locali
     * vuota e lo stack degli operandi vuoto.
     */
    ActivationRecord();

    /**
     * Distruttore
     */
    ~ActivationRecord();

    /**
     * Restituisce il valore del program counter.
     */
    unsigned int pc_get_value() const;

    /**
     * Cambia il valore del program counter, impostandolo al valore passato
     * <tt>value</tt>.
     */
    void pc_set_value(const unsigned int& value);

    /**
     * Incrementa il program counter (gli aggiunge 1) e restituisce il valore
     * del PC dopo l'incremento.
     */
    unsigned int pc_inc();

    /**
     * Mette sullo stack degli operandi il valore <tt>value</tt> di tipo int.
     */
    void op_stack_push_int(const int32_t& value);

    /**
     * Mette sullo stack degli operandi il valore <tt>value</tt> di tipo long;
     * da notare che il tipo long occupa due posti sullo stack.
     */
    void op_stack_push_long(const int64_t& value);

    /**
     * Mette sullo stack degli operandi il riferimento <tt>value</tt> di tipo 
     * void*, che punta ad una valore di tipo <tt>type</tt>.
     */
    void op_stack_push_ref(const string& type, void* value);

    /**
     * Restituisce il valore dell'elemento di tipo int in cima allo stack.
     * Se in cima allo stack non c'e` un elemento di tipo int viene lanciata
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    int32_t op_stack_top_int() const;

    /**
     * Restituisce il valore dell'elemento di tipo long in cima allo stack.
     * Se in cima allo stack non c'e` un elemento di tipo long viene lanciata
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    int64_t op_stack_top_long() const;

    /**
     * Restituisce il valore dell'elemento di tipo ref in cima allo stack.
     * Se in cima allo stack non c'e` un elemento di tipo ref viene lanciata
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    void* op_stack_top_ref() const;

    /**
     * Restituisce il tipo dell'oggetto puntato dall'elemento di tipo ref in 
     * cima allo stack. Se in cima allo stack non c'e` un elemento di tipo ref 
     * viene lanciata un'eccezione di tipo std::string con la descrizione
     * dell'errore.
     */
    string op_stack_top_ref_type() const;

    /**
     * Restituisce il carattere che rappresenta il tipo di elemento in cima 
     * allo stack con questa convenzione:
     *   - 'i': tipo int
     *   - 'l': tipo long
     *   - 'a': tipo ref (riferimento)
     * Se lo stack e` vuoto lancia un'eccezione di tipo std::string con la
     * descrizione dell'errore.
     */
    char op_stack_top_type() const;

    /**
     * Restituisce "true" se lo stack degli operandi e` vuoto, false altrimenti.
     */
    bool op_stack_empty() const;

    /**
     * Toglie il primo elemento sullo stack che occupa un posto (int o ref). Se
     * in cima e` presente un elemento che occupa due posizioni viene lanciata
     * l'eccezione un'eccezione di tipo std::string con la descrizione
     * dell'errore..\\
     * NOTA: se viene tolto un elemento di tipo "ref" (un riferimento) NON viene
     * distrutto l'oggetto puntato dal riferimento.
     */
    void op_stack_pop();

    /**
     * Toglie il primo elemento sullo stack che occupa due posti (long). Se
     * in cima e` presente un elemento che occupa un posto viene lanciata
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    void op_stack_pop2();

    /**
     * Duplica e mette sullo stack l'elemento che occupa una posizione (di tipo
     * int o ref). Se in cima allo stack degli operandi e` presente un elemento
     * che occupa due posizioni, o se lo stack e` vuoto viene lanciata
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    void op_stack_dup();

    /**
     * Duplica e mette sullo stack l'elemento che occupa due posti (di tipo
     * long). Se in cima allo stack degli operandi e` presente un
     * elemento che occupa un posto, o se lo stack e` vuoto viene lanciata
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    void op_stack_dup2();

    /**
     * Scambia il primo elemento sullo stack degli operandi con il secondo,
     * entrambi gli elementi devono occupare una posizione (tipo int o ref).
     * Se i primi due elementi in cima allo stack degli operandi non occupano,
     * una posizione, o se lo stack ha meno di due elementi, viene lanciata
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    void op_stack_swap();

    /**
     * Imposta la variabile di indice <tt>index</tt> con il valore 
     * <tt>value</tt> di tipo int. Se in quell'indice c'era un'altra variabile
     * viene sovrascritta. In caso di errore viene lanciata un'eccezione di
     * tipo std::string con la descrizione dell'errore.
     */
    void variable_set_int(const uint16_t& index, const int32_t& value);

    /**
     * Imposta la variabile di indice <tt>index</tt> con il valore 
     * <tt>value</tt> di tipo long; da notare che le variabili di tipo long
     * occupano due posti consecutivi. Se in quell'indice c'era un'altra 
     * variabile viene sovrascritta. In caso di errore viene lanciata 
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    void variable_set_long(const uint16_t& index, const int64_t& value);

    /**
     * Restituisce il valore della variabile di tipo int memorizzata nella
     * locazione di indice <tt>index</tt>. Se <tt>index</tt> non e` corretto
     * (troppo grande) o in quella locazione c'e` memorizzata una variabile
     * di tipo diverso veiene lanciata un'eccezione di tipo std::string con la
     * descrizione dell'errore.
     */
    int32_t variable_get_int(const uint16_t& index) const;

    /**
     * Restituisce il valore della variabile di tipo long memorizzata nella
     * locazione di indice <tt>index</tt>. Se <tt>index</tt> non e` corretto
     * (troppo grande) o in quella locazione c'e` memorizzata una variabile
     * di tipo diverso veiene lanciata un'eccezione di tipo std::string con la
     * descrizione dell'errore.
     */
    int64_t variable_get_long(const uint16_t& index) const;

  private:
    /* VARIABILI PRIVATE */

    //! PC (Program Counter)
    unsigned int program_counter;

    //! Generico elemento dello stack degli operandi
    struct operand_stack_element {
      char   first;  // tipo di oggetto sullo stack
      string second; // tipo dell'elemento puntato da third
      void*  third;  // puntatore all'elemento sullo stack
      operand_stack_element() {}
      operand_stack_element(const char& p_first, 
          const string& p_second, void* p_third) 
        : first(p_first), second(p_second), third(p_third) {}
    };

    //! Stack degli operandi
    stack<operand_stack_element> operand_stack;

    //! Vettore delle variabili locali
    vector< pair<char,void*> > local_variables;

    /* METODI PRIVATI */

    // cancella il puntatore della variabile con indice index
    void delete_variable(const uint16_t& index);

};


#endif // ACTIVATIONRECORD_H_INCLUSION_GUARD
