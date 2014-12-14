# Definitions
GRAPH = gnuplot
EXEC = pendulum
CC = clang
LOG = pend
PNG = pendulum.png
SOURCES = pendulum.o pend-ode.o
CFLAGS = -Wall -O0 -g 
LFLAGS = -O0 -g
LIBS = -lgsl -lm

# Compile Main Executable 
$(EXEC): $(SOURCES)                     
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

# Run, Export Log
$(LOG): $(EXEC)
	./$(EXEC) > $@

# Make plot of data
$(PNG): $(LOG) pend.gpl
	$(GRAPH) pend.gpl


#Cleanup: Remove Unneccessary Files
clean:
	rm -f *.o
veryclean: clean
	rm -f $(EXEC)
	rm -f $(LOG)
	rm -f $(PNG)

