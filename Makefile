RUN=g++
CFLAGS=-std=c++20 -g -c
SUBDIRS=method mode keygen parser
LIBRARIES=-pthread
SOURCES=method/method.cpp method/aesLookup.cpp method/aes.cpp mode/cbc.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXEC=run

all: subdirs $(SOURCES) $(EXEC)

.PHONY: subdirs $(SUBDIRS)
subdirs: $(SUBDIRS)
$(SUBDIRS): 
	+$(MAKE) -C $@

$(EXEC): $(OBJECTS)
	$(RUN) $(LIBRARIES) $(OBJECTS) -o $(EXEC)

.cpp.o:
	$(RUN) $(CFLAGS) $<

PHONY: clean
clean:
	find . -name \*.o -type f -delete
	find . -name \$(EXEC) -type f -delete
