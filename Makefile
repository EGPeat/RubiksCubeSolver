RubiksProgram: main.cpp rubikscube.hpp rubikscube.cpp 
	g++ -g -Wall -Werror main.cpp rubikscube.hpp rubikscube.cpp -o RubiksProgram

clean:
	rm -f *.o *.out

