#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

char result[MAXCHAR];
char performance[2][MAXCHAR];
int player_serial=0;

struct Player
{
	int scored;
	int missed;
	char name[20];
	Player(int scored, int missed, char* name)
	{
		this->scored=scored;
		this->missed=missed;
		strcpy(this->name,name);
	}
	void print_Information()
	{
		FILE *fp1 = fopen("Score.txt","w");
		fprintf(fp1,"%s has scored %d times while missing %d times\n",name,scored,missed);
		fclose(fp1);
		FILE *fp2 = fopen("Score.txt","r");
		fgets(performance[player_serial], MAXCHAR, fp2);
		++player_serial;
		fclose(fp2);
	}
	void compare_performance(Player second_player)
	{
		if(scored>second_player.scored)
		{
			FILE *fp1 = fopen("Result.txt","w");
			fprintf(fp1,"%s has won.\n\n",name);
			fclose(fp1);
			FILE *fp2 = fopen("Result.txt","r");
			fgets(result, MAXCHAR, fp2);
			fclose(fp2);
		}
		else if(second_player.scored>scored)
		{
			FILE *fp1 = fopen("Result.txt","w");
			fprintf(fp1,"%s has won.\n\n",second_player.name);
			fclose(fp1);
			FILE *fp2 = fopen("Result.txt","r");
			fgets(result, MAXCHAR, fp2);
			fclose(fp2);
		}
		else
		{
			FILE *fp1 = fopen("Result.txt","w");
			fprintf(fp1,"It's a tie.\n\n",name);
			fclose(fp1);
			FILE *fp2 = fopen("Result.txt","r");
			fgets(result, MAXCHAR, fp2);
			fclose(fp2);
		}
	}
};

#endif // !PLAYER_H_INCLUDED
