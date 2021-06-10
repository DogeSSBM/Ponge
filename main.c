#include "Includes.h"

typedef enum{P_PLAYER, P_BOT0, P_BOT1, P_BOT2}PaddleType;

typedef struct{
	PaddleType type;
	uint score;
	Direction dir;
	Coordf pos;
	Lengthf len;
	float speed;
}Paddle;

Paddle menu(const Length window, const uint scale)
{
	// uint optSelected = 0;
	// const static uint optNum = 5;
	// const uint entryOffset = window.y/5;
	Coord intvl[2] = {{window.x/4, 0}, (Coord){window.x/4, window.y}};
	Offset off = {window.x/2, 0};
	const char *optText[] = {"This", "Is", "A", "Test"};
	// const char *optText[] = {"Easy", "Medium", "Hard", "Multiplayer"};
	while(1){
		Ticks frameStart = getTicks();
		clear();

		if(mouseBtnState(MOUSE_L)){
			const uint i = coordDistSq(mouse.pos, intvl[0]) > coordDistSq(mouse.pos, intvl[1]);
			setColor(WHITE);
			fillCircleCoord(intvl[i], 3);
			intvl[i] = coordOffset(intvl[i], mouse.vec);
		}

		if(mouseBtnState(MOUSE_R))
			off = coordOffset(off, mouse.vec);

		const uint num = 4;
		setFontSize(24);
		setFontColor(RED);
		spanTextList(intvl[0], intvl[1], num, optText);
		setFontColor(BLUE);
		spanTextListCentered(coordOffset(intvl[0],off), coordOffset(intvl[1],off), num, optText);

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
