#ifndef TVBOARD_H_INCLUDED
#define TVBOARD_H_INCLUDED

int r1[5]={0,0,0,0,0},g1[5]={0,0,0,0,0},b1[5]={0,0,0,0,0};
int r2[5]={0,0,0,0,0},g2[5]={0,0,0,0,0},b2[5]={0,0,0,0,0};
char player_1_str2[1000] ;
char player_2_str2[1000] ;

void tvBoard()
{
	iSetColor(r1[0],g1[0],b1[0]); ///1st block of first player
	iFilledRectangle(200,500,50,50);
	iSetColor(255,255,255);
	iRectangle(200,500,50,50);
	iSetColor(r1[1],g1[1],b1[1]); ///2nd block of first player
	iFilledRectangle(250,500,50,50);
	iSetColor(255,255,255);
	iRectangle(250,500,50,50);
	iSetColor(r1[2],g1[2],b1[2]); ///3rd block of first player
	iFilledRectangle(300,500,50,50);
	iSetColor(255,255,255);
	iRectangle(300,500,50,50);
	iSetColor(r1[3],g1[3],b1[3]); ///4th block of first player
	iFilledRectangle(350,500,50,50);
	iSetColor(255,255,255);
	iRectangle(350,500,50,50);
	iSetColor(r1[4],g1[4],b1[4]); ///5th block of first player
	iFilledRectangle(400,500,50,50);
	iSetColor(255,255,255);
	iRectangle(400,500,50,50);
	iSetColor(127,255,0);
	iText(287,565,player_1_str2,GLUT_BITMAP_TIMES_ROMAN_24);///Name of the first player
	iSetColor(r2[0],g2[0],b2[0]);///1st block of second player
	iFilledRectangle(1000,500,50,50);
	iSetColor(255,255,255);
	iRectangle(1000,500,50,50);
	iSetColor(r2[1],g2[1],b2[1]);///2nd block of second player
	iFilledRectangle(1050,500,50,50);
	iSetColor(255,255,255);
	iRectangle(1050,500,50,50);
	iSetColor(r2[2],g2[2],b2[2]);///3rd block of second player
	iFilledRectangle(1100,500,50,50);
	iSetColor(255,255,255);
	iRectangle(1100,500,50,50);
	iSetColor(r2[3],g2[3],b2[3]);///4th block of second player
	iFilledRectangle(1150,500,50,50);
	iSetColor(255,255,255);
	iRectangle(1150,500,50,50);
	iSetColor(r2[4],g2[4],b2[4]);///5th block of second player
	iFilledRectangle(1200,500,50,50);
	iSetColor(255,255,255);
	iRectangle(1200,500,50,50);
	iSetColor(127,255,0);
	iText(1087,565,player_2_str2,GLUT_BITMAP_TIMES_ROMAN_24);///Name of the second player
}

#endif // !PLAYER_H_INCLUDED
