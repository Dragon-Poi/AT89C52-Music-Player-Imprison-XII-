#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"

sbit Buzzer = P2^5;

#define SPEED		300

#define P	0
#define C3	1
#define C3_	2
#define D3	3
#define D3_	4
#define E3	5
#define F3	6
#define F3_	7
#define G3	8
#define G3_	9
#define A3	10
#define A3_	11
#define B3	12
#define C4	13
#define C4_	14
#define D4	15
#define D4_	16
#define E4	17
#define F4	18
#define F4_	19
#define G4	20
#define G4_	21
#define A4	22
#define A4_	23
#define B4	24
#define C5	25
#define C5_	26
#define D5	27
#define D5_	28
#define E5	29
#define F5	30
#define F5_	31
#define G5	32
#define G5_	33
#define A5	34
#define A5_	35
#define B5	36

unsigned int code FreqTable[] = {0,63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,
	64463,64528,64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,
	65030,65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283,
};

/*
16分音符 1
8分音符  2
4分音符  4
2分音符  8
*/

unsigned int code Music[] = {
	C4,2,
	
	G4,6,
	D4,10,
	E4,2,
	
	D4,2,
	C4,2,
	C4,8,
	P,2,
	C4,2,

	G4,6,
	D4,10,
	E4,2,
	
	D4,2,
	C4,2,
	E4,8,
	P,2,
	E4,2,
	
	C5,6,
	B4,6,
	A4,6,
	
	G4,2,
	F4,2,
	E4,8,
	P,2,
	E4,2,
	
	D4,12,
	P,1,
	D4,2,
	C4,2,
	
	B3,12,
	P,2,
	C4,2,
	
	G4,6,
	D4,10,
	E4,2,
	
	D4,2,
	C4,2,
	C4,8,
	P,2,
	C4,2,
	
	G4,6,
	D4,10,
	E4,2,
	
	D4,2,
	C4,2,
	E4,8,
	P,2,
	E4,2,
	
	C5,6,
	B4,6,
	A4,6,
	
	G4,2,
	F4,2,
	E4,8,
	P,2,
	E4,2,
	
	D4,12,
	P,2,
	E4,2,
	
	F4,6,
	G4,6,
	C4,6,
	
	B4,16,
	A4,2,
	
	G4,12,
	E4,2,
	D4,2,
	C4,2,
	
	F4,6,
	E4,6,
	B3,6,
	
	C4,12,
	C4,6,
	
	B4,14,
	B4,2,
	C5,2,
	
	G4,12,
	E4,2,
	D4,2,
	C4,2,
	
	F4,6,
	E4,6,
	F4,6,
	
	G4,8,
	P,1,
	G4,2,
	D5,2,
	B4,2,
	
	C5,14,
	P,1,
	B4,2,

	C5,14,
	P,1,
	B4,2,

	C5,14,
	P,1,
	D5,2,
	
	E5,14,
	D5,2,
	C5,6,
	
	C5,10,
	B4,2,
	G4,6,
	
	G4,12,
	E4,2,
	
	F4,2,
	F4,2,
	E4,2,
	F4,2,
	F4,2,
	E4,2,
	F4,2,
	F4,2,
	E4,2,
	
	G4,8,
	P,1,
	G4,2,
	D5,4,
	B4,2,
	
	C5,14,
	P,1,
	B4,2,
	
	C5,14,
	P,1,
	B4,2,
	
	C5,14,
	P,1,
	D5,2,
	
	E5,10,
	F5,2,
	E5,4,
	D5,2,
	
	C5,4,
	C5,6,
	B4,2,
	C5,4,
	B4,2,
	
	C5,4,
	B4,2,
	G4,8,
	P,1,
	E4,2,
	
	F4,4,
	E4,2,
	F4,4,
	E4,2,
	D4,4,
	C4,2,
	
	C4,16,
	0xFF
};
	
unsigned int FreqSelect,MusicSelect;

void main(){
	Timer0Init();
	while(1){
		if(Music[MusicSelect]!=0xFF){
			FreqSelect = Music[MusicSelect];
			MusicSelect++;
			Delay(SPEED/4*Music[MusicSelect]);
			MusicSelect++;
			TR0 = 0;
			Delay(5);
			TR0 = 1;
		}
		else{
			TR0 = 0;
			while(1);
		}
	}
}

void Timer0_Rountine() interrupt 1{
	if(FreqTable[FreqSelect]){
		TL0 = FreqTable[FreqSelect]%256;		//设置定时初值
		TH0 = FreqTable[FreqSelect]/256;		//设置定时初值
		Buzzer =! Buzzer;
	}
}
