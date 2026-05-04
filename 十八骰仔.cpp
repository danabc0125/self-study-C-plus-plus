/// C++ source code

#include <iostream>
#include <random>
using namespace std;

int banker{0}, nop, minbet;

class player{
public:
    string name;
    int balance{0}, bet, point;
    
    player(string n, int p, int b=0){
        name=n;
        point=p;
        balance=b;
    }
};

vector<player> players;

class game{
public:
int r{0}, dice1, dice2, dice3, dice4; // "nof" represents "number of players"
//int dice();
};
int dice(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 6);
    return dist(gen);
    //void display();
}
int compare(int d1, int d2, int d3, int d4) {

    if(d1==d2&&d2==d3&&d3==d4) {
        return d1 + 12;
    }

    if((d1==d2&&d2==d3)||(d1==d2&&d2==d4)||(d1==d3&&d3==d4)||(d2==d3&&d3==d4)){
        return 0;
    }

    if(d1!=d2&&d1!=d3&&d1!=d4&&d2!=d3&&d2!= d4&&d3!=d4){
        return 0;
    }

    if((d1==d2&&d3==d4)||(d1==d3&&d2==d4)||(d1==d4&&d2==d3)){
        return max(d1, d3)*2;
    }

    if (d1==d2) return d3+d4;
    if (d1==d3) return d2+d4;
    if (d1==d4) return d2+d3;
    if (d2==d3) return d1+d4;
    if (d2==d4) return d1+d3;
    if (d3==d4) return d1+d2;

    return 0;
}
void display(int j){
    cout<<"......displaying player's balance......"<<endl;
    for(int k=0;k<j;k++){
        cout<<">>> "<<players[k].name<<"'s balance : "<<players[k].balance<<endl;
    }
    cout<<"......complete......"<<endl<<endl;
}

int main()
{
    game game;
    string playername;
    cout<<"how many players?"<<endl;
    cin>>nop;
    for(int i{0};i<nop;i++)
    {
        cout<<"player "<<i+1<<"'s name :";
        cin>>playername;
        players.push_back(player(playername, 0, 0));
    }
    cout<<endl;
    for(int i{0};i<nop;i++)
    {
        cout<<"enter "<<players[i].name<<"'s balance : ";
        cin>>players[i].balance;
    }
    cout<<"enter the min. of the bet : ";
    cin>>minbet;
    display(nop);
    cout<<"##game starts!"<<endl;
    ///////////////////////////////////////////////////////////////////////
    string Y;
    do
    {
        int t1, t2, t3, t4, tbet, tpoint;
        bool NOTOK;
        cout<<"#new round!"<<endl;
        banker=(banker+1)%nop;
        display(nop);
        cout<<"banker is "<<players[banker].name<<endl;
        for(int i{0};i<nop;i++)
        {
            if(i!=banker)
            {
                NOTOK=1;
                while(NOTOK){
                    cout<<"please place your bet("<<players[i].name<<") : ";
                    cin>>tbet;
                    if(tbet<0||tbet<minbet)
                    {
                        cout<<"bet is too less!"<<endl;
                    }else{
                        players[i].bet=tbet;
                        NOTOK=0;
                    }
                }
            }else{
            }
        }
        NOTOK=1;
        while(NOTOK)
        {
            t1=dice();
            t2=dice();
            t3=dice();
            t4=dice();
            tpoint=compare(t1, t2, t3, t4);
            if(tpoint!=0)
            {
                players[banker].point=tpoint;
                NOTOK=0;
            }else{
            }
        }
        cout<<"banker's dices : "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
        for(int i{0};i<nop;i++)
        {
            if(i!=banker)
            {
                NOTOK=1;
                while(NOTOK){
                    t1=dice();
                    t2=dice();
                    t3=dice();
                    t4=dice();
                    tpoint=compare(t1, t2, t3, t4);
                    if(tpoint==0)
                    {}else{
                        players[i].point=tpoint;
                        NOTOK=0;
                        cout<<players[i].name<<"'s dices are : "<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
                        if(players[i].point>players[banker].point){
                            players[i].balance=players[i].balance+players[i].bet;
                            players[banker].balance=players[banker].balance-players[i].bet;
                            cerr<<players[i].name<<" + $"<<players[i].bet<<";"<<players[banker].name<<" - $"<<players[i].bet<<endl;
                        }else if(players[i].point==players[banker].point){
                        }else{
                            players[i].balance=players[i].balance-players[i].bet;
                            players[banker].balance=players[banker].balance+players[i].bet;
                            cerr<<players[i].name<<" - $"<<players[i].bet<<";"<<players[banker].name<<" + $"<<players[i].bet<<endl;
                        }
                    }
                }
            }else{
            }
        }
        banker=banker+1;
        cout<<"next round?(y/n)"<<endl;
        cin>>Y;
    }while(Y=="y");
    
    display(nop);
    cout<<"game ends"<<endl;
    
    return 0;
}
