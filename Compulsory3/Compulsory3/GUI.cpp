#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE* event_queue = NULL;

class Font
{
public:
	ALLEGRO_FONT* font20;
	ALLEGRO_FONT* font22;
	ALLEGRO_FONT* font34;
}myFont;


void initAllegro(int w, int h)
{
	if (!al_init())
	{
		printf("failed to initialize allegro!\n");
	}

	display = al_create_display(w, h);

	if (!display)
	{
		printf("failed to create display!\n");
		exit(0);
	}
	else
	{
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	if (!al_install_keyboard())
	{
		printf("failed to install keyboard!\n");
		exit(0);
	}

	if (!al_init_primitives_addon())
	{
		printf("Failed to initialize primitives!\n");
		exit(0);
	}

	if (!al_init_font_addon())
	{
		printf("Failed to initialize fonts!\n");
		exit(0);
	}
	if (!al_init_ttf_addon())
	{
		printf("Failed to initialize ttf's!\n");
		exit(0);
	}

	event_queue = al_create_event_queue();
	if (!event_queue)
	{
		printf("failed to create event_queue!\n");
		exit(0);
	}	
	al_clear_to_color(al_map_rgb(200,95,0));	// Sets background color.

	// Assigns required data to fonts.
	ALLEGRO_PATH* path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
	al_append_path_component(path, "resources");
	al_set_path_filename(path, "cour.ttf");
	myFont.font20 = al_load_font(al_path_cstr(path, '/'), 20, NULL);
	myFont.font22 = al_load_font(al_path_cstr(path, '/'), 22, NULL);
	myFont.font34 = al_load_font(al_path_cstr(path, '/'), 34, NULL);
	al_destroy_path(path);	
}

void endAllegro()
{
	al_destroy_display(display);
}

void waitForKey(int k)
{
	ALLEGRO_KEYBOARD_STATE key_state;
	bool quit = { false };

	while (!quit)
	{
		al_get_keyboard_state(&key_state);
		if (al_key_down(&key_state, k))
		{
			quit = true;
		}
	}
}

void drawDice(short int roll_IntA[5], bool reRoll_BA[5], bool init_B)
{
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
	short int padding_IntA[2] = { 480, 30 };
	short int spacing_Int = { 180 };
	short int clear_IntA[2] = { 1100, 252 };

	// Draw over the dice with background color.
	al_draw_filled_rectangle(padding_IntA[0]-5, padding_IntA[1]-5, padding_IntA[0] + clear_IntA[0], padding_IntA[1] + clear_IntA[1],al_map_rgb(200,95,0));

	for (short int i = 0; i < 5; i++)
	{
		// Draws a selected dice.
		if (init_B == false)
		{
			if (reRoll_BA[i] == true)
			{
				color = al_map_rgb(200, 200, 200);
				padding_IntA[1] += 100;
			}
		}
		// Draw dice border.
		al_draw_rounded_rectangle(0 + padding_IntA[0] + i * spacing_Int, 0 + padding_IntA[1], 150 + padding_IntA[0] + i * spacing_Int, 150 + padding_IntA[1], 15, 15, color, 2);

		// Draw circles for each dice.
		switch (roll_IntA[i])
		{
		case 1:
		{
			al_draw_filled_circle(75 + padding_IntA[0] + i * spacing_Int, 75 + padding_IntA[1], 12, color);
			break;
		}
		case 2:
		{
			al_draw_filled_circle(40 + padding_IntA[0] + i * spacing_Int, 40 + padding_IntA[1], 12, color);
			al_draw_filled_circle(110 + padding_IntA[0] + i * spacing_Int, 110 + padding_IntA[1], 12, color);
			break;
		}
		case 3:
		{
			al_draw_filled_circle(75 + padding_IntA[0] + i * spacing_Int, 75 + padding_IntA[1], 12, color);
			al_draw_filled_circle(40 + padding_IntA[0] + i * spacing_Int, 40 + padding_IntA[1], 12, color);
			al_draw_filled_circle(110 + padding_IntA[0] + i * spacing_Int, 110 + padding_IntA[1], 12, color);
			break;
		}
		case 4:
		{
			al_draw_filled_circle(40 + padding_IntA[0] + i * spacing_Int, 40 + padding_IntA[1], 12, color);
			al_draw_filled_circle(110 + padding_IntA[0] + i * spacing_Int, 110 + padding_IntA[1], 12, color);
			al_draw_filled_circle(110 + padding_IntA[0] + i * spacing_Int, 40 + padding_IntA[1], 12, color);
			al_draw_filled_circle(40 + padding_IntA[0] + i * spacing_Int, 110 + padding_IntA[1], 12, color);
			break;
		}
		case 5:
		{
			al_draw_filled_circle(75  + padding_IntA[0] + i * spacing_Int, 75  + padding_IntA[1], 12, color);
			al_draw_filled_circle(40  + padding_IntA[0] + i * spacing_Int, 40  + padding_IntA[1], 12, color);
			al_draw_filled_circle(110 + padding_IntA[0] + i * spacing_Int, 110 + padding_IntA[1], 12, color);
			al_draw_filled_circle(110 + padding_IntA[0] + i * spacing_Int, 40  + padding_IntA[1], 12, color);
			al_draw_filled_circle(40  + padding_IntA[0] + i * spacing_Int, 110 + padding_IntA[1], 12, color);
			break;
		}
		case 6:
		{
			al_draw_filled_circle(40 + padding_IntA[0] + i * spacing_Int, 40 + padding_IntA[1], 12, color);
			al_draw_filled_circle(40 + padding_IntA[0] + i * spacing_Int, 75 + padding_IntA[1], 12, color);
			al_draw_filled_circle(40 + padding_IntA[0] + i * spacing_Int, 110 + padding_IntA[1], 12, color);
			al_draw_filled_circle(110 + padding_IntA[0] + i * spacing_Int, 40 + padding_IntA[1], 12, color);
			al_draw_filled_circle(110 + padding_IntA[0] + i * spacing_Int, 75 + padding_IntA[1], 12, color);
			al_draw_filled_circle(110 + padding_IntA[0] + i * spacing_Int, 110 + padding_IntA[1], 12, color);
			break;
		}
		} // End of switch statement.

		// Reset selected dice properties in case next dice is not selected..
		if (init_B == false)
		{
			if (reRoll_BA[i] == true)
			{
				color = al_map_rgb(255, 255, 255);
				padding_IntA[1] -= 100;
			}
		}
	} // End of for-loop
}

void drawYathzee()
{
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
	short int padding_Int = { 10 };
	short int spacing_Int = { 0 };

	// Draw Y.
	al_draw_line(10 + padding_Int+spacing_Int, 3 + padding_Int, 45 + padding_Int+spacing_Int, 38 + padding_Int, color, 8);
	al_draw_line(84 + padding_Int+spacing_Int, 3 + padding_Int,  0 + padding_Int+spacing_Int, 87 + padding_Int, color, 8);
	spacing_Int += 70;

	// Draw A.
	al_draw_line(40 + padding_Int+spacing_Int,  3 + padding_Int, -11 + padding_Int+spacing_Int, 54 + padding_Int, color, 8);
	al_draw_line(35 + padding_Int+spacing_Int,  3 + padding_Int,  86 + padding_Int+spacing_Int, 54 + padding_Int, color, 8);
	al_draw_line(16 + padding_Int+spacing_Int, 28 + padding_Int,  58 + padding_Int+spacing_Int, 28 + padding_Int, color, 8);
	spacing_Int += 105;

	// Draw H.
	al_draw_line(-3 + padding_Int+spacing_Int, -1 + padding_Int, -3 + padding_Int+spacing_Int, 48 + padding_Int, color, 8);
	al_draw_line(38 + padding_Int+spacing_Int, -1 + padding_Int, 38 + padding_Int+spacing_Int, 48 + padding_Int, color, 8);
	al_draw_line(-4 + padding_Int+spacing_Int, 23 + padding_Int, 38 + padding_Int+spacing_Int, 23 + padding_Int, color, 8);
	spacing_Int += 58;

	// Draw T.
	al_draw_line(-3 + padding_Int+spacing_Int, 3 + padding_Int, 42 + padding_Int+spacing_Int,  3 + padding_Int, color, 8);
	al_draw_line(21 + padding_Int+spacing_Int, 3 + padding_Int, 21 + padding_Int+spacing_Int, 48 + padding_Int, color, 8);
	spacing_Int += 58;

	// Draw Z.
	al_draw_line(-3 + padding_Int+spacing_Int,  3 + padding_Int, 42 + padding_Int+spacing_Int,  3 + padding_Int, color, 8);
	al_draw_line(40 + padding_Int+spacing_Int,  3 + padding_Int,  0 + padding_Int+spacing_Int, 43 + padding_Int, color, 8);
	al_draw_line(-3 + padding_Int+spacing_Int, 44 + padding_Int, 42 + padding_Int+spacing_Int, 44 + padding_Int, color, 8);
	spacing_Int += 58;

	// Draw E.
	al_draw_line( 0 + padding_Int+spacing_Int,  3 + padding_Int,  0 + padding_Int+spacing_Int, 44 + padding_Int, color, 8);
	al_draw_line(-4 + padding_Int+spacing_Int,  3 + padding_Int, 42 + padding_Int+spacing_Int,  3 + padding_Int, color, 8);
	al_draw_line(-4 + padding_Int+spacing_Int, 23 + padding_Int, 42 + padding_Int+spacing_Int, 23 + padding_Int, color, 8);
	al_draw_line(-4 + padding_Int+spacing_Int, 44 + padding_Int, 42 + padding_Int+spacing_Int, 44 + padding_Int, color, 8);
	spacing_Int += 58;

	// Draw E.
	al_draw_line( 0 + padding_Int+spacing_Int, 3  + padding_Int,  0 + padding_Int+spacing_Int, 44 + padding_Int, color, 8);
	al_draw_line(-4 + padding_Int+spacing_Int, 3  + padding_Int, 42 + padding_Int+spacing_Int,  3 + padding_Int, color, 8);
	al_draw_line(-4 + padding_Int+spacing_Int, 23 + padding_Int, 42 + padding_Int+spacing_Int, 23 + padding_Int, color, 8);
	al_draw_line(-4 + padding_Int+spacing_Int, 44 + padding_Int, 42 + padding_Int+spacing_Int, 44 + padding_Int, color, 8);

	// Draw Underline.
	al_draw_line(56 + padding_Int, 55 + padding_Int, 449 + padding_Int, 55 + padding_Int, color, 8);
}

void drawTextCurrentPlayer(short int roundCount_Int , short int currentPlayer_Int, short int playerCount_Int, std::string playerName_Str)
{
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);

	short int padding[2] = { 38, 80 };
	short int spacing = { 20 };

	std::string roundCount_Str = { "Round  of 13" };
	roundCount_Str = roundCount_Str.insert(6,std::to_string(roundCount_Int));
	std::string playerCount_Str = { "player  of " };
	playerCount_Str = playerCount_Str.insert(7, std::to_string(currentPlayer_Int));
	playerCount_Str = playerCount_Str.append(std::to_string(playerCount_Int));

	al_draw_filled_rectangle(padding[0] - 1, padding[1] - 1, padding[0] + 420, padding[1] + 76, al_map_rgb(200, 95, 0));
	for (short int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			color = al_map_rgb(0, 0, 0);
		}
		else
		{
			color = al_map_rgb(255, 255, 255);
		}

		al_draw_text(myFont.font22, color, (420 + padding[0] - 1 + i), (padding[1] - 1 + i) + spacing * (1 - 1), ALLEGRO_ALIGN_RIGHT, roundCount_Str.c_str());
		al_draw_text(myFont.font22, color, (420 + padding[0] - 1 + i), (padding[1] - 1 + i) + spacing * (2 - 1), ALLEGRO_ALIGN_RIGHT, playerCount_Str.c_str());
		al_draw_text(myFont.font34, color, (padding[0] - 1 + i), (padding[1] - 1 + i) + spacing * (3 - 1), ALLEGRO_ALIGN_LEFT, playerName_Str.c_str());
	}
}

void drawTable()
{
	ALLEGRO_COLOR color = { al_map_rgb(255,255,255) };
	ALLEGRO_COLOR colorShadow = { al_map_rgb(0,0,0) };
	short int padding_IntA[2] = { 38,160 };
	short int spacing_Int = { 28 };

	// Draw vertical border line shadows.
	al_draw_line( -2 + padding_IntA[0], padding_IntA[1],  -2 + padding_IntA[0], 532 + padding_IntA[1], colorShadow, 2);
	al_draw_line(303 + padding_IntA[0], padding_IntA[1], 303 + padding_IntA[0], 532 + padding_IntA[1], colorShadow, 2);
	al_draw_line(417 + padding_IntA[0], padding_IntA[1], 417 + padding_IntA[0], 532 + padding_IntA[1], colorShadow, 2);

	// Sets border thickness.
	for (int i = 0; i < 20 ; i++)
	{
		short int thickness_Int = { 2 };
		if (i == 0 || i == 1 || i == 8 || i == 10 || i == 17 || i == 19)
		{
			thickness_Int = 2;
		}
		else if (i == 9)
		{
			continue;
		}
		else
		{
			thickness_Int = 1;
		}
		// Draw horizontal border lines and shadows.
		al_draw_line(padding_IntA[0] - 3, padding_IntA[1]-1 + spacing_Int * i, 420 + padding_IntA[0] - 3, padding_IntA[1]-1 + spacing_Int * i, colorShadow, thickness_Int);
		al_draw_line(padding_IntA[0] - 2, padding_IntA[1]   + spacing_Int * i, 420 + padding_IntA[0] - 2, padding_IntA[1]   + spacing_Int * i, color, thickness_Int);
	}

	// Draw vertical border lines.
	al_draw_line( -1 + padding_IntA[0], padding_IntA[1],  -1 + padding_IntA[0], 532 + padding_IntA[1], color, 2);
	al_draw_line(304 + padding_IntA[0], padding_IntA[1], 304 + padding_IntA[0], 532 + padding_IntA[1], color, 2);
	al_draw_line(418 + padding_IntA[0], padding_IntA[1], 418 + padding_IntA[0], 532 + padding_IntA[1], color, 2);
}

void drawText(short int *playerScore, short int roundCount)
{
	short int spacing_Int = { 28 };
	short int padding_IntA[2] = { 38, 156 };
	short int RowSpacing_Int = { 308 };
	short int scoreSpacing_Int = { 0 };

	std::string score_StrA[16] = { "" };
	short int totalScores_IntA[3] = { 0 };
	std::string text_StrA[20] =
	{
		"UPPER SECTION", "Aces", "Twos", "Threes", "Fours", "Fives", "Sixes",
		"TOTAL UPPER", "", "LOWER SECTION",
		"Three of a kind", "Four of a kind", "Full House",
		"Small Straight", "Large Straight", "YATHZEE", "CHANCE",
		"TOTAL LOWER", "GRAND TOTAL"
	};

	// Score clearer.
	for (short int i = 0; i < 18; i++)
	{
		if (i == 7)
		{
			i += 2;
		}
		al_draw_filled_rectangle(305 + padding_IntA[0], 62 + padding_IntA[1] + spacing_Int * (i - 1), 416 + padding_IntA[0], 86 + padding_IntA[1] + spacing_Int * (i - 1), al_map_rgb(200, 95, 0));
	}

	// Text.
	for (short int i = 0; i < 2; i++)
	{
		short color = { 0 };
		short int scoreSpacing_Int = { 0 };


		if (i == 0)
		{
			color = { 0 };	// Shadow.
		}
		else
		{
			color = { 255 };
		}

		// Category names.
		al_draw_text(myFont.font34, al_map_rgb(color, color, color), -1 + i + padding_IntA[0] + RowSpacing_Int, -1 + i + padding_IntA[1] + spacing_Int * 0, ALLEGRO_ALIGN_LEFT, "SCORE");
		for (short int t = 0; t < 20; t++)
		{
			if (t == 8)
			{
				continue;
			}
			al_draw_text(myFont.font34, al_map_rgb(color, color, color), -1 + i + padding_IntA[0], -1 + i + padding_IntA[1] + spacing_Int * t, ALLEGRO_ALIGN_LEFT, text_StrA[t].c_str());
		}

		// Scores.
		for (short int s = 0; s < 13; s++)
		{
			if (s == 6)
			{
				scoreSpacing_Int += spacing_Int * 3;
			}

			if (playerScore[s] == -1)
			{
				if (score_StrA[s] == "")
				{
					score_StrA[s] = score_StrA[s].append("--");
				}
				al_draw_textf(myFont.font34, al_map_rgb(color, color, color), -1 + i + padding_IntA[0] + RowSpacing_Int, -1 + i + padding_IntA[1] + spacing_Int * (s + 1) + scoreSpacing_Int, ALLEGRO_ALIGN_LEFT, score_StrA[s].c_str());
			}
			else if (playerScore[s] != 0)
			{
				if (score_StrA[s] == "")
				{
					score_StrA[s] = score_StrA[s].append(std::to_string(playerScore[s]));
				}
				al_draw_textf(myFont.font34, al_map_rgb(color, color, color), -1 + i + padding_IntA[0] + RowSpacing_Int, -1 + i + padding_IntA[1] + spacing_Int * (s + 1) + scoreSpacing_Int, ALLEGRO_ALIGN_LEFT, score_StrA[s].c_str());
			}			
		}
		// Calculate upper score.
		for (short int s = 0; s < 6; s++)
		{
			if (playerScore[s] > 0)
			{
				totalScores_IntA[0] += playerScore[s];
			}
		}
		// Calculate lower score.
		for (short int s = 0; s < 7; s++)
		{
			if (playerScore[s+6] > 0)
			{
				totalScores_IntA[1] += playerScore[s+6];
			}
		}
		// Draw upper score.
		if (totalScores_IntA[0] != 0)
		{
			if (i == 0)
			{
				score_StrA[13] = score_StrA[13].append(std::to_string(totalScores_IntA[0]));
			}
			al_draw_textf(myFont.font34, al_map_rgb(color, color, color), -1 + i + padding_IntA[0] + RowSpacing_Int, -1 + i + padding_IntA[1] + spacing_Int * (4) + scoreSpacing_Int, ALLEGRO_ALIGN_LEFT, score_StrA[13].c_str());
		}
		// Draw lower score.
		if (totalScores_IntA[1] != 0)
		{
			if (i == 0)
			{
				score_StrA[14] = score_StrA[14].append(std::to_string(totalScores_IntA[1]));
			}
			al_draw_textf(myFont.font34, al_map_rgb(color, color, color), -1 + i + padding_IntA[0] + RowSpacing_Int, -1 + i + padding_IntA[1] + spacing_Int * (14) + scoreSpacing_Int, ALLEGRO_ALIGN_LEFT, score_StrA[14].c_str());
		}
		// Draw total score (upper + lower).
		if (roundCount == 13)
		{
			if (i == 0)
			{
				totalScores_IntA[2] = totalScores_IntA[0] + totalScores_IntA[1];
				score_StrA[15] = score_StrA[15].append(std::to_string(totalScores_IntA[2]));
			}
			al_draw_textf(myFont.font34, al_map_rgb(color, color, color), -1 + i + padding_IntA[0] + RowSpacing_Int, -1 + i + padding_IntA[1] + spacing_Int * (15) + scoreSpacing_Int, ALLEGRO_ALIGN_LEFT, score_StrA[15].c_str());
		}
	}
}

void drawControlsText(short int state_Int)
{
	ALLEGRO_COLOR color = al_map_rgb(0, 0, 0);
	short int padding_IntA[2] = { 1366, 768 };

	// Draw over control text area with background color.
	al_draw_filled_rectangle(padding_IntA[0] - 900, padding_IntA[1] - 30, padding_IntA[0], padding_IntA[1], al_map_rgb(200, 95, 0));
	switch (state_Int)
	{
	case 1:
	{
		for (short int i = 0; i < 2; i++)
		{
			if (i == 1)
			{
				color = al_map_rgb(255, 255, 255);
			}
			al_draw_text(myFont.font20, color, padding_IntA[0] - 11+i, padding_IntA[1] - 31+i, ALLEGRO_ALIGN_RIGHT, "(A & D) to move arrow, (E) to select dice to reroll, (R) to reroll or stay");
		}
		break;
	}
	case 2:
	{
		for (short int i = 0; i < 2; i++)
		{
			if (i == 1)
			{
				color = al_map_rgb(255, 255, 255);
			}
			al_draw_text(myFont.font20, color, padding_IntA[0] - 11 + i, padding_IntA[1] - 31 + i, ALLEGRO_ALIGN_RIGHT, "(W & S) to move selection box, (E) to select category");
		}
		break;
	}
	case 3:
	{
		for (short int i = 0; i < 2; i++)
		{
			if (i == 1)
			{
				color = al_map_rgb(255, 255, 255);
			}
			al_draw_text(myFont.font20, color, padding_IntA[0] - 11 + i, padding_IntA[1] - 31 + i, ALLEGRO_ALIGN_RIGHT, "Press (Space) to continue");
		}
		break;
	}
	default:
		break;
	}
}

void drawArrow(short int position_Int)
{
	ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
	short int padding_IntA[2] = { 555,310 };
	short int spacing_Int = { 180 };
	short int clear_IntA[2] = { 900,220 };

	// Draw over all arrow locations with background color.
	al_draw_filled_rectangle(padding_IntA[0]-20, padding_IntA[1]-20, padding_IntA[0] + clear_IntA[0], padding_IntA[1] + clear_IntA[1], al_map_rgb(200, 95, 0));
	if (position_Int == 0)
	{
		return;
	}

	// Draw arrow.
	al_draw_line(0 + padding_IntA[0] + spacing_Int * (position_Int-1), 0 + padding_IntA[1], 0 + padding_IntA[0] + spacing_Int * (position_Int-1), 200 + padding_IntA[1], color, 8);
	al_draw_filled_triangle(-15 + padding_IntA[0] + spacing_Int * (position_Int - 1), 0 + padding_IntA[1], 0 + padding_IntA[0] + spacing_Int * (position_Int - 1), -15 + padding_IntA[1], 15 + padding_IntA[0] + spacing_Int * (position_Int - 1), 0 + padding_IntA[1], color);
}

void interactWithDice(short int *diceRoll_IntA)
{
	ALLEGRO_EVENT ev;
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	short int position_Int = { 1 };
	bool selected_BA[5] = { false };

	while (true)
	{
		al_wait_for_event(event_queue, &ev);	// Waits for any events.

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)	// If a key has been pressed to a down state.
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_A:	// Move arrow left.
			{
				if (position_Int == 1)
				{
					continue;
				}
				position_Int--;
				drawArrow(position_Int);
				break;
			}
			case ALLEGRO_KEY_D: // Move arrow right.
			{
				if (position_Int == 5)
				{
					continue;
				}
				position_Int++;
				drawArrow(position_Int);
				break;

			}
			case ALLEGRO_KEY_E:	// Select or unselect dice.
			{
				selected_BA[position_Int-1] = !selected_BA[position_Int-1];
				drawDice(diceRoll_IntA, selected_BA, false);
				break;
			}
			case ALLEGRO_KEY_R: // Sets all selected dice values to 7 for rerolling.
			{
				for (short int i = 0; i < 5; i++)
				{
					if (selected_BA[i] == true)
					{
						diceRoll_IntA[i] = 7;
					}
				}
				return;
				break;
			}
			case ALLEGRO_KEY_ESCAPE: // Exits the game.
			{
				exit(0);
				break;
			}
			default:
				break;
			}
			al_flip_display();
		}
	}
	al_destroy_event_queue;
}

void drawSelectBox(short int a, bool b, short int c)
{
	short int padding_IntA[2] = { 38,160 };
	short int spacing_Int = { 28 };

	// Draws over selection box with background color.
	al_draw_filled_rectangle(307 + padding_IntA[0], 32 + padding_IntA[1] + spacing_Int * (a-1), 415 + padding_IntA[0], 52 + padding_IntA[1] + spacing_Int * (a-1), al_map_rgb(200, 95, 0));
	if (b == true)
	{
		return;
	}
	// Draw new selection box.
	al_draw_filled_rectangle(307 + padding_IntA[0], 32 + padding_IntA[1] + spacing_Int * (c-1), 415 + padding_IntA[0], 52 + padding_IntA[1] + spacing_Int * (c-1), al_map_rgb(50, 255, 50));
}

short int selectCategory(short int *playerScore)
{
	ALLEGRO_EVENT ev;
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	short int newPosition_Int = { 1 };
	short int currentPosition_Int = { 1 };
	short int arrayShift_Int = { 0 };

	while (playerScore[newPosition_Int-1 + arrayShift_Int] != 0)
	{
		
		newPosition_Int++;
		if (newPosition_Int == 7)
		{
			newPosition_Int += 3;
			arrayShift_Int = -3;
		}
	}


	drawSelectBox(newPosition_Int, false, newPosition_Int);
	al_flip_display();

	while (true)
	{

		al_wait_for_event(event_queue, &ev);
		currentPosition_Int = newPosition_Int;
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{

			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_W:	// Moves selection box up.
			{
				while (true)
				{
					newPosition_Int--;	// Moves up once before checking if it's valid.

					// Moves from lower to upper section.
					if (newPosition_Int == 9)
					{
						newPosition_Int -= 2;
						continue;
					}

					// If the selection box it at the top, reset and exit.
					else if (newPosition_Int == 0)
					{
						newPosition_Int = currentPosition_Int;
						break;
					}

					// If the selection box is in the lower section.
					// Shift the scoreArray for the category to match the selection box position.
					if (newPosition_Int > 9)
					{
						arrayShift_Int = -3;
					}
					else
					{
						arrayShift_Int = 0;
					}

					// Skips over boxes which already holds value.
					if (playerScore[newPosition_Int - 1 + arrayShift_Int] != 0)
					{						
						continue;
					}
					drawSelectBox(currentPosition_Int, false, newPosition_Int);	// Draws a new selection box and clears the previous one.
					break;
				}
				break;
			}
			case ALLEGRO_KEY_S:	// Moves selection box down.
			{
				while (true) // Moves down once before checking if it's valid.
				{
					// Moves from upper to lower section.
					newPosition_Int++;
					if (newPosition_Int == 7)
					{
						newPosition_Int += 2;
						continue;
					}

					// If the selection box it at the bottom, reset and exit.
					else if (newPosition_Int == 17)
					{
						newPosition_Int = currentPosition_Int;
						break;
					}

					// If the selection box is in the lower section.
					// Shift the scoreArray for the category to match the selection box position.
					if (newPosition_Int > 9)
					{
						arrayShift_Int = -3;
					}
					else
					{
						arrayShift_Int = 0;
					}

					// Skips over boxes which already holds value.
					if (playerScore[newPosition_Int - 1 + arrayShift_Int] != 0)
					{
						continue;
					}

					drawSelectBox(currentPosition_Int, false, newPosition_Int); // Draws a new selection box and clears the previous one.
					break;
				}
				break;

			}
			case ALLEGRO_KEY_E:	// Continue with currently marked category box.
			{
				drawSelectBox(currentPosition_Int, true,0); // Clears selection box.
				return currentPosition_Int+arrayShift_Int;	// return selected box position.
			}
			case ALLEGRO_KEY_ESCAPE:	// Exits the game.
			{
				exit(0);
				break;
			}
			default:
				break;
			}
			al_flip_display();
		}
	}
	al_destroy_event_queue;

}

short int redirector(short int state_Int, short int *diceRoll_IntA, short int roundCount_Int, short int currentPlayer_Int, std::string playerName_Str, short int *playerScore_IntA, short int playerCount_Int)
{
	switch (state_Int)
	{
	case 0: // Dice Section
	{	
		// Draws all the information.
		drawYathzee();
		drawDice(diceRoll_IntA, NULL , true);
		drawTextCurrentPlayer(roundCount_Int, currentPlayer_Int, playerCount_Int, playerName_Str);
		drawTable();
		drawText(playerScore_IntA, roundCount_Int);
		drawArrow(1);
		drawControlsText(state_Int + 1);
		al_flip_display();

		interactWithDice(diceRoll_IntA);	// Use arrow to select dices.
		drawArrow(0);	// remove arrow.
		return 0;
	}
	case 1:	// Score Section
	{
		// Draw information.
		drawDice(diceRoll_IntA, NULL, true);
		drawControlsText(state_Int + 1);

		return selectCategory(playerScore_IntA);	// Use the selection box to select a category.
	}
	case 2: // Scoring Result
	{
		// Draw information.
		drawDice(diceRoll_IntA, NULL, true);
		drawText(playerScore_IntA, roundCount_Int);
		drawControlsText(state_Int + 1);
		al_flip_display();

		waitForKey(ALLEGRO_KEY_SPACE);	// When the participant is done looking at the new score, continue to the next round/participant.
		return 0;
	}
	}
}
