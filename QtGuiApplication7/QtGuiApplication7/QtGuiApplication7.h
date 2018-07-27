#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiApplication7.h"
#include <qtimer.h>

class QtGuiApplication7 : public QMainWindow
{
	Q_OBJECT

public:

	QtGuiApplication7(QWidget *parent = Q_NULLPTR);
	static const int fs_offsets_tab[50][2];
	char fs_values_tab[50][20];
	static const float fs_operations_tab[50][2];
	int fs_flag_tab[50];
	static const int fs_types_tab[50];
	char fs_cvalues_tab[50][8];

private:
	Ui::QtGuiApplication7Class ui;
	QTimer *refresh_timer;
	private slots:

	void refresh_data();
	void Alt(int arg1);
	void Spd(int arg1); 
	void Hdg(int arg1);
	void VS(int arg1);
	void Gear(int arg1);
	void AP(int arg1);

signals:
	void refresh_left_gear(bool left_gear);
	void refresh_right_gear(bool right_gear);
	void refresh_nose_gear(bool nose_gear);
	void refresh_rt_alt(int alt);
	void refresh_rt_hdg(int hdg);
	void refresh_rt_spd(int spd);
	void refresh_spd(int spd);
	void refresh_alt(int alt);
	void refresh_hdg(int hdg);
	void refresh_vs(int vs);
	void refresh_gear(int gear);
	void refresh_ap(bool ap_master);
};