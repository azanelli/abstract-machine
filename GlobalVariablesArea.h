/*!
  \file GlobalVariablesArea.h
  \brief Interfaccia di GlobalVariablesArea
  \author Andrea Zanelli
  \date 19-11-2008
*/

#ifndef GLOBALVARIABLESAREA_H_INCLUSION_GUARD
#define GLOBALVARIABLESAREA_H_INCLUSION_GUARD

#include <stdint.h>
#include <string>
#include <map>

using std::string;
using std::map;


/*!
  \class GlobalVariablesArea
  \brief Memorizza le variabili globali con nome-valore

  Permette di aggiungere variabili globali di tipo S (short), C (char), I (int),
  J (long) e di impostare e leggere i valori associati al nome della variabile.
*/
class GlobalVariablesArea {
  public:
    /* METODI PUBBLICI */

    /**
     * Aggiunge la variabile di tipo S (short: intero con segno a 16 bit) con 
     * nome <tt>name</tt> e valore iniziale <tt>value</tt> (di default 0). 
     * Il valore di questa variabile va da -32.768 a +32.767. Se la variabile 
     * esiste gia` viene sovrascritta.
     */
    void add_variable_S(const string& name, const int16_t& value = 0);

    /**
     * Aggiunge la variabile di tipo C (char: intero senza segno a 16 bit) con 
     * nome <tt>name</tt> e valore iniziale <tt>value</tt> (di default 0). 
     * Il valore di questa variabile va da 0 a +65.535. Se la variabile 
     * esiste gia` viene sovrascritta.
     */
    void add_variable_C(const string& name, const uint16_t& value = 0);

    /**
     * Aggiunge la variabile di tipo I (int: intero con segno a 32 bit) con 
     * nome <tt>name</tt> e valore iniziale <tt>value</tt> (di default 0). 
     * Il valore di questa variabile va da -2.147.483.648  a +2.147.483.647. 
     * Se la variabile esiste gia` viene sovrascritta.
     */
    void add_variable_I(const string& name, const int32_t& value = 0);

    /**
     * Aggiunge la variabile di tipo J (long: intero con segno a 64 bit) cons
     * nome <tt>name</tt> e valore iniziale <tt>value</tt> (di default 0). 
     * Il valore di questa variabile va da -(2^63)  a +(2^63 - 1). 
     * Se la variabile esiste gia` viene sovrascritta.
     */
    void add_variable_J(const string& name, const int64_t& value = 0);

    /**
     * Cambia il valore della variabile di tipo S, con nome <tt>name</tt>, 
     * impostandolo a <tt>value</tt>. Se la variabile non esiste lancia 
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    void set_variable_S(const string& name, const int16_t& value);

    /**
     * Cambia il valore della variabile di tipo C, con nome <tt>name</tt>, 
     * impostandolo a <tt>value</tt>. Se la variabile non esiste lancia 
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    void set_variable_C(const string& name, const uint16_t& value);

    /**
     * Cambia il valore della variabile di tipo I, con nome <tt>name</tt>, 
     * impostandolo a <tt>value</tt>. Se la variabile non esiste lancia 
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    void set_variable_I(const string& name, const int32_t& value);

    /**
     * Cambia il valore della variabile di tipo J, con nome <tt>name</tt>, 
     * impostandolo a <tt>value</tt>. Se la variabile non esiste lancia 
     * un'eccezione di tipo std::string con la descrizione dell'errore.
     */
    void set_variable_J(const string& name, const int64_t& value);

    /**
     * Restituisce il valore della variabile di tipo S, con nome <tt>name</tt>.
     * Se la variabile non esiste lancia un'eccezione di tipo std::string con 
     * la descrizione dell'errore.
     */
    int16_t get_variable_S(const string& name) const;

    /**
     * Restituisce il valore della variabile di tipo C, con nome <tt>name</tt>.
     * Se la variabile non esiste lancia un'eccezione di tipo std::string con
     * la descrizione dell'errore.
     */
    uint16_t get_variable_C(const string& name) const;

    /**
     * Restituisce il valore della variabile di tipo I, con nome <tt>name</tt>.
     * Se la variabile non esiste lancia un'eccezione di tipo std::string con
     * la descrizione dell'errore.
     */
    int32_t get_variable_I(const string& name) const;

    /**
     * Restituisce il valore della variabile di tipo J, con nome <tt>name</tt>.
     * Se la variabile non esiste lancia un'eccezione di tipo std::string con
     * la descrizione dell'errore.
     */
    int64_t get_variable_J(const string& name) const;

  private:
    /* VARIABILI PRIVATE */

    //! usato per memorizzare le variabili di tipo S (short)
    map<string,int16_t> variables_s;

    //! usato per memorizzare le variabili di tipo C (char)
    map<string,uint16_t> variables_c; 

    //! usato per memorizzare le variabili di tipo I (int)
    map<string,int32_t> variables_i; 

    //! usato per memorizzare le variabili di tipo J (long)
    map<string,int64_t> variables_j;

};


#endif // GLOBALVARIABLESAREA_H_INCLUSION_GUARD
