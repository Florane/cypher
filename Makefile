RUN=g++
CFLAGS=-std=c++20 -g -c
LIBRARIES=-pthread
SOURCES=method/method.cpp method/aesLookup.cpp method/aes.cpp mode/cbc.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXEC=run

all: subdirs $(SOURCES) $(EXEC)

subdirs: 
	+$(MAKE) -C method
	+$(MAKE) -C mode

$(EXEC): $(OBJECTS)
	$(RUN) $(LIBRARIES) $(OBJECTS) -o $(EXEC)

.cpp.o:
	$(RUN) $(CFLAGS) $<

clean:
	find . -name \*.o -type f -delete
	find . -name \$(EXEC) -type f -delete
