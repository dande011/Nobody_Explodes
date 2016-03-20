#include <iostream>
#include <fstream>
#include "SerialClass.h"
#include <string>
using namespace std;
//using namespace System;
//using namespace System::IO::Ports;

int main(int argc, char* argv[]){
	// Open the logfile and ensure that it is open before continuing
	ifstream logFile ("log\\ktane.log");
	if( logFile.good() ){
	}
	else cout << "Unable to open file" << endl;
	
	// Set up variables for serial communication to Arduino
	string(answer);
	string(portName)="COM6";
	//int baudRate=9600;
	
	
	return 0;
}
