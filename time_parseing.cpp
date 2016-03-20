#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
	std::string value;
	ofstream dat;
	dat.open("dat.dat");
	
	dat << value;
	
	dat.close();
	
	std::string comPort = "COM3";
	std::string command = "cmd /c start "" /min putty -serial "+ comPort +" -sercfg 9600,8,n,1,N -m \"test.txt\"";
	system(command.c_str());
	
	system("taskkill /F /IM putty.exe");
	
	return(0);
}
