default: friday13

friday13: friday13.cpp
	g++ friday13.cpp -o bin/friday13

clean:
	-rm -f bin/friday13
