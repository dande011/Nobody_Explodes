#include <iostream>
using namespace std;

int main(){
	HANDLE hComm;
	hComm = CreateFile( gszPort,  
		GENERIC_READ | GENERIC_WRITE, 
		0, 
		0, 
		OPEN_EXISTING,
		FILE_FLAG_OVERLAPPED,
		0);
	if (hComm == INVALID_HANDLE_VALUE)
	// error opening port; abort
	return 0;
};
