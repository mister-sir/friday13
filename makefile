default: friday13

friday13: friday13.cpp
	@mkdir -p bin
	g++ friday13.cpp -o bin/friday13

clean:
	-rm -f bin/friday13
