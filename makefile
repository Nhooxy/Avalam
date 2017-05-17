#======================================================
#
#  Makefile du projets AVALAM
#
#  Auteur : Pierre PEREZ
#
#  Version Actuelle du projet: 1.0
#
#======================================================

#Compilateur
CC=g++
 
#Répertoires contenant les fichiers 
SRCDIR=SRC
HEADDIR=HEADER
HEADSFML= $(wildcard $(CURDIR)/SRC/SFML/*.hpp)
OBJDIR=OBJ
LIBDIR=LIB
BINDIR=Bin
 
#Ou trouver les librairie externe
LIB= -L $(LIBDIR) -lsfml-system -lsfml-audio -lsfml-window -lsfml-graphics -lGLEW

#Les différentes options de compilations
FLAGS= -I $(HEADDIR) $(HEADSFML) $(LIB)
FLAGSopti= $(FLAGS) -O2 -falign-loops=4 -ftree-loop-optimize -mfpmath=sse -mmmx -msse -msse2 -msse3 -m3dnow -w -Wall -ansi -pedantic
#-falign-loops=4 : où n est une puissance de 2, alignement du début du code des fonctions
#-ftree-loop-optimize : de même pour les boucle
#-mfpmath=sse : architecture, on dispose également d'un certain nombre d'options d'optimisation (SSE)
#-mmmx -msse -msse2 -msse3 -m3dnow: calcul sur les réels avec coprocesseur ou unités SSE
#option -pg pour profiler et lancer programme , le quitter une fois fini et gprof avalam.run >result.txt dans terminal

#L'exécutable
BIN=avalam.run
 
#Où trouver les différents sources *.cpp qu'il faudra compiler pour créer les objets correspondants
SRC= $(wildcard $(SRCDIR)/*.cpp)
OBJ= $(SRC:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(BIN)

#Création de l'exécutable
$(BIN): $(OBJ) 
	$(CC) -o $(BINDIR)/$@ $^ $(FLAGSopti)

# Création des différents *.o à partir des *.cpp
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) -o $@ -c $< 
 
# Nettoyage des objets => Tout sera recompiler !
clean:
	rm $(OBJDIR)/*.o
 
# Nettoyage complet => clean + effacement de l'exécutable
mrproper: clean
	rm $(BINDIR)/$(BIN)

#LD_LIBRARY_PATH=../LIBS:$LD_LIBRARY_PATH avalam.run 

exec: 
	$(MAKE) -C $(BINDIR)/ -f makefile \

run: 
	$(MAKE) -C $(BINDIR)/ -f makefile \

#============ fin du makefile =============
#
# 	$@: Nom de la cible.
#	$<: Nom du fichier préalable.
#	$?: Liste des préalables plus récents que la cible.
#	$^: La liste des dépendances
#	$(CURDIR): variable d'environnement : comme pwd
#	-O2 optimisation 2 (suffisant dans la pluspart des cas)
#	wildcard * (permet d'utiliser le joker dans une variable)
#

