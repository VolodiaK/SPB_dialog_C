#!/bin/make

#CC=gcc
#CC=clang
#CC=cl


MKDIR=mkdir -p
BUILDDIR=BUILD
SRC=src/Source.c

UNAME := $(shell uname -s)
ifeq ($(UNAME),Linux)
	EXEEXT=
else 
	EXEEXT=.exe
endif

ifeq ($CC,cl)
	OBJEXT=.OBJ
	OUTOPT=/Fe
	CFLAGS=/c
else
	ifeq ($CC,clang)
		CFLAGS=-Weverything -pedantic -std=c99 -c
	else
		CFLAGS=-Wall -pedantic -std=c99 -c
	endif

	OUTOPT=-o
	REMOVE=rm -Rf
	OBJEXT=.o
endif

EXE=$(BUILDDIR)/spb$(EXEEXT)
OBJ=$(BUILDDIR)/spb$(OBJEXT)
TESTDATA=test/test.inp

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OUTOPT) $(EXE) $(OBJ)

$(OBJ): $(BUILDDIR) $(SRC)
	$(CC) $(CFLAGS) $(OUTOPT) $(OBJ) $(SRC)

$(BUILDDIR):
	$(MKDIR) $(BUILDDIR)

test: $(EXE)
	$(EXE) < $(TESTDATA)

clean:
	$(REMOVE) $(BUILDDIR)
