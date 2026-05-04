/// C++ source code

#include <iostream>
#include <cstdlib>
using namespace std;

int num1, num2, num3, num4, g1, g2, g3, g4, x, cgame, cguess, A, B;
char c1, c2, c3;

int attempt{0};
bool gameongoing = 1;
bool wrong = 1;

int main() //1A2B
{
    cout<<"welcome to 1A2B!\nPlease enter 4 number in correct form.\ne.g.:2, 5, 1, 7"<<endl<<endl;
    srand((unsigned) time(NULL));
    bool NOTOK = 1;
    
    while(NOTOK)
    {
        num1 = rand()%10;num2 = rand()%10;num3 = rand()%10;num4 = rand()%10;
        if(num1==num2||num1==num3||num1==num4||num2==num3||num2==num4||num3==num4)
        {}else{
            NOTOK = 0;
        }
    }
    int game[1][4] = { {num1, num2, num3, num4} };
    
    while(gameongoing)
    {
        wrong = 1;
        while(wrong) //input and output
        {
            cout<<"enter four number in sequence"<<endl;
            cin>>g1>>c1>>g2>>c2>>g3>>c3>>g4;
            if(!(c1==c2&&c2==c3)||c1!=',')
            {
                cout<<"did you forgot to type the comma ?"<<endl;
                wrong = 1;
            }else if(g1==g2||g1==g3||g1==g4||g2==g3||g2==g4||g3==g4){
                cout<<"you can not enter the same number!"<<endl;
                wrong = 1;
                }else{
                A = 0;B = 0;
                //cout<<"right order"<<endl;
                int guess[1][4] = { {g1, g2, g3, g4} };
                wrong = 0;
                for(x=0;x<4;x++)
                {
                    if(game[0][x] == guess[0][x]) A++;
                }
                for(cguess=0;cguess<4;cguess++)
                {
                    for(cgame=0;cgame<4;cgame++)
                    {
                        if((guess[0][cguess]==game[0][cgame]&&cguess!=cgame))
                        {
                            B++;
                            break;
                        }
                    }
                }
                cout<<">>>>>Your answer: "<<A<<"A"<<B<<"B"<<endl;
                if(A==4)
                {
                    gameongoing==0;
                    cout<<"you won! Congratulations!"<<endl;
                }
            }
        }
        attempt++;
        cout<<"total attempts: "<<attempt<<endl<<endl;
        if(A==4) return 0;
    }
    return 0;
}
