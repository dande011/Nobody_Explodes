#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <sstream>

using namespace std;

std::string getTime();

int main(int argc, char* argv[]){
	string line;
	ifstream logFile ("log\\ktane.log");
	if( logFile.good() ){
		while( logFile.good() ){
			getline (logFile, line);
		}
		cout << "done" << endl;
		logFile.close();
	}
	else cout << "Unable to open file" << endl;
	
	
	
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
