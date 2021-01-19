#pragma once
#ifndef TXTTHREAD_H
#define TXTTHREAD_H

#include <QThread>
#include <QCoreApplication>
#include <QObject>

class txtThread : public QThread
{
	Q_OBJECT
public:
	txtThread();
	void closeThread();
	

protected:
	virtual void run();

signals:
	void sendLogMsg(QString);

private:
	volatile bool isStop;       //isStop����ʧ�Ա�������Ҫ��volatile��������
	bool FindProcess();

private slots:
	void threadMsg(QString msg);
};

#endif // TXTTHREAD_H