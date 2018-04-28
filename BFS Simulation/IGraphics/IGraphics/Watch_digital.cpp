#include "iGraphics.h"
#include <math.h>
#include <time.h>
#include <stdio.h>

double o,x=500,y=360+250,sx,sy,p;
double xm=500,ym=360+220,mx,my,pm;
double xh=500,yh=360+200,hx,hy,ph,H,M,S;
int i,sec,min,hor,secd,mind,hord,secs,mins,hors,check;

int second()
 
{
	time_t rawtime;
    tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );   //getting time from bios

   H=((((ptm->tm_hour+6)%24)-1)%12)+1;
	M=ptm->tm_min;
	S=(ptm->tm_sec);
	return S;
}

int minute()
 
{
	time_t rawtime;
    tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );   //getting time from bios

    H=((((ptm->tm_hour+6)%24)-1)%12)+1;
	M=ptm->tm_min;
	S=(ptm->tm_sec);
	return M;
}

int hour()
 
{
	time_t rawtime;
    tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );   //getting time from bios

    H=((((ptm->tm_hour+6)%24)-1)%12)+1;
	return H;
}

int am_pm()
{
	time_t rawtime;
    tm * ptm;

    time ( &rawtime );

    ptm = gmtime ( &rawtime );   //getting time from bios

    H=(ptm->tm_hour+6)/12;
	return H;
}


void iDraw()
{
	iClear();

	iSetColor(0,255,255);
	iFilledRectangle(250+20,415,50,10);//hd1
	iFilledRectangle(240+20,365,10,50);//hd2
	iFilledRectangle(300+20,365,10,50);//hd3
	iFilledRectangle(250+20,355,50,10);//hd4
	iFilledRectangle(240+20,305,10,50);//hd5
	iFilledRectangle(300+20,305,10,50);//hd6
	iFilledRectangle(250+20,295,50,10);//hd7

	iFilledRectangle(335+20,415,50,10);//hu1
	iFilledRectangle(325+20,365,10,50);//hu2
	iFilledRectangle(385+20,365,10,50);//hu3
	iFilledRectangle(335+20,355,50,10);//hu4
	iFilledRectangle(325+20,305,10,50);//hu5
	iFilledRectangle(385+20,305,10,50);//hu6
	iFilledRectangle(335+20,295,50,10);//hu7

	
	iFilledRectangle(435+20,415,50,10);//md1
	iFilledRectangle(425+20,365,10,50);//md2
	iFilledRectangle(485+20,365,10,50);//md3
	iFilledRectangle(435+20,355,50,10);//md4
	iFilledRectangle(425+20,305,10,50);//md5
	iFilledRectangle(485+20,305,10,50);//md6
	iFilledRectangle(435+20,295,50,10);//md7

	iFilledRectangle(520+20,415,50,10);//mu1
	iFilledRectangle(510+20,365,10,50);//mu2
	iFilledRectangle(570+20,365,10,50);//mu3
	iFilledRectangle(520+20,355,50,10);//mu4
	iFilledRectangle(510+20,305,10,50);//mu5
	iFilledRectangle(570+20,305,10,50);//mu6
	iFilledRectangle(520+20,295,50,10);//mu7

	iFilledRectangle(435+185+20,415,50,10);//sd1
	iFilledRectangle(425+185+20,365,10,50);//sd2
	iFilledRectangle(485+185+20,365,10,50);//sd3
	iFilledRectangle(435+185+20,355,50,10);//sd4
	iFilledRectangle(425+185+20,305,10,50);//sd5
	iFilledRectangle(485+185+20,305,10,50);//sd6
	iFilledRectangle(435+185+20,295,50,10);//sd7

	iFilledRectangle(520+185+20,415,50,10);//su1
	iFilledRectangle(510+185+20,365,10,50);//su2
	iFilledRectangle(570+185+20,365,10,50);//su3
	iFilledRectangle(520+185+20,355,50,10);//su4
	iFilledRectangle(510+185+20,305,10,50);//su5
	iFilledRectangle(570+185+20,305,10,50);//su6
	iFilledRectangle(520+185+20,295,50,10);//su7

	iFilledRectangle(405+20,380,10,10);//between hour and minute
	iFilledRectangle(405+20,330,10,10);

	iFilledRectangle(590+20,380,10,10);//between second and minute
	iFilledRectangle(590+20,330,10,10);

	iFilledRectangle(515+310,360,25,5);//A1
	iFilledRectangle(510+310,335,5,25);//A2
	iFilledRectangle(540+310,335,5,25);//A3
	iFilledRectangle(515+310,330,25,5);//A4
	iFilledRectangle(510+310,305,5,25);//A5
	iFilledRectangle(540+310,305,5,25);//A6

	iFilledRectangle(555+310,360,15,5);//M1
	iFilledRectangle(550+310,335,5,25);//M2
	iFilledRectangle(570+310,335,5,25);//M3
	iFilledRectangle(550+310,305,5,25);//M5
	iFilledRectangle(575+310,360,15,5);//M1
	iFilledRectangle(590+310,335,5,25);//M3
	iFilledRectangle(590+310,305,5,25);//M6

	iSetColor(0,0,0);
	sec=second();
	min=minute();
	hor=hour();
	secd=sec/10;
	secs=sec%10;
	mind=min/10;
	mins=min%10;
	hord=hor/10;
	hors=hor%10;
	//for decimal point of hour
	if(hord==0){
		iFilledRectangle(250+20,415,50,10);//hd1
		iFilledRectangle(240+20,365,10,50);//hd2
		iFilledRectangle(300+20,365,10,50);//hd3
		iFilledRectangle(250+20,355,50,10);//hd4
		iFilledRectangle(240+20,305,10,50);//hd5
		iFilledRectangle(300+20,305,10,50);//hd6
		iFilledRectangle(250+20,295,50,10);//hd7
	}
	else if(hord==1){
		iFilledRectangle(250+20,415,50,10);//hd1
		iFilledRectangle(240+20,365,10,50);//hd2
		iFilledRectangle(250+20,355,50,10);//hd4
		iFilledRectangle(240+20,305,10,50);//hd5
		iFilledRectangle(250+20,295,50,10);//hd7
	}

	//for unimal point of hour
	if(hors==1||hors==4){
		iFilledRectangle(335+20,415,50,10);//hu1
	}
	if(hors==1||hors==2||hors==3||hors==7){
		iFilledRectangle(325+20,365,10,50);//hu2
	}
	if(hors==5||hors==6){
		iFilledRectangle(385+20,365,10,50);//hu3
	}
	if(hors==0||hors==1||hors==7){
		iFilledRectangle(335+20,355,50,10);//hu4
	}
	if(hors==1||hors==3||hors==4||hors==5||hors==7||hors==9){
		iFilledRectangle(325+20,305,10,50);//hu5
	}
	if(hors==2){
		iFilledRectangle(385+20,305,10,50);//hu6
	}
	if(hors==1||hors==4||hors==7){
		iFilledRectangle(335+20,295,50,10);//hu7
	}

	//for decimal point of minute

	if(mind==1||mind==4){
		iFilledRectangle(435+20,415,50,10);//md1
	}
	if(mind==1||mind==2||mind==3){
		iFilledRectangle(425+20,365,10,50);//md2
	}
	if(mind==5||mind==6){
		iFilledRectangle(485+20,365,10,50);//md3
	}
	if(mind==0||mind==1){
		iFilledRectangle(435+20,355,50,10);//md4
	}
	if(mind==1||mind==3||mind==4||mind==5){
		iFilledRectangle(425+20,305,10,50);//md5
	}
	if(mind==2){
		iFilledRectangle(485+20,305,10,50);//md6
	}
	if(mind==1||mind==4){
		iFilledRectangle(435+20,295,50,10);//md7
	}

	//unimal point of minute

	if(mins==1||mins==4){
		iFilledRectangle(520+20,415,50,10);//mu1
	}
	if(mins==1||mins==2||mins==3||mins==7){
		iFilledRectangle(510+20,365,10,50);//mu2
	}
	if(mins==5||mins==6){
		iFilledRectangle(570+20,365,10,50);//mu3
	}
	if(mins==0||mins==1||mins==7){
		iFilledRectangle(520+20,355,50,10);//mu4
	}
	if(mins==1||mins==3||mins==4||mins==5||mins==7||mins==9){
		iFilledRectangle(510+20,305,10,50);//mu5
	}
	if(mins==2){
		iFilledRectangle(570+20,305,10,50);//mu6
	}
	if(mins==1||mins==4||mins==7){
		iFilledRectangle(520+20,295,50,10);//mu7
	}

	//for decimal point of second
	
	if(secd==1||secd==4){
		iFilledRectangle(435+185+20,415,50,10);//sd1
	}
	if(secd==1||secd==2||secd==3){
		iFilledRectangle(425+185+20,365,10,50);//sd2
	}
	if(secd==5||secd==6){
		iFilledRectangle(485+185+20,365,10,50);//sd3
	}
	if(secd==0||secd==1){
		iFilledRectangle(435+185+20,355,50,10);//sd4
	}
	if(secd==1||secd==3||secd==4||secd==5){
		iFilledRectangle(425+185+20,305,10,50);//sd5
	}
	if(secd==2){
		iFilledRectangle(485+185+20,305,10,50);//sd6
	}
	if(secd==1||secd==4){
		iFilledRectangle(435+185+20,295,50,10);//sd7
	}

	//for unimal point of second
	if(secs==1||secs==4){
		iFilledRectangle(520+185+20,415,50,10);//su1
	}
	if(secs==1||secs==2||secs==3||secs==7){
		iFilledRectangle(510+185+20,365,10,50);//su2
	}
	if(secs==5||secs==6){
		iFilledRectangle(570+185+20,365,10,50);//su3
	}
	if(secs==0||secs==1||secs==7){
		iFilledRectangle(520+185+20,355,50,10);//su4
	}
	if(secs==1||secs==3||secs==4||secs==5||secs==7||secs==9){
		iFilledRectangle(510+185+20,305,10,50);//su5
	}
	if(secs==2){
		iFilledRectangle(570+185+20,305,10,50);//su6
	}
	if(secs==1||secs==4||secs==7){
		iFilledRectangle(520+185+20,295,50,10);//su7
	}

	//blinking
	if(secs %2 != 0){
		
		iFilledRectangle(405+20,380,10,10);//between hour and minute
		iFilledRectangle(405+20,330,10,10);

		iFilledRectangle(590+20,380,10,10);//between second and minute
		iFilledRectangle(590+20,330,10,10);
	} 
	//am/pm
	check = am_pm();
	if( check == 1){
		iFilledRectangle(540+310,305,5,25);//A6
	}
}

void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
			
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		
	}
}


void iKeyboard(unsigned char key)
{
	if(key == 'A'||key== 'a')
	{
		
	}
	else if(key == 'D'||key== 'd')
	{
		
	}
	
}


void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
}

int main(){

	iInitialize(1200,720, "Digital");
	return 0;
}