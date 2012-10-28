all: cpp11

cpp11: main.o
	g++ obj/main.o obj/CPoint.o obj/key_handler.o obj/frame.o obj/snake.o obj/cmovesnake.o obj/clogger.o obj/CColisionDetector.o obj/CBasicWall.o obj/CGameControler.o obj/CItemToEat.o -o bin/snake -lboost_thread

main.o: src/main.cpp
	g++ -std=c++0x -c -g src/main.cpp -o obj/main.o 
	g++ -std=c++0x -c -g src/CPoint.cpp -o obj/CPoint.o
	g++ -std=c++0x -c -g src/key_handler.cpp -o obj/key_handler.o
	g++ -std=c++0x -c -g src/frame.cpp -o obj/frame.o
	g++ -std=c++0x -c -g src/snake.cpp -o obj/snake.o
	g++ -std=c++0x -c -g src/CMoveSnake.cpp -o obj/cmovesnake.o
	g++ -std=c++0x -c -g src/CLogger.cpp -o obj/clogger.o
	g++ -std=c++0x -c -g src/CColisionDetector.cpp -o obj/CColisionDetector.o
	g++ -std=c++0x -c -g src/CBasicWall.cpp -o obj/CBasicWall.o
	g++ -std=c++0x -c -g src/CGameControler.cpp -o obj/CGameControler.o
	g++ -std=c++0x -c -g src/CItemToEat.cpp -o obj/CItemToEat.o