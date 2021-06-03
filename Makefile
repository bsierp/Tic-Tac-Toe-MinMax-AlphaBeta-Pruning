OBJ=./obj
FLAGS= -Wall -pedantic -std=c++2a -iquote inc
TRGDIR=./

__start__: ${TRGDIR}/Tic_Tac_Toe
			${TRGDIR}/Tic_Tac_Toe
${TRGDIR}/Tic_Tac_Toe: ${OBJ}	${OBJ}/main.o ${OBJ}/Human_Player.o ${OBJ}/AI.o ${OBJ}/Board_Manager.o ${OBJ}/Board.o ${OBJ}/Tile.o 
						g++ -o ${TRGDIR}/Tic_Tac_Toe ${OBJ}/main.o ${OBJ}/Human_Player.o ${OBJ}/AI.o ${OBJ}/Board_Manager.o ${OBJ}/Board.o ${OBJ}/Tile.o

${OBJ}:
						mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/Player.hh inc/Board.hh inc/Tile.hh inc/Board_Manager.hh inc/Exception.hh inc/Human_Player.hh inc/AI.hh
						g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Board.o: inc/Board.hh src/Board.cpp inc/Tile.hh 
						g++ -c ${FLAGS} -o ${OBJ}/Board.o src/Board.cpp
${OBJ}/Tile.o: inc/Tile.hh src/Tile.cpp
						g++ -c ${FLAGS} -o ${OBJ}/Tile.o src/Tile.cpp
${OBJ}/Board_Manager.o: inc/Board_Manager.hh src/Board_Manager.cpp inc/Board.hh inc/Tile.hh inc/Exception.hh
						g++ -c ${FLAGS} -o ${OBJ}/Board_Manager.o src/Board_Manager.cpp
${OBJ}/AI.o: inc/AI.hh src/AI.cpp inc/Player.hh inc/Board_Manager.hh inc/Board.hh inc/Tile.hh inc/Exception.hh
						g++ -c ${FLAGS} -o ${OBJ}/AI.o src/AI.cpp
${OBJ}/Human_Player.o: inc/Human_Player.hh src/Human_Player.cpp inc/Player.hh inc/Board_Manager.hh inc/Board.hh inc/Tile.hh inc/Exception.hh
						g++ -c ${FLAGS} -o ${OBJ}/Human_Player.o src/Human_Player.cpp
clear:
						rm -f ${TRGDIR}/Tic_Tac_Toe ${OBJ}/*