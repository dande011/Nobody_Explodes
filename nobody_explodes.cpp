#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <sstream>

using namespace std;

std::string getTime();
void serialOut(std::string val);
int getPos(istream& logFile);
int findStats(istream& logFile, string& time, bool& start, bool& end, int& strike, int& strikeTot, bool& boom);
void serialOut(std::string val);

string boolstring( bool b) {return b ? "1" : "0"; }

int main(int argc, char* argv[]){
	bool boom = false;
	string time="-1";
	bool start = 0;
	bool end = 0;
	int strike = 0;
	int strikeTot = 0;
	ifstream logFile;
	ofstream logFileO;
	ifstream logFileOrig;
	string stats;
	string prevStats;
	string line;
	
	while(!boom)
	{	
		logFileOrig.open("log\\ktane.log",std::fstream::binary);
		logFileO.open("log\\copy.log",std::fstream::binary);
		//cout << "Opened file" << endl;
		if( logFileOrig.good() && logFileO.good() ){
			const int len = 4096;
			char buf[4096];
			while(1)
			{
				if(logFileOrig.eof())
					break;
				logFileOrig.read(buf, len);
				int nBytesRead = logFileOrig.gcount();
				if(nBytesRead <= 0)
					break;
				logFileO.write(buf, nBytesRead);
			}
		}
		else cout << "Unable to open file" << endl;
		logFileOrig.close();
		logFileO.close();
		logFile.open("log\\ktane.log");
		if(logFile.good());
		else cout << "Unable to open file" << endl;
		getPos(logFile);
		//cout << "Got Position: " << logFile.tellg() << endl;
		findStats(logFile, time, start, end, strike, strikeTot, boom);
		
		
		stats = "T:" + time + ";S:" + boolstring(start) + ";E:" + boolstring(end) + ";X:" + std::to_string(strike) + ";Y:" + std::to_string(strikeTot) + ";B:" + boolstring(boom) + "\n";
		//cout << "Stats: " << stats << endl;
		if(stats != prevStats)
		{
			//serialOut(stats);
			cout << "Stats: " << stats << endl;
		}
		prevStats = stats;
		logFile.close();
		//cout << "Closed File" << endl;
	}
	
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

int getPos(istream& logFile)
{
	//cout << "Begin getPos" << endl;
	string line;
	string currentTime = "2016-03-20 07:32:56"; //opposed to getTime()
	string extractedTime;
	getline (logFile, line);
	extractedTime = line.substr(9,19);
	//cout << "about to enter loop: " << extractedTime << ' ' << currentTime << ' ' << (extractedTime < currentTime) << endl;
	while(extractedTime < currentTime)
	{
		getline (logFile, line);
		//cout << line << endl;
		if(line[0] != '\r' && line[3] != '<' && line[6] == '2')
		{
			//cout << "in loop" << endl;
			//cout << line.substr(9.19) << endl;
			extractedTime = line.substr(6,19);
			//cout << extractedTime << endl;
		}
	}
	//cout << "exited loop" << endl;
	//cout << line << endl;
	return logFile.tellg();
}

int findStats(istream& logFile, string& time, bool& start, bool& end, int& strike, int& strikeTot, bool& boom)
{
	//cout << "Begin findStats()" << endl;
	string line;
	int found=0;
	while(!logFile.eof())
	{
		//cout << "Begin loop" << endl;
		getline (logFile, line);
		//cout << line << endl;
		//cout << "Time" << endl;
		if(time=="-1")
		{
			found = line.find(" Time: ");
			if (found!=static_cast<int>(std::string::npos)){
				time = line.substr(found+7,3);
				//cout << "Time: " << time << endl;
			}
		}
		//cout << "Start" << endl;
		found = line.find("Round Start!");
		if (found!=static_cast<int>(std::string::npos)) {
			start = 1;
			//cout << "Round Start!" << endl;
		}
		//cout << "Over" << endl;
		found = line.find("Round Over.");
		if (found!=static_cast<int>(std::string::npos)){
			end = 1;
			//cout << "Round Over." << endl;
		}
		found = line.find("Strike! ");
		if (found!=static_cast<int>(std::string::npos)){
			if(line[found+8]-48 > strike)
				strike = line[found+8]-48;
			//cout << line << endl;
			//cout << found << ' ' << line[49] << endl;
			if(line[49]-48 > strikeTot)
				strikeTot = line[49]-48;
			//cout << "Strike: " << strike << endl;
		}
		found = line.find("Boom");
		if (found!=static_cast<int>(std::string::npos)){
			boom = 1;
			cout << "Boom" << endl;
			return 0;
		}
	}
	//cout << "End findStats()" << endl;
	return 0;
}

void serialOut(std::string val)
{
	
	ofstream dat;
	dat.open("dat.dat");
	
	dat << val;
	
	dat.close();
	//cmd /c start /min 
	
	system("min.exe");
	std::string comPort = "COM3";
	std::string command = "plink -serial "+ comPort +" < \"test.txt\"&";
	system(command.c_str());
	system("ping localhost -w 20 -n 2");
	system("taskkill /F /IM plink.exe");
	system("exit 0");
	//If this gives you grief, comment out the system('exit 0');
	return;
	
	
}
