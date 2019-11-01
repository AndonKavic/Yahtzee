#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

void initAllegro(int w, int h);
void endAllegro();
short int redirector(short int state, short int *dice, short int roundCount, short int currentPlayer, std::string playerName, short int* playerScore, short int playerCount);

#endif