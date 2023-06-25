/*name : aryankumar patel
student id : 103094215
email id : anpatel34@myseneca.ca
NFF */
#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>

#define MINIMUM_LIVES 1
#define MAXIMUM_LIVES 10

#define LML 5
#define MINPATHLENGTH 10
#define MAXPATHLENGTH 70

struct PLAYER_INFO
{
	int lives;
	char symbol;
	int treasureFound;
	int history[MAXPATHLENGTH];
};
struct GAME_INFO
{
	int pathLength;
	int numberOfMoves;
	int bombs[MAXPATHLENGTH];
	int treasure[MAXPATHLENGTH];
};
int main(void)
{
	const char undiscovered = '-', bomb = '!', treasure = '$', bothbat = '&', neitherbat = '.';
	int a, b, c = 1, minimummove, maximummove, nextmove = 1, temp1, temp2, flag = 0;
	double temp;

	struct PLAYER_INFO pSetting;
	struct GAME_INFO gSetting;

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n");


	printf("\nPLAYER Configuration");
	printf("\n--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &pSetting.symbol);

	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &pSetting.lives);
		if (pSetting.lives < MINIMUM_LIVES || pSetting.lives > MAXIMUM_LIVES)
			printf("     Must be between %d and %d!\n", MINIMUM_LIVES, MAXIMUM_LIVES);
	} while (pSetting.lives < MINIMUM_LIVES || pSetting.lives > MAXIMUM_LIVES);

	printf("Player configuration set-up is complete\n");
	for (a = 0; a < MAXPATHLENGTH; a++)
	{
		pSetting.history[a] = 0;
	}
	printf("\nGAME Configuration");
	printf("\n------------------\n");

	do
	{
		printf("Set the path length (a multiple of %d between %d-%d): ", LML, MINPATHLENGTH, MAXPATHLENGTH);
		scanf("%d", &gSetting.pathLength);
		if
			((gSetting.pathLength < MINPATHLENGTH) || (gSetting.pathLength > MAXPATHLENGTH) || (gSetting.pathLength % LML != 0))
			printf("     Must be a multiple of %d and between %d-%d!!!\n", LML, MINPATHLENGTH, MAXPATHLENGTH);

	} while ((gSetting.pathLength < MINPATHLENGTH) || (gSetting.pathLength > MAXPATHLENGTH) || (gSetting.pathLength % LML != 0));
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &gSetting.numberOfMoves);
		minimummove = pSetting.lives;
		temp = ((double)gSetting.pathLength * 0.75);
		maximummove = (int)temp;
		if
			((temp - maximummove) > 0.5)++maximummove;
		if
			(gSetting.numberOfMoves < minimummove || gSetting.numberOfMoves >maximummove)
			printf("    Value must be between %d and %d\n", minimummove, maximummove);

	} while (gSetting.numberOfMoves < minimummove || gSetting.numberOfMoves>maximummove);

	printf("\nBOMB Placement");
	printf("\n--------------\n");

	printf("Enter the bomb positions in sets of %d where a value\n", LML);
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gSetting.pathLength);

	temp1 = 1;
	temp2 = LML;
	for (a = 0; a < gSetting.pathLength; a++)
	{
		if (a < 10)
		{
			if (temp2 < 10)
			{
				printf("   Positions [ %d- %d]: ", temp1, temp2);
				a = temp2;
				for (b = temp1 - 1; b < temp2; b++)
					scanf("%d", &gSetting.bombs[b]);
			}
			else
			{
				printf("   Positions [ %d-%d]: ", temp1, temp2);
				a = temp2;
				for (b = temp1 - 1; b < temp2; b++)
					scanf("%d", &gSetting.bombs[b]);
			}
		}
		else
		{
			printf("   Positions [%d-%d]: ", temp1, temp2);
			a = temp2;
			for (b = temp1 - 1; b < temp2; b++)
				scanf("%d", &gSetting.bombs[b]);
		}
		a = temp2;
		temp1 = temp2 + 1;
		temp2 += LML;
	}
	printf("BOMB placement set\n");
	printf("\nTREASURE Placement");
	printf("\n------------------\n");

	printf("Enter the treasure placements in sets of %d where a value\n", LML);
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gSetting.pathLength);

	temp1 = 1;
	temp2 = LML;
	for (a = 0; a < gSetting.pathLength; a++)
	{
		if (a < 10)
		{
			if (temp2 < 10)
			{
				printf("   Positions [ %d- %d]: ", temp1, temp2);
				a = temp2;
				for (b = temp1 - 1; b < temp2; b++)
					scanf("%d", &gSetting.treasure[b]);
			}
			else
			{
				printf("   Positions [ %d-%d]: ", temp1, temp2);
				a = temp2;
				for (b = temp1 - 1; b < temp2; b++)
					scanf("%d", &gSetting.treasure[b]);
			}
		}
		else
		{
			printf("   Positions [%d-%d]: ", temp1, temp2);
			a = temp2;
			for (b = temp1 - 1; b < temp2; b++)
				scanf("%d", &gSetting.treasure[b]);
		}
		a = temp2;
		temp1 = temp2 + 1;
		temp2 += LML;
	}
	printf("TREASURE placement set\n");
	printf("\nGAME configuration set-up is complete...\n");
	printf("\n------------------------------------");
	printf("\nTREASURE HUNT Configuration Settings");
	printf("\n------------------------------------");

	printf("\nPlayer:");
	printf("\n   Symbol     : %c", pSetting.symbol);
	printf("\n   Lives      : %d", pSetting.lives);
	printf("\n   Treasure   : [ready for gameplay]");
	printf("\n   History    : [ready for gameplay]\n");
	printf("\nGame:");
	printf("\n   Path Length: %d", gSetting.pathLength);
	printf("\n   Bombs      : ");


	for (a = 0; a < gSetting.pathLength; a++)

		printf("%d", gSetting.bombs[a]);
	printf("\n   Treasure   : ");

	for (a = 0; a < gSetting.pathLength; a++)

		printf("%d", gSetting.treasure[a]);
	printf("\n");

	printf("\n====================================");
	printf("\n~ Get ready to play TREASURE HUNT! ~");
	printf("\n====================================\n");

	temp = 0;
	pSetting.treasureFound = 0;


	while (1)
	{
		if (temp == 0)
			++temp;
		else
		{
			printf("\n ");
			printf(" ");

			for (a = 0; a < gSetting.pathLength; a++)
			{
				if (pSetting.history[a] == 1 && a == (nextmove - 1))
				{
					printf("%c", pSetting.symbol);
				}
				else
					printf(" ");
			}
		}
		printf("\n ");
		printf(" ");

		for (a = 0; a < gSetting.pathLength; a++)
		{
			if (pSetting.history[a] == 0)
				printf("%c", undiscovered);
			else if (gSetting.bombs[a] == 1 && gSetting.treasure[a] == 1)
			{

				printf("%c", bothbat);
			}
			else if (gSetting.bombs[a] == 1)
			{
				printf("%c", bomb);
			}
			else if (gSetting.treasure[a] == 1)
			{
				printf("%c", treasure);
			}
			else
				printf("%c", neitherbat);
		}
		printf("\n ");
		printf(" ");

		for (a = 0; a < gSetting.pathLength; a++)
		{
			if ((a + 1) % 10 == 0)
			{
				++flag;
				printf("%d", flag);
			}
			else
				printf("|");
		}
		flag = 0;
		printf("\n ");
		printf(" ");

		for (a = 0; a < gSetting.pathLength; a++)
		{
			if ((a + 1) % 10 == 0)
			{
				printf("0");
				c = 1;
			}
			else
				printf("%d", c++);
		}
		printf("\n");

		printf("+---------------------------------------------------+\n");
		printf("  Lives:  %d  | Treasures:  %d  |  Moves Remaining: %2d\n", pSetting.lives, pSetting.treasureFound, gSetting.numberOfMoves);
		printf("+---------------------------------------------------+\n");


		if (pSetting.lives == 0 || gSetting.numberOfMoves == 0)
			break;
		while (1)
		{
			printf("Next Move [1-%d]: ", gSetting.pathLength);
			scanf("%d", &nextmove);
			if (nextmove<1 || nextmove > gSetting.pathLength)
				printf("  Out of Range!!!\n");
			else
				break;
		}

		if (pSetting.history[nextmove - 1] == 1)
		{
			printf("\n===============> Dope! You've been here before!\n");
		}
		else
		{
			pSetting.history[nextmove - 1] = 1;
			gSetting.numberOfMoves -= 1;
			if (gSetting.bombs[nextmove - 1] == 1 &&
				gSetting.treasure[nextmove - 1] == 1)
			{
				pSetting.lives -= 1;
				pSetting.treasureFound += 1;
				printf("\n===============> [&] !!! BOOOOOM !!! [&]");
				printf("\n===============> [&] $$$ Life Insurance Payout!!! [&]\n");

				if (pSetting.lives == 0)
					printf("\nNo more LIVES remaining!\n");
				else if (gSetting.numberOfMoves == 0)
					printf("\nNo more MOVES remaining!\n");
			}
			else if (gSetting.bombs[nextmove - 1] == 1)
			{
				pSetting.lives -= 1;
				printf("\n===============> [!] !!! BOOOOOM !!! [!]\n");
				if (pSetting.lives == 0)
					printf("\nNo more LIVES remaining!\n");
				else if (gSetting.numberOfMoves == 0)
					printf("\nNo more MOVES remaining!\n");
			}
			else
				if (gSetting.treasure[nextmove - 1] == 1)
				{
					pSetting.treasureFound += 1;

					printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n");
				}
				else
				{
					printf("\n===============> [.] ...Nothing found here... [.]\n");
				}
		}
	}
	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n");


	printf("\nYou should play again and try to beat your score!\n");


	return 0;
}

