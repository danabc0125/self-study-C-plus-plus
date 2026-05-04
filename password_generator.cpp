/// C++ code

#include <iostream>
#include <random>
using namespace std;

int main() //pwd generator
{
  int EN, NN, SN, TC, rn;
  int a{0};
  const string symbols = "-/:;()$&@.,?!_<>[]{}#%";
  random_device rd; //generate random number
  mt19937 gen(rd()); //generate virtual random number
  cout<<"number of En characters:"<<endl;cin>>EN;
  cout<<"number of digital characters:"<<endl;cin>>NN;
  cout<<"number of symbols"<<endl;cin>>SN;

  TC = EN + NN + SN;string pwd(TC, ' ');
  uniform_int_distribution<> dist(0, 25); //scoping...
  uniform_int_distribution<> dist1(1, 2); //
  for(;EN>0;EN--) //English characters
  {
    if(dist1(gen) == 1)
    {
      pwd[a] = dist(gen)+65;
    } else {
      pwd[a] = dist(gen)+97;
    }
    a++;
  }
  uniform_int_distribution<> dist2(0, 9);
  for(;NN>0;NN--) //Numbers
  {
    pwd[a] = dist2(gen)+48;
    a++;
  }
  uniform_int_distribution<> dist3(0, symbols.size()-1);
  for(;SN>0;SN--) //Symbols
  {
    pwd[a] = symbols[dist3(gen)];
    a++;
  }
  uniform_int_distribution<> dist4(0, TC-1);
  for(int i=TC-1;i>=0;i--) //swapping...
  {
    // cout<<pwd<<"  ...swaping"<<endl; //display swapping procedure
    rn = dist4(gen); 
    swap(pwd[i], pwd[rn]); 
  }
  cout<<"\ngenerated pwd:"<<pwd<<endl;
  
  return 0;
}

