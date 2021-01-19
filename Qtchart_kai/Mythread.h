#pragma once
#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QCoreApplication>
#include <QObject>
#include <QProcess>

class MyThread : public QThread
{
	Q_OBJECT
public:
	MyThread();
	void closeThread();

protected:
	virtual void run();

signals:
	void MysignalUpdateData(QString);

private:
	volatile bool isStop;       //isStop是易失性变量，需要用volatile进行申明
	QProcess  *m_Process;

};

#endif // MYTHREAD_H