#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]){
	cout << argc << endl;
	if (argc == 1)
		cout << "Real mode" << endl;
	else if(static_cast<string>(argv[1]) == "test"){
		cout << "Test Mode" << endl;
	}
	else{
		cout << "Not a valid mode" << endl;
		return 0;
	}
	//ifstream fin;
	//fin.open("logfile");
	return 0;
}
