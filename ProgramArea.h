/*!
  \file ProgramArea.h
  \brief Interfaccia di ProgramArea
  \author Andrea Zanelli
  \date 18-12-2008
*/

#ifndef PROGRAMAREA_H_INCLUSION_GUARD
#define PROGRAMAREA_H_INCLUSION_GUARD

#include <string>
#include <vector>
#include <map>
#include <utility>

using std::string;
using std::vector;
using std::map;
using std::pair;


/*!
  \class ProgramArea
  \brief Area dove memorizzare le istruzioni

  Le istruzioni vengono memorizzate nell'ordine d'inserimento, vengono
  suddivise per funzione di appartenenza e gli viene dato un indice univoco
  e consecutivo all'istruzione che le precede. \\
  Le etichette vengono tolte e, attraverso una funzione apposta, puo` restituire
  l'istruzione "puntata" da una certa etichetta. \\
*/
class ProgramArea {
  public:
    /* METODI PUBBLICI */

    /**
     * Costruttore di default
     */
    ProgramArea();

    /**
     * Restituisce l'istruzione con indice <tt>index</tt> nella forma con cui e`
     * stata inserita a meno di un'eventuale etichetta. Se l'istruzione era
     * solamente un'etichetta viene restituita la stringa vuota. Se l'indice e`
     * errato lanciata un'eccezione di tipo std::string con la descrizione
     * dell'errore.
     */
    string get_instruction(const unsigned int& index) const;

    /**
     * Restituisce l'indice della prima istruzione della funzione con 
     * descrittore <tt>name</tt> che deve avere questa forma: 
     * "NomeFunzione(TipoArgomenti)TipoRitorno", con eventualmente degli spazi.
     * Se la funzione non esiste lancia un'eccezione di tipo std::string
     * con la descrizione dell'errore.
     */
    unsigned int get_function_index(string name) const;

    /**
     * Restituisce l'indice dell'ultima istruzione della funzione con 
     * descrittore <tt>name</tt> che deve avere questa forma: 
     * "NomeFunzione(TipoArgomenti)TipoRitorno", con eventualmente degli spazi.
     * Se la funzione non esiste lancia un'eccezione di tipo std::string
     * con la descrizione dell'errore.
     */
    unsigned int get_function_end_index(string name) const;

    /**
     * Restituisce l'indice dell'istruzione a cui corrispondeva l'etichetta
     * <tt>label</tt>. Se l'etichetta non esiste lancia un'eccezione di tipo
     * std::string con la descrizione dell'errore.
     */
    unsigned int get_label_index(const string& label) const;

    /**
     * Aggiunge l'istruzione <tt>instruction</tt> al programma. Se 
     * <tt>instruction</tt> inizia con la parola ".method public static " si 
     * assume che sia l'inizio di una funzione e tutte le istruzioni successive 
     * vengono considerate all'interno di quella funzione fino ad una istruzione 
     * ".end method". Ogni istruzione dev'essere all'interno di una funzione.
     * Si suppone che le istruzioni aggiunte siano tutte sintatticamente
     * corrette, senza spazi all'inizio e alla fine, con un solo spazio tra gli
     * argomenti e tra il nome e gli argomenti. Ogni funzione deve iniziare con
     * un'istruzione ".method public static " e finire con l'istruzione 
     * ".end method".\\
     * Se un'istruzione e` preceduta da un'etichetta, questa viene tolta e 
     * viene memorizzato l'indice dell'istruzione "puntata" dall'ettichetta. Le
     * etichette devono essere all'inizio dell'istruzione (eventualmente senza
     * istruzione di seguito).
     * In caso di errori viene lanciata un'eccezione di tipo std::string
     * con la descrizione dell'errore.
     */
    void add_instruction(const string& instruction);

    /**
     * Ritorna il numero di istruzioni memorizzate 
     */
    unsigned int get_instructions_size() const;

    /**
     * Ritorna il numero di funzioni memorizzate 
     */
    unsigned int get_functions_size() const;

  private:
    /* VARIABILI PRIVATE */

    //! usato per memorizzare le istruzioni
    vector<string> program;

    //! usato per memorizzare il nome delle funzioni con gli indici della prima
    //! e dell'ulitma istruzione
    map<string, pair<unsigned int, unsigned int> > functions;

    //! usato per memorizzare il nome delle etichette con l'indice dell'
    //! istruzione "puntata".
    map<string, unsigned int> labels;

    // true se e` stato appena aggiunta una funzione e l'istruzione successiva 
    // e` la prima
    bool is_start_function;

    // nome della funzione alla quale si stanno aggiungendo istruzioni
    string current_function;

    // true se si stanno aggiungendo istruzioni all'interno di una funzione
    bool inside_function;

    /* METODI PRIVATI */

    /**
     * Controlla se nella ultima istruzione inserita in program e` presente una
     * etichetta nella forma <em>label:</em>, in tal caso toglie l'etichetta e
     * la memorizza in <tt>labels</tt> con il corrispettivo indice dell'
     * istruzione.
     */
    void control_label();

    /**
     * Elimina gli spazi dalla stringa passata
     */
    void delete_space(string& str) const;

};


#endif // PROGRAMAREA_H_INCLUSION_GUARD
