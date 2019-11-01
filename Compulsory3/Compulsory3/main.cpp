#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <conio.h>
#include <ctime>
#include <random> 
#include "GUI.h"
#include <math.h>

class SeedEngine
{
public:
	// Seed engine for random numbers.
	typedef std::mt19937 RNG; // Merseene Twister Engine.
	RNG rng;
}mySeed;

class Players
{
public:
	// Holds player name and each category score.
	std::string participantName_Str = { "" };
	short int participantScore_IntA[13] = { 0 };
};

class GameOptions
{
public:
	// Keeps track of selected gamemode options.
	short int playerCount_Int = { 0 };
	bool aiEnabled = { false };
	short int aiCount_Int = { 0 };
	bool gamemodeIsDynamic = { true };
	bool bonusEnabled = { true };
};

void printPreGameText(short int state_Int, GameOptions newGameOptions, short int inputInvalid_Int)
{
	system("CLS");
	switch (state_Int)
	{
	case 0:
	{

	}
	case 1:
	{
		std::cout << "*************** Welcome to Yathzee! ***************\n"
			"\n"
			"Choose how many players you want to participate: ";
		break;

	}
	case 2:
	{
		std::cout << "*************** Welcome to Yathzee! ***************\n"
			"\n"
			"Number of players: " << newGameOptions.playerCount_Int << "\n";
		break;
	}
	case 3:
	{
		std::cout << "*************** Welcome to Yathzee! ***************\n"
			"\n"
			"Number of players: " << newGameOptions.playerCount_Int << "\n"
			"Play with ai? (Not implemented) (y/n): ";
		break;
	}
	case 4:
	{
		std::cout << "*************** Welcome to Yathzee! ***************\n"
			"\n"
			"Number of players: " << newGameOptions.playerCount_Int << "\n"
			"Play with ai? (Not implemented) (y/n): Yes\n"
			"Choose how many ai you want to play against: ";
		break;
	}
	case 5:
	{
		std::cout << "*************** Welcome to Yathzee! ***************\n"
			"\n"
			"Number of players: " << newGameOptions.playerCount_Int << "\n";
		if (newGameOptions.aiCount_Int > 0)
		{
			std::cout << "Number of Ai Opponents: " << newGameOptions.aiCount_Int << "\n";
		}
		std::cout << "Play with 'F: Fixed' or 'D: Dynamic' rules? \n";
		break;
	}
	case 6:
	{
		std::cout << "*************** Welcome to Yathzee! ***************\n"
			"\n"
			"Number of players: " << newGameOptions.playerCount_Int << "\n";
		if (newGameOptions.aiCount_Int > 0)
		{
			std::cout << "Number of Ai Opponents: " << newGameOptions.aiCount_Int << "\n";
		}
		if (newGameOptions.gamemodeIsDynamic == true)
		{
			std::cout << "Gamemode: Dynamic\n";
		}
		else
		{
			std::cout << "Gamemode: Fixed\n";
		}
		std::cout << "Play with bonus? (Not implemented) (y/n): ";
		break;
	}
	default:
	{
		std::cout << "Something went wrong.";
		break;
	}
	}
	if (inputInvalid_Int > 0)
	{
		switch (inputInvalid_Int)
		{
		case 1:
		{
			std::cout << "\n\nInvalid input. Please try again.\n";
			break;
		}
		case 2:
		{
			std::cout << "\n\nInput out of range. Please Choose a number between 1 and 20\n";
			break;
		}
		default:
		{
			std::cout << "Something went wrong.";
			break;
		}
		}
	}

}

short int calculateRoll(short int roll_IntA[5], short int scoreCategory_Int)
{
	short int value_Int = { 0 };

	//uppersection
	switch (scoreCategory_Int)
	{
	// Aces
	case 1:
	{
		for (short int i = 0; i < 5; i++)
		{
			if (roll_IntA[i] == 1)
			{
				value_Int++;
			}
		}
		break;
	}
	// Twos
	case 2:
	{
		for (short int i = 0; i < 5; i++)
		{
			if (roll_IntA[i] == 2)
			{
				value_Int += 2;
			}
		}
		break;
	}
	// Threes
	case 3:
	{
		for (short int i = 0; i < 5; i++)
		{
			if (roll_IntA[i] == 3)
			{
				value_Int += 3;
			}
		}
		break;
	}
	// Fours
	case 4:
	{
		for (short int i = 0; i < 5; i++)
		{
			if (roll_IntA[i] == 4)
			{
				value_Int += 4;
			}
		}
		break;
	}
	// Fives
	case 5:
	{
		for (short int i = 0; i < 5; i++)
		{
			if (roll_IntA[i] == 5)
			{
				value_Int += 5;
			}
		}
		break;
	}
	// Sixes
	case 6:
	{
		for (short int i = 0; i < 5; i++)
		{
			if (roll_IntA[i] == 6)
			{
				value_Int += 6;
			}
		}
		break;
	}
	// Three of a kind
	case 7:
	{
		if (roll_IntA[0] == roll_IntA[1] && roll_IntA[0] == roll_IntA[2])
		{
			for (short int i = 0; i < 5; i++)
			{
				value_Int += roll_IntA[i];
			}
		}
		else if (roll_IntA[1] == roll_IntA[2] && roll_IntA[1] == roll_IntA[3])
		{
			for (short int i = 0; i < 5; i++)
			{
				value_Int += roll_IntA[i];
			}
		}
		else if (roll_IntA[2] == roll_IntA[3] && roll_IntA[2] == roll_IntA[4])
		{
			for (short int i = 0; i < 5; i++)
			{
				value_Int += roll_IntA[i];
			}
		}
		break;
	}
	// Four of a kind
	case 8:
	{
		if (roll_IntA[0] == roll_IntA[1] && roll_IntA[0] == roll_IntA[2] && roll_IntA[0] == roll_IntA[3])
		{
			for (short int i = 0; i < 5; i++)
			{
				value_Int += roll_IntA[i];
			}
		}
		else if (roll_IntA[1] == roll_IntA[2] && roll_IntA[1] == roll_IntA[3] && roll_IntA[1] == roll_IntA[4])
		{
			for (short int i = 0; i < 5; i++)
			{
				value_Int += roll_IntA[i];
			}
		}
		break;
	}
	// Full House
	case 9:
	{
			if (roll_IntA[0] == roll_IntA[1] && roll_IntA[0] == roll_IntA[2] && roll_IntA[3] == roll_IntA[4])
			{
				value_Int = 25;
			}
			else if (roll_IntA[0] == roll_IntA[1] && roll_IntA[2] == roll_IntA[3] && roll_IntA[2] == roll_IntA[4])
			{
				value_Int = 25;
			}
		break;
	}
	//	Small straight
	case 10:
	{
		if (roll_IntA[0] == (roll_IntA[1]-1) && roll_IntA[0] == (roll_IntA[2]-2) && roll_IntA[0] == (roll_IntA[3] - 3))
		{
			value_Int = 30;
		}
		else if (roll_IntA[1] == (roll_IntA[2]-1) && roll_IntA[1] == (roll_IntA[3]-2) && roll_IntA[1] == (roll_IntA[4] - 3))
		{
			value_Int = 30;
		}
		else if (roll_IntA[0] == (roll_IntA[1] - 1) && roll_IntA[0] == (roll_IntA[3] - 2) && roll_IntA[0] == (roll_IntA[4] - 3))
		{
			value_Int = 30;
		}
		else if ((roll_IntA[0] == (roll_IntA[1] - 1) && roll_IntA[1] == (roll_IntA[2] - 2) && roll_IntA[1] == (roll_IntA[4] - 3)))
		{
			value_Int = 30;
		}

		break;
	}
	// Large straight
	case 11:
	{
		if (roll_IntA[0] == (roll_IntA[1]-1) && roll_IntA[0] == (roll_IntA[2]-2) && roll_IntA[0] == (roll_IntA[3]-3) && roll_IntA[0] == (roll_IntA[4] - 4))
		{
			value_Int = 40;
		}
		break;
	}
	// Yathzee
	case 12:
	{
		if (roll_IntA[0] == roll_IntA[1] && roll_IntA[0] == roll_IntA[2] && roll_IntA[0] == roll_IntA[3] && roll_IntA[0] == roll_IntA[4])
		{
			value_Int = 50;
		}
		break;
	}
	// Chance
	case 13:
	{
		for (short int i = 0; i < 5; i++)
		{
			value_Int += roll_IntA[i];
		}
		break;
	}
	}

	if (value_Int == 0)
	{
		value_Int = -1;	// If the participant doesn't get points, return -1 to later change to --;
	}
	return value_Int;
}

void throwDice(short int dice_IntA[5])
{
	std::uniform_int_distribution<short int> diceRange(1, 6);
	for (short int i = 0; i < 5; i++)
	{
		if (dice_IntA[i] == 7)
		{
			dice_IntA[i] = diceRange(mySeed.rng);

		}
	}
}

void yathzee(std::vector<Players> newPlayers, std::vector<Players> newAI, GameOptions newGameOptions)
{
	initAllegro(1366, 768);

	for (short int r = 0; r < 13; r++)	// Rounds
	{
		for(short int p = 0; p < newGameOptions.playerCount_Int; p++)	// Per Player
		{
			short int round_Int = { 0 };
			short int newDice_IntA[5] = { 7,7,7,7,7 };
			short int category_Int = { 0 };
			bool threwNewDice = { false };
			throwDice(newDice_IntA);

			while (true)
			{
				// Throw dice.
				round_Int++;
				threwNewDice = false;
				redirector(0, newDice_IntA, r+1, p+1, newPlayers[p].participantName_Str, newPlayers[p].participantScore_IntA, newGameOptions.playerCount_Int);
				std::sort(newDice_IntA, newDice_IntA + 5);

				// If any dice have been selected, rethrow those.
				for (short int i = 0; i < 5; i++)
				{
					if (newDice_IntA[i] == 7)
					{
						throwDice(newDice_IntA);
						threwNewDice = true;
						break;
					}
				}
				// Select category to score in.
				if (round_Int == 2 || threwNewDice == false)
				{
					std::sort(newDice_IntA, newDice_IntA + 5);
					// Dynamic mode for selecting score.
					if (newGameOptions.gamemodeIsDynamic == true)
					{
						category_Int = redirector(1, newDice_IntA, r + 1, p + 1, newPlayers[p].participantName_Str, newPlayers[p].participantScore_IntA, newGameOptions.playerCount_Int);
					}
					// Fixed mode for autoscoring.
					else
					{
						category_Int = r + 1;
					}
					newPlayers[p].participantScore_IntA[category_Int-1] = calculateRoll(newDice_IntA, category_Int);													// Calculate the roll.
					redirector(2, newDice_IntA, r + 1, p + 1, newPlayers[p].participantName_Str, newPlayers[p].participantScore_IntA, newGameOptions.playerCount_Int);	// Display the score.
					break;
				}
			}			
		}

	}
	// Sorts the participant by score and displays a winner along with all participants ranking when all dice throws are done.
	std::vector<short int> highscorers = { 0 };
	highscorers.resize(newPlayers.size());

	// Adds total scores to a temporary vector.
	for (short int i = 0; i < newPlayers.size();i++)
	{
		for (short int s = 0; s < 13; s++)
		{
			if (newPlayers[i].participantScore_IntA[s] == -1)
			{
				continue;
			}
			highscorers[i] += newPlayers[i].participantScore_IntA[s];
		}
	}
	// Sorts both vectors.
	for (short int i = 0; i < newPlayers.size()-1;i++)
	{
		if (highscorers[i] > highscorers[i + 1])
		{
			newPlayers.push_back(newPlayers[i]);
			newPlayers.erase(newPlayers.begin() + i);
			highscorers.push_back(highscorers[i]);
			highscorers.erase(highscorers.begin() + i);
			i = -1;
			continue;
		}
	}
	// Reverses the vector elements.
	std::reverse(newPlayers.begin(), newPlayers.end());
	std::reverse(highscorers.begin(), highscorers.end());

	// Display scores.
	system("CLS");
	std::cout << "Player " << newPlayers[0].participantName_Str << " Wins!\n\n";
	for (short int i = 0; i < newPlayers.size(); i++)
	{
		std::cout << "1. " << newPlayers[i].participantName_Str << "\t";
		if (newPlayers[i].participantName_Str.size() <= 4)
		{
			std::cout << "\t\t";
		}
		else if (newPlayers[i].participantName_Str.size() <= 11)
		{
			std::cout << "\t";
		}
		std::cout << "Score: " << highscorers[i] << "\n";
	}
	std::cout << "\n";

	endAllegro();	// Closes the Graphical window.


	std::cout << "Press Enter to Continue";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void preGameOptions()
{
	// Initializing
	std::vector<Players> newPlayers;
	std::vector<Players> newAI;
	GameOptions newGameOptions;

	// Used to take in different player input.
	char playerInput_C = { ' ' };
	std::string playerInput_Str = { "" };
	short int playerInput_Int = { 0 };

	short int inputInvalid_Int = { 0 };

	// User inputs how many players they want.
	while (true)
	{
		printPreGameText(1, newGameOptions, inputInvalid_Int);
		inputInvalid_Int = 0;
		std::cin >> playerInput_Int;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.sync();
			inputInvalid_Int = 1;
			continue;
		}

		if (playerInput_Int < 1 || playerInput_Int > 20)
		{
			inputInvalid_Int = 2;
			continue;
		}

		newGameOptions.playerCount_Int = playerInput_Int;
		newPlayers.resize(static_cast<unsigned long long>(playerInput_Int));
		break;
	}

	// The user can choose here if they want to give a custom name to each player.
	printPreGameText(2, newGameOptions, 0);
	std::cin.ignore();
	for (unsigned short int i = 0; i < newPlayers.size(); i++)
	{
		while (true)
		{
			std::cout << "Input name for player " << i + 1 << ": ";
			std::getline(std::cin, playerInput_Str);

			if (playerInput_Str.size() > 21)
			{
				std::cout << "\nName need to be at most 21 characters.\n";
				continue;
			}
			break;
		}

		if (playerInput_Str == "")
		{
			newPlayers[i].participantName_Str = { "player " };
			newPlayers[i].participantName_Str += std::to_string(i + 1);
			std::cout << "player " << i + 1 << " has been assigned the name: " << newPlayers[i].participantName_Str << "\n";
		}
		else
		{
			newPlayers[i].participantName_Str = playerInput_Str;
			std::cout << "player " << i + 1 << " has been assigned the name: " << newPlayers[i].participantName_Str << "\n";
		}
	}

	//// The user chooses if they want to enable AI to play against.
	//printPreGameText(3, newGameOptions, 0);
	//while (true)
	//{
	//	playerInput_C = _getch();
	//	playerInput_C = toupper(playerInput_C);
	//	if (playerInput_C == 'Y')
	//	{
	//		newGameOptions.aiEnabled = { true };
	//		break;
	//	}
	//	else if (playerInput_C == 'N')
	//	{
	//		newGameOptions.aiEnabled = { false };
	//		break;
	//	}
	//}

	//// The user chooses how many AI opponents to play against if enabled.
	//while (newGameOptions.aiEnabled == true)
	//{
	//	printPreGameText(4, newGameOptions, inputInvalid_Int);
	//	inputInvalid_Int = 0;
	//	std::cin >> playerInput_Int;
	//	if (std::cin.fail())
	//	{
	//		std::cin.clear();
	//		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//		std::cin.sync();
	//		inputInvalid_Int = 1;
	//		continue;
	//	}

	//	if (playerInput_Int < 1 || playerInput_Int > 50)
	//	{
	//		inputInvalid_Int = 2;
	//		continue;
	//	}

	//	newGameOptions.aiCount_Int = playerInput_Int;
	//	newAI.resize(static_cast<unsigned long long>(playerInput_Int));

	//	// Applies a name for all the AI opponents.
	//	for (unsigned short int i = 0; i < newAI.size(); i++)
	//	{
	//		newAI[i].participantName_Str = { "AI Opponent" };
	//		newAI[i].participantName_Str += std::to_string(i + 1);
	//	}
	//	break;
	//}

	// The user chooses what gamemode of yathzee they want.
	printPreGameText(5, newGameOptions, 0);
	while (true)
	{
		playerInput_C = _getch();
		playerInput_C = toupper(playerInput_C);
		if (playerInput_C == 'F')
		{
			newGameOptions.gamemodeIsDynamic = { false };
			break;
		}
		if (playerInput_C == 'D')
		{
			newGameOptions.gamemodeIsDynamic = { true };
			break;
		}
	}

	//// The player chooses if they want to enable bonus.
	//printPreGameText(6, newGameOptions, 0);
	//while (true)
	//{
	//	playerInput_C = _getch();
	//	playerInput_C = toupper(playerInput_C);
	//	if (playerInput_C == 'Y')
	//	{
	//		newGameOptions.bonusEnabled = { true };
	//		break;
	//	}
	//	if (playerInput_C == 'N')
	//	{
	//		newGameOptions.bonusEnabled = { false };
	//		break;
	//	}
	//}
	yathzee(newPlayers, newAI, newGameOptions);
}

int main()
{
	mySeed.rng.seed(static_cast<unsigned long long>(time(0)));
	preGameOptions();

	return 0;
}
