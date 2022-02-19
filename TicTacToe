
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <stdlib.h>
#define SPACE ' '
using namespace std;
char Matrix[5][5]=
{
    SPACE,SPACE,SPACE,SPACE,SPACE,
    SPACE,SPACE,SPACE,SPACE,SPACE,
    SPACE,SPACE,SPACE,SPACE,SPACE,
    SPACE,SPACE,SPACE,SPACE,SPACE,
    SPACE,SPACE,SPACE,SPACE,SPACE,
};

void Display();
void Player_Move(char);
void PC_Move();
char Check();


int main()

{
    system("clear");
    srand(static_cast<unsigned int>(time(0)));
    int Game=0;
    int Count=0;
    char Winner=SPACE;
    char Answer=SPACE;
    
    do
    {
        cout<<"---Tic Tac Toe---"<<endl;
        cout<<R"(Choose type of Game:
1 - Single Player (against PC)
2 - Multiplayer (against player)
3 - Quit
)";
        do {
            cin>>Game;
            if(Game<0||Game>4)cout<<"Incorrect input! Try again! "<<endl;
        } while (Game<0||Game>4);
        if(Game==0)break;
        system("clear");
        if(Game==1)cout<<"Single player!"<<endl;
        else cout<<"Multiplayer"<<endl;
        do
        {
           
            Display();
            Player_Move('X');
            Count++;
            if(Count>=5)Winner=Check();
            if(Winner!=SPACE)break;
            if (Count==25)break;
            if(Game==1)PC_Move();
            else
            {
                Display();
                Player_Move('0');
            }
            Count++;
            if(Count>=6)Winner=Check();
            
        } while (Winner==SPACE);
        Display();
        if(Winner!=SPACE)cout<<Winner<<" won!"<<endl;
        else cout<<"A tie!"<<endl;
        cout<<"Do you want to play aagain? Y/N? ";cin>>Answer;
        if (Answer=='Y'|| Answer=='y')
        {
            for(int i=0; i<5; i++)
            {
                for (int j=0; j<5; j++)
                {
                    Matrix[i][j]=SPACE;
                }
            }
            
            Winner=SPACE;
            system("clear");
        }
        else Game=0;
        
    }while(Game!=0);
    system( "read -n 1 -s -p \"Press any key to continue...\"" );

    
   
    return 0;
}

void Display()
{
    for (int i=0; i<5; i++)
    {
        cout<<" "<<Matrix[i][0]<<" | "<<Matrix[i][1]<<" | "<<Matrix[i][2]<<" | "<<Matrix[i][3]<<" | "<<Matrix[i][4]<<endl;
        if(i!=4)cout<<"---|---|---|---|---"<<endl;
    }
    
}
void Player_Move(char Symbol) /
{
    int x=0, y=0;
    do
    {
        cout<<"Select a location to place an "<<Symbol<<" ?"<<endl;
        cout<<"Which row: "; cin>>x;
        cout<<"Which column: "; cin>>y;
        x--; y--;
        if(x<0||x>4||y<0||y>4)cout<<"Incorrect input! Try again!"<<endl;
        else
            if(Matrix[x][y]!=SPACE)cout<<"This space is taken! Try again: "<<endl;
    }while(x<0||x>4||y<0||y>4||Matrix[x][y]!=SPACE );
    Matrix[x][y]=Symbol;
    
}
void PC_Move()
{
    int i=0, j=0;
    do
    {
        i=rand()%5;
        j=rand()%5;
        
    }while(Matrix[i][j]!=SPACE);
    cout<<" PC move: "<<i+1<<";"<<j+1<<endl;
    Matrix[i][j]='0';
}
char Check()
{
  
    for(int i=0;i<5;i++)
    {
        if(Matrix[i][0]==Matrix[i][1]&&Matrix[i][1]==Matrix[i][2]&&Matrix[i][0]!=SPACE)return Matrix[i][0];
        if(Matrix[i][1]==Matrix[i][2]&&Matrix[i][2]==Matrix[i][3]&&Matrix[i][1]!=SPACE)return Matrix[i][1];
        if(Matrix[i][2]==Matrix[i][3]&&Matrix[i][3]==Matrix[i][4]&&Matrix[i][2]!=SPACE)return Matrix[i][2];
    }
    for(int j=0;j<5;j++)
    {
        if(Matrix[0][j]==Matrix[1][j]&&Matrix[1][j]==Matrix[2][j]&&Matrix[0][j]!=SPACE)return Matrix[0][j];
        if(Matrix[1][j]==Matrix[2][j]&&Matrix[2][j]==Matrix[3][j]&&Matrix[1][j]!=SPACE)return Matrix[1][j];
        if(Matrix[2][j]==Matrix[3][j]&&Matrix[3][j]==Matrix[4][j]&&Matrix[2][j]!=SPACE)return Matrix[2][j];
    }
    if(Matrix[0][0]==Matrix[1][1]&&Matrix[1][1]==Matrix[2][2])return Matrix[2][2];
    if(Matrix[1][1]==Matrix[2][2]&&Matrix[2][2]==Matrix[3][3])return Matrix[3][3];
    if(Matrix[2][2]==Matrix[3][3]&&Matrix[3][3]==Matrix[4][4])return Matrix[4][4];
    
    if(Matrix[0][4]==Matrix[1][3]&&Matrix[1][3]==Matrix[2][2])return Matrix[2][2];
    if(Matrix[1][3]==Matrix[2][2]&&Matrix[2][2]==Matrix[3][1])return Matrix[3][1];
    if(Matrix[2][2]==Matrix[3][1]&&Matrix[3][1]==Matrix[4][0])return Matrix[4][0];
    return SPACE;
}
