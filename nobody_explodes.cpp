#include <iostream>
#include <fstream>
#include "SerialClass.h"
#include <string>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <sstream>

using namespace std;
//using namespace System;
//using namespace System::IO::Ports;

std::string getTime();
void serialOut(int val);

int main(int argc, char* argv[]){
	// Open the logfile and ensure that it is open before continuing
	ifstream logFile ("log\\ktane.log");
	if( logFile.good() ){
	}
	else cout << "Unable to open file" << endl;
	
<<<<<<< HEAD
=======
	// Set up variables for serial communication to Arduino
	string(answer);
	string(portName)="COM6";
	//int baudRate=9600;
>>>>>>> origin/master
	
	
	return 0;
}


std::string getTime()
{
	//Initialize time vars
	std::string timeStr;
	std::string month;
	std::string day;
	std::string hour;
	std::string minute;
	std::string second;
	
	std::stringstream buffer;
	
	//Create timer
	time_t rawTime;
	struct tm *timeInfo;
	time(&rawTime);


	timeInfo = localtime(&rawTime);	
	
	//Fill time variables
	buffer << setfill('0') << setw(2) << std::to_string(timeInfo->tm_mon);
	month = buffer.str();
	buffer.str(std::string());
	buffer << setfill('0') << setw(2) << std::to_string(timeInfo->tm_mday);
	day = buffer.str();
	buffer.str(std::string());
	buffer << setfill('0') << setw(2) << std::to_string(timeInfo->tm_hour);
	hour = buffer.str();
	buffer.str(std::string());
	buffer << setfill('0') << setw(2) << std::to_string(timeInfo->tm_min);
	minute = buffer.str();
	buffer.str(std::string());
	buffer << setfill('0') << setw(2) << std::to_string(timeInfo->tm_sec);
	second = buffer.str();
	buffer.str(std::string());
	
	//Combine each time variable.
	timeStr = std::to_string(1900+timeInfo->tm_year) + "-" +  month + "-" + day + " " + hour + ":" + minute + ":" + second;
	
	return(timeStr);
}

void serialOut(std::string val)
{
	
	ofstream dat;
	//Write value to text file.
	dat.open("dat.dat");
	dat << val;
	dat.close();
	//Shennanigans
	std::string comPort = "COM3";
	std::string command = "cmd /c start "" /min putty -serial "+ comPort +" -sercfg 9600,8,n,1,N -m \"test.txt\"";
	system(command.c_str());
	
	system("taskkill /F /IM putty.exe");
	
	return();
	
	
}
