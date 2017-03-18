/*!
  \mainpage Macchina Astratta

  \section intro_sec Introduzione

  La macchina astratta implementata e` basata sulla JVM sia per quanto riguarda
  la sua struttura, sia per l'instruction-set. Per quest'ultimo e` stato preso
  un sottoinsieme di quello della JVM, percui un programma funzionante su questa
  macchina astratta funziona anche sulla JVM, traducendo pero` gli mnemonici in
  bytecode con un assembler come, per esempio, l'Oolong scritto da Joshua Engel.
  La struttura, in modo simile alla JVM, e` composta da uno stack di sistema,
  in cui vengono messi i record di attivazione (RdA) di ogni funzione che viene
  eseguita, e da una area-programma dove vengono memorizzate le istruzioni da
  eseguire. Ogni RdA e` quindi composto da un program counter (PC) che punta
  all'istruzione da eseguire, da uno stack degli operandi e da un array delle
  variabili locali.

  \section install_sec Compilazione e installazione

  Per compilare e creare l'eseguibile della macchina astratta, o per creare la
  documentazione attraverso doxygen, e` possibile dare uno dei seguenti comandi
  all'interno della directory "macchina-astratta" dove sono presenti i file
  sorgente:
    - <tt>make</tt>: crea l'eseguibile <tt>macchina-astratta</tt> dentro la
      directory "bin".
    - <tt>make doc</tt>: crea la documentazione del codice in formato html e
      pdf dentro la directory "doc".
  L'eseguibile <tt>macchina-astratta</tt> si aspetta come argomento un file,
  all'interno del quale ci dovra` essere il codice del programma da eseguire.
*/

/*!
  \file macchina-astratta.cc
  \brief Implementazione della macchina astratta
  \author Andrea Zanelli
  \date 18-12-2008
*/

#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

#include "ProgramArea.h"
#include "GlobalVariablesArea.h"
#include "SystemStack.h"

using std::string;

// Variabili globali

//! Contiene l'insieme delle istruzioni da eseguire suddivise per funzione
ProgramArea programma;

//! Contiene le variabili globali del programma
GlobalVariablesArea variabili_globali; 

//! Stack di sistema del programma da eseguire, contiene i record di attivazione
SystemStack stack_di_sistema;

//! Se "true" e` stata trovata la funzione "clinit"
bool funzione_clinit = false;

//! Numero di funzioni trovate all'interno del programma
unsigned int n_funzioni = 0;

// Dichiarazione di funzioni

void leggi_file(std::ifstream& in_file);
bool leggi_istruzione(std::ifstream& file, string& str);
void cotrolla_etichetta(string& str);
void gestisci_direttiva(const string& direttiva);
void inserisci_variabile_globale(const string& direttiva);
void pulisci_stringa(string& str);
void elimina_spazi_iniziali_e_finali(string& str);
void cancella_carattere(string& str, char c = ' ');
extern void esecutore();


/*!
  \fn int main(int argc, char **argv)
  \brief Funzione iniziale della macchina astratta
  \param argv array con gli argomenti
  \param argc numero di argomenti  
  \return 0: Ok
  \return 1: Errore

  Prende come argomento il nome del file da eseguire (contenente il programma).
  Dopodiche` esegue i seguenti passi:
    - (1) Inizializza l'oggetto globale <tt>programma</tt> e carica le
      istruzioni del programma al suo interno.
    - (2) Inizializza l'oggetto globale <tt>variabili_globali</tt> e ci
      mette dentro le variabili globali del programma.
    - (3) Se esiste la funzione "\<clinit\> ()V" (per l'inizializzazione 
      delle variabili globali) crea un record di attivazione vuoto in
      <tt>stack_di_sistema</tt> impostando il PC alla prima istruzione di
      "&lt;clinit&gt; ()V" e chiama la funzione <tt>esecutore()</tt>.
    - (4) Crea un record di attivazione nell'oggetto globale
      <tt>stack_di_sistema</tt> e imposta il PC alla prima istruzione della
      funzione main.
    - (5) Passa il controllo alla funzione <tt>esecutore()</tt> che si occupa
      di eseguire le istruzioni contenute in <tt>programma</tt>.
*/
int main(int argc, char **argv) {
  /* Gestisce gli argomenti e apre il file */
  std::ifstream in_file;
  if(argc < 2) {
    std::cerr <<"Errore: specificare il nome del file" <<std::endl;
    return 1;
  }
  if(argc > 2) {
    std::cerr <<"Attenzione: i seguenti argomenti sono stati ignorati:";
    for(int i=2; i<argc; ++i)
      std::cerr  <<" " <<argv[i];
    std::cerr <<std::endl;
  } // end if(argc > 2)

  in_file.open(argv[1]);
  if(!in_file) {
    std::cerr <<"Errore: impossibile aprire il file " <<argv[1] <<std::endl;
    return 1;
  }

  try{
    /* (1) e (2): legge e gestisce le istruzioni nel file */
    leggi_file(in_file);

    /* (3) e (4): mette un RDA vuoto sullo stack di sistema e chiama la funzione
       esecutore() */
    if(funzione_clinit) {
      // esegue la funzione <clinit>()V
      stack_di_sistema.push_ar();
      stack_di_sistema.pc_set(programma.get_function_index("<clinit>()V"));
      esecutore();
    }
    stack_di_sistema.push_ar();
    stack_di_sistema.pc_set(
        programma.get_function_index("main([Ljava/lang/String;)V") );

    /* (5): passa il controllo alla funzione esecutore() */
    esecutore();
  } // end try

  /* Gestione eccezioni */
  catch(string e) {
    std::cerr <<"Errore: " <<e <<std::endl;
    in_file.close();
    return 1;
  }
  catch(...) {
    std::cerr <<"Errore: l'esecuzione e` stata interrotta da "
              <<"un errore sconosciuto" <<std::endl;
    in_file.close();
    return 1;
  }

  in_file.close();
  return 0;
} // end main(int argc, char **argv)


/*!
  \fn void leggi_file(const std::ifstream& in_file)
  \brief Legge il file passato e gestisce le istruzioni lette
  \param in_file file-stream di input, aperto sul file da leggere

  Legge il file passato come file-stream e mette le istruzioni in 
  <tt>programma</tt> e le variabili globali in <tt>variabili_globali</tt>.
  Ogni istruzione inserita in <tt>programma</tt> e` senza spazi all'inizio o 
  alla fine ed ha un solo spazio tra istruzione e argomenti. Allo stesso modo il
  nome delle variabili globali dentro alla struttura <tt>variabili_globali</tt>
  e` senza spazi.
*/
void leggi_file(std::ifstream& in_file) {
  string riga;
  while(leggi_istruzione(in_file,riga)) {
    cotrolla_etichetta(riga);
    if(riga == "") {
      // Riga vuota
    }
    else if(riga[0] == '.') {
      // Direttiva
      gestisci_direttiva(riga);
    }
    else{
      // Istruzione
      programma.add_instruction(riga);
    }
  } // end while(std::getline(infile,riga))
  return;
} // end leggi_file(std::ifstream& in_file)


/*!
  \fn bool leggi_istruzione(std::ifstream& file, string& str)
  \brief Legge le istruzioni da file e le mette in str
  \param file file-stream di input, aperto sul file da leggere
  \param str stringa in cui mettere le istruzioni lette
  \return <tt>false</tt>: errore di lettura o fine del file
  \return <tt>true</tt>: letta e inserita una istruzione in <tt>str</tt> 

  Legge le istruzioni dal file-stream <tt>file</tt> e le inserisce nella stringa
  <tt>str</tt>.\\
  Ogni istruzione dev'essere separata da un "a-capo". Da ogni istruzione vengono
  eliminati gli "spazi inutili", ovvero gli spazi iniziali e finali e gli spazi
  doppi (lasciando ovviamente inalterate le stringhe all'interno delle 
  istruzioni).\\ 
  Se si vuole cambiare il metodo di lettura delle istruzioni (ad esempio si 
  vuole permettere che stiano tutte su una riga, separate da spazi) e` 
  sufficente modificare solo questa funzione.
*/
bool leggi_istruzione(std::ifstream& file, string& str) {
  // azzera str
  str.clear();

  char ch; // carattere letto da file
  bool istr_stringa = false; // dentro o fuori a una stringa nell'istruzione

  // legge l'istruzione da file
  while(file.get(ch)) {
    if(!istr_stringa && ch == '\t') {
      // sostituisce le tabulazioni con spazi
      ch = ' ';
    }
    if(ch == ' ') {
      // spazio: elimina gli spazi inutili
      if(!str.empty() && !istr_stringa && str[str.size()-1]==' ')
        str.erase(str.size()-1);
    }
    else if(ch == '"') {
      // virgolette: valuta se nell'istruzione vi e` una stringa
      if(istr_stringa && str[str.size()-1]=='\\') {
        // dentro una stringa c'e` la sequenza \"
        // allora si rimane all'interno della stringa (istr_stringa=true)
      }
      else {
        // dentro o fuori una stringa dell'istruzione
        istr_stringa?istr_stringa=false:istr_stringa=true;
      }
    }
    else if(ch == '\n') {
      // a-capo: se e` fuori da una stringa e` la fine dell'istruzione
      if(!istr_stringa) {
        // fine istruzione
        elimina_spazi_iniziali_e_finali(str);
        return true;
      }
    } // end else if(ch=='\n')
    // inserisce il carattere letto nella stringa
    str.push_back(ch);
  } // end while(file.get(ch))

  // fine del file
  return false;
} // end leggi_istruzione(std::ifstream&, string&)


/*!
  \fn void cotrolla_etichetta(string& str)
  \brief Controlla se nell'istruzione c'e` un'ettichetta e la rende unica
  \param str istruzione da controllare

  Controlla se nell'istruzione e` presente un'ettichetta, in tal caso la rende
  unica all'interno del programma aggiungendoci un numero relativo alla funzione
  nella quale e` contenuta.\\
  L'istruzione passata dev'essere senza spazi iniziali e finali e con un solo
  spazio per separare gli argomenti.
*/
void cotrolla_etichetta(string& str) {
  if(!str.empty()) {
    // L'etichetta dev'essere sempre all'inizio dell'istruzione, siccome non ci
    // sono spazi iniziali e finali, se c'e` uno spazio prima dei due-punti
    // significa che non c'e` un'etichetta.
    string::size_type pos_label = str.find(':');
    string::size_type pos_space = str.find(' ');
    bool etichetta = false;
    char nf[3];
    if(pos_label != string::npos &&
        (pos_space == string::npos || pos_label < pos_space)) {
      // c'e` un'etichetta
      etichetta = true;
      sprintf(nf, "_%d", n_funzioni);
      str.insert(pos_label, nf);
    }
    string::size_type pos_istr = 0;
    if(etichetta) {
      pos_label = str.find(':');
      ++pos_label;
      while(str[pos_label] == ' ')
        ++pos_label;
      pos_istr = pos_label;
    }
    string::size_type pos_arg = str.find(' ',pos_istr);
    if(pos_arg != string::npos) {
      string istruzione;
      istruzione = str.substr(pos_istr,pos_arg-pos_istr);
      // istruzioni che hanno come argomento una etichetta
      if( istruzione == "goto" ||
          istruzione == "if_icmpeq" ||
          istruzione == "if_icmpge" ||
          istruzione == "if_icmpgt" ||
          istruzione == "if_icmple" ||
          istruzione == "if_icmplt" ||
          istruzione == "if_icmpne" ||
          istruzione == "ifeq" ||
          istruzione == "ifge" ||
          istruzione == "ifgt" ||
          istruzione == "ifle" ||
          istruzione == "iflt" ||
          istruzione == "ifne"
        ) {
        // sostituisce l'etichetta: siccome queste istruzioni hanno come
        // argomento solo l'etichetta, e non ci sono spazi finali, allora si
        // aggiunge il numero alla ifne dell'istruzione
        sprintf(nf, "_%d", n_funzioni);
        str.insert(str.size(), nf);
      }
    }
  } // end if(!str.empty())
  return;
}

/*!
  \fn void gestisci_direttiva(const string& direttiva)
  \brief In base alla direttiva passata esegue l'operazione appropriata
  \param direttiva direttiva da gestire

  Le direttive possono essere:
    - <tt>.method public static <em>methodname</em> <em>descriptor</em></tt>
    - <tt>.end method</tt>
    - <tt>.field public static <em>fieldname</em> <em>descriptor</em></tt>
    - <tt>.class public Main</tt>
    - <tt>.super java/lang/Object</tt>
    - <tt>.end class</tt>
  devono essere senza spazi iniziali e finali e con un solo sapzio tra le 
  parole, in caso di errore viene lanciata un'eccezione di tipo std::string
  con la descrizione dell'errore.
*/
void gestisci_direttiva(const string& direttiva) {
  if(direttiva.substr(0,22) == ".method public static ") {
    // Dichiarazione funzione
    string nome_funzione = direttiva.substr(22);
    cancella_carattere(nome_funzione,' ');
    if(nome_funzione == "<clinit>()V")
      funzione_clinit = true;
    programma.add_instruction(direttiva);
    ++n_funzioni;
  }
  else if(direttiva == ".end method") {
    // Fine funzione
    programma.add_instruction(direttiva);
  }
  else if(direttiva.substr(0,21) == ".field public static ") {
    // Variabile globale
    inserisci_variabile_globale(direttiva);
  }
  else if(direttiva == ".class public Main") {
    // Prima direttiva d'inizio del programma
  }
  else if(direttiva == ".super java/lang/Object") {
    // Seconda direttiva d'inizio del programma
  }
  else if(direttiva == ".end class") {
    // Fine del programma
  }
  else{
    throw string("direttiva sconosciuta: " + direttiva);
  }
  return;
} // end gestisci_direttiva(const string& direttiva)


/*!
  \fn void inserisci_variabile_globale(const string& direttiva)
  \brief Inserisce la variabile globale in <tt>variabili_globali</tt>
  \param direttiva direttiva contenente la variabile globale

  Estrapola la variabile globale dalla direttiva passata e la inserisce in 
  <tt>variabili_globali</tt>. La direttiva dev'essere nella forma
  <tt>.field public static <em>fieldname</em> <em>descriptor</em></tt>, con un
  solo spazio tra gli argomenti e senza spazi iniziali o finali. In caso di
  errore lancia un'eccezione di tipo std::string con la descrizione dell'errore.
*/
void inserisci_variabile_globale(const string& direttiva) {
  string fieldname, descriptor;
  // ricava il nome della variabile
  string::size_type pos_name = direttiva.find(' ', 21);
  if(pos_name != string::npos) {
    fieldname = direttiva.substr(21,pos_name-21);
    // ricava il nome del descrittore
    descriptor = direttiva.substr(pos_name+1);
    if(descriptor == "S")
      variabili_globali.add_variable_S(fieldname);
    else if(descriptor == "C")
      variabili_globali.add_variable_C(fieldname);
    else if(descriptor == "I")
      variabili_globali.add_variable_I(fieldname);
    else if(descriptor == "J")
      variabili_globali.add_variable_J(fieldname);
    else {
      throw string("tipo sconosciuto nella variabile globale: " + direttiva);
    }
  } // end if(pos_name != string::npos)
  else {
    throw string("manca il tipo nella variabile globale: " + direttiva);
  }
  return;
} // end inserisci_variabile_globale(const string& direttiva)


/*!
  \fn void pulisci_stringa(string& str)
  \brief Elimina gli spazi inutili alla stringa passata
  \param str stringa da "ripulire"

  Elimina gli spazi iniziali e finali (trim) dalla stringa <tt>str</tt> e
  rimuove tutti gli spazi consecutivi all'interno della stringa lasciando solo
  spazi singoli.
*/
void pulisci_stringa(string& str) {
  // eliminazione spazi iniziali e finali (trim)
  elimina_spazi_iniziali_e_finali(str);
  // eliminazione spazi doppi
  string::size_type pos = str.find("  ");
  while(pos != string::npos) {
    str.erase(pos, 1);
    pos = str.find("  ", pos);
  }
  return;
} // end pulisci_stringa(string& str)


/*!
  \fn void elimina_spazi_iniziali_e_finali(string& str)
  \brief Elimina gli spazi iniziali e finali nella stringa (trim)
  \param str stringa da "ripulire"

  Elimina gli spazi iniziali e finali dalla stringa <tt>str</tt> (funzione 
  trim).
*/
void elimina_spazi_iniziali_e_finali(string& str) {
  string::size_type pos = str.find_last_not_of(' ');
  if(pos != string::npos) {
    str.erase(pos + 1);
    pos = str.find_first_not_of(' ');
    if(pos != string::npos) str.erase(0, pos);
  }
  else {
    str.erase(str.begin(), str.end());
  }
  return;
}


/*!
  \fn void cancella_carattere(string& str, char c)
  \brief Elimina tutte le occorrenze del carattere passato dalla stringa
  \param str stringa da "ripulire"
  \param c carattere da eliminare dalla stringa

  Elimina dalla stringa <tt>str</tt> tutte le occorrenze del carattere passato
  <tt>c</tt>, di default ' ' (spazio bianco).
*/
void cancella_carattere(string& str, char c) {
  string::size_type pos = str.find(c);
  while(pos != string::npos) {
    str.erase(pos, 1);
    pos = str.find(c, pos);
  }
  return;
}
