#include <iostream>
#include <cstdlib>
#include <graphics.h>

using namespace std;

int x1coord[110];
int x2coord[110];
int ycoord[5];

int destroyedX[5][22], l1 = 0, l2 = 0, l3 = 0, l4 = 0, l5 = 0;

void bricks();
int checkCollision(int &x1, int &y1, int &r);
int beginGame();
void startScreen();
void gameOver(int s);

int main() // main
{
	initwindow(800,600, "brick breaker");
    
    startScreen();
    
    return 0;    
}

void startScreen()
{
	cleardevice();
	setcolor(WHITE);
    outtextxy(350,285," _____    _____ ");
    outtextxy(350,305,"|          |  |          |");
    outtextxy(350,320,"| <---    |  |    ---> |");
	outtextxy(350,335,"|_____|  |_____|");
	
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
	outtextxy(320, 500, "Press any key to begin");
    
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
	outtextxy(250, 200, "BRICK BREAKER");
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);       
    
    getch();
    cleardevice();
    bricks();
    
    beginGame();
}
void gameOver(int s)
{
	cleardevice();
	setcolor(WHITE);
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
	outtextxy(250,200,"    * * * * *    * * * * *    *        *   * * * * *");
    outtextxy(250,210,"   *               *         *    * *  * *   *        ");
    outtextxy(250,220,"  *   * * *     * * * * *    *   *   *   * * *    ");
    outtextxy(250,230," *   *    *    *         *    *        *   *        ");
    outtextxy(250,240,"* * *   *    *         *    *        *   * * * * *");
    outtextxy(250,270,"    * * * * *   *    *   * * * * *     * * * * *         ");
    outtextxy(250,280,"   *        *    *   *    *               *        *      ");
    outtextxy(250,290,"  *        *     *  *    * * *         *  *  *          ");
    outtextxy(250,300," *        *      * *    *              *        *       ");
    outtextxy(250,310,"* * * * *       *      * * * * *    *           *      ");
    
    char q[10];
	itoa(s,q, 10);
	
	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    outtextxy(350, 400, "Score: ");
    outtextxy(400, 400, q);
    
    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
    outtextxy(300, 500, "To play again hit space");
    
	int c = getch();
    
    if(c == 32) // space bar
    {
    	cleardevice();
    	startScreen();
	}
}
void bricks()
{
	int clr[5] = {BLUE, GREEN, RED, BROWN, WHITE};
	int i, j, x = 10, y = 20 ;

	for ( i = 0 ; i < 5 ; i++ )  
	{
		for ( j = 0 ; j < 22 ; j++ )  
		{
			setcolor(clr[i]);
			rectangle ( x, y, x + 31, y + 9 ) ;
			
			x1coord[j] = x;
			x2coord[j] = x+31;
			
			x += 35 ;					
		}
		ycoord[i] = y;
		x = 10 ;
		y +=  20 ;
	}	
}

int checkCollision(int &x1, int &y1, int &r)
{
	int tmpX=-1;
	
	for(int i = 0; i < 22; i++) // for coord of box touching the circle
	{
		if(x1 > x1coord[21]) // for when the circle is touching right most box
		{
			tmpX = x1coord[21];
			break;
		
		}
		if(x1 > x1coord[i])
		{				
			if(x1 < x2coord[i])			
			{
				tmpX = x1coord[i];
				break;
			}
		}
		if(x1 < x2coord[0]) // for left most box
		{
			tmpX = x1coord[0];
			break;
		}								
	}
			
	if(y1-r<=ycoord[0]) // ROW 1
	{
		
		for(int i = 0; i <22;i++)
		{
			if(destroyedX[0][i] == tmpX)
				return 0;						
		}
		setcolor(BLACK);
		rectangle(tmpX, ycoord[0], tmpX+31, ycoord[0]+9); // destroy brick		
		
		destroyedX[0][l1] = tmpX;
		l1++;
				
		return 1;
	}
	else if(y1-r<=ycoord[1] && y1-r >= ycoord[0]) // ROW 2
	{
		for(int i = 0; i <22;i++)
		{
			if(destroyedX[1][i] == tmpX)
				return 0;						
		}
		setcolor(BLACK);
		rectangle(tmpX, ycoord[1], tmpX+31, ycoord[1]+9); // destroy brick
		
		destroyedX[1][l2] = tmpX;
		l2++;
		
		return 1;
	}
	else if(y1-r<=ycoord[2] && y1-r >= ycoord[1]) // ROW 3
	{
		for(int i = 0; i <22;i++)
		{
			if(destroyedX[2][i] == tmpX)
				return 0;						
		}
		setcolor(BLACK);
		rectangle(tmpX, ycoord[2], tmpX+31, ycoord[2]+9); // destroy brick
		
		destroyedX[2][l3] = tmpX;
		l3++;
		
		return 1;
	}
	else if(y1-r<=ycoord[3] && y1-r >= ycoord[2]) // ROW 4
	{
		for(int i = 0; i <22;i++)
		{
			if(destroyedX[3][i] == tmpX)
				return 0;						
		}
		setcolor(BLACK);
		rectangle(tmpX, ycoord[3], tmpX+31, ycoord[3]+9); // destroy brick
		
		destroyedX[3][l4] = tmpX;
		l4++;
		
		return 1;
	}
	else if(y1-r<=ycoord[4] && y1-r >= ycoord[3]) // ROW 5
	{
		for(int i = 0; i <22;i++)
		{
			if(destroyedX[4][i] == tmpX)
				return 0;						
		}
		setcolor(BLACK);
		rectangle(tmpX, ycoord[4], tmpX+31, ycoord[4]+9); // destroy brick
		
		destroyedX[4][l5] = tmpX;
		l5++;
		
		return 1;
	}
	else
	{
		return 0;
	}
}

int beginGame() // the main thing of this progrm
{
	int m = 5, n = 5, tmp = 0,
		x = 0, y = 450,
    	x1 = 50, y1 = 420, r = 10;
    char c;
        
    //line(x,y,x+100,y);
    setcolor(WHITE);
	rectangle(x,y,x+100,y+4);    
	setcolor(RED);
    circle(x1,y1,r);
    	
    while(true)
    {
    	delay(30);		   
		setcolor(BLACK);
		circle(x1,y1,r);
			
    	if(kbhit())
      	{
	  	 	c = getch();                   
           	if(c == KEY_LEFT) // movew left
           	{
           	  	if(x > 30)
              	{
			    	delay(20);
                 	setcolor(BLACK);
                 	//line(x,y,x+100,y);                 	
                    rectangle(x,y,x+100,y+4);
					        
                 	setcolor(WHITE);
                 	x -= 35;                 	
              		rectangle(x,y,x+100,y+4);
                	//line(x,y,x+100,y);
              	}
           	}
           
		    if(c == KEY_RIGHT) // m,ove right
            {
                if(x < getmaxx()-125)
				{
					
                	delay(20);
                    setcolor(BLACK);
                    //line(x,y,x+100,y);	
                    rectangle(x,y,x+100,y+4); 
                    
					setcolor(WHITE);
                    x += 35;
                    //line(x,y,x+100,y);
                    rectangle(x,y,x+100,y+4);    
                }
			} 
		}
					
		if(x1 >= getmaxx()-r) // circle is at right-end
			m = -5;
		if(x1 <= r) // circle is at left-end
			m = 5;	
		if(y1 <= r) // circle is at top
			n = 5;				
		if(y1 >= y-r && (x1 >=x && x1 <= x+100)) // circle touching the paddle
		{			
			n = -5;		
		}
		
		///////// FOr Game Over ///////////
		if(y1 >= y)
		{
			cleardevice();
			gameOver(tmp);
			return 0;
		}	
		
		x1 += m;	
		y1 += n;		
		
		///////////// Draw Circle again ////////////
		setcolor(LIGHTGRAY);
		circle(x1,y1,r);  
		
		///////////////////////// CHECK COllisions ////////////////////////////////////
		int lol = checkCollision(x1,y1,r);  			          
        
		if(lol == 1)
        {
           	n=5;
        	tmp++;         	
        	
        	// get score and print
			char q[10];
			itoa(tmp,q, 10);	
			settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 1);
			setcolor(WHITE);
			outtextxy(100,500,q);
		}
 	}
}


