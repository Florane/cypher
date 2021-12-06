RUN=g++
CFLAGS=-std=c++20 -g -c
LIBRARIES=-pthread
SOURCES=cbc.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXEC=run

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJECTS)
	$(RUN) $(LIBRARIES) $(OBJECTS) -o $(EXEC)

.cpp.o:
	$(RUN) $(CFLAGS) $<

clean:
	rm -rf *.o $(EXEC)
