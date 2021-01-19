#include "Qtchart_kai.h"
#include <QtWidgets/QApplication>

#include <QDebug>
#include <QTextCodec> // for жпндотй╬

#pragma execution_character_set("utf-8")


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("utf-8"));

    //Qtchart_kai w;
   // w.show();
	mainMenu w;
	//w.setMinimumWidth(800);
	//w.setMaximumHeight(1612);
	w.show();


    return a.exec();
}
