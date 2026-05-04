/// C++ source code

#include <iostream>
using namespace std;

void display();
void inoutput();
int winingdec();

int x, y, tx, ty, gameover;
int step{1};

int game[3][3] = 
    {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

int main() //ooxx
{
    cout<<"welcome to ooxx game!\ngame starts!\n\n"<<endl<<"x for list y for number"<<endl;
    display();
    
    for(step=1;step<=9;step++)
    {
        inoutput();
        display();
        gameover = winingdec();
        if(gameover)
        {
            cout<<"game over!"<<endl;
            return 0;
        }
    }
    cout<<"tie! game over!"<<endl;
    return 0;
}

void display() //display situation
{
    cout<<endl;
    for(x=0;x<=2;x++)
    {
        for(y=0;y<=2;y++)
        {
            if(game[x][y]==0)
            {
                y==2?cout<<"?":cout<<"?|";
            }else if(game[x][y]==1){
                y==2?cout<<"o":cout<<"o|";
            }else if(game[x][y]==2)
                y==2?cout<<"x":cout<<"x|";
        }
        cout<<endl;
    }
}
void inoutput() //detect input and output o or x to the sellected grid
{
    bool ISNTOKAY{1};
    while(ISNTOKAY)
    {
        if(step %2 == 0)
        {
            cout<<"x's turn\nplease sellect a point\nenter the x coordinate of the point"<<endl;
            cin>>tx;tx=tx-1;
            cout<<"enter the y coordinate of the point"<<endl;
            cin>>ty;ty=ty-1;
            if(game[tx][ty]!=0 || tx>3 || tx<1 || ty>3 || ty<1)
            {
                cout<<"this point is not available! please sellect another.\n"<<endl;
            }else{
                cout<<"available"<<endl;
                game[tx][ty]=2;
                ISNTOKAY=0;
            }
        
        }else{
            cout<<"o's turn\nplease sellect a point\nenter the x coordinate of the point"<<endl;
            cin>>tx;tx=tx-1;
            cout<<"enter the y coordinate of the point"<<endl;
            cin>>ty;ty=ty-1;
            if(game[tx][ty]!=0 || tx>3 || tx<1 || ty>3 || ty<1)
            {
                cout<<"this point is not available! please sellect another.\n"<<endl;
            }else{
                game[tx][ty]=1;
                ISNTOKAY=0;
            }
        }
    }
}
int winingdec()
{
    int ix, iy;
    for(ix=0;ix<=2;ix++)
    {
        if(game[ix][0]==game[ix][1]&&game[ix][1]==game[ix][2]&&game[ix][0]!=0)
        {
            if(game[ix][0]==2){cout<<"x win!"<<endl;return 1;}else{cout<<"o win"<<endl;return 1;}
        }
    }
    for(iy=0;iy<=2;iy++)
    {
        if(game[0][iy]==game[1][iy]&&game[1][iy]==game[2][iy]&&game[0][iy]!=0)
        {
            if(game[0][iy]==2){cout<<"x win!"<<endl;return 1;}else{cout<<"o win"<<endl;return 1;}
        }
    }
    if(game[0][0]==game[1][1]&&game[1][1]==game[2][2]&&game[0][0]!=0)
    {
        if(game[0][0]==2){cout<<"x win!"<<endl;return 1;}else{cout<<"o win"<<endl;return 1;}
    }
    if(game[0][2]==game[1][1]&&game[1][1]==game[2][0]&&game[0][2]!=0)
    {
        if(game[0][2]==2){cout<<"x win!"<<endl;return 1;}else{cout<<"o win"<<endl;return 1;}
    }
    return 0;
}

