#include "QtGuiApplication7.h"
#include <QtCore>
#include <QMessageBox>
#include <qDebug>
#include <QTimer>
#include <QDateTime>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
// Universal data
#include "universal.h"
// Offset Fields
/*
0 Real Time Air Speed
1 Real Time Altitude
2 Real Time Heading
3 Left Gear Position
4 Right Gear Position
5 Nose Gear Position
6 Autopilot Altitude
7 Autopilot Heading
8 Autopilot Gear Command
9 Autopilot Throttle
10 Autopilot Master

*/

#define RT_SPD 0
#define RT_ALT 1
#define RT_HDG 2
#define LEFT_GEAR 3
#define RIGHT_GEAR 4
#define NOSE_GEAR 5
#define AP_ALT 6
#define AP_HDG 7
#define AP_GEAR 8
#define AP_SPD 9
#define AP_MASTER 10
#define AP_VS 11
#define STOP 12

#define TYPE_U_INT 0
#define TYPE_U_SHORT 1
#define TYPE_INT 2
#define TYPE_SHORT 3

// FS interface
#include "FSinterface.h"

#include "FSUIPC_User.h"

// for setting the timer
#include "timer.h"

// for Serial RS232
//#include "tserial.h"
#include"universal.h"
#include "types.h"

const int QtGuiApplication7::fs_offsets_tab[50][2] = { { 0x2B8, 4 }, { 0x574, 4 }, { 0x580, 4 }, { 0xBF4, 4 }, { 0xBF0, 4 }, { 0xBEC, 4 }, { 0x7D4, 4 }, { 0x7CC, 2 }, { 0xBE8, 4 }, { 0x88C, 2 }, { 0x7BC, 4 }, { 0x7F2, 2 } };
const float QtGuiApplication7::fs_operations_tab[50][2] = { { 1, 128 }, { 3.28084, 1 }, { 36000, (65536 * 65536 * 100) }, { 1, 16383 }, { 1, 16383 }, { 1, 16383 }, { 3.28084, 65536 }, { 360, 65536 }, { 1, 16383 }, { 100, 16384 }, {1 ,1 }, { 1,1 } };
const int QtGuiApplication7::fs_types_tab[50] = { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 2 };


QtGuiApplication7::QtGuiApplication7(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	int i, j;

	// Offset Types
	/*
	int 0
	short 1
	unsigned int 2
	unsigned short 3
	*/

	// Flags if values change
	
	for (i = 0; i < 50; i++){
			fs_flag_tab[i] = 0;
	}

	// Program Timer
	refresh_timer = new QTimer(this);
	connect(refresh_timer, SIGNAL(timeout()), this, SLOT(refresh_data()));
	refresh_timer->start(40);


	
}

void QtGuiApplication7::Alt(int arg1)
	{

		*((int*)fs_values_tab[AP_ALT]) = (arg1*(65536. / 3.2808));
		fs_flag_tab[AP_ALT] = 1;

	}

void QtGuiApplication7::Spd(int arg1)
{
		*((unsigned short*)fs_values_tab[AP_SPD]) = (unsigned short)((arg1 * 16384) / 100);
		fs_flag_tab[AP_SPD] = 1;
}
void QtGuiApplication7::Hdg(int arg1)


{
	int capsam;
	capsam = (arg1 * 65536) / 36;
	capsam += ((capsam % 10) >= 5 ? 10 : 0);
	capsam = capsam / 10;
	*((int *)fs_values_tab[AP_HDG]) = capsam;
	fs_flag_tab[AP_HDG] = 1;

}

void QtGuiApplication7::VS(int arg1)
{

	*((int *)fs_values_tab[AP_VS]) = arg1;
	fs_flag_tab[AP_VS] = 1;


}

void QtGuiApplication7::Gear(int arg1)
{

	*((int *)fs_values_tab[AP_GEAR]) = arg1;
	fs_flag_tab[AP_GEAR] = 1;

}

void QtGuiApplication7::AP(int arg1)
{

	*((int *)fs_values_tab[AP_MASTER]) = arg1;
	fs_flag_tab[AP_MASTER] = 1;

}


void QtGuiApplication7::refresh_data()
{
	char buffer[65600];
	char buffer_test[25];
	int ap_alt, ap_hdg, gear, ap_master, rt_alt, left_gear, right_gear, nose_gear, rt_spd, vs;
	int spd;
	unsigned int rt_hdg;

	int i = 0, j=0, process_flag = 0, val_int;
	short val_short;
	unsigned int val_u_int;
	unsigned short val_u_short;
	DWORD dwResult;
	while (i < STOP){
		if (fs_flag_tab[i])  {
			FSUIPC_Write((DWORD)fs_offsets_tab[i][0], fs_offsets_tab[i][1], (void *)fs_values_tab[i], &dwResult);
			fs_flag_tab[i] = 0;

		}
		i++;
	}
	FSUIPC_Read(0,65535,buffer, &dwResult);
	DWORD error = dwResult;
	FSUIPC_Process(&dwResult);

	while (j < STOP){
		if (fs_types_tab[j] == TYPE_U_INT){
			*(unsigned int *)fs_cvalues_tab[j] = (*(unsigned int *)(buffer + (fs_offsets_tab[AP_ALT][0]))) * fs_operations_tab[j][0] / fs_operations_tab[j][1];
		}
		else if (fs_types_tab[j] == TYPE_U_SHORT){
			*(unsigned short *)fs_cvalues_tab[j] = (*(unsigned short *)(buffer + (fs_offsets_tab[AP_ALT][0]))) * fs_operations_tab[j][0] / fs_operations_tab[j][1];
		}
		else if (fs_types_tab[j] == TYPE_INT){
			*(int *)fs_cvalues_tab[j] = (*(int *)(buffer + (fs_offsets_tab[AP_ALT][0]))) * fs_operations_tab[j][0] / fs_operations_tab[j][1];
		}
		else if (fs_types_tab[j] == TYPE_SHORT){
			*(short *)fs_cvalues_tab[j] = (*(short *)(buffer + (fs_offsets_tab[AP_ALT][0]))) * fs_operations_tab[j][0] / fs_operations_tab[j][1];
		}
		j++;
	}



	emit refresh_alt(*(unsigned int *)fs_cvalues_tab[AP_ALT]);
	emit refresh_hdg(*(unsigned short *)fs_cvalues_tab[AP_HDG]);
	emit refresh_gear(*(unsigned int *)fs_cvalues_tab[AP_GEAR]);
	emit refresh_spd(*(unsigned short *)fs_cvalues_tab[AP_SPD]);
	emit refresh_ap((bool)(*(unsigned int *)fs_cvalues_tab[AP_MASTER]));
	emit refresh_vs(*(unsigned short *)fs_cvalues_tab[AP_VS]);

	emit refresh_rt_alt(*(unsigned int *)fs_cvalues_tab[RT_ALT]);
	emit refresh_rt_spd(*(unsigned int *)fs_cvalues_tab[RT_SPD]);
	emit refresh_rt_hdg(*(unsigned int *)fs_cvalues_tab[RT_HDG]);

	emit refresh_left_gear((bool)(*(unsigned int *)fs_cvalues_tab[LEFT_GEAR]));
	emit refresh_right_gear((bool)(*(unsigned int *)fs_cvalues_tab[RIGHT_GEAR]));
	emit refresh_nose_gear((bool)(*(unsigned int *)fs_cvalues_tab[NOSE_GEAR]));
	//QMessageBox::information(this, "Altitude", alt_c);

}

