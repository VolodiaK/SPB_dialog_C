CC=gcc
MKDIR=mkdir -p
BUILDDIR=BUILD
SRC=src/Source.c
EXE=$(BUILDDIR)/spb
OBJ=$(BUILDDIR)/spb.o
REMOVE=rm -Rf

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) -o $(EXE) $(OBJ)

$(OBJ): $(BUILDDIR) $(SRC)
	$(CC) -std=c99 -c -o $(OBJ) $(SRC)

$(BUILDDIR):
	$(MKDIR) $(BUILDDIR)

test: $(EXE)
	$(EXE) < test/test.inp > test/test.out
	cat test/test.out

clean:
	$(REMOVE) $(BUILDDIR)
