#pragma once

#include <QWidget>
#include "ui_mainMenu.h"

class mainMenu : public QWidget
{
	Q_OBJECT

public:
	mainMenu(QWidget *parent = Q_NULLPTR);
	~mainMenu();

private:
	Ui::mainMenu ui;

private slots:
	void start();
};
