#include "QtGuiApplication7.h"
#include <QtWidgets/QApplication>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <QApplication>
#include <QDebug>

// Universal data
#include "universal.h"

// FS interface
//#include "FSinterface.h"

#include "FSUIPC_User.h"

// for setting the timer
#include "timer.h"

// for Serial RS232
//#include "tserial.h"
#include"universal.h"
#include "types.h"
const char *pszErrors[] =
{ "Okay",
"Attempt to Open when already Open",
"Cannot link to FSUIPC or WideClient",
"Failed to Register common message with Windows",
"Failed to create Atom for mapping filename",
"Failed to create a file mapping object",
"Failed to open a view to the file map",
"Incorrect version of FSUIPC, or not FSUIPC",
"Sim is not version requested",
"Call cannot execute, link not Open",
"Call cannot execute: no requests accumulated",
"IPC timed out all retries",
"IPC sendmessage failed all retries",
"IPC request contains bad data",
"Maybe running on WideClient, but FS not running on Server, or wrong FSUIPC",
"Read or Write request cannot be added, memory for Process is full",
};
char buffer_fsupc[25000];
char buffer_reception[12];
char bufftx[40];


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiApplication7 w;
	double Attitude[NROT];
//	FSAttitudeType FSAtt;
	DWORD dwResult;// a pointer to receive an error number if the operation fails.
	//          Tserial *com; // Serial declaration
	int SampleTime; // Sample Time in ms
	Timer timer;
	int capsam = 0;
	int pousseeL, pousseeR;
	int pousseeOldL = 0, pousseeOldR = 0;
	char car;
	int vret, index = 0;
	int oktrame = 0;
	int pousseeTmp;
	char   x[] = " \\\\.\\com3";

	if (FSUIPC_Open(SIM_ANY, &dwResult)){
		// Declaration des variables locales
		const char *pFS[] = { "FS98", "FS2000", "CFS2", "CFS1", "Fly!", "FS2002", "FS2004" };  // Change made 060603

		// Okay, we're linked, and already the FSUIPC_Open has had an initial
		// exchange with FSUIPC to get its version number and to differentiate
		// between FS's.
		printf("CapSim: Link established to FSUIPC\n");

		SampleTime = 100;

		// RS232
		//                       com=new Tserial();
		//                    if( com!=0 )
		//                            com->connect (x,9600,spNONE); // com Initialisation

		//    else
	//	printf("Error Setting COM");
	}
	else{  //Openninig FSUIPC failed
		// printf ("CapSim: Failed to open link to FSUIPC:%s\n", pszErrors[dwResult]) ;
		FSUIPC_Close(); // Closing when it wasn't open is okay, so this is safe here
		//    com->disconnect(); // Closing the port
		return 0;
	}
	while (true) {
//		Sleep(40);
		//if(timer.elasped((clock_t)SampleTime))
		//               if(1){

		/* -------------------------------------- Sending Data --------------------------------------  */

		// Read from FS data structure
		//     FSUIPC_Read(0x000,25000,buffer_fsupc,&dwResult);
		//    FSUIPC_Process(&dwResult); // Process all the request(s)

		w.show();
		return a.exec();
	}
}