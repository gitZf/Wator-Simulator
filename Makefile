LIBS=-lsfml-graphics -lsfml-window -lsfml-system 
DOXYGEN = doxygen

all: run

run:wator-simulation
	$(DOXYGEN) Doxyfile
	@echo '*********************'
	@echo '********SFML*********'
	@echo 'IF MISSING SFML PACKAGES'
	@echo 'INSTALL SFML ON UNBUNTU - sudo apt-get install libsfml-dev'
	@echo '*********************'
	@echo '*********************'
	@echo 'CHANGE WATOR SIZE!!!'
	@echo 'main.cpp line 128'
	@echo 'TESTED SIZES ARE 100 , 120 , 150 , 200'
	@echo 'SOME SIZE MIGHT CAUSING SEGMENTATION FAULT EX. 80 !!!!!!'
	@echo '*********************'
	@echo '*********************'
	./wator-simulation
	#//gprof wator-simulation

main.o: main.cpp
	g++ -std=c++11 -c "main.cpp" -o main.o -fopenmp

wator.o: wator.cpp
	g++ -std=c++11 -c "wator.cpp" -o wator.o -fopenmp

swimmer.o: swimmer.cpp
	g++ -std=c++11 -c "swimmer.cpp" -o swimmer.o

wator-simulation: main.o wator.o swimmer.o
	@echo "** Building the game Wator Simulation"
	g++ -g -Wall -o wator-simulation main.o wator.o swimmer.o $(LIBS) -fopenmp

clean:
	@echo "** Removing object files and executable..."
	rm -f *.o



.PHONY: all clean
