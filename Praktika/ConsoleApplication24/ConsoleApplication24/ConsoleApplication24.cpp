// ConsoleApplication24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <Windows.h>

void setup();
void CreateFile(TCHAR* ComPort, HANDLE& serialPort);
void CloseFile();

using namespace std;

struct _send {

	char prefix;
	char len;
	char ID;
	char command;
} send;


int main(int argc, char** argv)
{

	//Traektoria dlia dvigatelia


    //obiavliaem stroky s imenem porta
	TCHAR* ComPort = L"com1";

	//obiavliaem obiekt "serialPort"
	HANDLE serialPort;

	CreateFile(ComPort, serialPort);
	 
	////Parametri soedineniia
	////========================================================
	//DCB dcbSerialParams = { 0 };
	//dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
	//if (!GetCommState(ComPort, &dcbSerialParams))
	//{
	//	cout << "getting state error\n";
	//}
	//dcbSerialParams.BaudRate = CBR_9600;//skorost peredaci dannih
	//dcbSerialParams.ByteSize = 8;//razmer baita
	//dcbSerialParams.StopBits = ONESTOPBIT;
	//dcbSerialParams.Parity = NOPARITY;
	//if (!SetCommState(ComPort, &dcbSerialParams))
	//{
	//	cout << "error setting serial port state\n";
	//}
	////=======================================================

	send.command = '4';
	send.prefix = ':';
	send.ID = '777';
	char summ = sizeof(send.command) + sizeof(send.ID);
	send.len = summ + sizeof(summ) + 1;
	


    return 0;
}

void CreateFile(TCHAR* ComPort, HANDLE& serialPort)
{
	    serialPort = CreateFile(ComPort,
		GENERIC_READ | GENERIC_WRITE,
		0,      //  otkrit s eksklyzivnim dostypom
		NULL,   //  standartnie atribyti zashiti
		OPEN_EXISTING, //  ispolzovat OPEN_EXISTING
		0,      //  ne peregryzat I/O
		NULL); //  hTemplate == NULL dlia comm ystroistva

	//Proverka
	if (serialPort != INVALID_HANDLE_VALUE)	{
		cout << "open!\n";
	} else {	
		cout << "cant open! \n";
	}
}

