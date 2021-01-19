#include "mythread.h"
#include <QDebug>
#include <QMutex>
#include <qprocess.h>
#include "Qtchart_kai.h"


MyThread::MyThread()
{
	isStop = false;

}

void MyThread::closeThread()
{
	isStop = true;
}

void MyThread::run()
{	

	qint64 pid = GetCurrentThreadId();
	QString pidStr = tr("%1").arg(pid);

	QString qstrRExePath("warhead.exe");
	QString str = qstrRExePath + " >cmdLog.txt";
	qDebug()<<str;
	//����system����
	//system(str.toStdString().c_str());
	QStringList arguments;
	arguments << " >cmdLog.txt";
	//����process����
	QProcess p(this);
	p.execute(str);

	qDebug() << "mtthread.cpp pid :" << pid;




}