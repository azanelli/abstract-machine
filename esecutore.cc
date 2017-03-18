/*!
  \file esecutore.cc
  \brief Implementazione della funzione esecutore()
  \author Andrea Zanelli
  \date 24-12-2008
*/

#include <iostream>
#include <string>
#include <stdint.h>
#include <cstdlib>

#include "ProgramArea.h"
#include "GlobalVariablesArea.h"
#include "SystemStack.h"

using std::string;


// Variabili globali

extern ProgramArea programma;
extern GlobalVariablesArea variabili_globali; 
extern SystemStack stack_di_sistema;

// Dichiarazione funzioni

void f_ldc_w(string& arg);
void f_ldc2_w(string& arg);
void f_sipush(string& arg);
void f_goto(string& arg);
void f_if_icmpeq(string& arg);
void f_if_icmpge(string& arg);
void f_if_icmpgt(string& arg);
void f_if_icmple(string& arg);
void f_if_icmplt(string& arg);
void f_if_icmpne(string& arg);
void f_ifeq(string& arg);
void f_ifge(string& arg);
void f_ifgt(string& arg);
void f_ifle(string& arg);
void f_iflt(string& arg);
void f_ifne(string& arg);
void f_getstatic(string& arg);
void f_putstatic(string& arg);
void f_invokestatic(string& arg);
void f_lcmp();
void f_ireturn();
void f_lreturn();
void f_return();
void f_iadd();
void f_idiv();
void f_imul();
void f_ineg();
void f_irem();
void f_ishl();
void f_ishr();
void f_isub();
void f_ladd();
void f_ldiv();
void f_lmul();
void f_lneg();
void f_lrem();
void f_lshl();
void f_lshr();
void f_lsub();
void f_iload(string& arg);
void f_istore(string& arg);
void f_lload(string& arg);
void f_lstore(string& arg);
void f_i2c();
void f_i2s();
void f_i2l();
void f_l2i();
void f_dup();
void f_dup2();
void f_pop();
void f_pop2();
void f_swap();
void f_new(string& arg);
void f_invokevirtual(string& arg);
void stampa_int();
void stampa_char();
void stampa_long();
void stampa_stringa();
void f_invokespecial(string& arg);


/*!
  \fn void esecutore()
  \brief Esegue le istruzioni puntate dal PC nello <tt>stack_di_sitema</tt>

  Finche` in <tt>stack_di_sistema</tt> e` presente un activation record (AR)
  esegue i seguenti passi:
    - (1) Prende il valore del PC dell'AR in cima a <tt>stack_di_sitema</tt>.
    - (2) Legge l'istruzione in <tt>programma</tt> "puntata" dal PC.
    - (3) Incrementa il PC.
    - (4) Esegue l'istruzione chiamando la funzione appropriata (da notare che
      l'istruzione <tt>return</tt> toglie un AR da <tt>stack_di_sistema</tt>
  Si assume che le istruzioni siano valide (sintatticamente corrette) oppure
  vuote, senza spazi all'inizio e alla fine, con un solo spazio tra l'istruzione
  e gli argomenti ed un solo spazio per separare piu` argomenti, senza
  etichette.

  In caso di errori viene lanciata un'eccezione di tipo std::string con la
  descrizione dell'errore.
*/
void esecutore() {
  string istruzione = "";
  string argomenti = "";
  string::size_type pos_istruzione;

  while(!stack_di_sistema.empty()) {
    // (1), (2): legge l'istruzione puntata dal PC dell'AR in cima allo stack
    istruzione = programma.get_instruction(stack_di_sistema.pc_get());
    pos_istruzione = istruzione.find_first_of(' ');
    if(pos_istruzione != string::npos) {
      // siccome non ci sono spazi iniziali e finali dopo lo spazio c'e`
      // sicuramente almeno un argomento
      argomenti = istruzione.substr(pos_istruzione+1);
      istruzione = istruzione.substr(0,pos_istruzione);
    }
    else {
      // se non ci sono spazi significa che e` un'istruzione senza argomenti
      argomenti = "";
    }

    // (3): incrementa il PC
    stack_di_sistema.pc_inc();

    // (4): esegue l'istruzione
    if(istruzione.empty()) {
      //istruzione vuota
    }
    else if(istruzione == "ldc_w")
      f_ldc_w(argomenti);
    else if(istruzione == "ldc2_w")
      f_ldc2_w(argomenti);
    else if(istruzione == "sipush")
      f_sipush(argomenti);
    else if(istruzione == "goto")
      f_goto(argomenti);
    else if(istruzione == "if_icmpeq")
      f_if_icmpeq(argomenti);
    else if(istruzione == "if_icmpge")
      f_if_icmpge(argomenti);
    else if(istruzione == "if_icmpgt")
      f_if_icmpgt(argomenti);
    else if(istruzione == "if_icmple")
      f_if_icmple(argomenti);
    else if(istruzione == "if_icmplt")
      f_if_icmplt(argomenti);
    else if(istruzione == "if_icmpne")
      f_if_icmpne(argomenti);
    else if(istruzione == "ifeq")
      f_ifeq(argomenti);
    else if(istruzione == "ifge")
      f_ifge(argomenti);
    else if(istruzione == "ifgt")
      f_ifgt(argomenti);
    else if(istruzione == "ifle")
      f_ifle(argomenti);
    else if(istruzione == "iflt")
      f_iflt(argomenti);
    else if(istruzione == "ifne")
      f_ifne(argomenti);
    else if(istruzione == "getstatic")
      f_getstatic(argomenti);
    else if(istruzione == "invokestatic")
      f_invokestatic(argomenti);
    else if(istruzione == "putstatic")
      f_putstatic(argomenti);
    else if(istruzione == "return")
      f_return();
    else if(istruzione == "ireturn")
      f_ireturn();
    else if(istruzione == "lreturn")
      f_lreturn();
    else if(istruzione == "lcmp")
      f_lcmp();
    else if(istruzione == "nop") {
      // nessuna operazione
    }
    else if(istruzione == "iadd")
      f_iadd();
    else if(istruzione == "idiv")
      f_idiv();
    else if(istruzione == "imul")
      f_imul();
    else if(istruzione == "ineg")
      f_ineg();
    else if(istruzione == "irem")
      f_irem();
    else if(istruzione == "ishl")
      f_ishl();
    else if(istruzione == "ishr")
      f_ishr();
    else if(istruzione == "isub")
      f_isub();
    else if(istruzione == "ladd")
      f_ladd();
    else if(istruzione == "ldiv")
      f_ldiv();
    else if(istruzione == "lmul")
      f_lmul();
    else if(istruzione == "lneg")
      f_lneg();
    else if(istruzione == "lrem")
      f_lrem();
    else if(istruzione == "lshl")
      f_lshl();
    else if(istruzione == "lshr")
      f_lshr();
    else if(istruzione == "lsub")
      f_lsub();
    else if(istruzione == "iload")
      f_iload(argomenti);
    else if(istruzione == "istore")
      f_istore(argomenti);
    else if(istruzione == "lload")
      f_lload(argomenti);
    else if(istruzione == "lstore")
      f_lstore(argomenti);
    else if(istruzione == "i2c")
      f_i2c();
    else if(istruzione == "i2s")
      f_i2s();
    else if(istruzione == "i2l")
      f_i2l();
    else if(istruzione == "l2i")
      f_l2i();
    else if(istruzione == "dup")
      f_dup();
    else if(istruzione == "dup2")
      f_dup2();
    else if(istruzione == "pop")
      f_pop();
    else if(istruzione == "pop2")
      f_pop2();
    else if(istruzione == "swap")
      f_swap();
    else if(istruzione == "new")
      f_new(argomenti);
    else if(istruzione == "invokevirtual")
      f_invokevirtual(argomenti);
    else if(istruzione == "invokespecial")
      f_invokespecial(argomenti);
    else {
      throw string("istruzione sconosciuta: " + istruzione);
    }

  } // end while(!stack_di_sitema.empty())

  return;
} // end of function void esecutore()


/**
 * \fn void f_ldc_w(string& arg)
 * \param arg x
 * \brief Esegue <tt>ldc_w x</tt>
 *
 * Estrapola <em>x</em> da <tt>arg</tt>, che puo` rappresentare una costante di 
 * tipo int o String (stringa tra virgolette), e la mette in cima allo stack 
 * degli operandi in <tt>stack_di_sistema</tt>.\\
 * Si assume che in <tt>arg</tt> ci sia sempre un valore corretto, ovvero un
 * numero intero a 32 bit con segno, oppure una stringa valida racchiusa tra
 * virgolette. Senza spazi all'inizio e alla fine di <tt>arg</tt>.
 */
void f_ldc_w(string& arg) {
  if(arg[0]=='"') {
    // costante di tipo String
    arg.erase(arg.size()-1);
    arg.erase(0,1);
    // sostituisce i "caratteri particolari" (es: \" diventa ") prendendo come
    // ipotesi che la stringa sia corretta, quindi non possa finire con il
    // carattere \ non preceduto da un altro \.
    // Se si vogliono trasformare sequenze di caratteri in carateri speciali
    // basta cambiare solo il codice qui sotto (es: sostituire \t con una tab.)
    for(string::size_type i = 0; i < arg.size(); ++i) {
      if(arg[i] == '\\') {
        arg.erase(i,1);
      }
    }
    stack_di_sistema.op_stack_push_ref("Ljava/lang/String;", new string(arg));
  }
  else {
    // costante di tipo int
    stack_di_sistema.op_stack_push_int(
        static_cast<int32_t>(atol(arg.c_str())) );
  }
  return;
}


/**
 * \fn void f_ldc2_w(string& arg)
 * \param arg x
 * \brief Esegue <tt>ldc2_w x</tt>
 *
 * Estrapola <em>x</em> da <tt>arg</tt>, che deve rappresentare una costante di 
 * tipo long, e la mette in cima allo stack degli operandi in
 * <tt>stack_di_sistema</tt>.\\
 * Si assume che in <tt>arg</tt> ci sia sempre un valore corretto, ovvero un
 * numero intero a 64 bit con segno (tipo long) senza spazi all'inizio e
 * alla fine.
 */
void f_ldc2_w(string& arg) {
  stack_di_sistema.op_stack_push_long(
      static_cast<int64_t>( atoll(arg.c_str())) );
  return;
}


/**
 * \fn void f_sipush(string& arg)
 * \param arg x
 * \brief Esegue <tt>sipush x</tt>
 *
 * Estrapola <em>x</em> da <tt>arg</tt>, che deve rappresentare una costante di 
 * tipo int, la converte in short (intero con segno a 16 bit) e la mette in
 * cima allo stack degli operandi in <tt>stack_di_sistema</tt>.\\
 * Si assume che in <tt>arg</tt> ci sia sempre un valore corretto, ovvero un
 * numero intero a 32 bit con segno, senza spazi all'inizio e alla fine.
 */
void f_sipush(string& arg) {
  stack_di_sistema.op_stack_push_int(
      static_cast<int16_t>(atol(arg.c_str())) );
  return;
}


/**
 * \fn
 * \brief Esegue <tt>goto label</tt>
 * \param arg label
 *
 * Ricava da <tt>programma</tt> l'indice dell'istruzione "puntata" dall'
 * ettichetta <em>label</em>, quindi imposta il PC a quell'istruzione.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_goto(string& arg) {
  stack_di_sistema.pc_set(programma.get_label_index(arg));
  return;
}


/**
 * \fn void f_if_icmpeq(string& arg)
 * \brief Esegue <tt>if_icmpeq label</tt>
 * \param arg label 
 *
 * Preleva i primi due int in cima allo stack degli operandi (a e b): se il
 * secondo e` uguale al primo (b == a) imposta il PC dell'AR in cima allo stack
 * con l'indice dell'istruzione "puntata" da <em>label<em> (indice ricavato da
 * <tt>programma</tt>), altrimenti non esegue nessuna modifica. Se in cima allo
 * stack NON ci sono due int viene lanciata un'eccezione di tipo std::string
 * con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_if_icmpeq(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  if(stack_di_sistema.op_stack_top_int() == value_a) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_if_icmpge(string& arg)
 * \brief Esegue <tt>if_icmpge label</tt>
 * \param arg label 
 *
 * Preleva i primi due int in cima allo stack degli operandi (a e b): se il
 * secondo e` maggiore-uguale al primo (b >= a) imposta il PC dell'AR in cima
 * allo stack con l'indice dell'istruzione "puntata" da <em>label<em> (indice
 * ricavato da <tt>programma</tt>), altrimenti non esegue nessuna modifica.
 * Se in cima allo stack NON ci sono due int viene lanciata un'eccezione di
 * tipo std::string con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_if_icmpge(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  if(stack_di_sistema.op_stack_top_int() >= value_a) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_if_icmpgt(string& arg)
 * \brief Esegue <tt>if_icmpgt label</tt>
 * \param arg label 
 *
 * Preleva i primi due int in cima allo stack degli operandi (a e b): se il
 * secondo e` maggiore del primo (b \> a) imposta il PC dell'AR in cima
 * allo stack con l'indice dell'istruzione "puntata" da <em>label<em> (indice
 * ricavato da <tt>programma</tt>), altrimenti non esegue nessuna modifica.
 * Se in cima allo stack NON ci sono due int viene lanciata un'eccezione di
 * tipo std::string con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_if_icmpgt(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  if(stack_di_sistema.op_stack_top_int() > value_a) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_if_icmple(string& arg)
 * \brief Esegue <tt>if_icmple label</tt>
 * \param arg label 
 *
 * Preleva i primi due int in cima allo stack degli operandi (a e b): se il
 * secondo e` minore-uguale al primo (b <= a) imposta il PC dell'AR in cima
 * allo stack con l'indice dell'istruzione "puntata" da <em>label<em> (indice
 * ricavato da <tt>programma</tt>), altrimenti non esegue nessuna modifica.
 * Se in cima allo stack NON ci sono due int viene lanciata un'eccezione di
 * tipo std::string con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_if_icmple(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  if(stack_di_sistema.op_stack_top_int() <= value_a) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_if_icmplt(string& arg)
 * \brief Esegue <tt>if_icmplt label</tt>
 * \param arg label 
 *
 * Preleva i primi due int in cima allo stack degli operandi (a e b): se il
 * secondo e` minore del primo (b \< a) imposta il PC dell'AR in cima
 * allo stack con l'indice dell'istruzione "puntata" da <em>label<em> (indice
 * ricavato da <tt>programma</tt>), altrimenti non esegue nessuna modifica.
 * Se in cima allo stack NON ci sono due int viene lanciata un'eccezione di
 * tipo std::string con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_if_icmplt(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  if(stack_di_sistema.op_stack_top_int() < value_a) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_if_icmpne(string& arg)
 * \brief Esegue <tt>if_icmpne label</tt>
 * \param arg label 
 *
 * Preleva i primi due int in cima allo stack degli operandi (a e b): se il
 * secondo e` diverso dal primo (b != a) imposta il PC dell'AR in cima
 * allo stack con l'indice dell'istruzione "puntata" da <em>label<em> (indice
 * ricavato da <tt>programma</tt>), altrimenti non esegue nessuna modifica.
 * Se in cima allo stack NON ci sono due int viene lanciata un'eccezione di
 * tipo std::string con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_if_icmpne(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  if(stack_di_sistema.op_stack_top_int() != value_a) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_ifeq(string& arg)
 * \brief Esegue <tt>ifeq label</tt>
 * \param arg label 
 *
 * Preleva il primo elemento int in cima allo stack degli operandi (a): se e`
 * uguale a zero (a == 0) imposta il PC dell'AR in cima allo stack con l'indice
 * dell'istruzione "puntata" da <em>label<em> (indice ricavato da
 * <tt>programma</tt>), altrimenti non esegue nessuna modifica.
 * Se in cima allo stack NON c'e` un int viene lanciata un'eccezione di tipo
 * std::string con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_ifeq(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  if(stack_di_sistema.op_stack_top_int() == 0) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_ifge(string& arg)
 * \brief Esegue <tt>ifge label</tt>
 * \param arg label 
 *
 * Preleva il primo elemento int in cima allo stack degli operandi (a): se e`
 * maggiore-uguale a zero (a >= 0) imposta il PC dell'AR in cima allo stack con
 * l'indice dell'istruzione "puntata" da <em>label<em> (indice ricavato da
 * <tt>programma</tt>), altrimenti non esegue nessuna modifica.
 * Se in cima allo stack NON c'e` un int viene lanciata un'eccezione di tipo
 * std::string con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_ifge(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  if(stack_di_sistema.op_stack_top_int() >= 0) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_ifgt(string& arg)
 * \brief Esegue <tt>ifgt label</tt>
 * \param arg label 
 *
 * Preleva il primo elemento int in cima allo stack degli operandi (a): se e`
 * maggiore di zero (a > 0) imposta il PC dell'AR in cima allo stack con
 * l'indice dell'istruzione "puntata" da <em>label<em> (indice ricavato da
 * <tt>programma</tt>), altrimenti non esegue nessuna modifica.
 * Se in cima allo stack NON c'e` un int viene lanciata un'eccezione di tipo
 * std::string con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_ifgt(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  if(stack_di_sistema.op_stack_top_int() > 0) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_ifle(string& arg)
 * \brief Esegue <tt>ifle label</tt>
 * \param arg label 
 *
 * Preleva il primo elemento int in cima allo stack degli operandi (a): se e`
 * minore-uguale a zero (a <= 0) imposta il PC dell'AR in cima allo stack con
 * l'indice dell'istruzione "puntata" da <em>label<em> (indice ricavato da
 * <tt>programma</tt>), altrimenti non esegue nessuna modifica.
 * Se in cima allo stack NON c'e` un int viene lanciata un'eccezione di tipo
 * std::string con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_ifle(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  if(stack_di_sistema.op_stack_top_int() <= 0) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_iflt(string& arg)
 * \brief Esegue <tt>iflt label</tt>
 * \param arg label 
 *
 * Preleva il primo elemento int in cima allo stack degli operandi (a): se e`
 * minore di zero (a < 0) imposta il PC dell'AR in cima allo stack con
 * l'indice dell'istruzione "puntata" da <em>label<em> (indice ricavato da
 * <tt>programma</tt>), altrimenti non esegue nessuna modifica.
 * Se in cima allo stack NON c'e` un int viene lanciata un'eccezione di tipo
 * std::string con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_iflt(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  if(stack_di_sistema.op_stack_top_int() < 0) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_ifne(string& arg)
 * \brief Esegue <tt>ifne label</tt>
 * \param arg label 
 *
 * Preleva il primo elemento int in cima allo stack degli operandi (a): se e`
 * diverso da zero (a != 0) imposta il PC dell'AR in cima allo stack con
 * l'indice dell'istruzione "puntata" da <em>label<em> (indice ricavato da
 * <tt>programma</tt>), altrimenti non esegue nessuna modifica.
 * Se in cima allo stack NON c'e` un int viene lanciata un'eccezione di tipo
 * std::string con la descrizione dell'errore.\\
 * Si assume che <em>label</em> esista in <tt>programma</tt> e che <tt>arg</tt>
 * sia senza spazi iniziali e finali.
 */
void f_ifne(string& arg) {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  if(stack_di_sistema.op_stack_top_int() != 0) {
    // modifica il valore del PC
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.pc_set(programma.get_label_index(arg));
  }
  else {
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_getstatic(string& arg)
 * \param arg Main/f d
 * \brief Esegue <tt>getstatic Main/<em>f</em> <em>d</em> </tt>
 *
 * Prende il valore della variabile globale di nome <em>f</em> e tipo <em>d</em>
 * (che puo` essere J, I, S oppure C) da <tt>variabili_globali</tt> e lo mette
 * sullo stack. Si assume che la variabile globale <em>f d</em> esista, e che
 * il tipo <em>d</em> sia J, I, S oppure C.\\
 * Se <tt>getstatic</tt> e` utilizzato nella stampa, allora <tt>arg</tt>
 * dev'essere "java/lang/System/out Ljava/io/PrintStream;", in questo caso
 * viene messo sullo stack degli operandi un riferimento "finto" all'oggetto
 * <em>out</em>, che dovra` essere presente al momento della stampa.\\
 * Se <tt>getstatic</tt> e` utilizzato nella lettura, allora <tt>arg</tt>
 * dev'essere "java/lang/System/in Ljava/io/InputStream;", in questo caso viene
 * messo sullo stack degli operandi un "finto" riferimento all'oggetto
 * <em>in</em> che dovra` essere presente sullo stack al momento della 
 * lettura.\\
 * In ogni caso si assume che in <tt>arg</tt> ci sia un solo spazio per separare
 * gli argomenti, e non ci siano spazi iniziali e finali.
 */
void f_getstatic(string& arg) {
  // Variabile globale
  if(arg.substr(0,5) == "Main/") {
    string::size_type pos = arg.find_first_of(' ');
    string nome = arg.substr(5,pos-5);
    char tipo = arg[arg.size()-1];
    if(tipo == 'I')
      stack_di_sistema.op_stack_push_int(
          variabili_globali.get_variable_I(nome) );
    else if(tipo == 'J')
      stack_di_sistema.op_stack_push_long(
          variabili_globali.get_variable_J(nome) );
    else if(tipo == 'S')
      stack_di_sistema.op_stack_push_int(
          static_cast<int32_t>(variabili_globali.get_variable_S(nome)) );
    else if(tipo == 'C')
      stack_di_sistema.op_stack_push_int(
          static_cast<int32_t>(variabili_globali.get_variable_C(nome)) );
  }

  // Stampa
  else if(arg == "java/lang/System/out Ljava/io/PrintStream;") {
    stack_di_sistema.op_stack_push_ref("Ljava/io/PrintStream;",0);
  }

  // Lettura
  else if(arg == "java/lang/System/in Ljava/io/InputStream;") {
    stack_di_sistema.op_stack_push_ref("Ljava/io/InputStream;",0);
  }

  return;
} // end of void f_getstatic(string& arg)


/**
 * \fn void f_putstatic(string& arg)
 * \brief Esegue <tt>putstatic Main/<em>f</em> <em>d</em></tt>
 * \param arg Main/f d
 *
 * Estrapola da <tt>arg</tt> il nome della variabile globale <em>f</em> e il
 * tipo <em>d</em>, e memorizza in tale variabile, dentro
 * <tt>variabili_globali</tt>, il valore sullo stack degli operandi. Si assume
 * che la variabile globale <em>f d</em> esista, e che il tipo <em>d</em> sia J,
 * I, S oppure C.\\
 * Se la variabile e` di tipo J, sullo stack dovra` esserci un elemento di tipo
 * long, se la variabile e` di tipo S, C o I sullo stack dovra` esserci un int.
 * se l'elemento sullo stack non e` compatibile con il tipo della variabile
 * viene lanciata un'eccezione di tipo std::string con la descrizione
 * dell'errore.\\
 * Si assume inoltre che in <tt>arg</tt> ci sia un solo spazio per separare
 * gli argomenti, e non ci siano spazi iniziali e finali.
 */
void f_putstatic(string& arg) {
  // esempio arg = "Main/field I"
  string::size_type pos = arg.find_first_of(' ');
  string nome = arg.substr(5,pos-5);
  char tipo = arg[arg.size()-1];
  // se l'elemento sullo stack non e` di tipo giusto, "stack_di_sistema" lancia
  // un'eccezione
  if(tipo == 'I') {
    variabili_globali.set_variable_I(
        nome,
        stack_di_sistema.op_stack_top_int() );
    stack_di_sistema.op_stack_pop();
  }
  else if(tipo == 'J') {
    variabili_globali.set_variable_J(
        nome,
        stack_di_sistema.op_stack_top_long() );
    stack_di_sistema.op_stack_pop2();
  }
  else if(tipo == 'S') {
    variabili_globali.set_variable_S(
        nome,
        static_cast<int16_t>(stack_di_sistema.op_stack_top_int()) );
    stack_di_sistema.op_stack_pop();
  }
  else if(tipo == 'C') {
    variabili_globali.set_variable_C(
        nome,
        static_cast<uint16_t>(stack_di_sistema.op_stack_top_int()) );
    stack_di_sistema.op_stack_pop();
  }
  return;
}


/**
 * \fn void f_invokestatic(string& arg)
 * \param arg Main/m d
 * \brief Esegue <tt>invokestatic Main/<em>m</em> <em>d</em> </tt>
 *
 * Estrapola da <tt>arg</tt> il nome e il descrittore della funzione,
 * rispettivamente <em>m</em> e <em>d</em>, quindi crea un nuovo AR in
 * <tt>stack_di_sistema</tt>, imposta il PC dell'AR alla prima istruzione della
 * funzione <em>m d</em> ed, eventualmente, esegue il passaggio parametri alla
 * funzione chiamata, prendendo i valori sullo stack degli operandi dell'AR
 * corrente e mettendoli nelle variabili locali del nuovo AR. Nel passaggio
 * parametri viene preso come ultimo argomento il valore in cima allo stack
 * degli operandi, come penultimo il secondo in cima allo stack, e cosi` via,
 * e vengono messi nelle variabili locali, in ordine, a partire dalla variabile
 * locale 0.\\
 * Si assume che <tt>arg</tt> sia sintatticamente corretto, percio` inizi con
 * "Main/", seguito immediatamente (senza spazi) dal nome della funzione, e da
 * una coppia di parentesi contenenti i tipi degli argomenti della funzione
 * (senza spazi tra un tipo e l'altro), infine il tipo di ritorno della
 * funzione. Sono ammessi spazi tra il nome e la prima parentesi, tra le
 * parentesi e gli argomenti, tra l'ultima parentesi e il tipo di ritorno,
 * senza spazi iniziali e finali.\\
 * Se utilizzata nella lettura di int o long (per convertire la stringa letta
 * da input in un numero) <tt>arg</tt> deve rispettivamente contenere:
 *   - java/lang/Integer/parseInt (Ljava/lang/String;)I
 *   - java/lang/Long/parseLong (Ljava/lang/String;)J
 * in entrambi i casi sullo stack ci deve essere un riferimento ad un oggetto
 * di tipo Ljava/lang/String; (argomento della funzione). La prima funzione
 * converte una stringa in un int e lo mette sullo stack degli operandi, la
 * seconda la converte in un long e lo mette sullo stack degli operandi, in
 * caso di errori di conversioni (la stringa non contiene un numero) viene
 * messo il valore 0 sullo stack.\\
 * Se nello stack degli operandi non ci sono i tipi corrispondenti ai tipi
 * dei parametri della funzione viene lanciata un'eccezione di tipo std::string
 * con la descrizione dell'errore.
 */
void f_invokestatic(string& arg) {
  // elimina tutti gli spazi dall'argomento della funzione
  string::size_type pos = arg.find(' ');
  while(pos != string::npos) {
    arg.erase(pos, 1);
    pos = arg.find(' ', pos);
  }

  // Chiamata a funzione locale
  if(arg.substr(0,5) == "Main/") {
    uint16_t index = 0;
    string::size_type pos = arg.rfind('(');
    while(arg[pos] != ')') {
      // calcola lo spazio per mettere i parametri nelle variabili locali
      if(arg[pos] == 'I' || arg[pos] == 'C' || arg[pos] == 'S') {
        ++index; // le variabili int occupano un solo spazio
      }
      else if(arg[pos] == 'J') {
        index = index + 2; // le variabili long occupano due spazi
      }
      ++pos;
    } // end while( arg[pos] != ')' )

    stack_di_sistema.push_ar();
    --pos;
    while(index != 0 && arg[pos] != '(') {
      // trasferisce i parametri nelle variabili locali
      if(arg[pos] == 'I' || arg[pos] == 'C' || arg[pos] == 'S') {
        --index;
        // Se sullo stack degli operandi non c'e` il tipo giusto
        // "stack_di_sistema" lancia un'eccezione
        stack_di_sistema.parameter_pass_int(index);
      }
      else if(arg[pos] == 'J') {
        index = index - 2;
        // Se sullo stack degli operandi non c'e` il tipo giusto
        // "stack_di_sistema" lancia un'eccezione
        stack_di_sistema.parameter_pass_long(index);
      }
      --pos;
    } // end while( arg[pos] != '(' )

    // imposta il pc: per l'ipotesi che arg inizia esattamente con "Main/",
    // il nome della funzione e` dalla posizione 5 fino alla fine della stringa
    stack_di_sistema.pc_set(programma.get_function_index(arg.substr(5)));
  } // end if(arg.substr(0,4) == "Main")

  // Conversione di una stringa in int (utilizzato nella lettura)
  else if(arg == "java/lang/Integer/parseInt(Ljava/lang/String;)I") {
    // nota: se non c'e` un riferimento in cima allo stack degli operandi,
    // "stack_di_sistema" lancia un'eccezione
    if(stack_di_sistema.op_stack_top_ref_type() != "Ljava/lang/String;") {
      throw string("si ci aspettava un oggetto di tipo java/lang/String " +
          string("sullo stack degli operandi") );
    }
    string* str = static_cast<string*>(stack_di_sistema.op_stack_top_ref());
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.op_stack_push_int( atol(str->c_str()) );
    delete str;
  }

  // Conversione di una stringa in long (utilizzato nella lettura)
  else if(arg == "java/lang/Long/parseLong(Ljava/lang/String;)J") {
    // nota: se non c'e` un riferimento in cima allo stack degli operandi,
    // "stack_di_sistema" lancia un'eccezione
    if(stack_di_sistema.op_stack_top_ref_type() != "Ljava/lang/String;") {
      throw string("si ci aspettava un oggetto di tipo java/lang/String " +
          string("sullo stack degli operandi") );
    }
    string* str = static_cast<string*>(stack_di_sistema.op_stack_top_ref());
    stack_di_sistema.op_stack_pop();
    stack_di_sistema.op_stack_push_long( atoll(str->c_str()) );
    delete str;
  }

  return;
} // end of void f_invokestatic(string& arg)


/**
 * \fn void f_lcmp()
 * \brief Esegue <tt>lcmp</tt>
 *
 * Preleva i primi due long in cima allo stack (ab e cd), li confronta, e
 * mette il risultato del confronto, di tipo int, in cima allo stack.
 * Se il secondo e` maggiore del primo (cd \> ab) viene messo il valore 1. Se
 * i due valori sono uguali (cd == ab) viene messo il valore 0. Se il secondo
 * e` minore del primo (cd \< ab) viene messo il valore -1.\\
 * Se sullo stack non sono presenti due long viene lanciata un'eccezione di
 * tipo std::string con la descrizione dell'errore.
 */
void f_lcmp() {
  // Se sullo stack non ci sono due elementi di tipo long, "stack_di_sistema"
  // lancia un'eccezione
  int64_t value_ab = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  if(stack_di_sistema.op_stack_top_long() == value_ab) {
    stack_di_sistema.op_stack_pop2();
    stack_di_sistema.op_stack_push_int(0);
  }
  else if(stack_di_sistema.op_stack_top_long() > value_ab) {
    stack_di_sistema.op_stack_pop2();
    stack_di_sistema.op_stack_push_int(1);
  }
  else {
    // if(stack_di_sistema.op_stack_top_long() < value_ab)
    stack_di_sistema.op_stack_pop2();
    stack_di_sistema.op_stack_push_int(-1);
  }
  return;
}


/**
 * \fn void f_ireturn()
 * \brief Esegue <tt>ireturn</tt>
 *
 * Prende dallo stack degli operandi il valore di ritorno di tipo int (se il
 * tipo non e` esatto viene lanciata un'eccezione di tipo std::string con la
 * descrizione dell'errore.), dopodiche` toglie un AR da
 * <tt>stack_di_sitema</tt>, e mette il valore di ritorno sullo stack degli 
 * operandi del vecchio AR.\\
 * Si assume che il tipo di ritorno della funzione sia compatibile con il tipo
 * di ritorno (I, S, o C), e che in <tt>stack_di_sistema</tt> siano presenti
 * almeno due AR.
 */
void f_ireturn() {
  // Se non c'e` un int in cima allo stack degli operandi, "stack_di_sistema"
  // lancia un'eccezione
  int32_t return_value = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.pop_ar();
  stack_di_sistema.op_stack_push_int(return_value);
  return;
}


/**
 * \fn void f_lreturn()
 * \brief Esegue <tt>lreturn</tt>
 *
 * Prende dallo stack degli operandi il valore di ritorno di tipo long (se il
 * tipo non e` esatto viene lanciata un'eccezione di tipo std::string con la
 * descrizione dell'errore.), dopodiche` toglie un AR da
 * <tt>stack_di_sitema</tt>, e mette il valore di ritorno sullo stack degli
 * operandi del vecchio AR.\\
 * Si assume che il tipo di ritorno della funzione sia compatibile con il tipo
 * di ritorno (J), e che in <tt>stack_di_sistema</tt> siano presenti almeno
 * due AR.
 */
void f_lreturn() {
  // Se non c'e` un long in cima allo stack degli operandi, "stack_di_sistema"
  // lancia un'eccezione
  int64_t return_value = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.pop_ar();
  stack_di_sistema.op_stack_push_long(return_value);
  return;
}


/**
 * \fn void f_return()
 * \brief Esegue <tt>return</tt>
 *
 * Toglie un AR da <tt>stack_di_sistema</tt>.\\
 * Si assume che il tipo di ritorno della funzione sia compatibile con il tipo
 * di ritorno (V), e che in <tt>stack_di_sistema</tt> sia presente almeno un AR.
 */
void f_return() {
  stack_di_sistema.pop_ar();
  return;
}


/**
 * \fn void f_iadd()
 * \brief Esegue <tt>iadd</tt>
 *
 * Preleva i primi due int in cima allo stack degli operandi (a e b), esegue la
 * somma tra il second e il primo (b+a), mette il risultato (int) sullo stack.\\
 * Se i primi due elementi sullo stack non sono int, viene lanciata un'eccezione
 * di tipo std::string con la descrizione dell'errore.
 */
void f_iadd() {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  int32_t value_b = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  stack_di_sistema.op_stack_push_int(value_b + value_a);
  return;
}


/**
 * \fn void f_idiv()
 * \brief Esegue <tt>idiv</tt>
 *
 * Preleva il primo int in cima allo stack degli operandi (a), preleva il
 * secondo (b), esegue la divisione tra il secondo e il primo (b/a) e mette
 * il risultato (int) sullo stack.\\
 * Se i primi due elementi sullo stack non sono int, viene lanciata un'eccezione
 * di tipo std::string con la descrizione dell'errore. Se avviene una divisione
 * per 0 viene lanciata un'eccezione.
 */
void f_idiv() {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  if(value_a == 0)
    throw string("divisione per 0");
  stack_di_sistema.op_stack_pop();
  int32_t value_b = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  stack_di_sistema.op_stack_push_int(value_b / value_a);
  return;
}


/**
 * \fn void f_imul()
 * \brief Esegue <tt>imul</tt>
 *
 * Preleva i primi due int in cima allo stack degli operandi (a e b), esegue il
 * prodotto tra il second e il primo (b*a), mette il risultato (int) sullo
 * stack.\\
 * Se i primi due elementi sullo stack non sono int, viene lanciata un'eccezione
 * di tipo std::string con la descrizione dell'errore.
 */
void f_imul() {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  int32_t value_b = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  stack_di_sistema.op_stack_push_int(value_b * value_a );
  return;
}


/**
 * \fn void f_ineg() 
 * \brief Esegue <tt>ineg</tt>
 *
 * Preleva il primo int in cima allo stack degli operandi (a), lo nega (-a), e
 * mette il risultato (int) sullo stack.\\
 * Se sullo stack degli operandi non e` presente un int viene lanciata
 * un'eccezione di tipo std::string con la descrizione dell'errore.
 */
void f_ineg() {
  // Se in cima allo stack degli operandi non c'e` un intero, "stack_di_sistema"
  // lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  stack_di_sistema.op_stack_push_int(-value_a);
  return;
}


/**
 * \fn void f_irem()
 * \brief Esegue <tt>irem</tt>
 *
 * Preleva il primo int in cima allo stack degli operandi (a), preleva il
 * secondo (b), esegue il "resto della divisione" tra il secondo e il primo
 * (b%a) e mette il risultato (int) sullo stack.\\
 * Se i primi due elementi sullo stack non sono int, viene lanciata un'eccezione
 * di tipo std::string con la descrizione dell'errore. Se avviene una divisione
 * per 0 viene lanciata un'eccezione.
 */
void f_irem() {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  if(value_a == 0)
    throw string("divisione per 0");
  stack_di_sistema.op_stack_pop();
  int32_t value_b = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  stack_di_sistema.op_stack_push_int(value_b % value_a);
  return;
}


/**
 * \fn void f_ishl()
 * \brief Esegue <tt>ishl</tt>
 *
 * Preleva i primi due int in cima allo stack (a e b), calcola lo shift a
 * sinistra (b << a) e mette il risultato (int) sullo stack. Se in cima allo
 * stack degli operandi non ci sono due interi lancia un'eccezione di tipo
 * std::string con la descrizione dell'errore.
 */
void f_ishl() {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  int32_t value_b = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  stack_di_sistema.op_stack_push_int(value_b << value_a);
  return;
}


/**
 * \fn void f_ishr()
 * \brief Esegue <tt>ishr</tt>
 *
 * Preleva i primi due int in cima allo stack (a e b), calcola lo shift a
 * destra (b >> a) e mette il risultato (int) sullo stack. Se in cima allo
 * stack degli operandi non ci sono due interi lancia un'eccezione di tipo
 * std::string con la descrizione dell'errore.
 */
void f_ishr() {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  int32_t value_b = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  stack_di_sistema.op_stack_push_int(value_b >> value_a);
  return;
}


/**
 * \fn void f_isub()
 * \brief Esegue <tt>isub</tt>
 *
 * Preleva il primo int in cima allo stack degli operandi (a), preleva il
 * secondo (b), esegue la sottrazione tra il secondo e il primo (b-a) e mette
 * il risultato (int) sullo stack.\\
 * Se i primi due elementi sullo stack non sono int, viene lanciata un'eccezione
 * di tipo std::string con la descrizione dell'errore.
 */
void f_isub() {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  int32_t value_b = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  stack_di_sistema.op_stack_push_int(value_b - value_a);
  return;
}


/**
 * \fn void f_ladd()
 * \brief Esegue <tt>ladd</tt>
 *
 * Preleva i primi due long in cima allo stack degli operandi (ab e cd),
 * esegue la somma tra il secondo e il primo (cd+ab) e mette il risultato (long)
 * sullo stack.\\
 * Se i primi due elementi sullo stack non sono long, viene lanciata
 * un'eccezione di tipo std::string con la descrizione dell'errore.
 */
void f_ladd() {
  // Se in cima allo stack degli operandi non ci sono due long,
  // "stack_di_sistema" lancia un'eccezione
  int64_t value_ab = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  int64_t value_cd = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  stack_di_sistema.op_stack_push_long(value_cd + value_ab);
  return;
}


/**
 * \fn void f_ldiv()
 * \brief Esegue <tt>ldiv</tt>
 *
 * Preleva il primo long in cima allo stack degli operandi (ab), preleva il
 * secondo (cd), esegue la divisione tra il secondo e il primo (cd/ab) e mette
 * il risultato (long) sullo stack.\\
 * Se i primi due elementi sullo stack non sono long, viene lanciata
 * un'eccezione di tipo std::string con la descrizione dell'errore. Se avviene
 * una divisione per 0 viene lanciata un'eccezione.
 */
void f_ldiv() {
  // Se in cima allo stack degli operandi non ci sono due long,
  // "stack_di_sistema" lancia un'eccezione
  int64_t value_ab = stack_di_sistema.op_stack_top_long();
  if(value_ab == 0)
    throw string("divisione per 0");
  stack_di_sistema.op_stack_pop2();
  int64_t value_cd = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  stack_di_sistema.op_stack_push_long(value_cd / value_ab);
  return;
}


/**
 * \fn void f_lmul()
 * \brief Esegue <tt>lmul</tt>
 *
 * Preleva i primi due long in cima allo stack degli operandi (ab e cd), esegue
 * il prodotto tra il secondo e il primo (cd*ab), mette il risultato (long)
 * sullo stack.\\
 * Se i primi due elementi sullo stack non sono long, viene lanciata
 * un'eccezione di tipo std::string con la descrizione dell'errore.
 */
void f_lmul() {
  // Se in cima allo stack degli operandi non ci sono due long,
  // "stack_di_sistema" lancia un'eccezione
  int64_t value_ab = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  int64_t value_cd = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  stack_di_sistema.op_stack_push_long(value_cd * value_ab);
  return;
}


/**
 * \fn void f_lneg()
 * \brief Esegue <tt>lneg</tt>
 *
 * Preleva il primo long in cima allo stack degli operandi (ab), lo nega (-ab),
 * e mette il risultato (long) sullo stack.\\
 * Se sullo stack degli operandi non e` presente un long viene lanciata
 * un'eccezione di tipo std::string con la descrizione dell'errore.
 */
void f_lneg() {
  // Se in cima allo stack degli operandi non c'e` un long, "stack_di_sistema"
  // lancia un'eccezione
  int64_t value_ab = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  stack_di_sistema.op_stack_push_long(-value_ab);
  return;
}


/**
 * \fn void f_lrem()
 * \brief Esegue <tt>lrem</tt>
 *
 * Preleva il primo long in cima allo stack degli operandi (ab), preleva il
 * secondo (cd), esegue il "resto della divisione" tra il secondo e il primo
 * (cd%ab) e mette il risultato (long) sullo stack.\\
 * Se i primi due elementi sullo stack non sono long, viene lanciataun'eccezione
 * di tipo std::string con la descrizione dell'errore. Se avviene una divisione
 * per 0 viene lanciata un'eccezione.
 */
void f_lrem() {
  // Se in cima allo stack degli operandi non ci sono due long,
  // "stack_di_sistema" lancia un'eccezione
  int64_t value_ab = stack_di_sistema.op_stack_top_long();
  if(value_ab == 0)
    throw string("divisione per 0");
  stack_di_sistema.op_stack_pop2();
  int64_t value_cd = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  stack_di_sistema.op_stack_push_long(value_cd % value_ab);
  return;
}


/**
 * \fn void f_lshl()
 * \brief Esegue <tt>lshl</tt>
 *
 * Preleva un elemento di tipo int in cima allo stack (a), quindi preleva un
 * long (bc), calcola lo shift a sinistra (bc << a) e mette il risultato (long)
 * sullo stack. Se in cima allo stack degli operandi non ci sono prima un int,
 * poi un long, lancia un'eccezione di tipo std::string con la descrizione
 * dell'errore.
 */
void f_lshl() {
  // Se in cima allo stack degli operandi non ci sono un int e un long,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  int64_t value_bc = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  stack_di_sistema.op_stack_push_long(value_bc << value_a);
  return;
}


/**
 * \fn void f_lshr()
 * \brief Esegue <tt>lshr</tt>
 *
 * Preleva un elemento di tipo int in cima allo stack (a), quindi preleva un
 * long (bc), calcola lo shift a destra (bc >> a) e mette il risultato (long)
 * sullo stack. Se in cima allo stack degli operandi non ci sono prima un int,
 * poi un long, lancia un'eccezione di tipo std::string con la descrizione
 * dell'errore.
 */
void f_lshr() {
  // Se in cima allo stack degli operandi non ci sono un int e un long,
  // "stack_di_sistema" lancia un'eccezione
  int32_t value_a = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  int64_t value_bc = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  stack_di_sistema.op_stack_push_long(value_bc >> value_a);
  return;
}


/**
 * \fn void f_lsub()
 * \brief Esegue <tt>lsub</tt>
 *
 * Preleva il primo long in cima allo stack degli operandi (ab), preleva il
 * secondo (cd), esegue la sottrazione tra il secondo e il primo (cd-ab) e mette
 * il risultato (long) sullo stack.\\
 * Se i primi due elementi sullo stack non sono long, viene lanciata
 * un'eccezione di tipo std::string con la descrizione dell'errore.
 */
void f_lsub() {
  // Se in cima allo stack degli operandi non ci sono due interi,
  // "stack_di_sistema" lancia un'eccezione
  int64_t value_ab = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  int64_t value_cd = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  stack_di_sistema.op_stack_push_long(value_cd - value_ab);
  return;
}


/**
 * \fn void f_iload(string& arg)
 * \brief Esegue <tt>iload n</tt>
 * \param arg n
 *
 * Mette sullo stack degli operandi il valore memorizzato nella variabile
 * locale di tipo int con indice <em>n</em>.\\
 * Si assume che in <tt>arg</tt> sia presente la rappresentazione di un numero
 * intero, senza spazi all'inizio e alla fine, e che la variabile con indice
 * <em>n</em> sia stata precedentemente inizializzata con il tipo esatto (int).
 */
void f_iload(string& arg) {
  stack_di_sistema.op_stack_push_int(
      stack_di_sistema.local_variable_get_int(
          static_cast<uint16_t>(atol(arg.c_str())) ) );
  return;
}


/**
 * \fn void f_istore(string& arg)
 * \brief Esegue <tt>istore n</tt>
 * \param arg n
 *
 * Preleva l'elemento di tipo int in cima allo stack degli operandi (se non e`
 * presente un elemento di tipo int lancia un'eccezione di tipo std::string con
 * la descrizione dell'errore.) e lo memorizza nella variabile locale di indice
 * <em>n</em>.\\
 * Si assume che in <tt>arg</tt> sia presente la rappresentazione di un numero
 * intero, senza spazi all'inizio e alla fine.
 */
void f_istore(string& arg) {
  // Se non c'e` un elemento di tipo int in cima allo stack degli operandi,
  // "stack_di_sistema" lancia un'eccezione
  stack_di_sistema.local_variable_set_int(
      static_cast<uint16_t>(atol(arg.c_str())),
      stack_di_sistema.op_stack_top_int() );
  stack_di_sistema.op_stack_pop();
  return;
}


/**
 * \fn void f_lload(string& arg)
 * \brief Esegue <tt>lload n</tt>
 * \param arg n
 *
 * Mette sullo stack degli operandi il valore memorizzato nella variabile
 * locale di tipo long con indice <em>n</em>.\\
 * Si assume che in <tt>arg</tt> sia presente la rappresentazione di un numero
 * intero, senza spazi all'inizio e alla fine, e che la variabile con indice
 * <em>n</em> sia stata precedentemente inizializzata con il tipo esatto (long).
 */
void f_lload(string& arg) {
 stack_di_sistema.op_stack_push_long(
      stack_di_sistema.local_variable_get_long(
          static_cast<uint16_t>(atol(arg.c_str())) ) );
  return;
}


/**
 * \fn void f_lstore(string& arg)
 * \brief Esegue <tt>lstore n</tt>
 * \param arg n
 *
 * Preleva l'elemento di tipo long in cima allo stack degli operandi (se non e`
 * presente un elemento di tipo long lancia un'eccezione di tipo std::string con
 * la descrizione dell'errore.) e lo memorizza nella variabile locale di indice
 * <em>n</em>.\\
 * Si assume che in <tt>arg</tt> sia presente la rappresentazione di un numero
 * intero, senza spazi all'inizio e alla fine.
 */
void f_lstore(string& arg) {
  // Se non c'e` un elemento di tipo long in cima allo stack degli operandi,
  // "stack_di_sistema" lancia un'eccezione
  stack_di_sistema.local_variable_set_long(
      static_cast<uint16_t>(atol(arg.c_str())),
      stack_di_sistema.op_stack_top_long() );
  stack_di_sistema.op_stack_pop2();
  return;
}


/**
 * \fn void f_i2c()
 * \brief Esegue <tt>i2c</tt>
 *
 * Preleva l'elemento di tipo int in cima allo stack degli operandi, lo converte
 * in char (intero a 16 bit senza segno) e mette il risultato in cima allo
 * stack degli operandi. Se non e` presente un int sullo stack viene lanciata
 * un'eccezione di tipo std::string con la descrizione dell'errore.
 */
void f_i2c() {
  // Se in cima allo stack non c'e` un int, "stack_di_sistema" lancia
  // un'eccezione
  int32_t value = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  stack_di_sistema.op_stack_push_int( static_cast<uint16_t>(value) );
  return;
}


/**
 * \fn void f_i2s()
 * \brief Esegue <tt>i2s</tt>
 *
 * Preleva l'elemento di tipo int in cima allo stack degli operandi, lo converte
 * in short (intero a 16 bit con segno) e mette il risultato in cima allo
 * stack degli operandi. Se non e` presente un int sullo stack viene lanciata
 * un'eccezione di tipo std::string con la descrizione dell'errore.
 */
void f_i2s() {
  // Se in cima allo stack non c'e` un int, "stack_di_sistema" lancia
  // un'eccezione
  int32_t value = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  stack_di_sistema.op_stack_push_int( static_cast<int16_t>(value) );
  return;
}


/**
 * \fn void f_i2l()
 * \brief Esegue <tt>i2l</tt>
 *
 * Preleva l'elemento di tipo int in cima allo stack degli operandi, lo converte
 * in long (intero a 64 bit con segno) e mette il risultato (di tipo long) in
 * cima allo stack degli operandi (che occupera` due posizione). Se non e`
 * presente un int sullo stack viene lanciata un'eccezione di tipo std::string
 * con la descrizione dell'errore.
 */
void f_i2l() {
  // Se in cima allo stack non c'e` un int, "stack_di_sistema" lancia
  // un'eccezione
  int32_t value = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();
  stack_di_sistema.op_stack_push_long(value);
  return;
}


/**
 * \fn void f_l2i()
 * \brief Esegue <tt>l2i</tt>
 *
 * Preleva l'elemento di tipo long in cima allo stack degli operandi, lo
 * converte in int (intero a 32 bit con segno) e mette il risultato (di tipo
 * int) in cima allo stack degli operandi (che occupera` una posizione). Se non
 * e` presente un int sullo stack viene lanciata un'eccezione di tipo
 * std::string con la descrizione dell'errore.
 */
void f_l2i() {
  // Se in cima allo stack non c'e` un long, "stack_di_sistema" lancia
  // un'eccezione
  int64_t value = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();
  stack_di_sistema.op_stack_push_int( static_cast<int32_t>(value) );
  return;
}


/**
 * \fn void f_dup()
 * \brief Esegue <tt>dup</tt>
 *
 * Duplica e mette sullo stack degli operandi l'elemento in cima allo stack che
 * occupa una posizione (int o riferimento). Se in cima allo stack e` presente
 * un elemento che occupa due posizioni, oppure se lo stack e` vuoto, viene
 * lanciata un'eccezione di tipo std::string con la descrizione dell'errore.
 */
void f_dup() {
  stack_di_sistema.op_stack_dup();
  return;
}


/**
 * \fn void f_dup2()
 * \brief Esegue <tt>dup2</tt>
 *
 * Duplica e mette sullo stack degli operandi l'elemento in cima allo stack che
 * occupa due posizioni (long). Se in cima allo stack e` presente un elemento
 * che occupa uan posizione, oppure se lo stack e` vuoto, viene lanciata
 * un'eccezione di tipo std::string con la descrizione dell'errore.
 */
void f_dup2() {
  stack_di_sistema.op_stack_dup2();
  return;
}


/**
 * \fn void f_pop()
 * \brief Esegue <tt>pop</tt>
 *
 * Toglie il primo elemento sullo stack degli operandi che occupa una posizione
 * (int o riferimento). Se in cima e` presente un elemento che occupa due
 * posizioni  viene lanciata un'eccezione di tipo std::string con la descrizione
 * dell'errore.\\
 * NOTA: se viene tolto un elemento di tipo "ref" (un riferimento) NON viene
 * distrutto l'oggetto puntato dal riferimento.
 */
void f_pop() {
  stack_di_sistema.op_stack_pop();
  return;
}


/**
 * \fn void f_pop2()
 * \brief Esegue <tt>pop2</tt>
 *
 * Toglie il primo elemento sullo stack degli operandi che occupa due posizioni
 * (di tipo long). Se in cima e` presente un elemento che occupa una posizione
 * viene lanciata un'eccezione di tipo std::string con la descrizione
 * dell'errore.
 */
void f_pop2() {
  stack_di_sistema.op_stack_pop2();
  return;
}


/**
 * \fn void f_swap()
 * \brief Esegue <tt>swap</tt>
 *
 * Scambia il primo elemento sullo stack degli operandi con il secondo,
 * entrambi gli elementi devono occupare una posizione (tipo int o riferimento).
 * Se i primi due elementi in cima allo stack degli operandi non occupano,
 * una posizione, o se lo stack contiene meno di due elementi, viene
 * lanciata un'eccezione di tipo std::string con la descrizione dell'errore.
 */
void f_swap() {
  stack_di_sistema.op_stack_swap();
  return;
}


/**
 * \fn void f_invokevirtual(string& arg)
 * \param arg
 * \brief Istruzione fittizia utilizzata solo per stampa e lettura
 *
 * Per la stampa <tt>arg</tt> dev'essere:
 * "java/io/PrintStream/print (<em>T</em>)V", dove <em>T</em> puo` essere C, I,
 * J oppure Ljava/lang/String;, se si stampa rispettivamente un carattere, un
 * intero, un long, oppure una stringa. Se nello stack degli operandi non c'e`
 * il tipo corrispondente a quello che si vuol cambiare viene lanciata
 * un'eccezione di tipo std::string con la descrizione dell'errore. Allo stesso
 * modo, per effettuare la stampa, dev'essere presente sullo stack un oggetto
 * di tipo Ljava/io/PrintStream;, se non c'e` viene lanciata un'eccezione di
 * tipo std::string con la descrizione dell'errore.\\
 * Nella lettura di un carattere <tt>arg</tt> dev'essere:
 * "java/io/BufferedReader/read ()I".\\
 * Nella lettura di una stringa (utilizzata anche per int e long) <tt>arg</tt>
 * dev'essere: "java/io/BufferedReader/readLine ()Ljava/lang/String;".\\
 * Nella lettura (sia di char, int o long) ci dev'essere un "finto" riferimento
 * ad un oggetto di tipo LBufferedReader; sullo stack degli operandi, altrimenti
 * viene lanciata un'eccezione di tipo std::string con la descrizione
 * dell'errore.\\
 * In ogni caso sono ammessi spazi tra il nome della funzione e le parentesi,
 * tra le parentesi e gli argomenti della funzione e del tipo di ritorno. Si
 * assume che non ci siano spazi iniziale e finali.
 */
void f_invokevirtual(string& arg) {
  // elimina tutti gli spazi dall'argomento della funzione
  string::size_type pos = arg.find(' ');
  while(pos != string::npos) {
    arg.erase(pos, 1);
    pos = arg.find(' ', pos);
  }

  // Stampa
  if(arg.substr(0,25) == "java/io/PrintStream/print") {
    if(arg[26] == 'I')
      stampa_int();
    else if(arg[26] == 'L')
      stampa_stringa();
    else if(arg[26] == 'C')
      stampa_char();
    else if(arg[26] == 'J')
      stampa_long();
  }

  // Lettura char
  else if(arg == "java/io/BufferedReader/read()I") {
    // nota: se non c'e` un riferimento in cima allo stack degli operandi,
    // "stack_di_sistema" lancia un'eccezione
    if(stack_di_sistema.op_stack_top_ref_type() != "Ljava/io/BufferedReader;") {
      throw string("si ci aspettava un oggetto di tipo java/io/BufferedReader "
          + string("sullo stack degli operandi") );
    }
    stack_di_sistema.op_stack_pop();
    // legge un carattere e lo mette sullo stack
    char c;
    c = getchar();
    if(c != '\n') {
      char t = getchar();
      while(t != '\n')
        t = getchar();
    }
    stack_di_sistema.op_stack_push_int(static_cast<int32_t>(c));
  }

  // Lettura di una stringa (utilizzata anche per int e long)
  else if(arg == "java/io/BufferedReader/readLine()Ljava/lang/String;") {
    // nota: se non c'e` un riferimento in cima allo stack degli operandi,
    // "stack_di_sistema" lancia un'eccezione
    if(stack_di_sistema.op_stack_top_ref_type() != "Ljava/io/BufferedReader;") {
      throw string("si ci aspettava un oggetto di tipo java/io/BufferedReader "
          + string("sullo stack degli operandi") );
    }
    stack_di_sistema.op_stack_pop();
    // legge una stringa e la mette sullo stack
    string* str = new string("");
    std::getline(std::cin, *str);
    stack_di_sistema.op_stack_push_ref("Ljava/lang/String;",str);
  }

  return;
}


/**
 * Stampa l'elemento di tipo int sullo stack degli operandi (utilizzato
 * dalla funzione f_invokevirtual)
 */
void stampa_int() {
  // Se sullo stack degli operandi non c'e` un int, "stack_di_sistema" 
  // lancia un'eccezione
  int32_t print_value = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();

  // Se non c'e` un riferimento in cima allo stack degli operandi,
  // "stack_di_sistema" lancia un'eccezione
  if(stack_di_sistema.op_stack_top_ref_type() != "Ljava/io/PrintStream;") {
    throw string("si ci aspettava un oggetto di tipo java/io/PrintStream "
          + string("sullo stack degli operandi") );
  }
  stack_di_sistema.op_stack_pop();

  // stampa il valore
  std::cout <<print_value;
  return;
}


/**
 * Stampa l'elemento di tipo int sullo stack degli operandi convertendolo
 * in un carattere (utilizzato dalla funzione f_invokevirtual)
 */
void stampa_char() {
  // Se sullo stack degli operandi non c'e` un int, "stack_di_sistema" 
  // lancia un'eccezione
  int32_t print_value = stack_di_sistema.op_stack_top_int();
  stack_di_sistema.op_stack_pop();

  // Se non c'e` un riferimento in cima allo stack degli operandi,
  // "stack_di_sistema" lancia un'eccezione
  if(stack_di_sistema.op_stack_top_ref_type() != "Ljava/io/PrintStream;") {
    throw string("si ci aspettava un oggetto di tipo java/io/PrintStream "
          + string("sullo stack degli operandi") );
  }
  stack_di_sistema.op_stack_pop();

  // stampa il valore
  std::cout <<static_cast<char>(print_value);
  return;
}


/**
 * Stampa l'elemento di tipo long sullo stack degli operandi (utilizzato
 * dalla funzione f_invokevirtual)
 */
void stampa_long() {
  // Se sullo stack degli operandi non c'e` un long, "stack_di_sistema" 
  // lancia un'eccezione
  int64_t print_value = stack_di_sistema.op_stack_top_long();
  stack_di_sistema.op_stack_pop2();

  // Se non c'e` un riferimento in cima allo stack degli operandi,
  // "stack_di_sistema" lancia un'eccezione
  if(stack_di_sistema.op_stack_top_ref_type() != "Ljava/io/PrintStream;") {
    throw string("si ci aspettava un oggetto di tipo java/io/PrintStream "
          + string("sullo stack degli operandi") );
  }
  stack_di_sistema.op_stack_pop();

  // stampa il valore
  std::cout <<print_value;
  return;
}


/**
 * Stampa l'elemento di tipo string sullo stack degli operandi (utilizzato
 * dalla funzione f_invokevirtual)
 */
void stampa_stringa() {
  // Se non c'e` un riferimento in cima allo stack degli operandi,
  // "stack_di_sistema" lancia un'eccezione
  if(stack_di_sistema.op_stack_top_ref_type() != "Ljava/lang/String;") {
    throw string("si ci aspettava un oggetto di tipo java/lang/String "
          + string("sullo stack degli operandi") );
  }
  string* print_str;
  print_str = static_cast<string*>( stack_di_sistema.op_stack_top_ref() );
  stack_di_sistema.op_stack_pop();

  // Se non c'e` un riferimento in cima allo stack degli operandi,
  // "stack_di_sistema" lancia un'eccezione
  if(stack_di_sistema.op_stack_top_ref_type() != "Ljava/io/PrintStream;") {
    // errore sullo stack degli operandi
    throw string("si ci aspettava un oggetto di tipo java/io/PrintStream "
          + string("sullo stack degli operandi") );
  }
  stack_di_sistema.op_stack_pop();

  // stampa la stringa
  std::cout <<*print_str;
  delete print_str;
  return;
}


/**
 * \fn void f_new(string& arg)
 * \brief Istruzione fittizia utilizzata solo per la lettura
 * \param arg
 *
 * Crea e mette sullo stack degli operandi un "finto" riferimento ad un'oggetto
 * di tipo passato come parametro in <tt>arg</tt>.\\
 * Per l'operazione di lettura servono:
 *   - java/io/BufferedReader
 *   - java/io/InputStreamReader
 */
void f_new(string& arg) {
  arg.insert(arg.begin(), 'L');
  arg.push_back(';');
  stack_di_sistema.op_stack_push_ref(arg, 0);
  return;
}


/**
 * \fn void f_invokespecial(string& arg)
 * \brief Istruzione fittizia utilizzata solo per la lettura
 * \param arg
 *
 * Chiama un metodo di una classe con riferimento sullo stack degli operandi.
 * Possibili valori di <tt>arg</tt> (utilizzati nella lettura):
 *   - java/io/InputStreamReader/\<init\> (Ljava/io/InputStream;)V
 *   - java/io/BufferedReader/\<init\> (Ljava/io/Reader;)V
 * Nel primo caso finge di chiamare il costruttore di un oggetto di tipo
 * InputStreamReader, che prende un InputStream come argomento del costruttore,
 * percui sullo stack degli operandi dovra` esserci un riferimento (finto) con
 * tipo InputStream, nel caso della lettura l'oggetto <em>in</em>, e un
 * riferimento (finto) con tipo InputStreamReader (l'oggetto da inizializzare)
 * creato con una operazione <em>new</em>.\\
 * In modo simile, nel secondo caso, finge di chiamare il costruttore di un
 * oggetto di tipo BufferedReader, che prende con argomento un Reader, percui
 * sullo stack degli operandi dovra` esserci un riferimento (finto) ad un
 * oggetto di tipo Reader, nel caso della lettura l'oggetto InputStreamReader
 * appena "costruito" (sempre "virtualmente"), ed un riferimento (finto) ad un
 * BufferedReader. Di quest'ultimo oggetto verranno poi chiamati i metodi
 * per eseguire la lettura.\\
 * Si assume che questa funzione venga utilizzata solamente per i due casi
 * descritti, e che <tt>arg</tt> non contenga spazi iniziali e finali ed un solo
 * spazio per separare gli argomenti.\\
 * Se nello stack degli operandi non ci sono gli elementi sopracitati viene
 * lanciata un'eccezione di tipo std::string con la descrizione dell'errore.\\
 */
void f_invokespecial(string& arg) {
  // elimina tutti gli spazi dall'argomento della funzione
  string::size_type pos = arg.find(' ');
  while(pos != string::npos) {
    arg.erase(pos, 1);
    pos = arg.find(' ', pos);
  }

  if(arg == "java/io/InputStreamReader/<init>(Ljava/io/InputStream;)V") {
    // nota: se non c'e` un riferimento in cima allo stack degli operandi,
    // "stack_di_sistema" lancia un'eccezione
    if(stack_di_sistema.op_stack_top_ref_type() != "Ljava/io/InputStream;") {
      throw string("si ci aspettava un oggetto di tipo java/io/InputStream "
          + string("sullo stack degli operandi") );
    }
    stack_di_sistema.op_stack_pop();
    if(stack_di_sistema.op_stack_top_ref_type() != 
        "Ljava/io/InputStreamReader;") {
      throw string("si ci aspettava un oggetto di tipo " +
          string("java/io/InputStreamReader sullo stack degli operandi") );
    }
    stack_di_sistema.op_stack_pop();
    // oggetto InputStreamReader costruito
  }
  else if(arg == "java/io/BufferedReader/<init>(Ljava/io/Reader;)V") {
    // nota: se non c'e` un riferimento in cima allo stack degli operandi,
    // "stack_di_sistema" lancia un'eccezione
    if(stack_di_sistema.op_stack_top_ref_type() !=
        "Ljava/io/InputStreamReader;") {
      throw string("si ci aspettava un oggetto di tipo " +
          string("java/io/InputStreamReader sullo stack degli operandi") );
    }
    stack_di_sistema.op_stack_pop();
    if(stack_di_sistema.op_stack_top_ref_type() != "Ljava/io/BufferedReader;") {
      throw string("si ci aspettava un oggetto di tipo java/io/BufferedReader "
          + string("sullo stack degli operandi") );
    }
    stack_di_sistema.op_stack_pop();
    // oggetto BufferedReader costruito
  }
  return;
} // end of void f_invokespecial(string& arg)
