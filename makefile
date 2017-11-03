default: program

program: friday13.cpp
	gcc friday13.cpp -o bin/friday13

clean:
	-rm -f bin/friday13
