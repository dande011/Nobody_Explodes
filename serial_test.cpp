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
	std::string value = "Hello World. This is a somewhat long string of text.\n";

	ofstream dat;
	dat.open("dat.dat");
	
	dat << value;
	
	dat.close();
	//cmd /c start /min 
	
	system("min.exe");
	std::string comPort = "COM3";
	std::string command = "plink -serial "+ comPort +" < \"test.txt\"&";
	system(command.c_str());
	system("ping localhost -w 20 -n 2");
	system("taskkill /F /IM plink.exe");
	system("exit 0");
	
	
	return(0);
}
