#******************************************************************************#
#* MACCHINA ASTRATTA                                                          *#
#******************************************************************************#

# Directory con eseguibili (targets):
TARGETDIR = bin

# Eseguibili:
MACCHINA_ASTRATTA = ${TARGETDIR}/macchina-astratta

# Targets set
TARGETS = $(MACCHINA_ASTRATTA)

# File di configurazione per doxygen:
DOXYFILE = doxyfile
# Directory con documentazione:
DIRDOC = doc

# Compilatore C++:
CC = g++
# Opzioni compilatore:
CPPFLAGS = -W -Wall

# Comando mkdir con opzioni:
MKDIR = mkdir -p

# Comando rm con opzioni:
RM = rm -rf


#* TARGETS ********************************************************************#

all: $(TARGETS)

$(MACCHINA_ASTRATTA): macchina-astratta.o esecutore.o ProgramArea.o \
                      GlobalVariablesArea.o ActivationRecord.o
	$(MKDIR) $(TARGETDIR)/
	$(CC) $(CPPFLAGS) macchina-astratta.o esecutore.o ProgramArea.o \
  GlobalVariablesArea.o ActivationRecord.o -o $(MACCHINA_ASTRATTA)

# MACCHINA_ASTRATTA

macchina-astratta.o: macchina-astratta.cc ProgramArea.h GlobalVariablesArea.h \
                     SystemStack.h ActivationRecord.h
	$(CC) $(CPPFLAGS) -c macchina-astratta.cc

# ESECUTORE

esecutore.o: esecutore.cc ProgramArea.h GlobalVariablesArea.h SystemStack.h
	$(CC) $(CPPFLAGS) -c esecutore.cc

# PROGRAM_AREA

ProgramArea.o: ProgramArea.h ProgramArea.cc
	$(CC) $(CPPFLAGS) -c ProgramArea.cc

# GLOBAL_VARIABLES_AREA

GlobalVariablesArea.o: GlobalVariablesArea.h GlobalVariablesArea.cc
	$(CC) $(CPPFLAGS) -c GlobalVariablesArea.cc

# ACTIVATION_RECORD

ActivationRecord.o: ActivationRecord.h ActivationRecord.cc
	$(CC) $(CPPFLAGS) -c ActivationRecord.cc


# Documentazione
$(DIRDOC): $(TARGETS)
	doxygen $(DOXYFILE)
	cd ./$(DIRDOC)/latex/ ; make ;


# Pulisci
clean:
	$(RM) *.o $(TARGETS) $(DIRDOC) $(TARGETDIR)
