/** Simple On-board LED flashing program - written in C++ by Derek Molloy
*    simple functional struture for the Exploring BeagleBone book
*
*    This program uses USR LED 3 and can be executed in three ways:
*         makeLED on
*         makeLED off
*         makeLED flash  (flash at 100ms intervals - on 50ms/off 50ms)
*         makeLED status (get the trigger status)
*
* * Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

#include<iostream>
#include<fstream>
#include<string>
using namespace std;


#define FILE_PATH "/home/debian/CPE422-Exam/Problem3/"


int main(int argc, char* argv[]){
	float f_line=0.0;
   	if(argc!=2){
	cout << "Usage is for reading file temperatures.txt: " << endl;
        return 2;
   }


   string cmd(argv[1]);// argument after command 
   cout << "Processing Temperatures... " << endl;
   cout << "The current file being read is: " << FILE_PATH << endl;
   
	// display the current trigger details
        std::fstream fs;  //needed
	string cmd_path = "/" + cmd;
	fs.open( FILE_PATH + cmd_path, std::fstream::in);
	string line;
	while(getline(fs,line)) 
		//cout << line << endl;
		f_line = f_line + stof(line);
	fs.close();
	float avg_temp=f_line/10;
	cout << "Avergae Temperature is: " << avg_temp << endl; 
	
   cout << "Finished the process-temp Program" << endl;
   return 0;
}
