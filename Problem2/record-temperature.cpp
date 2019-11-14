#include <iostream>
#include <sstream>
#include "unistd.h"
#include <fstream>
using namespace std;

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"
#define ADC 0

#define FILE_PATH "/home/debian/CPE422-Exam/Problem2/temperatures.txt"

float getTemperature(int adc_value) {     // from the TMP36 datasheet
   float cur_voltage = adc_value * (1.80f/4096.0f); // Vcc = 1.8V, 12-bit
   float diff_degreesC = (cur_voltage-0.75f)/0.01f;
   return (25.0f + diff_degreesC);
}

int readAnalog(int number){
   stringstream ss;
   ss << ADC_PATH << number << "_raw";
   fstream fs;
   fs.open(ss.str().c_str(), fstream::in);
   fs >> number;
   fs.close();
   return number;
}

int main(){
   fstream fs; 
   std::cout << "Starting the record-temperature" << std::endl;
   std::cout << "The ADC value input is: " << readAnalog(ADC) << endl;
      fs.open( FILE_PATH, std::fstream::out);//changed in to out to write to a file
   for (int i=0;i<10;i++){
	   fs << getTemperature(readAnalog(ADC)) << endl;
	   sleep(1);
	   cout << i+1 << " seconds" << endl; 
   }	
fs.close();
}
	
