OBJECTS = main.o sort.o
TEST = test.o sort.o 
INSTALL_PATH = /usr/local
simplex: $(OBJECTS)
	gcc -o simplex $(OBJECTS)
simplex_test: $(TEST)
	gcc -o simplex_test $(TEST)	
main.o: sort.h	
sort.o: sort.h	
test.o: sort.h	
install:simplex
	mv simplex $(INSTALL_PATH)
clean:
	rm simplex simplex_test $(OBJECTS) $(TEST)       
run: simplex
	./simplex
test: simplex_test
	./simplex_test
