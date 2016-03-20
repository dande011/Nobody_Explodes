#include <iostream>
#include <afx.h>

int main()
{
    using namespace std;
    int i=0;
//  cout << "Hello world!" << endl;



    HANDLE hSerial;

    hSerial = CreateFile("COM5",
    GENERIC_READ | GENERIC_WRITE,
    FILE_SHARE_WRITE | FILE_SHARE_READ,
    0,
    OPEN_EXISTING,
    FILE_ATTRIBUTE_NORMAL,
    0);

    if(hSerial==INVALID_HANDLE_VALUE)
    {
        if(GetLastError()==ERROR_FILE_NOT_FOUND)
        {
//          TRACE("serial port does not exist for reading\n");
        //serial port does not exist. Inform user.
        }
//          TRACE("some other error,serial port does not exist for reading\n");
        //some other error occurred. Inform user.
    }

    DCB dcbSerialParams = {0};

    dcbSerialParams.DCBlength=sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) 
    {
//                  TRACE("error getting state for reading\n");
    //error getting state
    }

    dcbSerialParams.BaudRate=9600;
    dcbSerialParams.ByteSize=8;
    dcbSerialParams.StopBits=ONESTOPBIT;
    dcbSerialParams.Parity=NOPARITY;
    dcbSerialParams.fOutX=TRUE;
    dcbSerialParams.fInX=TRUE;
    if(!SetCommState(hSerial, &dcbSerialParams))
    {
    //TRACE("error setting state for reading\n");
    //error setting serial port state
    }
    COMMTIMEOUTS timeouts={0};

    timeouts.ReadIntervalTimeout=50;
    timeouts.ReadTotalTimeoutConstant=50;
    timeouts.ReadTotalTimeoutMultiplier=10;

    timeouts.WriteTotalTimeoutConstant=50;
    timeouts.WriteTotalTimeoutMultiplier=10;

    if(!SetCommTimeouts(hSerial, &timeouts))
    {
//      TRACE("some error occured for reading\n");
        //error occureed. Inform user
    }       
    int n=100,n1=100;
    char szBuff[100];
    DWORD dwBytesRead = 0;
    char szBuff1[100];
    DWORD dwByteswrote = 0;
    memset(szBuff1,0,100);
    memcpy(szBuff1,"LIST\r",5);
    FlushFileBuffers(hSerial);
    LPDWORD uf=0;
    GetCommModemStatus(hSerial,uf);
    TRACE("%d\n",uf);
    if(!WriteFile(hSerial, szBuff1,5, &dwByteswrote, NULL))
    {
                    cout << "error writing" ;
    }
    cout << szBuff1 << endl;
    cout << dwByteswrote << endl;
    dwByteswrote=0;
    while(1)
    {
        if(!ReadFile(hSerial, szBuff, n1, &dwBytesRead, NULL))
        {
            cout << "error reading";
            break;
        }
        else
        {
            cout << dwBytesRead << endl;
            szBuff[dwBytesRead]='\0';
            if(dwBytesRead>0)
            {
                cout << (szBuff);

                break;
            }
            else
            {
            }
        }
    }
    cin >> i;
}
