#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int get_stick_number()
{
	char response[10];
	printf("entrez le nombre de stick\n");
	scanf("%s",response);
	return atoi(response);
}

char get_first_player()
{
	char response[10];
	printf("qui commence 0 pour le bot 1 pour vous\n");
	scanf("%s",response);
	return atoi(response);
}

int get_player_move(int stick_number)
{
	char response[10];
	printf("combien de stick(s) souhaitez vous retirer?\n");
	scanf("%s",response);
	while ((atoi(response)<1 || atoi(response)>3) || stick_number - atoi(response) <0)
	{		
		printf("combien de stick(s) souhaitez vous retirer?\n");
		scanf("%s",response);
	}
	return atoi(response);
}

char get_computer_move(int number)
{
	return (number-1)%4 + (number%4==1);
}

int computer_turn(int stick_number)
{
	int best_move = get_computer_move(stick_number);
	printf("je retire %d stick(s) il en reste %d\n",best_move,stick_number-best_move);
	return stick_number - best_move;
}

int player_turn(int stick_number)
{
	int player_move = get_player_move(stick_number);
	printf("vous avez retiré %d stick(s) il en reste %d\n",player_move, stick_number - player_move);
	return stick_number - player_move;
}

char game(int stick_number, char first_player)
{
	while (stick_number>0)
	{
		if (first_player)
		{
			stick_number = player_turn(stick_number);
		}
		else
		{
			stick_number = computer_turn(stick_number);
		}
		first_player = (first_player+1)%2;
	}
	return first_player;
}

void show_winner(int first_player)
{
	if (first_player==0)
	{
		printf("j'ai gagné\n");
	}
	else
	{
		printf("vous avez gagné\n");
        }
}

char want_to_replay()
{
	char response[10];
	printf("voulez vous rejouer? 1 pour oui 0 pour non\n");
	scanf("%s",response);
	return atoi(response);
}

void main()
{
	char want_to_play = 1;
	while (want_to_play)
	{
		int stick_number = get_stick_number();	
		char first_player = get_first_player();
		
		first_player = game(stick_number, first_player);

		show_winner(first_player);
		want_to_play = want_to_replay();
	}	
}
