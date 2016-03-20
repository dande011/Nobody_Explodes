#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
