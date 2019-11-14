//github.com/xKaco/HW7

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include "derek_LED.h"

using namespace std;

int main(int argc, char* argv[]){
   if(argc!=3){
	cout << "Usage is makeLEDs <command>" << endl;
        cout << "   command is one of: on, off, flash or status" << endl;
	cout << " e.g. makeLEDs flash" << endl;
   }
   cout << "Starting the makeLEDs program" << endl;
   string cmd(argv[1]);
   int blink_num = atoi(argv[2]);	//number of blinksis the second argument
   LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
   //got rid of for loop
      if(cmd=="on")leds[0].turnOn();
      else if(cmd=="off")leds[0].turnOff();
      else if(cmd=="flash")leds[0].flash("100"); //default is "50"
      else if(cmd=="status")leds[0].outputState();
      else if (cmd=="blink")leds[0].blink(blink_num); //blink_num is being usedas an input
      else{ cout << "Invalid command!" << endl; }
   //changed all i's to zero to jsut blink one LED 
   cout << "Finished the makeLEDs program" << endl;
   return 0;
}
