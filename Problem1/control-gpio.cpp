/* A Simple GPIO application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2018
* ISBN 9781119533160. Please see the file README.md in the repository root
* directory for copyright and GNU GPLv3 license information.            */

#include<iostream>
#include<unistd.h> //for usleep
#include"GPIO.h"
#include"derek_LED.h"
#include<fstream>
#include<string>
#include<sstream>
using namespace exploringBB;
using namespace std;

int main(){
   GPIO outGPIO(49), inGPIOA(26), inGPIOB(46);
   LED LED(3);

   // Basic Output - Flash the LED 10 times, once per second
   outGPIO.setDirection(OUTPUT);
   cout << "The value of the output is: "<< outGPIO.getValue() << endl;

   // Basic Input example
   inGPIOA.setDirection(INPUT);
   cout << "The value of Button A is: "<< inGPIOA.getValue() << endl;
   		   	
   inGPIOB.setDirection(INPUT);
   cout << "The value of Button B is: " << inGPIOB.getValue() << endl; 
   
   if (inGPIOA.getValue()==LOW){
	outGPIO.setValue(HIGH);
	cout << "Turning on external LED" << endl;
   }


   else if (inGPIOB.getValue()==LOW){
	   LED.turnOn();
	   cout << "Turning on on-board LED0" << endl;
   }
   else 
	   LED.turnOff();
   return 0;
}
