#include <wiringPi.h>
#include <stdio.h>

#define max 5

#define H1 6
#define H2 27
#define H3 13
#define H4 31
#define H5 25
#define H6 14
#define H7 24
#define H8 21

#define L1 26
#define L2 23
#define L3 22
#define L4 10
#define L5 30
#define L6 11
#define L7 18
#define L8 29

int row[8] = {L1,L2,L3,L4,L5,L6,L7,L8};
int col[8] = {H1,H2,H3,H4,H5,H6,H7,H8};

unsigned char table1 [8][8] =
{
 	1,1,1,1,1,1,1,1,
 	1,0,0,0,0,0,0,1,
 	1,0,0,0,0,0,0,1,
 	1,0,0,0,0,0,0,1,
 	1,0,0,0,0,0,0,1,
 	1,0,0,0,0,0,0,1,
 	1,0,0,0,0,0,0,1,
 	1,1,1,1,1,1,1,1,
};

unsigned char table2 [8][8] =
{
	0,0,0,0,0,0,0,0,
	0,1,1,1,1,1,1,0,
	0,1,0,0,0,0,1,0,
	0,1,0,0,0,0,1,0,
	0,1,0,0,0,0,1,0,
	0,1,0,0,0,0,1,0,
	0,1,1,1,1,1,1,0,
	0,0,0,0,0,0,0,0,
};

unsigned char table3 [8][8] =
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,1,1,1,1,0,0,
	0,0,1,0,0,1,0,0,
	0,0,1,0,0,1,0,0,
	0,0,1,1,1,1,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};

unsigned char table4 [8][8] =
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,1,1,0,0,0,
	0,0,0,1,1,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};

void clear_matrix()
{
	for(int i=0; i<8; i++)
	{
		digitalWrite(row[i],HIGH);
		digitalWrite(col[i],LOW);
	}
}

void display_matrix(unsigned char dat [8][8])
{
	for(int j=0; j<8; j++)
	{
		digitalWrite(row[j],LOW);
		for(int i=0; i<8; i++)
		{
		digitalWrite(col[i],dat[i][j]);
		}
		delay(1);
		clear_matrix();
	}
}

void setup()
{
	for(int i=0; i<8; i++)
	{
		pinMode(row[i],OUTPUT);
		pinMode(col[i],OUTPUT);
	}
}

void loop() 
{
	for(int i=0; i<max; i++)
	{
		display_matrix(table1);
	
	}
	for(int i=0;i<max;i++)
	{
		display_matrix(table2);
	}
	for (int i= 0; i<max;i++)
	{
		display_matrix(table3);
	}
	for (int i=0;i<max;i++)
	{
		display_matrix(table4);
	}
}

int main(void)
{
	printf("welcome to Elecrow...\n");
	printf("Raspberry Pi blink program...\n");
	printf("press Ctlr + C to exit \n");

	wiringPiSetup();
	setup();
	while(1)
	{
		loop();
	}
}
