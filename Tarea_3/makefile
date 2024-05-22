CC=g++
EXE=programa
FLAGS=-std=c++11 -Wextra -Wuninitialized -Winit-self -Werror -Wundef -Wall
MAIN=main.cpp		#Hora_punta.cpp		main.cpp
FILE1=buses.o
FILE2=paradas.o

$(EXE): $(FILE1) $(FILE2) $(MAIN)
	$(CC) $(FLAGS) $^ -o $@
	./$(EXE)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

run:
	./$(EXE)

clean:
	rm -f *.o $(EXE)	