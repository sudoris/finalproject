output: main.o Game.o Train.o Space.o Point.o LastCar.o Car5.o Car4.o Car3.o Freight.o Head.o 
	g++ main.o Game.o Train.o Space.o Point.o LastCar.o Car5.o Car4.o Car3.o Freight.o Head.o -o output
	
main.o: main.cpp
	g++ -c main.cpp
	
Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp
	
Train.o: Train.cpp Train.hpp
	g++ -c Train.cpp
	
Space.o: Space.cpp Space.hpp
	g++ -c Space.cpp

Point.o: Point.cpp Point.hpp
	g++ -c Point.cpp

LastCar.o: LastCar.cpp LastCar.hpp
	g++ -c LastCar.cpp

Car5.o: Car5.cpp Car5.hpp
	g++ -c Car5.cpp

Car4.o: Car4.cpp Car4.hpp
	g++ -c Car4.cpp

Car3.o: Car3.cpp Car3.hpp
	g++ -c Car3.cpp
	
Freight.o: Freight.cpp Freight.hpp
	g++ -c Freight.cpp
	
Head.o: Head.cpp Head.hpp
	g++ -c Head.cpp

clean: 
	rm *.o output