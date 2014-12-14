GRAPH = gnuplot
EXEC = pendulum
CC = clang
LOG = pend
PNG = pendulum.png
SOURCES = pendulum.o pend-ode.o
CFLAGS = -Wall -O0 -g 
LFLAGS = -O0 -g
LIBS = -lgsl -lm

$(EXEC): $(SOURCES)
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

$(LOG): $(EXEC)
	./$(EXEC) > $@

$(PNG): $(LOG) pend.gpl
	$(GRAPH) pend.gpl


pendulum.png: 

clean:
	rm -f *.o

veryclean: clean
	rm -f $(EXEC)
	rm -f $(LOG)
	rm -f *.png
