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
	
	fs_types_tab[RT_SPD] = 0;
	fs_types_tab[RT_ALT] = 0;
	fs_types_tab[RT_HDG] = 2;
	fs_types_tab[LEFT_GEAR] = 0;
	fs_types_tab[RIGHT_GEAR] = 0;
	fs_types_tab[NOSE_GEAR] = 0;
	fs_types_tab[AP_ALT] = 0;
	fs_types_tab[AP_HDG] = 0;
	fs_types_tab[AP_GEAR] = 0;
	fs_types_tab[AP_SPD] = 3;
	fs_types_tab[AP_MASTER] = 0;
	fs_types_tab[AP_VS] = 3;

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
	
	*((unsigned short*)fs_values_tab[AP_SPD]) = (unsigned short)round(((arg1 * 16384) / 100));
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
	int ap_alt, ap_hdg, gear, ap_master, rt_alt, left_gear, right_gear, nose_gear, rt_spd, vs;
	unsigned short spd;
	unsigned int rt_hdg;

	int i = 0, process_flag = 0, val_int;
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
	FSUIPC_Process(&dwResult);

	i = buffer[fs_offsets_tab[AP_ALT][0]];

	ap_alt = (((unsigned int )buffer[fs_offsets_tab[AP_ALT][0]]) * 3.28084) / 65536.;
	spd = round(((unsigned short )buffer[fs_offsets_tab[AP_SPD][0]]) * 100. / 16384);
	ap_hdg = ((unsigned short )buffer[fs_offsets_tab[AP_HDG][0]]) * 360. / 65536.;
	gear = ((unsigned int )buffer[fs_offsets_tab[AP_GEAR][0]]) / 16383;
	rt_alt = ((unsigned int )buffer[fs_offsets_tab[RT_ALT][0]]) * 3.28084;
	rt_hdg = (((unsigned int )buffer[fs_offsets_tab[RT_HDG][0]]) * 36000.) / (65536 * 65536.);
	rt_spd = ((unsigned int )buffer[fs_offsets_tab[RT_SPD][0]]) / 128;
	vs = ((short )buffer[fs_offsets_tab[AP_VS][0]]);
	ap_master = ((int )buffer[fs_offsets_tab[AP_MASTER][0]]);



	emit refresh_alt(ap_alt);
	emit refresh_hdg(ap_hdg);
	emit refresh_gear(gear);
	emit refresh_spd(spd);
	emit refresh_ap((bool)ap_master);
	emit refresh_vs(vs);

	emit refresh_rt_alt(rt_alt);
	emit refresh_rt_spd(rt_spd);
	emit refresh_rt_hdg(rt_hdg/100);

	emit refresh_left_gear((bool)(*((int *)fs_values_tab[LEFT_GEAR]) / 16383));
	emit refresh_right_gear((bool)(*((int *)fs_values_tab[RIGHT_GEAR]) / 16383));
	emit refresh_nose_gear((bool)(*((int *)fs_values_tab[NOSE_GEAR]) / 16383));
	//QMessageBox::information(this, "Altitude", alt_c);

}

