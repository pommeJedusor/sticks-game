#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char get_sticks_number(int number)
{
	return (number-1)%4 + (number%4==1);
}

int computer_turn(int stick_number)
{
	int best_move = get_sticks_number(stick_number);
	printf("je retire %d stick(s) il en reste %d\n",best_move,stick_number-best_move);
	return stick_number - best_move;
}

int get_player_input(int stick_number)
{
	char response[10];
	printf("combien de stick(s) souhaitez vous retirer?\n");
	scanf("%s",response);
	while ((atoi(response)<1 || atoi(response)>3) || stick_number - atoi(response) <0)
	{		
		memset(response,0,strlen(response));
		printf("combien de stick(s) souhaitez vous retirer?\n");
		scanf("%s",response);
	}
	return atoi(response);
}

int player_turn(int stick_number)
{
	int player_move = get_player_input(stick_number);
	printf("vous avez retiré %d stick(s) il en reste %d\n",player_move, stick_number - player_move);
	return stick_number - player_move;
}

void main()
{
	printf("entrez le nombre de stick\n");
	char response[10];
	scanf("%s",response);
	int stick_number = atoi(response);
	
	printf("qui commence 0 pour le bot 1 pour vous\n");
	char response2[10];
	scanf("%s",response2);
	int first_player = atoi(response2);
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
}
