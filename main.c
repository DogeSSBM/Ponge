#include "Includes.h"

typedef enum{P_PLAYER, P_BOT0, P_BOT1, P_BOT2}PlayerType;

typedef struct{
	PlayerType type;
	uint score;
	Direction dir;
	Coord pos;
	Length len;
	float speed;
}Player;


Player menu(const Length window, const uint scale)
{
	uint selection = 0;
	const uint numentries = 5;
	const uint entryOffset = window.y/5;
	const char *text[numentries] = {"Ponge", "Easy", "Medium", "Hard", "Multiplayer"};
	while(1){
		Ticks frameStart = getTicks();
		clear();

		for

		draw();
		events(frameStart + TPF);
	}
}

int main(int argc, char const *argv[])
{
	const uint scale = 20;
	const Length window = {scale*40, scale*30};
	init(window);

	menu(window, scale);


	return 0;
}
