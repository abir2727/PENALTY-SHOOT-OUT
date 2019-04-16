#include <stdio.h>
#include <string.h>
#include "iGraphics.h"
#include "player.h"
#include "tvBoard.h"

using namespace std ;

int screen_width = 1400, screen_height = 700;
double ball_position_x = 655, ball_position_y = 0;
double change_of_x_of_ball = 0, change_of_y_of_ball = 0;
int count1 = 0, count2 = 0;
int random_number = 0, state_of_ball = 10, shot_number = 0, individual_shot_number, index_1 = 0, index_2 = 0;
int football_image, background_image, initial_goalkeeper_image, left_dive_image, right_dive_image;
int player_1[5] = {1,1,1,1,1}, player_2[5] = {1,1,1,1,1};
int goal_keeper_left_dive_position_x = 100, goal_keeper_left_dive_position_y = 60;
int goal_keeper_right_dive_position_x = 900, goal_keeper_right_dive_position_y = 60;
double angle_of_goalkeeper_on_left = 0, angle_of_goalkeeper_on_right = 0;
int UI_var_image;
int UI_show_flag;
char player_1_str[1000];
char player_2_str[1000];
int len_player_1, len_player_2;
int mode_player_1, mode_player_2;
int name_input_box_on;
int about_image,help_image;
int about_var, help_var;
bool music = true;
double ball_rotate_angle = 0;
int game_over_image;
int back_end;

//Prepares for the next kick
void reset()
{
	ball_position_x = 655;
	ball_position_y = 0;
	change_of_x_of_ball = 3;
	change_of_y_of_ball = 2;
	angle_of_goalkeeper_on_right=0;
	angle_of_goalkeeper_on_left=0;
	ball_rotate_angle = 0;
	state_of_ball=10;
}

//Shows the ball
void ball()
{
	iRotate(ball_position_x+45,ball_position_y+45,ball_rotate_angle);
	iShowImage(ball_position_x,ball_position_y,90,90,football_image);
	iUnRotate();
}

//Determines the situation after a shot when user kicks the ball on the left
void ball_going_left()
{
	ball_position_x -= change_of_x_of_ball;
	ball_position_y += change_of_y_of_ball;
	ball_rotate_angle += 30;
	for(int i=0;i<1000000;i++)
	{
		;
		;
		;
		;
	}
	if(ball_position_x<=300 || ball_position_y>=600)
	{
		change_of_x_of_ball = 0;
		change_of_y_of_ball = -8;
		if(ball_position_y<=150)
		{
			change_of_y_of_ball = 0;
			angle_of_goalkeeper_on_right=-20;
			angle_of_goalkeeper_on_left=10;
			ball_rotate_angle = 0;
		}
	}
}

//Determines the situation after a shot when user kicks the ball on the right
void ball_going_right()
{
	ball_position_x += change_of_x_of_ball;
	ball_position_y += change_of_y_of_ball;
	ball_rotate_angle -= 30;
	for(int i=0;i<1000000;i++)
	{
		;
		;
		;
		;
	}
	if((ball_position_x>=1100) || (ball_position_y>=600))
	{
		change_of_x_of_ball = 0;
		change_of_y_of_ball = -8;
		if(ball_position_y<=150)
		{
			change_of_y_of_ball = 0;
			angle_of_goalkeeper_on_right=-20;
			angle_of_goalkeeper_on_left=10;
			ball_rotate_angle = 0;
		}
	}
}

//Shows the position and movement of the goalkeeper
void goalKeeper()
{
	if(random_number==0)                 //Shows the goalkeeper on the middle
	{
		iShowImage(450,0,500,550,initial_goalkeeper_image);
	}
	else if(random_number==1)         //Shows the dive of the goalkeeper on right side
	{
		iRotate(goal_keeper_right_dive_position_x,goal_keeper_right_dive_position_y,angle_of_goalkeeper_on_right);
		iShowImage(goal_keeper_right_dive_position_x,goal_keeper_right_dive_position_y,450,550,left_dive_image);
		iUnRotate();
	}
	else if(random_number==2)       //Shows the dive of the goalkeeper on right side
	{
		iRotate(goal_keeper_right_dive_position_x,goal_keeper_right_dive_position_y,angle_of_goalkeeper_on_left);
		iShowImage(goal_keeper_left_dive_position_x,goal_keeper_left_dive_position_y,450,550,right_dive_image);
		iUnRotate();
	}
}

//Shows the page for input of players' names
void player_1_2_name_input_box()
{
	iSetColor(255,255,255) ;
	iFilledRectangle(550,300,300,70);        //Shows the bar for input of name of first player
	iSetColor(255,255,255) ;
	iText(300,320,"Enter name of Player 1",GLUT_BITMAP_TIMES_ROMAN_24) ;
	iSetColor(255,255,255) ;
	iFilledRectangle(550,440,300,70);       //Shows the bar for input of name of second player
	iSetColor(255,255,255) ;
	iText(300,460,"Enter name of Player 2",GLUT_BITMAP_TIMES_ROMAN_24) ;
	iSetColor(0,0,0) ;
	iFilledRectangle(20,20,100,50) ;
	iSetColor(0,255,0) ;
	iText(45,35,"Play",GLUT_BITMAP_TIMES_ROMAN_24);      //Button for beginning the gameplay
}

void iDraw()
{
	iClear();
	if( UI_show_flag == 0 )      //Shows 'Menu'
	{
		iShowImage( 0,0,1400,700, UI_var_image );
	}
	if(about_var == 1)           //Goes to 'About' page
	{
		iShowImage( 0,0,1400,700,about_image) ;
		iSetColor(0,0,0);
		iFilledRectangle(600,20,200,75);
		iSetColor(255,255,255);
		iText(675,55,"Back",GLUT_BITMAP_HELVETICA_18);
	}
	if(help_var == 1)            //Goes to 'Help' page
	{
		iShowImage( 0,0,1400,700,help_image) ;
		iSetColor(0,0,0); 
		iFilledRectangle(600,20,200,75);
		iSetColor(255,255,255);
		iText(675,55,"Back",GLUT_BITMAP_HELVETICA_18);     //Shows the button to go back to menu
	}
	if( name_input_box_on == 0 && UI_show_flag != 0 )
	{
		iSetColor(0,130,130) ;
		iFilledRectangle(0,0,1400,700);
		player_1_2_name_input_box() ;
		if(mode_player_1 == 1)
		{
			iSetColor(0, 0, 0);
			iText(570, 330 , player_1_str);           //Shows the name of second player upto current state of typing
		}
		if( mode_player_2 == 1 )
		{
			iSetColor(0,0,0) ;
			iText( 570,470 , player_2_str );          //Shows the name of second player upto current state of typing
		}
		iSetColor(255,255,255) ;
		iText(100, 100, "Click the box to write name. Press ENTER to rewrite it.",GLUT_BITMAP_TIMES_ROMAN_24) ;
	}
	if( name_input_box_on == 1 )                  //Begins gameplay
	{
		if(music)
		{
			music = false;                       //Turns the music off when the gameplay begins
			PlaySound(0,0,0);
		}
		iShowImage(0,0,screen_width,screen_height,background_image);

		//Adds the presence of the Goal Keeper to the gameplay
		goalKeeper();

		//Adds the presence of the Ball to the gameplay
		ball();
		if(state_of_ball==1)
		{
			ball_going_left();
		}
		if(state_of_ball==0)
		{
			ball_going_right();
		}
		if(shot_number>10)
		{
			back_end = 1;
		}
		tvBoard();
	}
	if(back_end == 1)       //Shows the 'Game Over' page
	{
		iSetColor(255,255,0) ;
		iShowImage( 0,0,1400,700,game_over_image) ;
		iText(300,130,performance[0],GLUT_BITMAP_TIMES_ROMAN_24) ;         //Shows the first player's performance
		iText(300,100,performance[1],GLUT_BITMAP_TIMES_ROMAN_24) ;		   //Shows the second player's performance
		iText(300,70,result,GLUT_BITMAP_TIMES_ROMAN_24) ;				   //Shows the result of the game
		iSetColor(255,255,255); 
		iFilledRectangle(1100,70,140,60);
		iSetColor(0,0,0);
		iText(1127,95,"End Game",GLUT_BITMAP_HELVETICA_18);         //Shows the 'End Game' button
	}
}

void iMouseMove(int mx, int my)
{

}

void iPassiveMouse(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{
	if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx>=1101 && mx <= 1374 && my >= 608 && my <= 660 )
		{
			UI_show_flag = 1 ;
		}
	}
	if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN)                          //Goes to 'About' page
	{
		if(mx>=1101 && mx <= 1374 && my >= 249 && my <= 331 )
		{
			about_var = 1 ;
		}
	}
	if(button==GLUT_LEFT_BUTTON && state == GLUT_DOWN)                          //Goes to 'Help' page
	{
		if(mx>=1101 && mx <= 1374 && my >= 386 && my <= 445 )
		{
			help_var = 1 ;
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)                        //Only takes input of name of first player at the time
	{
		if(mx >= 550  && mx <= 850  && my >= 300  && my <= 370  && mode_player_1 == 0  )
		{
			mode_player_1 = 1 ;
			mode_player_2 = 0 ;
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)                        //Only takes input of name of second player at the time
	{
		if(mx >= 550  && mx <= 850  && my >= 440  && my <= 510  && mode_player_2 == 0  )
		{
			mode_player_2 = 1 ;
			mode_player_1 = 0 ;
		}
	}
	if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )                      //Exits from name input screen
	{
		if( mx >= 20 && mx <= 120 && my >= 20 && my <= 70  )
		{
			name_input_box_on = 1;
		}
	}
	if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )                      //Goes back to 'Menu' from 'About' or 'Help' page
	{
		if( mx >= 600 && mx <= 800 && my >= 20 && my <= 75  )
		{
			about_var=0;
			help_var=0;
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)                        //Quits game from the 'Menu'
	{
		if(mx >= 1101  && mx <= 1374  && my >= 177  && my <= 229)
		{
			exit(0);
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)                        //Turns the music on or off from the 'Menu'
	{
		if(mx >= 1101  && mx <= 1374  && my >= 499  && my <= 551)
		{
			if(music)
			{
				music = false;
				PlaySound(0,0,0);
			}
			else
			{
				music = true;
				PlaySound("SamFenderPlayGodDemoLatbizRingtone.wav",NULL,SND_LOOP | SND_ASYNC);
			}
		}
	}
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)                                   //Ends game
	{
		if(mx >= 1101  && mx <= 1240  && my >= 70  && my <= 130)
		{
			exit(0);
		}
	}
}

void iKeyboard(unsigned char key)
{
	int i;
	if(mode_player_1 == 1)                               //While entering name of first player
	{
        if(key == '\r')
		{
			mode_player_1 = 0;
			strcpy(player_1_str2, player_1_str);
			for(i = 0; i < len_player_1; i++)
				player_1_str[i] = 0;
			len_player_1 = 0;
		}
		else
		{
			player_1_str[len_player_1] = key;
			len_player_1++;
		}
	}
	if(mode_player_2 == 1)                               //While entering name of second player
	{
        if(key == '\r')
		{
			mode_player_2 = 0;
			strcpy(player_2_str2, player_2_str);
			for(i = 0; i < len_player_2; i++)
				player_2_str[i] = 0;
			len_player_2 = 0;
		}
		else
		{
			player_2_str[len_player_2] = key;
			len_player_2++;
		}
	}
}

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_RIGHT)
	{
		reset();
		random_number=rand()%2+1;
		state_of_ball=0;
		if(random_number==1)
		{
			if(shot_number%2==0)
			{
				player_1[index_1]=0;                            //The miss of first player is being stored
				r1[index_1]=255;
				index_1++;
			}
			else
			{
				player_2[index_2]=0;                             //The miss of second player is being stored
				r2[index_2]=255;
				index_2++;
			}
		}
		else
		{
			if(shot_number%2==0)
			{
				g1[index_1]=255;
				index_1++;                                       //Means that first player scored
			}
			else
			{
				g2[index_2]=255;
				index_2++;                                        //Means that second player scored
			}
		}
		++shot_number;
		if(shot_number==10)
		{
			for(individual_shot_number=0;individual_shot_number<5;individual_shot_number++)
			{
				if(player_1[individual_shot_number]==1)
					count1++;                                     //Counting goals for first player
			}
			for(individual_shot_number=0;individual_shot_number<5;individual_shot_number++)
			{
				if(player_2[individual_shot_number]==1)
					count2++;                                     //Counting goals for second player
			}
			Player p1(count1,5-count1,player_1_str2);                         //Sending first player's information to structure
			p1.print_Information();
			Player p2(count2,5-count2,player_2_str2);                         //Sending second player's information to structure
			p2.print_Information();
			p1.compare_performance(p2);
		}
	}
	else if (key == GLUT_KEY_LEFT)
	{
		reset();
		random_number=rand()%2+1;
		state_of_ball=1;
		if(random_number==2)
		{
			if(shot_number%2==0)
			{
				player_1[index_1]=0;
				r1[index_1]=255;
				index_1++;
			}
			else
			{
				player_2[index_2]=0;
				r2[index_2]=255;
				index_2++;
			}
		}
		else
		{
			if(shot_number%2==0)
			{
				g1[index_1]=255;
				index_1++;
			}
			else
			{
				g2[index_2]=255;
				index_2++;
			}
		}
		++shot_number;
		if(shot_number==10)
		{
			for(individual_shot_number=0;individual_shot_number<5;individual_shot_number++)
			{
				if(player_1[individual_shot_number]==1)
					count1++;
			}
			for(individual_shot_number=0;individual_shot_number<5;individual_shot_number++)
			{
				if(player_2[individual_shot_number]==1)
					count2++;
			}
			Player p1(count1,5-count1,player_1_str2);
			p1.print_Information();
			Player p2(count2,5-count2,player_2_str2);
			p2.print_Information();
			p1.compare_performance(p2);
		}
	}
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_HOME)
	{
		random_number=0;
		reset();
	}
}


int main()
{
	srand(time(NULL));
	if(music)
		PlaySound("SamFenderPlayGodDemoLatbizRingtone.wav",NULL,SND_LOOP | SND_ASYNC);
	iInitialize(screen_width, screen_height, "Penalty Shoot Out");
	UI_var_image = iLoadImage("Images//UI.jpg") ;
	football_image = iLoadImage("Images//Untitled.png");
	background_image = iLoadImage("Images//Goal Bars.jpg");
	initial_goalkeeper_image = iLoadImage("Images//keeperZero.png");
	left_dive_image = iLoadImage("Images//keeperOne1.png");
	right_dive_image = iLoadImage("Images//keeperTwo2.png");
	about_image=iLoadImage("Images//About.jpg");
	help_image=iLoadImage("Images//Help.jpg");
	game_over_image = iLoadImage( "Images//GameOver.png" ) ;
	iStart();
	return 0;
}

