#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <Windows.h>
#include <time.h> 
using namespace std;
  ifstream WordsGet("Words.txt");
  ifstream SenGet("Sentences.txt");

string Words_Get(string type)
{
  WordsGet.close();
  ifstream WordsGet("Words.txt");
  string temp4;
  int temp3;
  while(getline(WordsGet, temp4))
  {
    if(temp4 == type)
    {
      getline(WordsGet, temp4);
      temp3 = rand()%stoi(temp4);
      while(getline(WordsGet, temp4) && temp3 > 0)
        temp3--;
      return temp4;
    }
  }
  return "Error: No Such Word Found:" + type; // error
}

string Sen_Get(string type)
{
  SenGet.close();
  ifstream SenGet("Sentences.txt");
  string temp4;
  int temp3;
  while(getline(SenGet, temp4))
  {
    if(temp4 == type)
    {
      getline(SenGet, temp4);
      temp3 = rand()%stoi(temp4);
      while(getline(SenGet, temp4) && temp3 > 0)
        temp3--;
      return temp4;
    }
  }
  return "Error: No Such Sentence Found: " + type; // error
}

string Sen_Conv(string code)
{
  istringstream stream(code);
  int temp4;
  string temp5, result;
  stream >> temp4;
  for(int i=0; i<temp4; i++)
  {
    stream >> temp5;
    if(temp5 == ".stop")
    {
      result.erase(result.size() - 1);
      result += ". ";
    }
    else if(temp5 == ".comma")
    {
      result.erase(result.size() - 1);
      result += ", ";
    }
    else if(temp5.rfind(".", 0) == 0) //Has a "." at the front
    {
      temp5.erase(0, 1);
      result += temp5;
    }
    else
    result += Words_Get(temp5);
    result += " ";
  }
  return result;
}

int main()
{
  string choice;
  int choice2;
  srand (time(NULL));
  if(!WordsGet.is_open())
    cout << "Error loading \"Words.txt\". Please check if the file is installed properly." << endl;
  else if(!SenGet.is_open())
    cout << "Error loading \"Sentences.txt\". Please check if the file is installed properly." << endl;
  else
    cout << "All text documents loaded!" << endl;
  // while(true)
  // {
  //   getline(cin, choice);
  //   if(choice == "word")
  //   {
  //     getline(cin, choice);
  //     cout << Words_Get(choice) << endl;
  //   }
  //   else if(choice == "sen")
  //   {
  //     getline(cin, choice);
  //     cout << Sen_Get(choice) << endl;
  //   }
  //   else 
  //   {
  //     getline(cin, choice);
  //     cout << Sen_Conv(Sen_Get(choice)) << endl;
  //   }
  // }
  while(true)
  {
    cout << "Please select the number that corresponds to the compo you wish to generate. \n";
    cout << "1) Happy feelings \n";
    cout << "2) Weather Introduction \n";
    cout << "3) Pooping Situation (not recommended)\n";
    cin >> choice2;
    switch(choice2)
    {
      case 1:
        cout << Sen_Conv(Sen_Get("Sentence_Happy_Past")) << endl;
        break;
      case 2:
        cout << Sen_Conv(Sen_Get("Sentence_Intro_Weather_Past")) << endl;
        break;
      case 3:
        cout << "You sure bro? (yes/nah I was just kidding lol i did not attend school just to listen to poop jokes smh)" << endl;
        getline(cin, choice);
        getline(cin, choice);
        if(choice == "yes")
        {
          cout << "Fine. I hope you know what is coming to you though..." << endl;
          Sleep(3000);
          while(true)
            cout << Sen_Conv(Sen_Get("Sentence_Pooping_Present")) << endl;
        }
        else
        {cout << "Yeah thats what I thought" << endl;}
    }
    Sleep(1500);
  }
}
