OBJ tipo.o liste.o compito.o

CXXFLAGS=-Wall

agenda: $(OBJ)
	g++ -o agenda $(OBJ)

-include dependencies

.PHONY: clean cleanall
depend:
	g++ -MM *.cc > dependencies
clean:
	rm -f *.o
cleanall:
	rm -f agenda *.o